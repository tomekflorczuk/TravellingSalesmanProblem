#include "Clock.h"

float Clock::Duration;
long long int Clock::elapsed;
long long int Clock::frequency;
long long int Clock::start;

//Konstruktor
Clock::Clock()
{
	Duration = 5;
	elapsed = 0;
	frequency = 0;
	start = 0;
}

//Ustawianie zadanego czasu trwania algorytmu
void Clock::SetDuration(float duration)
{
	Duration = duration;
}

//Dost�p do zadanego czasu trwania algorytmu
float Clock::GetDuration()
{
	return Duration;
}

//Pomiar czasu
long long int Clock::read_QPC()
{
	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	return((long long int)count.QuadPart);
}

//Dost�p do casu startu algorytmu
long long int Clock::GetStart()
{
	return start;
}

//Ustawienie czasu startu algorytmu
void Clock::SetStart(long long int start)
{
	Clock::start = start;
}

//Dost�p do cz�stotliwo�ci
long long int Clock::GetFrequency()
{
	return frequency;
}

//Dost�p do czasu trwania algorytmu
long long int Clock::GetElapsed()
{
	return elapsed;
}

//Ustawienie czasu trwania algorytmu
void Clock::SetElapsed(long long int elapsed)
{
	Clock::elapsed = elapsed;
}