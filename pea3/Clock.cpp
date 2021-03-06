#include "Clock.h"
#include <windows.h>

//Ustawiony czas trwania algorytmu w sekundach
float Clock::Duration;
//Częstotliwość impulsów licznika
long long int Clock::Frequency;
//Czas rozpoczęcia pracy algorytmu
long long int Clock::Start;
//Czas który upłynął od startu pracy algorytmu
long long int Clock::Elapsed;

//Konstruktor
Clock::Clock()
{
	Duration = 5;
}

//Metoda czytania czasu z procesora
long long Clock::read_QPC()
{
	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	return((long long int)count.QuadPart);
}

//Dostęp do czasu trwania algorytmu
float Clock::GetDuration()
{
	return Duration;
}

//Ustawienie czasu trwania algorytmu
void Clock::SetDuration(float duration)
{
	Duration = duration;
}

//Dostęp do częstotliwości
long long int Clock::GetFrequency()
{
	return Frequency;
}

//Ustawienie częstotliwości
void Clock::SetFrequency(long long int frequency)
{
	Frequency = frequency;
}

//Dostęp do czasu startu pracy algorytmu
long long int Clock::GetStart()
{
	return Start;
}

//Ustawienie czasu startu algorytmu
void Clock::SetStart(long long start)
{
	Start = start;
}

//Dostep do upłyniętego czasu pracy algorytmu
long long Clock::GetElapsed()
{
	return Elapsed;
}

//Ustawienie upłyniętego czasy pracy algorytmu
void Clock::SetElapsed(long long elapsed)
{
	Elapsed = elapsed;
}