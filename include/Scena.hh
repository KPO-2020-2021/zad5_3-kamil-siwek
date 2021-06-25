#ifndef SCENA_HH
#define SCENA_HH
#include <iostream>
#include <iomanip>
#include <memory>
#include <fstream>
#include <list>
#include "Graniastoslup.hh"
#include "lacze_do_gnuplota.hh"
#include "Dron.hh"
#include "Gora.hh"
#include "Gran.hh"
#include "Plaskowyz.hh"
#include "powierzchnia.hh"

#define N 2

class Scena
{
    
    PzG::LaczeDoGNUPlota Lacze;
    std::list<std::shared_ptr<dron >> Lista_Dronow; /// element fazy3
     std::list<std::shared_ptr<Bryla >>  Lista_elementow; /// element fazy3; /// element fazy3
    int nr_elem;
    int nr_drona;
    Powierzchnia *dno;

public:
    Scena();
    void rysuj();
    bool interfejs();
    ~Scena();
};

Scena::Scena()
{

  Lacze.ZmienTrybRys(PzG::TR_3D);
  nr_elem = 0;
  nr_drona=0;
  Lacze.UstawZakresY(-150, 150);
  Lacze.UstawZakresX(-150, 150);
  Lacze.UstawZakresZ(-20, 150);

  double tab_wym[3] = {600, 600, 0};
  Wektor3D wym_dna(tab_wym);
  dno = new Powierzchnia(300,300,-10, "../datasets/dno.dat");
  Wektor3D srod;

    for(int i=0; i<4; i++)
  {
  tab_wym[0] = rand() % 240 - 120;
  tab_wym[1] = rand() % 240 - 120;
  tab_wym[2] = -5;
  int nr_p=rand()%3;
   if(nr_p==0)
  Lista_elementow.push_front(std::make_shared<Gora>( tab_wym[0],tab_wym[1],tab_wym[2],"../datasets/Element" + std::to_string(nr_elem) + ".dat"));
 else if(nr_p==1)
  Lista_elementow.push_front(std::make_shared<Plaskowyz>(tab_wym[0],tab_wym[1],tab_wym[2] ,"../datasets/Element" + std::to_string(nr_elem) + ".dat"));
   else if(nr_p==2)
  Lista_elementow.push_front(std::make_shared<Gran>(tab_wym[0],tab_wym[1],tab_wym[2], "../datasets/Element" + std::to_string(nr_elem) + ".dat"));
  nr_elem++;
  }
  for (std::list<std::shared_ptr<Bryla>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
  {
    Lacze.DodajNazwePliku((*a)->get_nazwa().c_str());
    ofstream plik((*a)->get_nazwa());
    plik<<  *(*a);
    plik.close();
    
  }

  Lacze.DodajNazwePliku(dno->get_nazwa().c_str());
  dno->Zapis();
  for (int i = 0; i < N; i++)
  {
   // double pozycja[3] = {(double)(rand() % 440 - 220), (double)(rand() % 440 - 220), 25};
    Lista_Dronow.push_front(std::make_shared<dron >( Lacze) );
  
    nr_drona++;
  }

  Lacze.Rysuj();
}
void Scena::rysuj()
{

  Lacze.Rysuj();
}
bool Scena::interfejs()
{
  cout << "1.Drony 2. dodaj obiekt" << endl;
  int opcja;
  cin >> opcja;
  switch (opcja)
  {
  case 1:
  {
    cout << "podaj nr " << endl;
    for(int i=0; i<(int)Lista_Dronow.size(); i++)
    {
      cout<<i <<" ";
    }
    cout<<":"<<endl;
    int nr;
    cin >> nr;
    std::list<std::shared_ptr<dron >>::const_iterator a;
    a=Lista_Dronow.begin();
    for(int i=0; i<nr; i++)
    {
      a++;
    }
    
    (*a)->obsluga_drona();
  }
  break;
  
  case 2:
{
  double tab_wym[3];
 
  tab_wym[0] = rand() % 240 - 120;
  tab_wym[1] = rand() % 240 - 120;
  tab_wym[2] = -5;
  int nr_p=rand()%3;
   if(nr_p==0)
  Lista_elementow.push_front(std::make_shared<Gora>( tab_wym[0],tab_wym[1],tab_wym[2],"../datasets/Element" + std::to_string(nr_elem) + ".dat"));
 else if(nr_p==1)
  Lista_elementow.push_front(std::make_shared<Plaskowyz>(tab_wym[0],tab_wym[1],tab_wym[2] ,"../datasets/Element" + std::to_string(nr_elem) + ".dat"));
   else if(nr_p==2)
  Lista_elementow.push_front(std::make_shared<Gran>(tab_wym[0],tab_wym[1],tab_wym[2], "../datasets/Element" + std::to_string(nr_elem) + ".dat"));
  nr_elem++;
  
  for (std::list<std::shared_ptr<Bryla>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
  {
    Lacze.DodajNazwePliku((*a)->get_nazwa().c_str());
    ofstream plik((*a)->get_nazwa());
    plik<<  *(*a);
    plik.close();
    
  }
}
  break;
  }
  return true;
}

Scena::~Scena()
{
  free(dno);

}
#endif
