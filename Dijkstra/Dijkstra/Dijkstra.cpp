/** @file Dijkstra.cpp */
#include <iostream>
using namespace std;

//! Funkciya realizuet algoritm Dejkstry
/**
@param [in] **a - dvojnoj ukazatel' na massiv
@param [in]   n - razmernost' massiva
@param [in]  st - nachal'naya vershina
**/
void Dijkstra(int **a, int n, int st)
{
	int count, index, i, u, m = st + 1;
	int *distance = new int[n]; /// Chislennyj massiv, v kotoryj budut zanosit'sya najdennye min puti 
	bool *visited = new bool[n]; /// Logicheskij massiv dlya hraneniya informacii o poseshhennyh vershinah 
	for (i = 0; i < n; i++)
	{
		distance[i] = INT_MAX; /// Iznachal'no sozdaem massiv s rasstoyaniyami, kotorye zavedomo bol'she lubogo potencial'nogo puti  
		visited[i] = false; /// Kazhduju vershinu otmechaem kak ne poseshhennuju 
	}
	distance[st] = 0; /// Ishodnaya vershina 
	for (count = 0; count < n - 1; count++)
	{/// Poisk sosednih vershin 
		int min = INT_MAX;
		for (i = 0; i < n; i++)
			if (!visited[i] && distance[i] <= min) /// Peresmotr rasstoyaniya
			{
			min = distance[i]; index = i;
			}
		u = index;
		visited[u] = true; /// Pomechaem vershiny kak poseshhennye 
		for (i = 0; i < n; i++)
			if (!visited[i] && a[u][i] && distance[u] != INT_MAX && distance[u] + a[u][i] < distance[i]) /// Vychislenie rasstoyaniya 
				distance[i] = distance[u] + a[u][i];
	}

	cout << "Мин путь из начальной вершины до остальных:\t\n"; /// Vyvod min puti 
	for (i = 0; i < n; i++) if (distance[i] != INT_MAX)
		cout << m << " -> " << i + 1 << " = " << distance[i] << endl;
	else cout << m << " -> " << i + 1 << " = " << "маршрут недоступен" << endl;
}

//! Glavnaya funkciya main()

void main()
{
	setlocale(LC_ALL, "RUS");
	int N, start;
	cout << "Кол-во вершин >> "; /// Vvod kolichestva vershin 
	cin >> N;
	/// Sozdaem matricu smezhnosti (vmesto edinic v nej budut vystavleny vesa reber)
	int **A = new int *[N];
	for (int i = 0; i < N; i++) A[i] = new int[N];

	cout << "Введите матрицу смежности " << N << " на " << N << " >>" << endl << endl;
	for (int j = 0; j < N; j++)
	{
		cout << "\t";
		for (int k = 0; k < N; k++)
		{
			cin >> A[j][k];
		}
	}
	cout << endl;

	cout << "Начальная вершина >> "; cin >> start; /// Zadaem nachal'nuju vershinu 
	Dijkstra(A, N, start - 1); /// Vyzyvaem funkciju, realizujushhuju algoritm Dejkstry 
	for (int i = 0; i < N; i++) delete[]A[i];
	delete[]A;
	system("pause");
}