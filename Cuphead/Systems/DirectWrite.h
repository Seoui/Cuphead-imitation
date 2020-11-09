#pragma once

class DirectWrite
{
private:
	DirectWrite();
	~DirectWrite();

private:
	static DirectWrite* instance;

public:
	static void Create();
	static void Delete();
	static DirectWrite* Get();
	static ID2D1DeviceContext* GetDC() { return deviceContext; }

	static void CreateBackBuffer();
	static void DeleteBackBuffer();

	static void RenderText(wstring& text, RECT& rect);

private:
	/*
	Microsoft::WRL::ComPtr<ID2D1Factory1> factory;
	static Microsoft::WRL::ComPtr<IDWriteFactory> writeFactory;
	
	Microsoft::WRL::ComPtr<ID2D1Device> device;
	static Microsoft::WRL::ComPtr<ID2D1DeviceContext> deviceContext;

	static Microsoft::WRL::ComPtr<ID2D1Bitmap1> bitmap;
	static Microsoft::WRL::ComPtr<IDXGISurface> surface;

	static Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
	static Microsoft::WRL::ComPtr<IDWriteTextFormat> format;
	*/
	ID2D1Factory1* factory;
	static IDWriteFactory* writeFactory;

	ID2D1Device* device;
	static ID2D1DeviceContext* deviceContext;

	static ID2D1Bitmap1* bitmap;
	static IDXGISurface* surface;

	static ID2D1SolidColorBrush* brush;
	static IDWriteTextFormat* format;
};