#include "Clock.h"
#include <windows.h>

//Ustawiony czas trwania algorytmu w sekundach
float Clock::Duration;
//Cz�stotliwo�� impuls�w licznika
long long int Clock::Frequency;
//Czas rozpocz�cia pracy algorytmu
long long int Clock::Start;
//Czas kt�ry up�yn�� od startu pracy algorytmu
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

//Dost�p do czasu trwania algorytmu
float Clock::GetDuration()
{
	return Duration;
}

//Ustawienie czasu trwania algorytmu
void Clock::SetDuration(float duration)
{
	Duration = duration;
}

//Dost�p do cz�stotliwo�ci
long long int Clock::GetFrequency()
{
	return Frequency;
}

//Ustawienie cz�stotliwo�ci
void Clock::SetFrequency(long long frequency)
{
	Frequency = frequency;
}

//Dost�p do czasu startu pracy algorytmu
long long int Clock::GetStart()
{
	return Start;
}

//Ustawienie czasu startu algorytmu
void Clock::SetStart(long long start)
{
	Start = start;
}

//Dostep do up�yni�tego czasu pracy algorytmu
long long Clock::GetElapsed()
{
	return Elapsed;
}

//Ustawienie up�yni�tego czasy pracy algorytmu
void Clock::SetElapsed(long long elapsed)
{
	Elapsed = elapsed;
}