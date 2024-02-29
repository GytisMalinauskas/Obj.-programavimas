#include <iostream>
#include <iomanip>
using namespace std;
struct studentas
{
  string name;
  string surname;
  double nd[50];
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
cout<<"Enter the results of homework "<<j+1<<": "; cin>>a[i].nd[j];
a[i].m[j]=a[i].nd[j];
sum+=a[i].nd[j];
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
}
string choice;
cout<<"Choose either average or median: "; cin>>choice;
if (choice=="median")
{
cout<<"Name     Surname      Grade(Med.)"<<endl;
for(int i=0; i<StudentuSkaicius; i++)
cout<<fixed<<setw(8)<<left<<a[i].name<<" "<<setw(12)<<left<<a[i].surname<<" "<<setprecision(2)<<setw(13)<<a[i].median<<endl;

}
else if (choice=="average")
{
cout<<"Name     Surname      Grade(Vid.)"<<endl;
for(int i=0; i<StudentuSkaicius; i++)
cout<<fixed<<setw(8)<<left<<a[i].name<<" "<<setw(12)<<left<<a[i].surname<<" "<<setprecision(2)<<setw(13)<<a[i].grade<<endl;
}

else {
  cout<<"Ivesta neteisingai";
}
}
