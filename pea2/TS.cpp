#include "TS.h"

int TS::mincost;
vector<int> TS::minvertexes;
bool TS::Diversification = false;

//W��czanie/Wy��czanie dywersyfikacji
void TS::ToogleDiversification()
{
	if (Diversification == false) Diversification = true;
	else Diversification = false;
}

//Dost�p do dywersyfikacji
bool TS::GetDiversification()
{
	return Diversification;
}

//Algorytm tabu search
void TS::Algorithm()
{
	//Zmienne zapisu danych do pliku
	ofstream TSDataFile;
	TSDataFile.open("ts.csv");
	//Zmienne do obs�ugi czasu
	long long int frequency = Clock::GetFrequency();
	float duration = 0;
	float timestamp = 0;
	//Rozwi�zanie pocz�tkowe
	vector<int> vertexes = Data::RandomVertexes();
	//Zmienne pomocnicze
	vector<int> bestneighbourvertexes;
	mincost = Data::CalculateCost(vertexes);	
	int movei, movej, cost, bestneighbourcost;
	int iterations = 0;
	//Tworzenie listy tabu
	int** tabulist = new int* [vertexes.size() - 1];
	for(int i = 0 ; i < vertexes.size() - 1; i++)
		tabulist[i] = new int[i + 1];
	//Wype�enienie listy tabu zerami
	for (int i = 0; i < vertexes.size() - 1; i++)
		for(int j = 0; j < i + 1 ;j++)
			tabulist[i][j] = 0;

	TSDataFile << "minimalny koszt; czas dzia�ania algorytmu[s]" << endl;
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	Clock::SetStart(Clock::read_QPC());

	//G��wny algorytm
	while(duration < Clock::GetDuration())
	{
		//Pobranie czasu
		Clock::SetElapsed(Clock::read_QPC() - Clock::GetStart());
		duration = (float)Clock::GetElapsed() / frequency;
		
		bestneighbourcost = INT_MAX;
		//Szukanie najlepszego s�siada
		for(int i = 0; i < vertexes.size() - 1; i++)
			for(int j = i + 1; j < vertexes.size(); j++)
			{
				int tempcost = Data::CalculateCost(Neighbourhood::FindNeighbour(vertexes, i, j));
				//Sprawdzenie czy ruch nie znajduje si� na li�cie tabu oraz czy spe�nia kryterium aspiracji			
				if (tabulist[j - 1][i] == 0 || Aspiration(tempcost) == true)
				{
					//Sprawdzanie czy aktualny s�siad jest lepszy od dot�d znalezionego
					if (tempcost < bestneighbourcost)
					{
						movei = i;
						movej = j;
						bestneighbourvertexes = Neighbourhood::FindNeighbour(vertexes, i, j);
						bestneighbourcost = tempcost;
					}
					
				}
			}
		//Ustalenie aktualnego rozwi�zania na najlepszego s�siada
		vertexes = bestneighbourvertexes;
		cost = bestneighbourcost;
		//Sprawdzanie najlepszego s�siada z najlepszym do tej pory znalezionym rozwi�zaniem
		if (cost < mincost)
		{
			mincost = cost;
			minvertexes = vertexes;
			iterations = 0;
		}
		else iterations++;
		//Sprawdzenie czy dywersyfikacja zosta�a w��czona
		if (Diversification == true)
		{
			//Sprawdzenie zdarzenia krytycznego
			if (CriticalEvent(iterations) == true)
			{
				iterations = 0;
				//Nowe losowe rozwi�zanie
				vertexes = Restart();
				//Wyzerowanie listy tabu
				for (int i = 0; i < vertexes.size() - 1; i++)
					for (int j = 0; j < i + 1; j++)
					{
						tabulist[i][j] = 0;
					}
				if (Data::CalculateCost(vertexes) < mincost)
				{
					mincost = Data::CalculateCost(vertexes);
					minvertexes = vertexes;
				}
				continue;
			}
		}
		//Wpisanie wykonanego ruchu na list� tabu
		tabulist[movej - 1][movei] = Data::GetSize() / 2;
		//Zaktualizowanie listy tabu
		for (int i = 0; i < vertexes.size() - 1; i++)
		{
			for (int j = 0; j < i + 1; j++)
				if (tabulist[i][j] > 0) tabulist[i][j]--;
		}
		//Zapisanie danych do pliku co okre�lony czas
		if (duration > timestamp)
		{
			TSDataFile << mincost << ";" << duration << endl;
			timestamp += 0.1;
		}
	};

	for (int i = 0; i < vertexes.size() - 1; i++)
		delete[] tabulist[i];
	delete[] tabulist;

	TSDataFile.close();
}

//Kryterium aspiracji
inline bool TS::Aspiration(int neighbourcost)
{
	if (neighbourcost < mincost) return true;
	return false;
}

//Zdarzenie krytyczne
inline bool TS::CriticalEvent(int iterations)
{
	if (iterations > Data::GetSize()) return true;
	return false;
}

//Nowe losowe rozwi�zanie
vector<int> TS::Restart()
{
	return Data::RandomVertexes();
}

//Wy�wietlenie wyniku
void TS::ShowResult()
{
	cout << "$" << mincost << endl;
}