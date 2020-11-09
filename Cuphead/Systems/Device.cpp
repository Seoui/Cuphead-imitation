#include "stdafx.h"
#include "Device.h"
#include "resource.h"

namespace wrl = Microsoft::WRL;

int APIENTRY WinMain
(
	HINSTANCE hInstance,
	HINSTANCE prevInstance,
	LPSTR lPCmdLine,
	int nCmdShow
)
{
	InitWindow(hInstance, nCmdShow);
	InitDirect3D(hInstance);

	Running();

	return 0;
}

UINT Width = 1280;
UINT Height = 720;
HWND Hwnd = nullptr;
wstring Title = L"Cuphead";

wrl::ComPtr<IDXGISwapChain> SwapChain;
wrl::ComPtr<ID3D11Device> Device;
wrl::ComPtr<ID3D11DeviceContext> DeviceContext;
wrl::ComPtr<ID3D11RenderTargetView> RTV;

unique_ptr<Keyboard> Key;
unique_ptr<CMouse> Mouse;

void InitWindow(HINSTANCE hInstance, int nCmdShow)
{
	//Register Wnd Class
	{
		WNDCLASSEX wc;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = WndProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = hInstance;
		wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = static_cast<HBRUSH>(WHITE_BRUSH);
		wc.lpszMenuName = nullptr;
		wc.lpszClassName = Title.c_str();
		wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

		WORD check = RegisterClassEx(&wc);
		assert(check != 0);
	}

	//Create Window & Show Window
	{
		Hwnd = CreateWindowEx
		(
			0,
			Title.c_str(),
			Title.c_str(),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			Width,
			Height,
			nullptr,
			nullptr,
			hInstance,
			nullptr
		);
		assert(Hwnd != nullptr);

		RECT rect = { 0, 0, static_cast<LONG>(Width), static_cast<LONG>(Height) };
		UINT centerX = (GetSystemMetrics(SM_CXSCREEN) - Width) / 2;
		UINT centerY = (GetSystemMetrics(SM_CYSCREEN) - Height) / 2;
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
		MoveWindow
		(
			Hwnd, centerX, centerY,
			rect.right - rect.left,
			rect.bottom - rect.top,
			TRUE
		);

		ShowWindow(Hwnd, nCmdShow);
		UpdateWindow(Hwnd);
	}
}

void InitDirect3D(HINSTANCE hInstance)
{
	//SwapChain
	DXGI_MODE_DESC bufferDesc;
	ZeroMemory(&bufferDesc, sizeof(DXGI_MODE_DESC));
	bufferDesc.Width = Width;
	bufferDesc.Height = Height;
	bufferDesc.RefreshRate.Numerator = 60;		
	bufferDesc.RefreshRate.Denominator = 1;		
	bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

	DXGI_SWAP_CHAIN_DESC swapDesc;
	ZeroMemory(&swapDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
	swapDesc.BufferDesc = bufferDesc;
	swapDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapDesc.BufferCount = 1;
	swapDesc.SampleDesc.Count = 1;
	swapDesc.SampleDesc.Quality = 0;
	swapDesc.OutputWindow = Hwnd;
	swapDesc.Windowed = TRUE;
	swapDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	vector<D3D_FEATURE_LEVEL> feature_level =
	{
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_2,
		D3D_FEATURE_LEVEL_9_1,
	};

	// Create Device & SwapChain
	HRESULT hr = D3D11CreateDeviceAndSwapChain
	(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		D3D11_CREATE_DEVICE_BGRA_SUPPORT,
		feature_level.data(),
		feature_level.size(),
		D3D11_SDK_VERSION,
		&swapDesc,
		&SwapChain,
		&Device,
		nullptr,
		&DeviceContext
	);
	assert(SUCCEEDED(hr));

	CreateBackBuffer();
}

WPARAM Running()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	ImGui::Create(Hwnd, Device.Get(), DeviceContext.Get());
	ImGui::StyleColorsDark();

	DirectWrite::Create();

	Time::Create();
	Time::Get()->Start();

	Key = make_unique<Keyboard>();
	Mouse = make_unique<CMouse>(Hwnd);

	InitScene();

	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Time::Get()->Update();
			Update();
			Mouse->Update();
			ImGui::Update();
			Render();
		}
	}

	Time::Delete();
	ImGui::Delete();
	DirectWrite::Delete();

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui::WndProc(reinterpret_cast<UINT*>(Hwnd), msg, wParam, lParam))
		return true;

	if (Mouse != nullptr)
		Mouse->WndProc(msg, wParam, lParam);

	switch (msg)
	{
	case WM_SIZE:
	{
		if(Device != nullptr)
		{
			ImGui::Invalidate();

			Width = LOWORD(lParam);
			Height = HIWORD(lParam);

			DirectWrite::DeleteBackBuffer();

			HRESULT hr = SwapChain->ResizeBuffers(0, Width, Height, DXGI_FORMAT_UNKNOWN, 0);
			assert(SUCCEEDED(hr));

			DirectWrite::CreateBackBuffer();
			CreateBackBuffer();

			ImGui::Validate();
		}
	}
	break;
		case WM_DESTROY: PostQuitMessage(0); return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

void CreateBackBuffer()
{
	// Get BackBuffer
	wrl::ComPtr<ID3D11Texture2D> BackBuffer;
	HRESULT hr = SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), &BackBuffer);
	assert(SUCCEEDED(hr));

	// Create RTV
	hr = Device->CreateRenderTargetView(BackBuffer.Get(), nullptr, &RTV);
	assert(SUCCEEDED(hr));

	// Set OM
	DeviceContext->OMSetRenderTargets(1, RTV.GetAddressOf(), nullptr);

	// Create Viewport
	{
		D3D11_VIEWPORT viewPort;
		ZeroMemory(&viewPort, sizeof(D3D11_VIEWPORT));
		viewPort.TopLeftX = 0;
		viewPort.TopLeftY = 0;
		viewPort.Width = static_cast<float>(Width);
		viewPort.Height = static_cast<float>(Height);

		DeviceContext->RSSetViewports(1, &viewPort);
	}
}