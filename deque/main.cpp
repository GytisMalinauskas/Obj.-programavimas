#include "main.h"

int main() 
{
  try{
  auto start=chrono::high_resolution_clock::now();
  vector<string> names;
  vector<string> surnames;
  srand(time(0));
  int MinP=1, MaxP=10;
  int m=0,n;
  string duomPav;
  deque <studentas> s; //studentai
  deque <studentas> k; //kieti s
  deque <studentas> l; //lievi s
  int skaicius;
  srand(time(nullptr));
  while (true)
  {
  cout<<"Enter number"<<endl; 
  cout<<"1 - manual input"<<endl;
  cout<<"2 - generate grades"<<endl;
  cout<<"3 - generate names and grades"<<endl;
  cout<<"4 - reading from file"<<endl;
  cout<<"5 - generate file"<<endl;
  cout<<"6 - quit / show results"<<endl;
  cout<<"Number: ";
  try{
  skaicius=intIvestis(1,6);}
  catch(const exception &e)
  {cerr<<"Klaida: "<<e.what()<<endl;
  continue;}
    
  if(skaicius==6)
  {break;}
  if(skaicius==3)
  {
    VarduGeneravimui();
  }
  if(skaicius!=4 && skaicius!=5){
  cout<<"Enter number"<<endl;
  cout<<"1 - n and m is given"<<endl;
  cout<<"2 - n and m is not given"<<endl;
  cout<<"Number: ";
  int number1; 
  number1=intIvestis(1,2);
    if(number1==1)
    {
      Skaicius1(s,m,skaicius,MinP,MaxP);
    }
    else if(number1 == 2)
    {
      Skaicius2(s,skaicius,MinP,MaxP);
    }
      names.clear();
      surnames.clear();
      cout<<endl;
  }
  if(skaicius==4)
  {
    auto start_filereading=chrono::high_resolution_clock::now(); 
    FailoSkaitymas(s,duomPav);
    auto end_filereading=chrono::high_resolution_clock::now();
    auto duration_filereading= chrono::duration_cast<chrono::milliseconds>(end_filereading-start_filereading).count();  
    cout << "Failo " << duomPav << " nuskaitymas uztruko: " << duration_filereading/1000.0 << " sekundes" << endl;
  }
  if(skaicius == 5){
            int kiekis;
            int nd_kiekis;
            string fileName;
            cout << "How many students you want to generate in file?: "; kiekis=intIvestis2();
            cout << "How many tasks should students have (final counts in)?: "; nd_kiekis=intIvestis2();
            auto start_generate=chrono::high_resolution_clock::now();
            GenerateFile(kiekis, nd_kiekis,fileName);
            auto end_generate=chrono::high_resolution_clock::now();
            auto duration_generate= chrono::duration_cast<chrono::milliseconds>(end_generate-start_generate).count();  
            cout << "Failo " << fileName << " generavimas uztruko: " << duration_generate/1000.0 << " sekundes" << endl;
        }
    }
    auto start_result=chrono::high_resolution_clock::now();
    Isvedimas(s,l,k);
    auto end_result=chrono::high_resolution_clock::now();
    auto duration_result= chrono::duration_cast<chrono::milliseconds>(end_result-start_result).count();  
    cout << "Isvedimas uztruko: " << duration_result/1000.0 << " sekundes" << endl; 
    auto end =chrono::high_resolution_clock::now();
    auto duration_start_to_end= chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cout << "Visos programos veikimas uztruko: " << duration_start_to_end/1000.0 << " sekundes" << endl;
    return 0;
  }
  catch(const exception& e){
                cerr << "Klaida: " << e.what() << endl;
                return 1;
            }
  
}