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
//vector<int> grades;
//int pazymys[11];
double suma = 0;
double egz = 0;
vector<int> grade (0);

int vidurkis()
{
	double vid = ((suma / sk) * 0.4) + (egz * 0.6);
	return vid;
}
int mediana()
{
	double med = 0;
	if (sk % 2 != 0)
	{
		med = (grade.at(grade.size()/2) * 0.4) + (egz * 0.6);
	}
	return med;
}
int main()
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
		//S[n].nd = 0;
		grade.clear();
		for (int j = 0; j < sk; j++)
		{
			in >> y;	
			suma = suma + y;		
			grade.push_back(y);
		}	
		in >> egz;
		S[i].finalVid = vidurkis();
		S[i].finalMed = mediana();
		n++;
	}
	delete &grade;
	in.close();

	for (int i = 0; i < n; i++)
		cout << S[i].name << " " << S[i].lastname << " " << S[i].finalVid << " " << S[i].finalMed << endl;

	cout << n;
  return 0;
}
