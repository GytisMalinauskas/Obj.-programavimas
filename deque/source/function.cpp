#include "../headers/function.h"

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
bool isBelowAverage(const studentas& stud) {
    return stud.average < 5.0;
}
bool isBelowMedian(const studentas& stud) {
    return stud.median < 5.0;
}
void Skaicius1(deque<studentas>& s, int &m, int skaicius, int MinP, int MaxP)
{
  try{
  int b,n;
  studentas st;
  cout<<"Enter the number of students: "; m=intIvestis2();
      cout<<"Enter the number of homework: "; n=intIvestis2();
      for(int i=0; i<m; i++)
      {
        if(skaicius==1||skaicius==2)
        {
          cout<<"Enter name: "; cin>>st.name; 
          cout<<"Enter Surname: "; cin>>st.surname;
        }
        else if(skaicius==3)
        {
            st.name=generateRandomName(names);
            st.surname=generateRandomSurname(surnames); 
        }
          for(int j=0; j<n; j++)
          {
            double result=0;
            if(skaicius==1)
            {
              cout<<"Enter homework result "<<j+1<<": ";
              result=intIvestis(MinP,MaxP);
            }
            if(skaicius==2||skaicius==3)
            {
              result=MinP+rand()%(MaxP-MinP+1);
            }
            st.nd.push_back(result);
            st.sum+=result;
          }
            if(skaicius==1)
            {
              cout<<"Enter exam results: ";
              st.Eresults=intIvestis(MinP,MaxP);
            }
            if(skaicius==2||skaicius==3)
            {
              st.Eresults=MinP+rand()%(MaxP-MinP+1);
            }
      sort(st.nd.begin(),st.nd.end());
      st.median=0;
      if(n%2!=0)
      {st.median=st.nd[n/2];}
      if(n%2==0)
      {st.median=(st.nd[n/2]+st.nd[n/2+1])/2.0;}
      st.average=st.sum/n;
      st.grade=st.average*0.4+0.6*st.Eresults;
      st.ndCount=n;
      s.push_back(st);
      cout<<s.size()<<endl;
      }
  }
    catch(const exception& e){
    cerr<<"Klaida :"<<e.what()<<endl;
    exit(1);
  }
}
void Skaicius2(deque<studentas>& s, int skaicius, int MinP, int MaxP)
{
  try{
  studentas st;
  while(true)
      {
        if(skaicius==1||skaicius==2)
        {
          string vardas;
          cout<<"Enter name or type 'quit' to quit: "; 
          cin>>vardas;
          if (vardas=="quit")
          {break;}
          st.name=vardas;
          cout<<"Enter surname: ";
          cin>>st.surname;
        } 
        if(skaicius==3)
        {
          string gq;
          cout<<"Enter g (to generate 1 student) or q (to quit): "; 
          gq=SimbolioTikrinimas();
          if(gq=="q")
          {break;}
          else if(gq=="g")
          {
            st.name=generateRandomName(names);
            st.surname=generateRandomSurname(surnames);
          }
        }
        st.ndCount=0;
        double result;  
        if(skaicius==1)
        {
          while(true)
          { 
          cout<<"Enter homework results or type '0' to quit: "; 
          result=intIvestis(0,10); 
          if(result == 0) 
          {break;}
          st.ndCount++;
          st.nd.push_back(result);
          st.sum+=result;
          }
        }
        if(skaicius==2||skaicius==3)
        {
          while(true)
          {
            string gq2;
            cout<<"Enter g (to generate "<<st.ndCount+1<<" homework result) or q (to quit): "; 
            gq2=SimbolioTikrinimas();
            if(gq2=="q")
            {break;}
            else if(gq2=="g")
            {
              result=MinP+rand()%(MaxP-MinP+1);
              st.ndCount++;
              st.nd.push_back(result);
              st.sum+=result;
            }
          } 
        }
        if(skaicius==1)
        {
          cout<<"Enter exam result: ";
          st.Eresults=intIvestis(MinP,MaxP);
        }
        if(skaicius==2||skaicius==3)
        {
          st.Eresults=MinP+rand()%(MaxP-MinP+1);
        }
        sort(st.nd.begin(),st.nd.end());
        st.median=0;
        if (st.ndCount%2!=0)
        {st.median=st.nd[st.ndCount/2];}
        if (st.ndCount%2==0)
        {st.median=(st.nd[st.ndCount/2]+st.nd[st.ndCount/2+1])/2.0;}
        st.average=st.sum/st.ndCount;
        st.Eresults=MinP+rand()%(MaxP-MinP+1);
        st.grade=st.average*0.4+0.6*st.Eresults;
        s.push_back(st);
      }
  }catch(const exception& e)
  {
    cerr<<"Klaida: "<<e.what()<<endl;
    exit(1);
  }   
}
void FailoSkaitymas(deque <studentas> &s, string &duomPav)
{
  try{
  system("ls *.txt");
    cout << "Pasirinkite duomenų failą: ";
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

auto start_filereading=chrono::high_resolution_clock::now(); 
    
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
      in.close();
    auto end_filereading=chrono::high_resolution_clock::now();
    auto duration_filereading= chrono::duration_cast<chrono::milliseconds>(end_filereading-start_filereading).count();  
    cout << "Failo " << duomPav << " nuskaitymas uztruko: " << duration_filereading/1000.0 << " sekundes" << endl;  
  }catch(const exception& e){
    cerr<<"Klaida: "<<e.what()<<endl;
    exit(1);
  }
  
}
void VarduGeneravimui()
{
  try{
  int number2;
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
    }catch(const exception& e)
    {
      cerr<<"Klaida: "<<e.what()<<endl;
      exit(1);
    }
}
void Isvedimas(deque <studentas> s, deque <studentas> &l, deque <studentas> &k)
{
  try
  {
    string IsvedBudas, choice;
  cout << "Choose how to output the results: "<<endl
       <<"f - To file"<<endl
       <<"c - To console"<<endl
       <<"Choice: ";
  IsvedBudas=SimbolioTikrinimas3();
  cout<<"Choose the strategy for sorting"<<endl
      <<"1 - to 'k' and 'l' containers"<<endl
      <<"2 - to 'l' and leaving only good students in a 's' container"<<endl
      <<"3 - optimized and best strategy"<<endl
      <<"Strategy: ";
  int strategy = intIvestis(1,3);
  cout<<"Choose either average (type a) or median (type m): "; 
  choice=SimbolioTikrinimas2();
  cout << "Choose how to sort: " << endl
       << "1 - By name" << endl
       << "2 - By surname" << endl
       << "3 - By grade" << endl
       << "Choice: ";
  int sortmeth=intIvestis(1,3); 
  Sorting(s,k,l,choice,sortmeth,strategy);    
  size_t IlgiausiasVardas = 0;
  size_t IlgiausiaPavarde = 0;
  for (const auto& student : s) 
      {
        IlgiausiasVardas = max(IlgiausiasVardas, student.name.length());
        IlgiausiaPavarde = max(IlgiausiaPavarde, student.surname.length());
      }
  if(IsvedBudas=="c")
    {
      auto start_konsole=chrono::high_resolution_clock::now();
      if(strategy==1){
      if (choice=="m")
      {
        cout<<"Kieti studentai"<<endl;
        cout<<left<<setw(IlgiausiasVardas+5)<<"Name"<<setw(IlgiausiaPavarde+5)<<"Surname"<<setw(20)<<"Grade(Med.)"<<endl;
        for(const auto& student : k)
        {cout<<left<<setw(IlgiausiasVardas+5)<<student.name<<" "<<setw(IlgiausiaPavarde+5)<<student.surname<<" "<<fixed<<setprecision(2)<<setw(20)<<student.median<<endl;}
        cout<<"Lievi studentai"<<endl;
        cout<<left<<setw(IlgiausiasVardas+5)<<"Name"<<setw(IlgiausiaPavarde+5)<<"Surname"<<setw(20)<<"Grade(Med.)"<<endl;
        for(const auto& student : l)
        {cout<<left<<setw(IlgiausiasVardas+5)<<student.name<<" "<<setw(IlgiausiaPavarde+5)<<student.surname<<" "<<fixed<<setprecision(2)<<setw(20)<<student.median<<endl;}

      }
      else if (choice=="a")
      {
        cout<<"Kieti studentai"<<endl;
        cout<<left<<setw(IlgiausiasVardas+5)<<"Name"<<setw(IlgiausiaPavarde+5)<<"Surname"<<setw(20)<<"Grade(Vid.)"<<endl;
        for(const auto& student : k)
        {cout<<left<<setw(IlgiausiasVardas+5)<<student.name<<" "<<setw(IlgiausiaPavarde+5)<<student.surname<<" "<<fixed<<setprecision(2)<<setw(20)<<student.grade<<endl;}
        cout<<"Lievi studentai"<<endl;
        cout<<left<<setw(IlgiausiasVardas+5)<<"Name"<<setw(IlgiausiaPavarde+5)<<"Surname"<<setw(20)<<"Grade(Vid.)"<<endl;
        for(const auto& student : l)
        {cout<<left<<setw(IlgiausiasVardas+5)<<student.name<<" "<<setw(IlgiausiaPavarde+5)<<student.surname<<" "<<fixed<<setprecision(2)<<setw(20)<<student.grade<<endl;}
      }
      }
      if(strategy==2 || strategy==3)
      {
        if (choice=="m")
      {
        cout<<"Kieti studentai"<<endl;
        cout<<left<<setw(IlgiausiasVardas+5)<<"Name"<<setw(IlgiausiaPavarde+5)<<"Surname"<<setw(20)<<"Grade(Med.)"<<endl;
        for(const auto& student : s)
        {cout<<left<<setw(IlgiausiasVardas+5)<<student.name<<" "<<setw(IlgiausiaPavarde+5)<<student.surname<<" "<<fixed<<setprecision(2)<<setw(20)<<student.median<<endl;}
        cout<<"Lievi studentai"<<endl;
        cout<<left<<setw(IlgiausiasVardas+5)<<"Name"<<setw(IlgiausiaPavarde+5)<<"Surname"<<setw(20)<<"Grade(Med.)"<<endl;
        for(const auto& student : l)
        {cout<<left<<setw(IlgiausiasVardas+5)<<student.name<<" "<<setw(IlgiausiaPavarde+5)<<student.surname<<" "<<fixed<<setprecision(2)<<setw(20)<<student.median<<endl;}

      }
      else if (choice=="a")
      {
        cout<<"Kieti studentai"<<endl;
        cout<<left<<setw(IlgiausiasVardas+5)<<"Name"<<setw(IlgiausiaPavarde+5)<<"Surname"<<setw(20)<<"Grade(Vid.)"<<endl;
        for(const auto& student : s)
        {cout<<left<<setw(IlgiausiasVardas+5)<<student.name<<" "<<setw(IlgiausiaPavarde+5)<<student.surname<<" "<<fixed<<setprecision(2)<<setw(20)<<student.grade<<endl;}
        cout<<"Lievi studentai"<<endl;
        cout<<left<<setw(IlgiausiasVardas+5)<<"Name"<<setw(IlgiausiaPavarde+5)<<"Surname"<<setw(20)<<"Grade(Vid.)"<<endl;
        for(const auto& student : l)
        {cout<<left<<setw(IlgiausiasVardas+5)<<student.name<<" "<<setw(IlgiausiaPavarde+5)<<student.surname<<" "<<fixed<<setprecision(2)<<setw(20)<<student.grade<<endl;}
      }
      }
      auto end_konsole=chrono::high_resolution_clock::now();
      auto duration_konsole=chrono::duration_cast<chrono::milliseconds>(end_konsole-start_konsole).count();
      cout << "Isvedimas i konsole  uztruko: " << duration_konsole/1000.0 << " sekundes" << endl;
      }
  if(IsvedBudas=="f")
  {
    auto start_result=chrono::high_resolution_clock::now();
    if(strategy == 1)
    {
    ofstream fr("kieti.txt");
    if(choice=="m")
    {
      fr<<left<<setw(IlgiausiasVardas+5)<<"Name"<<setw(IlgiausiaPavarde+5)<<"Surname"<<setw(20)<<"Grade(Med.)"<<endl;
      for(const auto& student : k)
        {fr<<left<<setw(IlgiausiasVardas+5)<<student.name<<" "<<setw(IlgiausiaPavarde+5)<<student.surname<<" "<<fixed<<setprecision(2)<<setw(20)<<student.median<<endl;}
    }
    else if (choice=="a")
    {
      fr<<left<<setw(IlgiausiasVardas+5)<<"Name"<<setw(IlgiausiaPavarde+5)<<"Surname"<<setw(20)<<"Grade(Vid.)"<<endl;
      for(const auto& student : k)
      {fr<<left<<setw(IlgiausiasVardas+5)<<student.name<<" "<<setw(IlgiausiaPavarde+5)<<student.surname<<" "<<fixed<<setprecision(2)<<setw(20)<<student.grade<<endl;}
    }
    fr.close();
    ofstream fr2("lievi.txt");
    if(choice=="m")
      {
        fr2<<left<<setw(IlgiausiasVardas+5)<<"Name"<<setw(IlgiausiaPavarde+5)<<"Surname"<<setw(20)<<"Grade(Med.)"<<endl;
        for(const auto& student : l)
      {fr2<<left<<setw(IlgiausiasVardas+5)<<student.name<<" "<<setw(IlgiausiaPavarde+5)<<student.surname<<" "<<fixed<<setprecision(2)<<setw(20)<<student.median<<endl;}
      }
      else if (choice=="a")
    {
      fr2<<left<<setw(IlgiausiasVardas+5)<<"Name"<<setw(IlgiausiaPavarde+5)<<"Surname"<<setw(20)<<"Grade(Vid.)"<<endl;
      for(const auto& student : l)
      {fr2<<left<<setw(IlgiausiasVardas+5)<<student.name<<" "<<setw(IlgiausiaPavarde+5)<<student.surname<<" "<<fixed<<setprecision(2)<<setw(20)<<student.grade<<endl;}
    }
    fr2.close();
    }
    if(strategy==2 || strategy==3)
    {
      ofstream fr("kieti.txt");
    if(choice=="m")
    {
      fr<<left<<setw(IlgiausiasVardas+5)<<"Name"<<setw(IlgiausiaPavarde+5)<<"Surname"<<setw(20)<<"Grade(Med.)"<<endl;
      for(const auto& student : s)
        {fr<<left<<setw(IlgiausiasVardas+5)<<student.name<<" "<<setw(IlgiausiaPavarde+5)<<student.surname<<" "<<fixed<<setprecision(2)<<setw(20)<<student.median<<endl;}
    }
    else if (choice=="a")
    {
      fr<<left<<setw(IlgiausiasVardas+5)<<"Name"<<setw(IlgiausiaPavarde+5)<<"Surname"<<setw(20)<<"Grade(Vid.)"<<endl;
      for(const auto& student : s)
      {fr<<left<<setw(IlgiausiasVardas+5)<<student.name<<" "<<setw(IlgiausiaPavarde+5)<<student.surname<<" "<<fixed<<setprecision(2)<<setw(20)<<student.grade<<endl;}
    }
    fr.close();
    ofstream fr2("lievi.txt");
    if(choice=="m")
      {
        fr2<<left<<setw(IlgiausiasVardas+5)<<"Name"<<setw(IlgiausiaPavarde+5)<<"Surname"<<setw(20)<<"Grade(Med.)"<<endl;
        for(const auto& student : l)
      {fr2<<left<<setw(IlgiausiasVardas+5)<<student.name<<" "<<setw(IlgiausiaPavarde+5)<<student.surname<<" "<<fixed<<setprecision(2)<<setw(20)<<student.median<<endl;}
      }
      else if (choice=="a")
    {
      fr2<<left<<setw(IlgiausiasVardas+5)<<"Name"<<setw(IlgiausiaPavarde+5)<<"Surname"<<setw(20)<<"Grade(Vid.)"<<endl;
      for(const auto& student : l)
      {fr2<<left<<setw(IlgiausiasVardas+5)<<student.name<<" "<<setw(IlgiausiaPavarde+5)<<student.surname<<" "<<fixed<<setprecision(2)<<setw(20)<<student.grade<<endl;}
    }
    fr2.close();
    }
    auto end_result=chrono::high_resolution_clock::now();
    auto duration_result= chrono::duration_cast<chrono::milliseconds>(end_result-start_result).count();  
    cout << "Isvedimas uztruko: " << duration_result/1000.0 << " sekundes" << endl; 
    }
  }
  catch (const exception& e)
  {
    cerr<<"Klaida: "<<e.what()<<endl;
    exit(1);
  }
}
bool rikiavimasVardu(studentas& s1, studentas& s2) {
    return s1.name < s2.name;
}
bool rikiavimasPavarde(studentas& s1, studentas& s2) {
    return s1.surname < s2.surname;
}
bool rikiavimasVid(studentas& s1, studentas& s2) {
    return s1.average > s2.average;
}
bool rikiavimasMed(studentas& s1, studentas& s2) {
    return s1.median > s2.median;
}
void Sorting(deque<studentas>& s, deque<studentas>& k, deque<studentas>& l, string choice, int rikiavimas, int strategy) {
    auto start_rusiavimas_visu = chrono::high_resolution_clock::now();

    if (rikiavimas == 1) {
        sort(s.begin(), s.end(), rikiavimasVardu);
    } else if (rikiavimas == 2) {
        sort(s.begin(), s.end(), rikiavimasPavarde);
    } else if (rikiavimas == 3) {
        if (choice == "a") {
            sort(s.begin(), s.end(), rikiavimasVid);
        } else if (choice == "m") {
            sort(s.begin(), s.end(), rikiavimasMed);
        }
    }

    auto end_rusiavimas_visu = chrono::high_resolution_clock::now();
    auto duration_rusiavimas_visu = chrono::duration_cast<chrono::milliseconds>(end_rusiavimas_visu - start_rusiavimas_visu).count();
    cout << "Studentu rikiavimas didejimo tvarka uztruko: " << duration_rusiavimas_visu / 1000.0 << " sekundes" << endl;

    auto start_rusiavimas = chrono::high_resolution_clock::now();

    if (strategy == 1) {
        for (const auto& stud : s) {
            if ((choice == "a" && stud.grade < 5.0) || (choice == "m" && stud.median < 5.0)) {
                l.push_back(stud);
            } else {
                k.push_back(stud);
            }
        }
    } else if (strategy == 2) {
        auto it = s.begin();
        for (auto& stud : s) {
            if ((choice == "a" && stud.grade < 5.0) || (choice == "m" && stud.median < 5.0)) {
                l.push_back(stud);
            } else {
                *it++ = move(stud);
            }
        }
        s.erase(it, s.end());
    } else if (strategy == 3) {
        if (choice == "a") {
            auto partitionPoint = partition(s.begin(), s.end(), isBelowAverage);
            l.assign(s.begin(), partitionPoint);
            s.erase(s.begin(), partitionPoint);
        } else if (choice == "m") {
            auto partitionPoint = partition(s.begin(), s.end(), isBelowMedian);
            l.assign(s.begin(), partitionPoint);
            s.erase(s.begin(), partitionPoint);
        }
    }

    auto end_rusiavimas = chrono::high_resolution_clock::now();
    auto duration_rusiavimas = chrono::duration_cast<chrono::milliseconds>(end_rusiavimas - start_rusiavimas).count();
    cout << "Rusiavimas uztruko: " << duration_rusiavimas / 1000.0 << " sekundes" << endl;
}