#include "funkcijos.h"

using namespace std;

bool check(double number)
{
	if (number > 0 && number <= 10)
		return true;
	if (number <= -1 || number > 10)
		return false;
}
double vidurkis()
{
	double vid = ((suma / sk) * 0.4) + (egz * 0.6);
	return vid;
}
double mediana()
{
	for (int i = 0; i < sk; i++)
	{
		for (int j = i + 1; j < sk; j++)
		{
			if (pazymiai[i] > pazymiai[j])
			{
				double t = pazymiai[i];
				pazymiai[i] = pazymiai[j];
				pazymiai[j] = t;
			}
		}
	}
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
	try {
		if (!in)
		{
			throw 1;
		}
		for (int i = 0; i < 100; i++)
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
		n = n + 1;
		in.close();
	}
	catch (int ex3)
	{
		cout << "Duomenu failas nerastas" << endl;
		exit;
	}
}
void ZinomasStudentuSK()
{
	string input1, input2, answer3, answer4, answer5;
	int number3 = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "iveskite studento varda: ";
		cin >> input1;
		cout << "iveskite studento pavarde: ";
		cin >> input2;
		S.push_back(Studentas());
		S[i].name = input1;
		S[i].lastname = input2;
		cout << "Ar norite patys ivesti namu darbu pazymius? (t/n): ";
		cin >> answer3;
		if (answer3 == yes)
		{
			cout << "Ar zinote kiek bus namu darbu pazymiu? (t/n): ";
			cin >> answer4;
			if (answer4 == yes)
			{
				cout << "Iveskite kiek bus namu darbu pazymiu: ";
				cin >> sk;
				int input3;
				cout << "iveskite " << sk << " skacius: ";
				pazymiai.clear();
				suma = 0;
				for (int ii = 0; ii < sk; ii++)
				{
					cin >> input3;
					if (check(input3) == false)
					{
						cout << "Ivedete netinkama skaiciu, iveskite studento informacija is naujo" << endl;
						ZinomasStudentuSK();
					}
					suma = suma + input3;
					pazymiai.push_back(input3);
				}
				cout << "Ar norite patys ivesti egzamino bala? (t/n): ";
				cin >> answer5;
				if (answer5 == yes)
				{
					cout << "Iveskite egzamino bala: ";
					cin >> egz;
					if (check(egz) == false)
					{
						cout << "Ivedete netinkama skaiciu, iveskite studento informacija is naujo" << endl;
						ZinomasStudentuSK();
					}
				}
				else if (answer5 == no)
				{
					srand(time(NULL));
					number3 = rand() % 10 + 1;
					egz = number3;
				}
				S[i].finalVid = vidurkis();
				S[i].finalMed = mediana();
			}
			else if (answer4 == no)
			{
				cout << "Veskite kiek norite namu darbu pazymiu, kai noresite baigti vesti, iveskite '00': ";
				int enter = 1;
				int i = 0;
				pazymiai.clear();
				suma = 0;
				while (enter != 00)
				{
					cin >> enter;
					if (check(enter) == false)
					{
						cout << "Ivedete netinkama skaiciu, iveskite studento informacija is naujo" << endl;
						ZinomasStudentuSK();
					}
					suma = suma + enter;
					pazymiai.push_back(enter);
					i++;
				}
				cout << "Ar norite patys ivesti egzamino bala? (t/n): ";
				cin >> answer5;
				if (answer5 == yes)
				{
					cout << "Iveskite egzamino bala: ";
					cin >> egz;
					if (check(egz) == false)
					{
						cout << "Ivedete netinkama skaiciu, iveskite studento informacija is naujo" << endl;
						ZinomasStudentuSK();
					}
				}
				else if (answer5 == no)
				{
					srand(time(NULL));
					number3 = rand() % 10 + 1;
					egz = number3;
				}
				sk = i - 1;
				S[i].finalVid = vidurkis();
				S[i].finalMed = mediana();
			}
		}
		else if (answer3 == no)
		{
			cout << "Iveskite kiek bus namu darbu pazymiu: ";
			cin >> sk;
			srand(time(NULL));
			int number6;
			pazymiai.clear();
			suma = 0;
			for (int j = 0; j < sk; j++)
			{
				number6 = rand() % 10 + 1;
				suma = suma + number6;
				pazymiai.push_back(number6);
			}
			cout << "Ar norite patys ivesti egzamino bala? (t/n): ";
			cin >> answer5;
			if (answer5 == yes)
			{
				cout << "Iveskite egzamino bala: ";
				cin >> egz;
				if (check(egz) == false)
				{
					cout << "Ivedete netinkama skaiciu, iveskite studento informacija is naujo" << endl;
					ZinomasStudentuSK();
				}
			}
			else if (answer5 == no)
			{
				srand(time(NULL));
				number3 = rand() % 10 + 1;
				egz = number3;
			}
			S[i].finalVid = vidurkis();
			S[i].finalMed = mediana();
		}
	}
}
void NezinomasStudentuSK()
{
	string input1, input2, answer3, answer4, answer5, answer6;
	int number3 = 0;
	cout << "iveskite studento varda: ";
	cin >> input1;
	cout << "iveskite studento pavarde: ";
	cin >> input2;
	S.push_back(Studentas());
	S[n].name = input1;
	S[n].lastname = input2;
	cout << "Ar norite patys ivesti namu darbu pazymius? (t/n): ";
	cin >> answer3;
	if (answer3 == yes)
	{
		cout << "Ar zinote kiek bus namu darbu pazymiu? (t/n): ";
		cin >> answer4;
		if (answer4 == yes)
		{
			cout << "Iveskite kiek bus namu darbu pazymiu: ";
			cin >> sk;
			int input3;
			cout << "iveskite " << sk << " skacius: ";
			pazymiai.clear();
			suma = 0;
			for (int i = 0; i < sk; i++)
			{
				cin >> input3;
				if (check(input3) == false)
				{
					cout << "Ivedete netinkama skaiciu, iveskite studento informacija is naujo" << endl;
					NezinomasStudentuSK();
				}
				suma = suma + input3;
				pazymiai.push_back(input3);
			}
			cout << "Ar norite patys ivesti egzamino bala? (t/n): ";
			cin >> answer5;
			if (answer5 == yes)
			{
				cout << "Iveskite egzamino bala: ";
				cin >> egz;
				if (check(egz) == false)
				{
					cout << "Ivedete netinkama skaiciu, iveskite studento informacija is naujo" << endl;
					NezinomasStudentuSK();
				}
			}
			else if (answer5 == no)
			{
				srand(time(NULL));
				number3 = rand() % 10 + 1;
				egz = number3;
			}
			S[n].finalVid = vidurkis();
			S[n].finalMed = mediana();
		}
		else if (answer4 == no)
		{
			cout << "Veskite kiek norite namu darbu pazymiu, kai noresite baigti vesti, iveskite '00': ";
			int enter = 1;
			int i = 0;
			pazymiai.clear();
			suma = 0;
			while (enter != 00)
			{
				cin >> enter;
				if (check(enter) == false)
				{
					cout << "Ivedete netinkama skaiciu, iveskite studento informacija is naujo" << endl;
					NezinomasStudentuSK();
				}
				suma = suma + enter;
				pazymiai.push_back(enter);
				i++;
			}
			cout << "Ar norite patys ivesti egzamino bala? (t/n): ";
			cin >> answer5;
			if (answer5 == yes)
			{
				cout << "Iveskite egzamino bala: ";
				cin >> egz;
				if (check(egz) == false)
				{
					cout << "Ivedete netinkama skaiciu, iveskite studento informacija is naujo" << endl;
					NezinomasStudentuSK();
				}
			}
			else if (answer5 == no)
			{
				srand(time(NULL));
				number3 = rand() % 10 + 1;
				egz = number3;
			}
			sk = i - 1;
			S[n].finalVid = vidurkis();
			S[n].finalMed = mediana();
		}
	}
	else if (answer3 == no)
	{
		cout << "Iveskite kiek bus namu darbu pazymiu: ";
		cin >> sk;
		srand(time(NULL));
		int number6;
		pazymiai.clear();
		suma = 0;
		for (int ii = 0; ii < sk; ii++)
		{
			number6 = rand() % 10 + 1;
			suma = suma + number6;
			pazymiai.push_back(number6);
		}
		cout << "Ar norite patys ivesti egzamino bala? (t/n): ";
		cin >> answer5;
		if (answer5 == yes)
		{
			cout << "Iveskite egzamino bala: ";
			cin >> egz;
			if (check(egz) == false)
			{
				cout << "Ivedete netinkama skaiciu, iveskite studento informacija is naujo" << endl;
				NezinomasStudentuSK();
			}
		}
		else if (answer5 == no)
		{
			srand(time(NULL));
			number3 = rand() % 10 + 1;
			egz = number3;
		}
		S[n].finalVid = vidurkis();
		S[n].finalMed = mediana();
	}
	n++;
	cout << "Ar norite prideti dar viena studenta? (t/n): ";
	cin >> answer6;
	if (answer6 == yes)
		NezinomasStudentuSK();

}
void Print()
{
	string answer7;
	cout << "Ar norite su vidurkiu (t) ar su mediana (n) skaiciuoto galutinio balo?: ";
	cin >> answer7;
	if (answer7 == yes)
	{
		cout << "Vardas" << setw(20) << setfill(' ') << "Pavarde" << setw(20) << setfill(' ') << "Galutinis (vid)" << endl;
		cout << "______________________________________________" << endl;
		for (int i = 0; i < n; i++)
			cout << S[i].name << setw(20) << setfill(' ') << S[i].lastname << setw(20) << setfill(' ') << setprecision(3) << S[i].finalVid << endl;
	}
	else if (answer7 == no)
	{
		cout << "Vardas" << setw(20) << setfill(' ') << "Pavarde" << setw(20) << setfill(' ') << "Galutinis (med)" << endl;
		cout << "______________________________________________" << endl;
		for (int i = 0; i < n; i++)
			cout << S[i].name << setw(20) << setfill(' ') << S[i].lastname << setw(20) << setfill(' ') << setprecision(3) << S[i].finalMed << endl;
	}
}
void questions()
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
			try
			{
				if (n <= 0)
				{
					throw 1;
				}
			}
			catch (int ex1)
			{
				cout << "Ivedete netinkama studentu skaiciu (skaicius > 0), pabandykite is naujo " << endl;
				questions();
			}
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
		ofstream fr("rez.txt");
		fr << "Vardas" << setw(20) << setfill(' ') << "Pavarde" << setw(30) << setfill(' ') << "Galutinis (vid)" << setw(20) << setfill(' ') << "Galutinis (med)" << endl;
		fr << "_____________________________________________________________________________" << endl;
		for (int i = 0; i < n; i++)
			fr << S[i].name << setw(20) << setfill(' ') << S[i].lastname << setw(30) << setfill(' ') << setprecision(3) << S[i].finalVid << setw(20) << setfill(' ') << setprecision(3) << S[i].finalMed << endl;
		fr.close();
	}
}
