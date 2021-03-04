#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


struct Studentas
{
	string name;
	string lastname;
	double finalVid;
	double finalMed;
};

vector<Studentas> S;
int sk = 0;
int n = 0;
double suma = 0;
double egz = 0;
vector<double> pazymiai;
string yes = "t";
string no = "n";

double vidurkis()
{
	double vid = ((suma / sk) * 0.4) + (egz * 0.6);
	return vid;
}
void BubbleSort(vector<double> &vektorius)
{
	for (int i = 0; i < sk; i++)
	{
		for (int j = i + 1; j < sk; j++)
		{
			if (vektorius[i] > vektorius[j])
			{
				double t = vektorius[i];
				vektorius[i] = vektorius[j];
				vektorius[j] = t;
			}
		}
	}
}
double mediana()
{
	BubbleSort(pazymiai);
	double med = 0;

	if (pazymiai.size() % 2 != 0)
	{
		med = (pazymiai.at(pazymiai.size() / 2) * 0.4) + (egz * 0.6);
		
	}
	else if (pazymiai.size() % 2 == 0)
	{
		med = (((pazymiai.at(pazymiai.size() / 2) + pazymiai.at((pazymiai.size() / 2) - 1)) / 2) * 0.4) + (egz * 0.6);
	}
	return med;
}
void ReadFromFile()
{
	ifstream in("kursiokai.txt");
	string x;
	int y;
	for (int i = 0; i < 1000; i++)
	{
		in >> x;
		if (x == "Egz.")
		{
			sk = i - 2;
			break;
		}
	}
	for (int i = 0; !in.eof(); i++)
	{
		suma = 0;
		S.push_back(Studentas());
		in >> S[i].name;
		in >> S[i].lastname;
		pazymiai.clear();
		for (int j = 0; j < sk; j++)
		{
			in >> y;
			suma = suma + y;
			pazymiai.push_back(y);
		}
		in >> egz;
		S[i].finalVid = vidurkis();
		S[i].finalMed = mediana();
		n = i;
	}
	in.close();
}
int main()
{
	string answer1;
	cout << "Ar norite patys irasyti duomenis (t), ar norite, kad jie butu paimti is failo? (n): ";
	cin >> answer1;
	if (answer1 == yes) cout << " lol" << endl;
	else if (answer1 == no)
	{
		ReadFromFile();
		for (int i = 0; i < n; i++)
			cout << S[i].name << " " << S[i].lastname << " " << S[i].finalVid << " " << S[i].finalMed << endl;
	}

	return 0;
}
