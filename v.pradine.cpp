#include <iostream>
#include <iomanip>
using namespace std;
struct studentas
{
  string name;
  string surname;
  double nd[2];
  double Eresults;
  double average;
  double grade;
};
int main() 
{ 
  int StudentuSkaicius=2;
  studentas a[StudentuSkaicius];
  int n=2;
  double sum=0;
  a[0].name = "Gytis";
  a[1].name = "Marius";
  a[0].surname = "Malinauskas";
  a[1].surname = "Pavardenis";
  a[0].nd[0]=10;
  a[0].nd[1]=15;
  a[1].nd[0]=57.5;
  a[1].nd[1]=68.25;
  a[0].Eresults=100;
  a[1].Eresults=75.25;
  for(int i=0; i<StudentuSkaicius; i++)
  {
  for(int j=0; j<n; j++)
  {
  sum+=a[i].nd[j];
  }
  a[i].average=sum/n;
  }
  for(int i=0; i<StudentuSkaicius; i++)
  a[i].grade=a[i].average*0.4+0.6*a[i].Eresults;
  cout<<"Name     Surname      Grade(Vid.)"<<endl;
  for(int i=0; i<StudentuSkaicius; i++)
  cout<<fixed<<setw(8)<<left<<a[i].name<<" "<<setw(12)<<left<<a[i].surname<<" "<<setprecision(2)<<setw(13)<<a[i].grade<<endl;
}
