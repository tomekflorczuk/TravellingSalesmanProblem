#include "SA.h"

int SA::mincost;
vector<int> SA::minvertexes;
int const SA::maxit = 100000;

//Algorytm symulowanego wy¿arzania
void SA::Algorithm()
{
	//Zmienne zapisu danych do pliku
	ofstream SADataFile;
	SADataFile.open("sa.csv");
	//Zmienne do obs³ugi czasu
	long long int frequency = Clock::GetFrequency();
	float duration, timestamp = 0;
	//Rozwi¹zanie pocz¹tkowe
	vector<int> vertexes = Data::RandomVertexes();
	int cost = Data::CalculateCost(vertexes);
	mincost = cost;
	minvertexes = vertexes;
	//Zmienne pomocnicze
	vector<int> neighbourvertexes;
	int i, j, neighbourcost;
	double t,pb, tmin, tmax = (float)Data::GetMaxCost();
	t = tmax;
	tmin = pow(10, -4) * tmax;

	SADataFile << "minimalny koszt; czas dzia³ania algorytmu[s]; prawdopodobiensto; temp; neighbourcost" << endl;
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	Clock::SetStart(Clock::read_QPC());

	//G³ówny algorytm
	do
	{
		//Generowanie losowego s¹siada
		i = rand() % vertexes.size();
		do
			j = rand() % vertexes.size();
		while (i == j);		
		neighbourvertexes = Neighbourhood::FindNeighbour(vertexes, i, j);
		neighbourcost = Data::CalculateCost(neighbourvertexes);
		pb = Probability(cost, neighbourcost, t);
		//Sprawdzenie s¹siedniego rozwi¹zania z aktualnym rozwi¹zaniem oraz prawdopobieñstwo przejœcia do gorszego rozwi¹zania
		if (neighbourcost < cost || Random() < Probability(cost, neighbourcost, t))
			{
				vertexes = neighbourvertexes;
				cost = neighbourcost;
			}
		//Sprawdzanie nowego rozwi¹zania z najlepszym do tej pory znalezionym rozwi¹zaniem
		if (cost < mincost)
			{			
				minvertexes = vertexes;
				mincost = cost;
			}
		//Pobranie czasu
		Clock::SetElapsed(Clock::read_QPC() - Clock::GetStart());
		duration = (float) Clock::GetElapsed() / frequency;
		//Zapisywanie danych do pliku co okreœlony czas
		if (duration > timestamp)
			{
			SADataFile << mincost << ";" << duration << ";" << pb << ";" << t << ";" << neighbourcost << endl;
				timestamp += 0.1;
			}
		//Zmniejszanie temperatury
		t = t / ( 1 +  (tmax - tmin) / (maxit*tmax*tmin) * t);

	} while (duration < Clock::GetDuration());

	SADataFile.close();
}

//Obliczanie prawdopodobieñstwa zmiany na gorsze rozwi¹zanie
inline float SA::Probability(int cost, int neighbourcost, float t)
{
	return exp(-(float)((neighbourcost - cost) / t) );
}

//Generowanie losowej liczby z przedzia³u <0,1>
inline float SA::Random()
{
	return (float) rand() / RAND_MAX;
}

//Wyœwietlenie wyniku
void SA::ShowResult()
{
	cout << "$" << mincost << endl;
}