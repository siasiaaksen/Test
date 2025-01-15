#include "PreCompile.h"
#include "TestLevel.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EnginePlatform/EngineInput.h>
#include "MyCustomRenderer.h"


ATestLevel::ATestLevel()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
	Camera->GetCameraComponent()->SetZSort(0, true);

	Renderer = CreateDefaultSubObject<MyCustomRenderer>();
	Renderer->SetupAttachment(RootComponent);
	Renderer->SetScale3D({ 100.0f, 100.0f, 100.0f });
}

ATestLevel::~ATestLevel()
{
}

void ATestLevel::Tick(float _DeltaTime)
{
	AGameMode::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown('P'))
	{
		GetWorld()->GetMainCamera()->FreeCameraSwitch();
	}
}