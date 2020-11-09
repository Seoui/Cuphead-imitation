#include "stdafx.h"
#include "Time.h"

Time* Time::instance = nullptr;
bool Time::isTimerStopped = true;
float Time::timeElapsed = 0.0f;

Time::Time() :
	ticksPerSecond(0), currentTime(0), lastTime(0), lastFPSUpdate(0), fpsUpdateInterval(0),
	frameCount(0), runningTime(0), framePerSecond(0)
{
	QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER *>(&ticksPerSecond));
	fpsUpdateInterval = ticksPerSecond >> 1;
}

Time* Time::Get()
{
	assert(instance != nullptr);

	return instance;
}

void Time::Create()
{
	assert(instance == nullptr);

	instance = new Time();
}

void Time::Delete()
{
	SAFE_DELETE(instance);
}

void Time::Update()
{
	if (isTimerStopped) return;

	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER *>(&currentTime));
	timeElapsed = static_cast<float>(currentTime - lastTime) / static_cast<float>(ticksPerSecond);
	runningTime += timeElapsed;

	frameCount++;
	if (currentTime - lastFPSUpdate >= fpsUpdateInterval)
	{
		float tempCurrentTime = static_cast<float>(currentTime) / static_cast<float>(ticksPerSecond);
		float tempLastTime = static_cast<float>(lastFPSUpdate) / static_cast<float>(ticksPerSecond);
		framePerSecond = static_cast<float>(frameCount) / (tempCurrentTime - tempLastTime);

		lastFPSUpdate = static_cast<INT64>(currentTime);
		frameCount = 0;
	}

	lastTime = currentTime;
}

void Time::Print()
{

}

void Time::Start()
{
	if (!isTimerStopped)
		assert(false);

	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER *>(&lastTime));
	isTimerStopped = false;
}

void Time::Stop()
{
	if (isTimerStopped)
		assert(false);

	INT64 stopTime = 0;
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER *>(&stopTime));
	runningTime += static_cast<float>(stopTime - lastTime) / static_cast<float>(ticksPerSecond);
	isTimerStopped = true;
}

///////////////////////////////////////////////////////////////////////////////

Timer::Timer()
{
	bComplete = false;

	count = 0;
}

void Timer::Start(function<void()> func, int milliSec, UINT repeat)
{
	assert(bComplete == false);

	bComplete = false;
	thread t([=]()
	{
		while (true)
		{
			if (repeat > 0 && count == repeat)
				break;

			if (bComplete == true)
				break;

			count++;
			Sleep(milliSec);

			if (bComplete == true)
				break;

			func();
		}

		Stop();
	});
	t.detach();
}

void Timer::Stop()
{
	count = 0;

	bComplete = true;
}
