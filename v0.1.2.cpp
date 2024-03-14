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
// Function to generate a random full name
string generateRandomName(vector <string> names) {
     // Seed the random number generator
    string name2 = names[rand() % names.size()];
    return name2;
}
string generateRandomSurname(vector <string> surnames) {
    // Seed the random number generator
    string surname2 = surnames[rand() % surnames.size()];
    return surname2;
}

int main() 
{
  initializeNamesAndSurnames();
  srand(time(0));
  int MinP=1, MaxP=100;
  int MinP2=1, MaxP2=20; 
  int m,n;
  cout<<"Enter number"<<endl; 
  cout<<"1 - n and m are given"<<endl;
  cout<<"2 - n and m are not given"<<endl;
  int skaicius;
  vector <studentas> c; 
  cin>>skaicius;
  if(skaicius==1)
    {
    cout<<"Enter the number of students: "; cin>>m;
    cout<<"Enter the number of homework: "; cin>>n;
    int number3;
    c.resize(m);
    for(int i=0; i<m; i++)
    c[i].nd.resize(n);
    cout<<"Enter number 1 (for manual input) or 2 (for auto generating) homework results: "; cin>>number3; 
    for(int i=0; i<m; i++)
      {
      if(number3==2)
        {
        c[i].name=generateRandomName(names);
        c[i].surname=generateRandomSurname(surnames);
        for(int j=0; j<n; j++)
          {
          double result = MinP+rand()%(MaxP-MinP+1);
          c[i].nd.push_back(result);
          c[i].sum+=result;
          c[i].Eresults=MinP+rand()%(MaxP-MinP+1);
          }
        }
      if(number3==1)
        {
        cout<<"Enter name: "; cin>>c[i].name; 
        cout<<"Enter Surname: "; cin>>c[i].surname;
        for(int j=0; j<n; j++)
          {
          double result;
          cout<<"Enter the result of homework "<<j+1<<": "<<endl;
          cin>>result;
          c[i].nd.push_back(result);
          c[i].sum+=result;
          }
        cout<<"Enter the results of an exam: "; cin>>c[i].Eresults;
        }
      sort(c[i].nd.begin(),c[i].nd.end());
      c[i].median=0;
      if (n%2!=0)
        {c[i].median=c[i].nd[n/2];}
      if (n%2==0)
        {c[i].median=(c[i].nd[n/2]+c[i].nd[n/2+1])/2.0;}
      c[i].average=c[i].sum/n;
      c[i].Eresults=MinP+rand()%(MaxP-MinP+1);
      c[i].grade=c[i].average*0.4+0.6*c[i].Eresults;
      }
    }
  if(skaicius==2)
    {
    m=0; c.resize(m+1);
    int number2;
    cout<<"Enter number 1 (for manual input) or 2 (for auto generating) homework results: "; cin>>number2;
    while(true)
      {
      if(number2==1)
        {
          cout<<"Enter name or type 'quit' to quit: "; 
          cin>>c[m].name;
          if (c[m].name=="quit")break;
          cout<<"Enter surname: ";
          cin>>c[m].surname;
        while(true)
          { 
          c[m].ndCount=0;
          c[m].nd.resize(c[m].ndCount);
          double result;
          cout<<"Enter homework results or type '1000' to quit: "; cin>>result; 
          if(result == 1000) {break;}
          c[m].ndCount++;
          c[m].nd.resize(c[m].ndCount);
          c[m].nd.push_back(result);
          c[m].sum+=result;
          }
        cout<<"Enter results of exam: "; cin>>c[m].Eresults;
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
      if(number2==2)
        {
        bool continueLoop = true;
        while(continueLoop)
          {
          string gq;
          cout<<"Enter g (to generate 1 student) or q (to quit): "; cin>>gq;
          if(gq=="q"){continueLoop=false;}
          else if(gq=="g")
            {
            c[m].name=generateRandomName(names); cout<<c[m].name<<" ";
            c[m].surname=generateRandomSurname(surnames); cout<<c[m].surname<<endl;
            c[m].ndCount=MinP2+rand()%(MaxP2-MinP2+1);
            c[m].nd.resize(c[m].ndCount);
            for(int j=0; j<c[m].ndCount; j++)
              {
        double result = MinP+rand()%(MaxP-MinP+1);
              c[m].nd.push_back(result);
              c[m].sum+=result;
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
          }
          break;
        }
      }
  }
  string choice;
  cout<<"Choose either average or median: "; cin>>choice;
  if (choice=="median")
{
  cout<<"Name     Surname      Grade(Med.)"<<endl;
  for(int i=0; i<m; i++)
  cout<<fixed<<setw(8)<<left<<c[i].name<<" "<<setw(12)<<left<<c[i].surname<<" "<<setprecision(2)<<setw(13)<<c[i].median<<endl;
}
  else if (choice=="average")
{
  cout<<"Name     Surname      Grade(Vid.)"<<endl;
  for(int i=0; i<m; i++)
  cout<<fixed<<setw(8)<<left<<c[i].name<<" "<<setw(12)<<left<<c[i].surname<<" "<<setprecision(2)<<setw(13)<<c[i].grade<<endl;
}
}
