#include "funkcijos.h"
#include "funkcija.cpp"

using namespace std;

int main()
{
	string answer1, answer2;
	cout << "Namu darbu ir egzamino pazymiai turi priklausyti intervalui [1;10]" << endl;
	cout << "Ar norite patys irasyti duomenis (t), ar norite, kad jie butu paimti is failo? (n): ";
	cin >> answer1;
	if (answer1 == yes)
	{
		cout << "Ar zinote kiek bus studentu? (t/n): ";
		cin >> answer2;
		if (answer2 == yes)
		{
			cout << "iveskite kiek bus studentu: ";
			cin >> n;
			ZinomasStudentuSK();
			Print();
		}
		else if (answer2 == no)
		{
			NezinomasStudentuSK();
			Print();
		}
	}
	else if (answer1 == no)
	{
		ReadFromFile();
		BubbleSort2();
		ofstream fr("rez.txt");
		fr << "Vardas" << setw(20) << setfill(' ') << "Pavarde" << setw(30) << setfill(' ') << "Galutinis (vid)" << setw(20) << setfill(' ') << "Galutinis (med)" << endl;
		fr << "_____________________________________________________________________________" << endl;
		for (int i = 0; i < n; i++)
			fr << S[i].name << setw(20) << setfill(' ') << S[i].lastname << setw(30) << setfill(' ') << setprecision(3) << S[i].finalVid << setw(20) << setfill(' ') << setprecision(3) << S[i].finalMed << endl;
		fr.close();
	}

	return 0;
}
