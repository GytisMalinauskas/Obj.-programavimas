#include "fileGenerator.h"

void GenerateFile (int kiekis, int nd_kiekis, string &fileName)
{
  int MinP=1, MaxP=10;
  fileName ="StudentaiGen" + to_string(kiekis) +".txt"; 
  ofstream fr(fileName);
  try{
    if(!fr)
    {
      throw runtime_error("Nepavyko sukurti failo: " + fileName);
    }
    fr<<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavarde";
    for(int i=1; i<nd_kiekis; i++)
    {
      fr<<setw(7)<<"ND"+to_string(i);
    }
    fr<<setw(7)<<"Egz."<<endl;
    for(int i=1;i<=kiekis; i++)
    {
      fr<<left<<setw(20)<<"Vardas"+to_string(i)<<setw(20)<<"Pavarde"+to_string(i);
    for(int j=1; j<=nd_kiekis; j++)
    {fr<<setw(7)<<MinP+rand()%(MaxP-MinP+1);}
    if(i!=kiekis) {fr<<endl;}
    }
    fr.close();
    cout << "Failas: " << fileName << " sugeneruotas sekmingai:)" << endl;
  }catch(const exception& e)
  {
    cerr<<e.what()<<endl;
  }
}