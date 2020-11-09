#include "stdafx.h"
#include "Systems/Device.h"
#include "Viewer/Freedom.h"
#include "Scenes/Scene.h"
#include "Scenes/CagneyCarnation.h"

shared_ptr<SceneValues> values;
vector<unique_ptr<Scene>> scenes;

void InitScene()
{
	// default camera
	values = make_shared<SceneValues>();
	values->MainCamera = make_unique<Freedom>();
	D3DXMatrixIdentity(&values->Projection);
	// Initialize scenes
	scenes.push_back(make_unique<CagneyCarnation>(values));
}

void Update()
{
	values->MainCamera->Update();
	
	D3DXMatrixOrthoOffCenterLH
	(	&values->Projection, 
		0, static_cast<float>(Width), 0, static_cast<float>(Height),
		-1, 1
	); 
	for (auto& scene : scenes)
		scene->Update();
}

void Render()
{
	const float color[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	DeviceContext->ClearRenderTargetView(RTV.Get() , color);
	{
		for (auto& scene : scenes)
			scene->Render();
	}

	ImGui::Render();

	DirectWrite::GetDC()->BeginDraw();
	{
		RECT rect = { 0, 0, 500, 200 };
		wstring text = L"FPS : " + to_wstring(static_cast<int>(ImGui::GetIO().Framerate));
		DirectWrite::RenderText(text, rect);
	}
	DirectWrite::GetDC()->EndDraw();

	SwapChain->Present(0, 0);
} 