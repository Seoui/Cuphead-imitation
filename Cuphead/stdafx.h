#pragma once
// Window
#include <Windows.h>
#include <assert.h>
#include <wrl.h>

// STL
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <functional>
#include <mutex>
#include <algorithm>
#include <random>
#include <math.h>
using namespace std;

// DX Lib
#include <d3d11.h>
#include <D3DX11.h>
#include <D3DX10.h>
#include <D3DX10math.h>
#include <d3dx11effect.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dx10.lib")
#pragma comment(lib, "Effects11d.lib")
#pragma comment(lib, "d3dcompiler.lib")

// DirectWrite
#include <d2d1_2.h>
#include <dwrite.h>
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")

// Imgui
#include <imgui.h>
#include <imguiDx11.h>
#pragma comment(lib, "ImGui.lib")

// Type def
typedef D3DXVECTOR3 Vector3;
typedef D3DXVECTOR2 Vector2;
typedef D3DXMATRIX Matrix;
typedef D3DXQUATERNION Quaternion;
typedef D3DXCOLOR Color;

// Framework
#include "Systems/Time.h"
#include "Systems/Keyboard.h"
#include "Systems/Mouse.h"
#include "Systems/DirectWrite.h"

#include "Renders/Shader.h"
#include "Renders/Sprite.h"
#include "Renders/Clip.h"
#include "Renders/Animation.h"

#include "Utilities/String.h"
#include "Utilities/Math.h"

#include "Collider/Collider.h"

#include "Static/StaticCollisionList.h"

// Macro
#define SAFE_DELETE(p) { if(p) { delete(p); (p) = nullptr; }}
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p); (p) = nullptr; }}
#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p) = nullptr; }}

// Global
extern UINT Width;
extern UINT Height;

extern HWND Hwnd;
extern wstring Title;

// DX Interface
extern Microsoft::WRL::ComPtr<IDXGISwapChain> SwapChain;
extern Microsoft::WRL::ComPtr<ID3D11Device> Device;
extern Microsoft::WRL::ComPtr<ID3D11DeviceContext> DeviceContext;
extern Microsoft::WRL::ComPtr<ID3D11RenderTargetView> RTV;

extern unique_ptr<Keyboard> Key;
extern unique_ptr<CMouse> Mouse;