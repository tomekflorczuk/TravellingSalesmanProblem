#include "Clock.h"
#include <windows.h>

//Ustawiony czas trwania algorytmu w sekundach
float Clock::Duration;
//Czêstotliwoœæ impulsów licznika
long long int Clock::Frequency;
//Czas rozpoczêcia pracy algorytmu
long long int Clock::Start;
//Czas który up³yn¹³ od startu pracy algorytmu
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

//Dostêp do czasu trwania algorytmu
float Clock::GetDuration()
{
	return Duration;
}

//Ustawienie czasu trwania algorytmu
void Clock::SetDuration(float duration)
{
	Duration = duration;
}

//Dostêp do czêstotliwoœci
long long int Clock::GetFrequency()
{
	return Frequency;
}

//Ustawienie czêstotliwoœci
void Clock::SetFrequency(long long frequency)
{
	Frequency = frequency;
}

//Dostêp do czasu startu pracy algorytmu
long long int Clock::GetStart()
{
	return Start;
}

//Ustawienie czasu startu algorytmu
void Clock::SetStart(long long start)
{
	Start = start;
}

//Dostep do up³yniêtego czasu pracy algorytmu
long long Clock::GetElapsed()
{
	return Elapsed;
}

//Ustawienie up³yniêtego czasy pracy algorytmu
void Clock::SetElapsed(long long elapsed)
{
	Elapsed = elapsed;
}