#pragma once
#include <EngineCore/GameMode.h>


class ATestLevel : public AGameMode
{
public:
	ATestLevel();
	~ATestLevel();

	ATestLevel(const ATestLevel& _Other) = delete;
	ATestLevel(ATestLevel&& _Other) noexcept = delete;
	ATestLevel& operator=(const ATestLevel& _Other) = delete;
	ATestLevel& operator=(ATestLevel&& _Other) noexcept = delete;

	void Tick(float _DeltaTime);

protected:

private:
	std::shared_ptr<class ATestActor> Object;
};

