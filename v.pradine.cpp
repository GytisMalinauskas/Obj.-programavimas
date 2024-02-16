#include <iostream>
#include <iomanip>
using namespace std;
struct studentas
{
  string name;
  string surname;
  double HWresults[50];
  double Eresults;
  double average;
  double grade;
  double m[50];
  double median;
};
int main() 
{ 
  int StudentuSkaicius;
  cout<<"Enter the number of students: "; cin>>StudentuSkaicius;
studentas a[StudentuSkaicius];
  int n;
  cout<<"Enter the number of homework: "; cin>>n; 
  for(int i=0; i<StudentuSkaicius; i++)
{
cout<<"Enter name: "; cin>>a[i].name; 
cout<<"Enter Surname: "; cin>>a[i].surname;
double sum=0;
for(int j=0; j<n; j++)
{
cout<<"Enter the results of homework "<<j+1<<": "; cin>>a[i].HWresults[j];
a[i].m[j]=a[i].HWresults[j];
sum+=a[i].HWresults[j];
}
for(int j=0; j<n-1; j++)
{
for(int y=j+1; y<n; y++)
{
  double k=0;
  if(a[i].m[j]>a[i].m[y])
  {
    k=a[i].m[j];
    a[i].m[j]=a[i].m[y];
    a[i].m[y]=k;
  }
}
}
a[i].median=0;
if (n%2!=0)
{a[i].median=a[i].m[n/2];}
if (n%2==0)
{a[i].median=(a[i].m[n/2]+a[i].m[n/2+1])/2.0;}
a[i].average=sum/n;
cout<<"Enter the result of an exam: "; cin>>a[i].Eresults;
a[i].grade=a[i].average*0.4+0.6*a[i].Eresults;
cout<<"Final grade: "<<a[i].grade<<endl;
}
cout<<"Name     Surname      Grade(Vid.)  Grade(Med.)"<<endl;
for(int i=0; i<StudentuSkaicius; i++)
cout<<fixed<<setw(8)<<left<<a[i].name<<" "<<setw(12)<<left<<a[i].surname<<" "<<setprecision(2)<<setw(13)<<a[i].grade<<setprecision(2)<<a[i].median<<endl;
}
