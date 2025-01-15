#include "PreCompile.h"
#include "MyCustomRenderer.h"

MyCustomRenderer::MyCustomRenderer()
{
	CreateRenderUnit();
	SetMesh("TestMesh");
	SetMaterial("TestMaterial");
}

MyCustomRenderer::~MyCustomRenderer()
{
}

