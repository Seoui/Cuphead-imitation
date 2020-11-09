#include "stdafx.h"
#include "Line.h"

Line::Line(Vector2 A, Vector2 B)
	: position(0, 0)
	, scale(1, 1)
{
	CreateBuffer(A, B);

	sView = shader->AsMatrix("View");
	sProjection = shader->AsMatrix("Projection");
	sWorld = shader->AsMatrix("World");
}

Line::~Line()
{
	SAFE_DELETE(shader);
	SAFE_RELEASE(vertexBuffer);
}

void Line::Update(Matrix & V, Matrix & P)
{
	sView->SetMatrix(V);
	sProjection->SetMatrix(P);

	Matrix W, S, T;
	D3DXMatrixScaling(&S, scale.x, scale.y, 1.0f);
	D3DXMatrixTranslation(&T, position.x, position.y, 0.0f);
	W = S * T;

	vertices[0].Position = Vector3(left.x, left.y, 0.0f);
	vertices[1].Position = Vector3(right.x, right.y, 0.0f);

	D3D11_MAPPED_SUBRESOURCE subResource;
	DeviceContext->Map(vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &subResource);
	{
		memcpy(subResource.pData, vertices, sizeof(Vertex) * 2);
	}
	DeviceContext->Unmap(vertexBuffer, 0);

	sWorld->SetMatrix(W);
}

void Line::Render()
{
	UINT stride = sizeof(Vertex);
	UINT offset = 0;

	DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
	DeviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
	shader->Draw(0, 0, 2);
}

void Line::Position(float x, float y)
{
	Position(Vector2(x, y));
}

void Line::Position(Vector2 & vec)
{
	position = vec;
}

void Line::Scale(float x, float y)
{
	Scale(Vector2(x, y));
}

void Line::Scale(Vector2 & vec)
{
	scale = vec;
}

void Line::CreateBuffer(Vector2 A, Vector2 B)
{
	shader = new Shader(L"Line.fx");
	// Vertices
	{
		vertices[0].Position = Vector3(A.x, A.y, 0.0f);
		vertices[1].Position = Vector3(B.x, B.y, 0.0f);
	}
	// Create VertexBuffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DYNAMIC;
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		desc.ByteWidth = sizeof(Vertex) * 2;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA data;
		ZeroMemory(&data, sizeof(D3D11_SUBRESOURCE_DATA));
		data.pSysMem = vertices;

		HRESULT hr = Device->CreateBuffer(&desc, &data, &vertexBuffer);
		assert(SUCCEEDED(hr));
	}
}
