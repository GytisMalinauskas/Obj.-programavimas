#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
struct studentas
{
  string name;
  string surname;
  vector <double> HWresults;
  double Eresults;
  double average;
  double grade;
  vector <double> me;
  double median;
};
int main() 
{ 
  int m;
  cout<<"Enter the number of students: "; cin>>m;
vector <studentas> c(m);
  int n;
  cout<<"Enter the number of homework: "; cin>>n; 
  for(int i=0; i<m; i++)
{
cout<<"Enter name: "; cin>>c[i].name; 
cout<<"Enter Surname: "; cin>>c[i].surname;
double sum=0;
for(int j=0; j<n; j++)
{
cout<<"Enter the results of homework "<<j+1<<": ";
double result;
cin>>result;
c[i].HWresults.push_back(result);
c[i].me.push_back(result);
sum+=result;
}
sort(c[i].me.begin(),c[i].me.end());
c[i].median=0;
if (n%2!=0)
{c[i].median=c[i].me[n/2];}
if (n%2==0)
{c[i].median=(c[i].me[n/2]+c[i].me[n/2+1])/2.0;}
c[i].average=sum/n;
cout<<"Enter the result of an exam: "; cin>>c[i].Eresults;
c[i].grade=c[i].average*0.4+0.6*c[i].Eresults;
cout<<"Final grade: "<<c[i].grade<<endl;
}
cout<<"Name     Surname      Grade(Vid.)  Grade(Med.)"<<endl;
for(int i=0; i<m; i++)
cout<<fixed<<setw(8)<<left<<c[i].name<<" "<<setw(12)<<left<<c[i].surname<<" "<<setprecision(2)<<setw(13)<<c[i].grade<<setprecision(2)<<c[i].median<<endl;
}
