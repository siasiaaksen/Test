#include "PreCompile.h"
#include "MyCustomRenderer.h"

MyCustomRenderer::MyCustomRenderer()
{
	CreateRenderUnit();
	SetMesh("TestMesh");
	SetMaterial("MyMaterial");

	MyColor.Albedo = float4(1.0f, 1.0f, 1.0f, 1.0f);

	GetRenderUnit().ConstantBufferLinkData("FMyColor", MyColor);
}

MyCustomRenderer::~MyCustomRenderer()
{
}

