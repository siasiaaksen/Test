#include "PreCompile.h"
#include "TestActor.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/CameraActor.h>
#include "MyCustomRenderer.h"

ATestActor::ATestActor()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Renderer = CreateDefaultSubObject<MyCustomRenderer>();
	Renderer->SetupAttachment(RootComponent);
	Renderer->SetScale3D({ 100.0f, 100.0f, 100.0f });

}

ATestActor::~ATestActor()
{
}

void ATestActor::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	AddActorRotation({ 0.0f, 0.0f, _DeltaTime * 100.0f });
}

