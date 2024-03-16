#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
struct studentas
{
  string name;
  string surname;
  double Eresults;
  double average;
  double grade;
  double* nd;
  double median;
  int ndCount;
  double sum;
};

string generateRandomName(string names[]) {
    return names[rand() % 10];
}

string generateRandomSurname(string surnames[]) {
    return surnames[rand() % 10];
}

int main() 
{
   srand(time(0));
  int MinP=1, MaxP=100;
  int m, n;
  studentas *c=nullptr;
  cout<<"Enter number"<<endl; 
  cout<<"1 - manual input"<<endl;
  cout<<"2 - generate grades"<<endl;
  cout<<"3 - generate names and grades"<<endl;
  cout<<"4 - quit"<<endl;
  int skaicius;
  string names[] = {"John", "Emma", "Michael", "Sophia", "William", "Olivia", "James", "Ava", "Alexander", "Isabella"};
  string surnames[] = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"};    
  cin>>skaicius;
  cout<<"Enter number"<<endl;
  cout<<"1 - n and m is given"<<endl;
  cout<<"2 - n and m is not given"<<endl;
  int number1; 
  cin>>number1;
  if(skaicius!=4)
  {
    if(number1==1)
    {
      cout<<"Enter the number of students: "; cin>>m;
      cout<<"Enter the number of homework: "; cin>>n;
      c = new studentas[m];
      for(int i=0; i<m; i++)
      {
        c[i].nd=new double[n];
        if(skaicius==1||skaicius==2)
        {
          cout<<"Enter name: "; cin>>c[i].name; 
          cout<<"Enter Surname: "; cin>>c[i].surname;
        }
        else if(skaicius==3)
        {
          c[i].name=generateRandomName(names);
          c[i].surname=generateRandomSurname(surnames);
        }
          for(int j=0; j<n; j++)
          {
            double result;
            if(skaicius==1)
            {
              cout<<"Enter homework result "<<j+1<<" : ";
              cin>>result;
              cout<<endl;
            }
            if(skaicius==2||skaicius==3)
            {
              result=MinP+rand()%(MaxP-MinP+1);
            }
            c[i].nd[j]=result;
            c[i].sum+=result;
          }
            if(skaicius==1)
            {
              cout<<"Enter exam results: "<<endl;
              cin>>c[i].Eresults;
            }
            if(skaicius==2||skaicius==3)
            {
              c[i].Eresults=MinP+rand()%(MaxP-MinP+1);
            }
      sort(c[i].nd,c[i].nd+n);
      c[i].median=0;
      if(n%2!=0)
      {c[i].median=c[i].nd[n/2];}
      if(n%2==0)
      {c[i].median=(c[i].nd[n/2]+c[i].nd[n/2+1])/2.0;}
      c[i].average=c[i].sum/n;
      c[i].grade=c[i].average*0.4+0.6*c[i].Eresults;
      }
    }
    else if(number1 == 2)
    {
      m=0; 
      c = new studentas [m+1];
      while(true)
      {
        if(skaicius==1||skaicius==2)
        {
          string vardas;
          cout<<"Enter name or type 'quit' to quit: "; 
          cin>>vardas;
          if (vardas=="quit")
          {break;}
          c[m].name=vardas;
          cout<<"Enter surname: ";
          cin>>c[m].surname; 
        } 
        if(skaicius==3)
        {
          string gq;
          cout<<"Enter g (to generate 1 student) or q (to quit): "; 
          cin>>gq;
          if(gq=="q")
          {break;}
          else if(gq=="g")
          {
            c[m].name=generateRandomName(names);
            c[m].surname=generateRandomSurname(surnames);
          }
        }

        c[m].ndCount=0;
        c[m].nd=new double[c[m].ndCount+1];
        double result;  
        if(skaicius==1)
        {
          while(true)
          { 
          cout<<"Enter homework results or type '1000' to quit: "; 
          cin>>result; 
          if(result == 1000) 
          {break;}
          c[m].ndCount++;
          c[m].nd=new double[c[m].ndCount+1];
          c[m].nd[c[m].ndCount-1]=result;
          c[m].sum+=result;
          }

        }
        if(skaicius==2||skaicius==3)
        {
          while(true)
          {
            string gq2;
            cout<<"Enter g (to generate "<<c[m].ndCount+1<<" homework result) or q (to quit): "; 
            cin>>gq2;
            if(gq2=="q")
            {break;}
            else if(gq2=="g")
            {
              result=MinP+rand()%(MaxP-MinP+1);
              c[m].ndCount++;
              c[m].nd=new double[c[m].ndCount+1];
              c[m].nd[c[m].ndCount-1]=result;
              c[m].sum+=result;
            }
          } 
        }
        if(skaicius==1)
        {
          cout<<"Enter exam result: ";
          cin>>c[m].Eresults;
        }
        if(skaicius==2||skaicius==3)
        {
          c[m].Eresults=MinP+rand()%(MaxP-MinP+1);
        }
        sort(c[m].nd,c[m].nd+c[m].ndCount+1);
        c[m].median=0;
        if (c[m].ndCount%2!=0)
        {c[m].median=c[m].nd[c[m].ndCount/2];}
        if (c[m].ndCount%2==0)
        {c[m].median=(c[m].nd[c[m].ndCount/2]+c[m].nd[c[m].ndCount/2+1])/2.0;}
        c[m].average=c[m].sum/c[m].ndCount;
        c[m].Eresults=MinP+rand()%(MaxP-MinP+1);
        c[m].grade=c[m].average*0.4+0.6*c[m].Eresults;
        studentas* temp = new studentas[m];
        for (int i = 0; i <= m; ++i)
        {
            temp[i] = c[i];
        }
        delete[] c;
        c = temp;
        ++m;
      }   
    }
    string choice;
    cout<<"Choose either average or median: "; cin>>choice;
    if (choice=="median")
    {
      cout<<"Name      Surname      Grade(Med.)"<<endl;
      for(int i=0; i<m; i++)
      {cout<<fixed<<setw(9)<<left<<c[i].name<<" "<<setw(12)<<left<<c[i].surname<<" "<<setprecision(2)<<setw(13)<<c[i].median<<endl;}
    }
    else if (choice=="average")
    {
      cout<<"Name      Surname      Grade(Vid.)"<<endl;
      for(int i=0; i<m; i++)
      {cout<<fixed<<setw(9)<<left<<c[i].name<<" "<<setw(12)<<left<<c[i].surname<<" "<<setprecision(2)<<setw(13)<<c[i].grade<<endl;}
    }
    if (c != nullptr)
    {
        for (int i = 0; i < m; ++i)
        {
            delete[] c[i].nd;
        }
        delete[] c;
    }
  }
}
