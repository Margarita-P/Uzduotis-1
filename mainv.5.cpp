#include "funkcijos4.cpp"

int main()
{
	int conteiner;
	cout << "Pasirinkite konteineri: (vector - 1, list - 2, deque - 3)";
	cin >> conteiner;
	try
	{
		if (conteiner != 1 && conteiner != 2 && conteiner != 3)
		{
			throw 1;
		}
		if (conteiner == 1)
		{
			vector <Studentas> S;
			vector <double> pazymiai;
			questions(S, pazymiai);
		}
		else if (conteiner == 2)
		{
			list <Studentas> S;
			list <double> pazymiai;
			questions(S, pazymiai);
		}
		else if (conteiner == 3)
		{
			deque <Studentas> S;
			deque <double> pazymiai;
			questions(S, pazymiai);
		}
	}
	catch (int ex4)
	{
		cout << "Ivedete netinkama skaiciu, paleiskite programa isnaujo.";
		exit;
	}
	return 0;
}
