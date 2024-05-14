#pragma once
#include <deque>
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
  deque <double> nd;
  double median;
  int ndCount;
  double sum;
};
