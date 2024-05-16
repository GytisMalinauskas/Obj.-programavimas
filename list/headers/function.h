#ifndef function_h
#define function_h
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
#include "../headers/studentas.h"
#include "../headers/error.h"

void Skaicius1(list<studentas>& s, int &m, int skaicius, int MinP, int MaxP);
void Skaicius2(list<studentas>& s, int skaicius, int MinP, int MaxP);
void FailoSkaitymas(list <studentas> &s, string &duomPav);
void VarduGeneravimui();
void Sorting(list<studentas>& s,list<studentas> &k, list <studentas> &l, string choice, int rikiavimas, int strategy);
void Isvedimas(list <studentas> s, list <studentas> &l, list <studentas> &k);
bool rikiavimasVid(studentas& s1, studentas& s2);
bool rikiavimasMed(studentas& s1, studentas& s2);
bool isBelowMedian(const studentas& stud);
bool isBelowAverage(const studentas& stud);
#endif