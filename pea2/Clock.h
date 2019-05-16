#pragma once
#include <windows.h>

class Clock
{
	static float Duration;
	static long long int frequency, start, elapsed;
public:
	Clock();
	long long int static read_QPC();
	void static SetDuration(float duration);
	float static GetDuration();
	long long int static GetStart();
	void static SetStart(long long int start);
	long long int static GetFrequency();
	long long int static GetElapsed();
	void static SetElapsed(long long int elapsed);
};