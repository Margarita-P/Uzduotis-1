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
#include <chrono>
#include <list>
#include <deque>

using namespace std;

struct Studentas
{
	string name;
	string lastname;
	double finalVid;
	double finalMed;
	int kintamasis1;
};

int sk = 0;
int n = 0;
double suma = 0;
double egz = 0;
string yes = "t";
string no = "n";
string ka = "k";
double number = 0;
double number5 = 0;
string FileName;
vector <double> pazymiai;
int n1 = 0, n2 = 0;

bool check(double number);
double vidurkis();
template <class T>
double mediana();
template <class T>
void ReadFromFile(T& S);
template <class T>
void ReadFromFile1(T& S);
template <class T>
void ZinomasStudentuSK(T& S);
template <class T>
void NezinomasStudentuSK(T& S);
template <class T>
void Print(T& S);
void CreateFile();
template <class T>
void Strategija1(T& S, T& G, T& V);
template <class T>
void Strategija2(T& S, T& V);
template <class T>
void Strategija11(T& S, T& G, T& V);
template <class T>
void Strategija22(T& S, T& V);
