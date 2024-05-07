#include "main.h"

int main() 
{
  try{
  vector<string> names;
  vector<string> surnames;
  srand(time(0));
  int MinP=1, MaxP=10;
  int m=0,n;
  vector <studentas> s;
  int skaicius;
  while (true)
  {
  cout<<"Enter number"<<endl; 
  cout<<"1 - manual input"<<endl;
  cout<<"2 - generate grades"<<endl;
  cout<<"3 - generate names and grades"<<endl;
  cout<<"4 - reading from file"<<endl;
  cout<<"5 - quit / show results"<<endl;
  cout<<"Number: ";
  try{
  skaicius=intIvestis(1,5);}
  catch(const exception &e)
  {cerr<<"Klaida: "<<e.what()<<endl;
  continue;}
    
  if(skaicius==5)
  {break;}
  if(skaicius==3)
  {
    VarduGeneravimui();
  }
  if(skaicius!=4){
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
    FailoSkaitymas(s);    
  }
    }
    Isvedimas(s);
  }
  catch(const exception& e){
                cerr << "Klaida: " << e.what() << endl;
                return 1;
            }
}