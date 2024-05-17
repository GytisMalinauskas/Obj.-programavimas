#ifndef studentas_h
#define studentas_h
#include <list>
#include <string>
#include <iostream>
using namespace std;
struct studentas
{
  string name;
  string surname;
  double Eresults;
  double average;
  double grade;
  list <double> nd;
  double median;
  int ndCount;
  double sum;
};

#endif
