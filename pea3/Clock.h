#pragma once

class Clock
{
	static float Duration;
	static long long int Frequency, Start, Elapsed;
public:
	Clock();
	long long int static read_QPC();
	static float GetDuration();
	static void SetDuration(float duration);
	static long long int GetFrequency();
	static void SetFrequency(long long int frequency);
	static long long int GetStart();
	static void SetStart(long long int start);
	static long long int GetElapsed();
	static void SetElapsed(long long int elapsed);
};