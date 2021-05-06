#include "funkcijos4.cpp"

int main()
{
	int conteiner;
	string answer1, answer2;
	string galvotukai;
	string vargsiukai;
	int kint;
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
			vector <Studentas> V;
			vector <Studentas> G;
			cout << "Namu darbu ir egzamino pazymiai turi priklausyti intervalui [1;10]" << endl;
			cout << "Ar norite patys irasyti duomenis (t), ar norite, kad jie butu paimti is failo (n), ar kad keli duomenu failai butu nuskaityti? (k): ";
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
						ZinomasStudentuSK(S);
						Print(S);
					}
					catch (int ex1)
					{
						cout << "Ivedete netinkama studentu skaiciu (skaicius > 0), paleiskite programa is naujo " << endl;
						exit;
					}
				}
				else if (answer2 == no)
				{
					NezinomasStudentuSK(S);
					Print(S);
				}
			}
			else if (answer1 == no)
			{
				FileName = "kursiokai.txt";
				ReadFromFile(S);
				ofstream fr("rez.txt");
				fr << "Vardas" << setw(20) << setfill(' ') << "Pavarde" << setw(30) << setfill(' ') << "Galutinis (vid)" << setw(20) << setfill(' ') << "Galutinis (med)" << endl;
				fr << "_____________________________________________________________________________" << endl;
				for (int i = 0; i < n; i++)
					fr << S[i].name << setw(20) << setfill(' ') << S[i].lastname << setw(30) << setfill(' ') << setprecision(3) << S[i].finalVid << setw(20) << setfill(' ') << setprecision(3) << S[i].finalMed << setw(30) << setfill(' ') << S[i].kintamasis1 << endl;
				fr.close();
			}
			else if (answer1 == ka)
			{
				cout << "Kiek failu norite nuskaityti (nuo 1 iki 5)? : ";
				cin >> kint;
				for (int i = 0; i < kint; i++)
				{
					cout << "Iveskite n skaiciu: " << endl;
					cin >> n;
					FileName = "kursiokai" + to_string(n);
					FileName += ".txt";
					vargsiukai = "vargsiukai" + to_string(n);
					vargsiukai += ".txt";
					galvotukai = "galvotukai" + to_string(n);
					galvotukai += ".txt";
					ofstream out4(galvotukai);
					ofstream out5(vargsiukai);
					ReadFromFile(S);
					cout << "Kuria strategija norite naudoti?(t - 1, n - 2, k - 3) " << endl;
					cin >> answer2;
					cout << n << endl;
					if (answer2 == yes)
					{
						Strategija1(S, G, V);
						for (int j = 0; j < n1; j++)
						{
							out4 << G[j].name << setw(20) << setfill(' ') << G[j].lastname << setw(30) << setfill(' ') << setprecision(3) << G[j].finalVid << endl;
						}
						out4.close();
						for (int j = 0; j < n2; j++)
						{
							out5 << V[j].name << setw(20) << setfill(' ') << V[j].lastname << setw(30) << setfill(' ') << setprecision(3) << V[j].finalVid << endl;
						}
						out5.close();
					}
					else if (answer2 == no)
					{
						Strategija2(S, V);
						for (int j = 0; j < n2; j++)
							out4 << S[j].name << setw(20) << setfill(' ') << S[j].lastname << setw(30) << setfill(' ') << setprecision(3) << S[j].finalVid << endl;
						out4.close();
						for (int j = 0; j < n1; j++)
							out5 << V[j].name << setw(20) << setfill(' ') << V[j].lastname << setw(30) << setfill(' ') << setprecision(3) << V[j].finalVid << endl;
						out5.close();
					}
					else if (answer2 == ka)	
					{
						auto start = chrono::steady_clock::now();
						for (int j = 0; j < n; j++)
						{
							if (S[j].kintamasis1 == 1)
							{
								out4 << S[j].name << setw(20) << setfill(' ') << S[j].lastname << setw(30) << setfill(' ') << setprecision(3) << S[j].finalVid << endl;
							}
							else if (S[j].kintamasis1 == 0)
							{
								out5 << S[j].name << setw(20) << setfill(' ') << S[j].lastname << setw(30) << setfill(' ') << setprecision(3) << S[j].finalVid << endl;
							}
						}
						out4.close();
						out5.close();
						cout << "Sugrupiuoti studentus i 'Galvotukus' ir 'Vargsiukus', faile su " << n << " stulpeliu uztruko: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << endl;
					}
				}
			}
		}
		else if (conteiner == 2)
		{
			list <Studentas> S;
			list <Studentas> V;
			list <Studentas> G;
			cout << "Namu darbu ir egzamino pazymiai turi priklausyti intervalui [1;10]" << endl;
			cout << "Ar norite patys irasyti duomenis (t), ar norite, kad jie butu paimti is failo (n), ar kad keli duomenu failai butu nuskaityti? (k): ";
			cin >> answer1;
			if (answer1 == yes)
			{
				cout << "Ne" << endl;
			}
			else if (answer1 == no)
			{
				cout << "Ne" << endl;
			}
			else if (answer1 == ka)
			{
				cout << "Kiek failu norite nuskaityti (nuo 1 iki 5)? : ";
				cin >> kint;
				for (int i = 0; i < kint; i++)
				{
					cout << "Iveskite n skaiciu: " << endl;
					cin >> n;
					FileName = "kursiokai" + to_string(n);
					FileName += ".txt";
					Studentas temporary;
					vargsiukai = "vargsiukai" + to_string(n);
					vargsiukai += ".txt";
					galvotukai = "galvotukai" + to_string(n);
					galvotukai += ".txt";
					ofstream out4(galvotukai);
					ofstream out5(vargsiukai);
					ReadFromFile1(S);
					cout << "Kuria strategija norite naudoti?(t - 1, n - 2, k - 3) " << endl;
					cin >> answer2;
					cout << n << endl;
					if (answer2 == yes)
					{
						Strategija11(S, G, V);
						for (int j = 0; j < G.size(); j++)
						{
							out4 << G.front().name << setw(20) << setfill(' ') << G.front().lastname << setw(30) << setfill(' ') << setprecision(3) << G.front().finalVid << endl;
							G.pop_front();
						}
						out4.close();
						cout << G.size() << endl;
						cout << V.size() << endl;
						for (int j = 0; j < V.size(); j++)
						{
							out5 << V.front().name << setw(20) << setfill(' ') << V.front().lastname << setw(30) << setfill(' ') << setprecision(3) << V.front().finalVid << endl;
							V.pop_front();
						}
						out5.close();
					}
					else if (answer2 == no)
					{
						Strategija22(S, V);
						for (int j = 0; j < S.size(); j++)
						{
							out4 << S.front().name << setw(20) << setfill(' ') << S.front().lastname << setw(30) << setfill(' ') << setprecision(3) << S.front().finalVid << endl;
							S.pop_front();
						}
						out4.close();
						for (int j = 0; j < V.size(); j++)
						{
							out5 << V.front().name << setw(20) << setfill(' ') << V.front().lastname << setw(30) << setfill(' ') << setprecision(3) << V.front().finalVid << endl;
							V.pop_front();
						}
						out5.close();
					}
					else if (answer2 == ka)
					{
						auto start = chrono::steady_clock::now();
						for (int j = 0; j < n; j++)
						{
							if (S.front().kintamasis1 == 1)
							{
								out4 << S.front().name << setw(20) << setfill(' ') << S.front().lastname << setw(30) << setfill(' ') << setprecision(3) << S.front().finalVid << endl;
							}
							else if (S.front().kintamasis1 == 0)
							{
								out5 << S.front().name << setw(20) << setfill(' ') << S.front().lastname << setw(30) << setfill(' ') << setprecision(3) << S.front().finalVid << endl;
							}
							S.pop_front();
						}
						out4.close();
						out5.close();
						cout << "Sugrupiuoti studentus i 'Galvotukus' ir 'Vargsiukus', faile su " << n << " stulpeliu uztruko: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << endl;
					}
				}
			}
		}
		else if (conteiner == 3)
		{
			deque <Studentas> S;
			deque <Studentas> G;
			deque <Studentas> V;
			cout << "Namu darbu ir egzamino pazymiai turi priklausyti intervalui [1;10]" << endl;
			cout << "Ar norite patys irasyti duomenis (t), ar norite, kad jie butu paimti is failo (n), ar kad keli duomenu failai butu nuskaityti? (k): ";
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
						ZinomasStudentuSK(S);
						Print(S);
					}
					catch (int ex1)
					{
						cout << "Ivedete netinkama studentu skaiciu (skaicius > 0), paleiskite programa is naujo " << endl;
						exit;
					}
				}
				else if (answer2 == no)
				{
					NezinomasStudentuSK(S);
					Print(S);
				}
			}
			else if (answer1 == no)
			{
				FileName = "kursiokai.txt";
				ReadFromFile(S);
				ofstream fr("rez.txt");
				fr << "Vardas" << setw(20) << setfill(' ') << "Pavarde" << setw(30) << setfill(' ') << "Galutinis (vid)" << setw(20) << setfill(' ') << "Galutinis (med)" << endl;
				fr << "_____________________________________________________________________________" << endl;
				for (int i = 0; i < n; i++)
					fr << S[i].name << setw(20) << setfill(' ') << S[i].lastname << setw(30) << setfill(' ') << setprecision(3) << S[i].finalVid << setw(20) << setfill(' ') << setprecision(3) << S[i].finalMed << setw(30) << setfill(' ') << S[i].kintamasis1 << endl;
				fr.close();
			}
			else if (answer1 == ka)
			{
				cout << "Kiek failu norite nuskaityti (nuo 1 iki 5)? : ";
				cin >> kint;
				for (int i = 0; i < kint; i++)
				{
					cout << "Iveskite n skaiciu: " << endl;
					cin >> n;
					FileName = "kursiokai" + to_string(n);
					FileName += ".txt";
					vargsiukai = "vargsiukai" + to_string(n);
					vargsiukai += ".txt";
					galvotukai = "galvotukai" + to_string(n);
					galvotukai += ".txt";
					ofstream out4(galvotukai);
					ofstream out5(vargsiukai);
					ReadFromFile(S);
					cout << "Kuria strategija norite naudoti?(t - 1, n - 2, k - 3) " << endl;
					cin >> answer2;
					cout << n << endl;
					if (answer2 == yes)
					{
						Strategija1(S, G, V);
						for (int j = 0; j < n1; j++)
						{
							out4 << G[j].name << setw(20) << setfill(' ') << G[j].lastname << setw(30) << setfill(' ') << setprecision(3) << G[j].finalVid << endl;
						}
						out4.close();
						for (int j = 0; j < n2; j++)
						{
							out5 << V[j].name << setw(20) << setfill(' ') << V[j].lastname << setw(30) << setfill(' ') << setprecision(3) << V[j].finalVid << endl;
						}
						out5.close();
					}
					else if (answer2 == no)
					{
						Strategija2(S, V);
						for (int j = 0; j < n2; j++)
							out4 << S[j].name << setw(20) << setfill(' ') << S[j].lastname << setw(30) << setfill(' ') << setprecision(3) << S[j].finalVid << endl;
						out4.close();
						for (int j = 0; j < n1; j++)
							out5 << V[j].name << setw(20) << setfill(' ') << V[j].lastname << setw(30) << setfill(' ') << setprecision(3) << V[j].finalVid << endl;
						out5.close();
					}
					else if (answer2 == ka)
					{
						auto start = chrono::steady_clock::now();
						for (int j = 0; j < n; j++)
						{
							if (S[j].kintamasis1 == 1)
							{
								out4 << S[j].name << setw(20) << setfill(' ') << S[j].lastname << setw(30) << setfill(' ') << setprecision(3) << S[j].finalVid << endl;
							}
							else if (S[j].kintamasis1 == 0)
							{
								out5 << S[j].name << setw(20) << setfill(' ') << S[j].lastname << setw(30) << setfill(' ') << setprecision(3) << S[j].finalVid << endl;
							}
						}
						out4.close();
						out5.close();
						cout << "Sugrupiuoti studentus i 'Galvotukus' ir 'Vargsiukus', faile su " << n << " stulpeliu uztruko: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << endl;
					}
				}
			}
		}
	}
	catch (int ex4)
	{
		cout << "Ivedete netinkama skaiciu, paleiskite programa isnaujo.";
		exit;
	}
	return 0;
}
