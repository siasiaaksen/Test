#pragma once
#include <EngineCore/Actor.h>


class ATestActor : public AActor
{
public:
	ATestActor();
	~ATestActor();

	ATestActor(const ATestActor& _Other) = delete;
	ATestActor(ATestActor&& _Other) noexcept = delete;
	ATestActor& operator=(const ATestActor& _Other) = delete;
	ATestActor& operator=(ATestActor&& _Other) noexcept = delete;

protected:
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class MyCustomRenderer> Renderer;
};

