#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h> 

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
double number;

bool check(double number);
double vidurkis();
double mediana();
void ReadFromFile();
void ZinomasStudentuSK();
void NezinomasStudentuSK();
