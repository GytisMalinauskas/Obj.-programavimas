#include <iostream>
#include <iomanip>
using namespace std;
int *n = new int;
struct studentas
{
  string name;
  string surname;
  double *HWresults = new double [*n];
  double Eresults;
  double average;
  double grade;
  double *me = new double [*n];
  double median;
};
int main() 
{ 
  int *m = new int;
  cout<<"Enter the number of students: "; cin>>*m;
studentas *c = new studentas [*m];
  
  cout<<"Enter the number of homework: "; cin>>*n; 
  for(int i=0; i<*m; i++)
{
cout<<"Enter name: "; cin>>c[i].name; 
cout<<"Enter Surname: "; cin>>c[i].surname;
double sum=0;
for(int j=0; j<*n; j++)
{
cout<<"Enter the results of homework "<<j+1<<": "; cin>>c[i].HWresults[j];
c[i].me[j]=c[i].HWresults[j];
sum+=c[i].HWresults[j];
}
for(int j=0; j<*n-1; j++)
{
for(int y=j+1; y<*n; y++)
{
  double k=0;
  if(c[i].me[j]>c[i].me[y])
  {
    k=c[i].me[j];
    c[i].me[j]=c[i].me[y];
    c[i].me[y]=k;
  }
}
}
c[i].median=0;
if (*n%2!=0)
{c[i].median=c[i].me[*n/2];}
if (*n%2==0)
{c[i].median=(c[i].me[*n/2]+c[i].me[*n/2+1])/2.0;}
c[i].average=sum/(*n);
cout<<"Enter the result of an exam: "; cin>>c[i].Eresults;
c[i].grade=c[i].average*0.4+0.6*c[i].Eresults;
cout<<"Final grade: "<<c[i].grade<<endl;
}
cout<<"Name     Surname      Grade(Vid.)  Grade(Med.)"<<endl;
for(int i=0; i<*m; i++)
cout<<fixed<<setw(8)<<left<<c[i].name<<" "<<setw(12)<<left<<c[i].surname<<" "<<setprecision(2)<<setw(13)<<c[i].grade<<setprecision(2)<<c[i].median<<endl;
}
