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
double number;
double number5 = 0;
string FileName;

bool check(double number);
double vidurkis();
template <class T>
double mediana(T& pazymiai);
template <class T>
void ReadFromFile(T& S,T& pazymiai);
template <class T>
void ZinomasStudentuSK(T& S, T& pazymiai);
template <class T>
void NezinomasStudentuSK(T& S, T& pazymiai);
template <class T>
void Print(T& S);
void CreateFile();
template <class T>
void questions(T S, T pazymiai);
