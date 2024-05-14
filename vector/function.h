#pragma once
#include <cstdio>
#include <locale>
#include <time.h>
#include <limits>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstring> 
#include <cerrno>
#include <random>
#include <chrono>
#include "studentas.h"
#include "error.h"

void Skaicius1(vector<studentas>& s, int &m, int skaicius, int MinP, int MaxP);
void Skaicius2(vector<studentas>& s, int skaicius, int MinP, int MaxP);
void FailoSkaitymas(vector <studentas> &s, string &duomPav);
void VarduGeneravimui();
void Sorting(vector<studentas>& s,vector<studentas> &k, vector <studentas> &l, string choice, int rikiavimas);
void Isvedimas(vector <studentas> s, vector <studentas> &l, vector <studentas> &k);
bool rikiavimasVid(studentas& s1, studentas& s2);
bool rikiavimasMed(studentas& s1, studentas& s2);