#include "PreCompile.h"
#include "TestLevel.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>
#include "TestActor.h"

ATestLevel::ATestLevel()
{
}

ATestLevel::~ATestLevel()
{
	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
	Camera->GetCameraComponent()->SetZSort(0, true);

	Object = GetWorld()->SpawnActor<ATestActor>();
}

void ATestLevel::Tick(float _DeltaTime)
{
	// 부모 호출
	AGameMode::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown('P'))
	{
		GetWorld()->GetMainCamera()->FreeCameraSwitch();
	}
}

