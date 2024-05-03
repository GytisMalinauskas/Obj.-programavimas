#include <cstdio>
#include <locale>
#include <time.h>
#include <limits>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstring> 
#include <cerrno>
#include <random> 
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

void Sorting(vector<studentas>& s, string choice, int rikiavimas);

int main() 
{
  srand(time(0));
  int MinP=1, MaxP=10;
  int m=0,n,b;
  vector <studentas> s;
  while (true)
  {
  cout<<"Enter number"<<endl; 
  cout<<"1 - manual input"<<endl;
  cout<<"2 - generate grades"<<endl;
  cout<<"3 - generate names and grades"<<endl;
  cout<<"4 - reading from file"<<endl;
  cout<<"5 - quit / show results"<<endl;
  cout<<"Number: ";
  int skaicius;
  cin>>skaicius;
  if(skaicius==5)
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
  if(skaicius!=4){
  cout<<"Enter number"<<endl;
  cout<<"1 - n and m is given"<<endl;
  cout<<"2 - n and m is not given"<<endl;
  cout<<"Number: ";
  int number1; 
  cin>>number1;
    if(number1==1)
    {
      cout<<"Enter the number of students: "; cin>>b;
      cout<<"Enter the number of homework: "; cin>>n;
      m+=b;
      if(m-b==0)
      {b=0;}
      s.resize(m);
      for(int i=b; i<m; i++)
      {
        if(skaicius==1||skaicius==2)
        {
          cout<<"Enter name: "; cin>>s[i].name; 
          cout<<"Enter Surname: "; cin>>s[i].surname;
        }
        else if(skaicius==3)
        {
            s[i].name=generateRandomName(names);
            s[i].surname=generateRandomSurname(surnames); 
        }
          for(int j=0; j<n; j++)
          {
            double result=0;
            if(skaicius==1)
            {
              cout<<"Enter homework result "<<j+1<<": ";
              cin>>result;
            }
            if(skaicius==2||skaicius==3)
            {
              result=MinP+rand()%(MaxP-MinP+1);
            }
            s[i].nd.push_back(result);
            s[i].sum+=result;
          }
            if(skaicius==1)
            {
              cout<<"Enter exam results: ";
              cin>>s[i].Eresults;
            }
            if(skaicius==2||skaicius==3)
            {
              s[i].Eresults=MinP+rand()%(MaxP-MinP+1);
            }
      sort(s[i].nd.begin(),s[i].nd.end());
      s[i].median=0;
      if(n%2!=0)
      {s[i].median=s[i].nd[n/2];}
      if(n%2==0)
      {s[i].median=(s[i].nd[n/2]+s[i].nd[n/2+1])/2.0;}
      s[i].average=s[i].sum/n;
      s[i].grade=s[i].average*0.4+0.6*s[i].Eresults;
      }
    }
    else if(number1 == 2)
    {
      while(true)
      {
        if(skaicius==1||skaicius==2)
        {
          string vardas;
          cout<<"Enter name or type 'quit' to quit: "; 
          cin>>vardas;
          if (vardas=="quit")
          {break;}
          s[m].name=vardas;
          cout<<"Enter surname: ";
          cin>>s[m].surname;
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
            s[m].name=generateRandomName(names);
            s[m].surname=generateRandomSurname(surnames);
          }
        }
        s[m].ndCount=0;
        double result;  
        if(skaicius==1)
        {
          while(true)
          { 
          cout<<"Enter homework results or type '100' to quit: "; 
          cin>>result; 
          if(result == 100) 
          {break;}
          s[m].ndCount++;
          s[m].nd.push_back(result);
          s[m].sum+=result;
          }
        }
        if(skaicius==2||skaicius==3)
        {
          while(true)
          {
            string gq2;
            cout<<"Enter g (to generate "<<s[m].ndCount+1<<" homework result) or q (to quit): "; 
            cin>>gq2;
            if(gq2=="q")
            {break;}
            else if(gq2=="g")
            {
              result=MinP+rand()%(MaxP-MinP+1);
              s[m].ndCount++;
              s[m].nd.push_back(result);
              s[m].sum+=result;
            }
          } 
        }
        if(skaicius==1)
        {
          cout<<"Enter exam result: ";
          cin>>s[m].Eresults;
        }
        if(skaicius==2||skaicius==3)
        {
          s[m].Eresults=MinP+rand()%(MaxP-MinP+1);
        }
        sort(s[m].nd.begin(),s[m].nd.end());
        s[m].median=0;
        if (s[m].ndCount%2!=0)
        {s[m].median=s[m].nd[s[m].ndCount/2];}
        if (s[m].ndCount%2==0)
        {s[m].median=(s[m].nd[s[m].ndCount/2]+s[m].nd[s[m].ndCount/2+1])/2.0;}
        s[m].average=s[m].sum/s[m].ndCount;
        s[m].Eresults=MinP+rand()%(MaxP-MinP+1);
        s[m].grade=s[m].average*0.4+0.6*s[m].Eresults;
        m++;
        s.resize(m+1);
      }   
    }
      names.clear();
      surnames.clear();
      cout<<endl;
  }
  if(skaicius==4)
  {
    system("ls *.txt");
    cout << "Pasirinkite duomenų failą: ";
    string duomPav;
    cin >> duomPav;

    ifstream in(duomPav);
    try
    {    
        if (!in) 
        {
        throw runtime_error("Failas nerastas.");
        }
    }
    catch(const runtime_error& e)
    {cout<<e.what()<<endl;}

    string line;
    getline(in, line);

    while (getline(in, line)) {
        std::istringstream iss(line);
        studentas st;
        iss >> st.name >> st.surname;
        st.sum=0;
        int pazymys;
        while (iss >> pazymys) {
            st.nd.push_back(pazymys);
            st.sum+=pazymys;        }
        
        st.Eresults = st.nd.back();
        st.nd.pop_back();
        st.ndCount = st.nd.size();
        st.average = st.sum/st.ndCount;
        if (st.ndCount%2!=0)
        {st.median=st.nd[st.ndCount/2];}
        if (st.ndCount%2==0)
        {st.median=(st.nd[st.ndCount/2]+st.nd[st.ndCount/2+1])/2.0;}
        st.grade=st.average*0.4+0.6*st.Eresults;
        s.push_back(st);
      }
        
  }
  }
    string choice;
    cout<<"Choose either average or median: "; cin>>choice;
    cout << "Choose how to sort: " << endl
         << "1 - By name" << endl
         << "2 - By surname" << endl
         << "3 - By grade" << endl;
    int sortmeth;
    cin>>sortmeth;
    Sorting(s,choice,sortmeth);
    if (choice=="median")
    {
      cout<<"Name       Surname      Grade(Med.)"<<endl;
      for(const auto& student : s)
      {cout<<fixed<<setw(10)<<left<<student.name<<" "<<setw(12)<<left<<student.surname<<" "<<setprecision(2)<<setw(13)<<student.median<<endl;}
    }
    else if (choice=="average")
    {
      cout<<"Name       Surname      Grade(Vid.)"<<endl;
      for(const auto& student : s)
      {cout<<fixed<<setw(10)<<left<<student.name<<" "<<setw(12)<<left<<student.surname<<" "<<setprecision(2)<<setw(13)<<student.grade<<endl;}
    }
}
   
bool rikiavimasVardu(studentas& s1, studentas& s2) {
    return s1.name < s2.name;
}

bool rikiavimasPavarde(studentas& s1, studentas& s2) {
    return s1.surname < s2.surname;
}

bool rikiavimasVid(studentas& s1, studentas& s2) {
    return s1.grade > s2.grade;
}
bool rikiavimasMed(studentas& s1, studentas& s2) {
    return s1.median > s2.median;
}
void Sorting(vector<studentas>& s, string choice, int rikiavimas) {
    if (rikiavimas == 1) {
        sort(s.begin(), s.end(), rikiavimasVardu);
    } else if (rikiavimas == 2) {
        sort(s.begin(), s.end(), rikiavimasPavarde);
    } else if (rikiavimas == 3) {
      if(choice=="average")
        sort(s.begin(), s.end(), rikiavimasVid);
      if(choice=="median")
        sort(s.begin(), s.end(), rikiavimasMed);
    }
}
