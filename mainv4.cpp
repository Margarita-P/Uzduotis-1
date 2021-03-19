#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h> 
#include <chrono>

using namespace std;

vector<Studentas> S;
vector<double> pazymiai;
double suma = 0, egz = 0, number5 = 0;
int sk = 0, n = 0;

using namespace std;

int main()
{
  auto start = chrono::steady_clock::now();
	string file;
	string eil = "_";
	string eil1;
	file = "kursiokai"+to_string(n);
	file += ".txt";
	ofstream out(file);
	eil1 += "Vardas         Pavarde  ";
	for (int i = 1; i < sk+1; i++)
	{
		eil1 += "    ND" + to_string(i);
	}
	eil1 += "     Egz.";
	out << eil1 << endl;
	for (int i = 0; i < eil1.length(); i++)
	{
		out << eil;
	}
	out << endl;
	srand(time(NULL));
	for (int i = 1; i < n+1; i++)
	{
		out << left << setw(15) << "Vardas" + to_string(i) << setw(15) << "Pavarde" + to_string(i);
		for (int j = 0; j < sk; j++)
		{
			out << setw(7) << rand() % 10 + 1;
		}
		out << setw(7) << rand() % 10 + 1 << endl;
	}
	out << "Sugeneruoti faila su " << n << " stulpeliu uztruko: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << endl;
 	out.close();
  return 0;
}
