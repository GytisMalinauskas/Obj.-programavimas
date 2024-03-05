#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
struct studentas
{
  string name;
  string surname;
  double Eresults;
  double average;
  double grade;
  double *nd = new double [20];
  double median;
  int ndCount;
  double sum;
};

int main() 
{
  srand(time(0));
  int MinP=1, MaxP=100;
  int MinP2=1, MaxP2=20; 
  int *m = new int(0), *n = new int(0);
  cout<<"Iveskite skaiciu"<<endl; 
  cout<<"1 - Jau zinome n ir m skaicius"<<endl;
  cout<<"2 - Nezinome n ir m skaiciu"<<endl;
  int skaicius;
  studentas *c = new studentas [10]; 
  cin>>skaicius;
  if(skaicius==1)
     {
  cout<<"Enter the number of students: "; cin>>*m;
  cout<<"Enter the number of homework: "; cin>>*n;
  int number3;
cout<<"Enter number 1 (for manual input) or 2 (for auto generating) homework results:"; cin>>number3; 
  for(int i=0; i<*m; i++)
     {
  cout<<"Enter name: "; cin>>c[i].name; 
  cout<<"Enter Surname: "; cin>>c[i].surname;
if(number3==2)
  {
    for(int j=0; j<*n; j++)
     {
  double result = MinP+rand()%(MaxP-MinP+1);
  c[i].nd[j]=result;
  c[i].sum+=result;
  c[i].Eresults=MinP+rand()%(MaxP-MinP+1);
     }
  }
if(number3==1)
  {
    for(int j=0; j<*n; j++)
    {
      double result;
      cout<<"Enter the result of homework "<<j+1<<": "<<endl;
      cin>>result;
      c[i].nd[j]=result;
      c[i].sum+=result;
    }
    cout<<"Enter the results of an exam: "; cin>>c[i].Eresults;
  }
  for(int j=0;j<*n-1;j++)
  {
  for(int k=j+1; k<*n; k++)
  {
    if (c[i].nd[j] > c[i].nd[k]) {
            // Swap elements if they are out of order
            int temp = c[i].nd[j];
            c[i].nd[j] = c[i].nd[k];
            c[i].nd[k] = temp;
        }
  
  }
  }
  c[i].median=0;
  if (*n%2!=0)
  {c[i].median=c[i].nd[*n/2];}
  if (*n%2==0)
  {c[i].median=(c[i].nd[*n/2]+c[i].nd[*n/2+1])/2.0;}
  c[i].average=c[i].sum/(*n);
  c[i].Eresults=MinP+rand()%(MaxP-MinP+1);
  c[i].grade=c[i].average*0.4+0.6*c[i].Eresults;
    }
    }
  if(skaicius==2)
  {
    int number2;
      cout<<"Enter number 1 (for manual input) or 2 (for auto generating) homework results: "; cin>>number2;
    while(true)
    {
      cout<<"Enter name or type 'quit' to quit: "; 
      cin>>c[*m].name;
      if (c[*m].name=="quit")break;
      cout<<"Enter surname: ";
      cin>>c[*m].surname;
      c[*m].ndCount=0;
      c[*m].sum=0;
      if(number2==1)
      {
        while(true)
        {
          double result;
          cout<<"Enter homework results or type '1000' to quit: "; cin>>result; 
          if(result == 1000) {break;}
          c[*m].nd[c[*m].ndCount]=result;
          c[*m].ndCount++;
          c[*m].sum+=result;
        }
        cout<<"Enter results of exam: "; cin>>c[*m].Eresults;
      }
    if(number2==2)
      {
        c[*m].ndCount=MinP2+rand()%(MaxP2-MinP2+1);
        for(int j=0; j<c[*m].ndCount; j++)
        {
          double result = MinP+rand()%(MaxP-MinP+1);
          c[*m].nd[j]=result;
          c[*m].sum+=result;
     }
      }
        
  for(int j=0;j<c[*m].ndCount-1;j++)
  for(int k=j+1; k<c[*m].ndCount; k++)
  if (c[*m].nd[j] > c[*m].nd[k]) {
            // Swap elements if they are out of order
            int temp = c[*m].nd[j];
            c[*m].nd[j] = c[*m].nd[k];
            c[*m].nd[k] = temp;
        }
  c[*m].median=0;
  if (c[*m].ndCount%2!=0)
  {c[*m].median=c[*m].nd[c[*m].ndCount/2];}
  if (c[*m].ndCount%2==0)
  {c[*m].median=(c[*m].nd[c[*m].ndCount/2]+c[*m].nd[c[*m].ndCount/2+1])/2.0;}
  c[*m].average=c[*m].sum/c[*m].ndCount;
  c[*m].Eresults=MinP+rand()%(MaxP-MinP+1);
  c[*m].grade=c[*m].average*0.4+0.6*c[*m].Eresults;
        (*m)++;
    }

  }
  string choice;
  cout<<"Choose either average or median: "; cin>>choice;
  if (choice=="median")
{
  cout<<"Name     Surname      Grade(Med.)"<<endl;
  for(int i=0; i<*m; i++)
  cout<<fixed<<setw(8)<<left<<c[i].name<<" "<<setw(12)<<left<<c[i].surname<<" "<<setprecision(2)<<setw(13)<<c[i].median<<endl;
}
  else if (choice=="average")
{
  cout<<"Name     Surname      Grade(Vid.)"<<endl;
  for(int i=0; i<*m; i++)
  cout<<fixed<<setw(8)<<left<<c[i].name<<" "<<setw(12)<<left<<c[i].surname<<" "<<setprecision(2)<<setw(13)<<c[i].grade<<endl;
}
delete[] c;
delete m;
delete n;
}
