#include <iostream>
#include <iomanip>
#include <vector>
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
  vector <double> nd;
  double median;
  int ndCount;
  double sum;
};
vector<string> names;
vector<string> surnames;
void initializeNamesAndSurnames() {
    names.push_back("John");
    names.push_back("Emma");
    names.push_back("Michael");
    names.push_back("Sophia");
    names.push_back("William");
    names.push_back("Olivia");
    names.push_back("James");
    names.push_back("Ava");
    names.push_back("Alexander");
    names.push_back("Isabella");

    surnames.push_back("Smith");
    surnames.push_back("Johnson");
    surnames.push_back("Williams");
    surnames.push_back("Jones");
    surnames.push_back("Brown");
    surnames.push_back("Davis");
    surnames.push_back("Miller");
    surnames.push_back("Wilson");
    surnames.push_back("Moore");
    surnames.push_back("Taylor");
}
string generateRandomName(vector <string> names) {
    string name2 = names[rand() % names.size()];
    return name2;
}
string generateRandomSurname(vector <string> surnames) {
    string surname2 = surnames[rand() % surnames.size()];
    return surname2;
}

int main() 
{
  srand(time(0));
  int MinP=1, MaxP=100;
  int m,n;
  vector <studentas> c;
  vector <studentas> students;
  while (true)
  {
  cout<<"Enter number"<<endl; 
  cout<<"1 - manual input"<<endl;
  cout<<"2 - generate grades"<<endl;
  cout<<"3 - generate names and grades"<<endl;
  cout<<"4 - quit / show results"<<endl;
  cout<<"Number: ";
  int skaicius;
  cin>>skaicius;
  if(skaicius==4)
  {break;}
  int number2;
  if(skaicius==3)
  {
    cout<<"Enter number"<<endl;
    cout<<"1 - generate name and surname by pc"<<endl;
    cout<<"2 - manually input names and surnames for generating students"<<endl;
    cout<<"Number: ";
    cin>>number2;
    if(number2==1)
    {
      initializeNamesAndSurnames();
    }
    if(number2==2)
    {
      while(true)
      {
        string vardas, pavarde;
        cout<<"Enter name or type 'quit' to quit: ";
        cin>>vardas;
        if(vardas=="quit")
        {break;}
        cout<<"Enter surname: ";
        cin>>pavarde;
        names.push_back(vardas);
        surnames.push_back(pavarde);
      }
    }
  }
  cout<<"Enter number"<<endl;
  cout<<"1 - n and m is given"<<endl;
  cout<<"2 - n and m is not given"<<endl;
  cout<<"Number: ";
  int number1; 
  cin>>number1;
    if(number1==1)
    {
      cout<<"Enter the number of students: "; cin>>m;
      cout<<"Enter the number of homework: "; cin>>n;
      c.resize(m);
      for(int i=0; i<m; i++)
      {
        c[i].nd.resize(n);
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
            double result=0;
            if(skaicius==1)
            {
              cout<<"Enter homework result "<<j+1<<" :";
              cin>>result;
            }
            if(skaicius==2||skaicius==3)
            {
              result=MinP+rand()%(MaxP-MinP+1);
            }
            c[i].nd.push_back(result);
            c[i].sum+=result;
          }
            if(skaicius==1)
            {
              cout<<"Enter exam results: ";
              cin>>c[i].Eresults;
            }
            if(skaicius==2||skaicius==3)
            {
              c[i].Eresults=MinP+rand()%(MaxP-MinP+1);
            }
      sort(c[i].nd.begin(),c[i].nd.end());
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
      c.resize(m+1);
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
        c[m].nd.resize(c[m].ndCount);
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
          c[m].nd.resize(c[m].ndCount);
          c[m].nd.push_back(result);
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
              c[m].nd.resize(c[m].ndCount);
              c[m].nd.push_back(result);
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
        sort(c[m].nd.begin(),c[m].nd.end());
        c[m].median=0;
        if (c[m].ndCount%2!=0)
        {c[m].median=c[m].nd[c[m].ndCount/2];}
        if (c[m].ndCount%2==0)
        {c[m].median=(c[m].nd[c[m].ndCount/2]+c[m].nd[c[m].ndCount/2+1])/2.0;}
        c[m].average=c[m].sum/c[m].ndCount;
        c[m].Eresults=MinP+rand()%(MaxP-MinP+1);
        c[m].grade=c[m].average*0.4+0.6*c[m].Eresults;
        m++;
        c.resize(m+1);
      }   
    }
    for (int i = 0; i < m; ++i) 
      {
        students.push_back(c[i]);
      }
      c.clear();
      names.clear();
      surnames.clear();
      cout<<endl;
  
  }
    string choice;
    cout<<"Choose either average or median: "; cin>>choice;
    if (choice=="median")
    {
      cout<<"Name     Surname      Grade(Med.)"<<endl;
      for(const auto& student : students)
      {cout<<fixed<<setw(8)<<left<<student.name<<" "<<setw(12)<<left<<student.surname<<" "<<setprecision(2)<<setw(13)<<student.median<<endl;}
    }
    else if (choice=="average")
    {
      cout<<"Name     Surname      Grade(Vid.)"<<endl;
      for(const auto& student : students)
      {cout<<fixed<<setw(8)<<left<<student.name<<" "<<setw(12)<<left<<student.surname<<" "<<setprecision(2)<<setw(13)<<student.grade<<endl;}
    }
}
