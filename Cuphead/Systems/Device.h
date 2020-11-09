#pragma once

// Function
void InitWindow(HINSTANCE hInstance, int nCmdshow);
void InitDirect3D(HINSTANCE hInstance);
WPARAM Running();
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

// PlayScene
void InitScene();
void Update();
void Render();

void CreateBackBuffer();