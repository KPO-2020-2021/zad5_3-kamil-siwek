#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include <iostream>
#include "Bryla.h"
using namespace std;


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
/* szablon Prostopadloscian oparta na szablonie Wektor
zawiera funkcje typu:
-porownaj boki
-buduj prostopadloscian za pomoca wektora i dlugosci bokow
-przeciazenie opratora [] oraz ()
*/

class Graniastoslup : public Bryla
{

  public:
  Graniastoslup(std::string nazwa){ this->nazwa=nazwa;}
bool StworzGraniastoslup6(double       Kat_st,double       x_trans,double       y_trans,double       z_trans)
{

  double  KatSkoku_st = 2*M_PI/ILOSC_WIERZCHOLKOW_GRANIATOSLUPA;
  double  x_wierz, y_wierz;
 Wierz.clear();
  for (unsigned int Idx = 0; Idx <= ILOSC_WIERZCHOLKOW_GRANIATOSLUPA; ++Idx)
  {
    x_wierz = PROMIEN_PODSTAWY*cos(Kat_st);
    y_wierz = PROMIEN_PODSTAWY*sin(Kat_st);
    Kat_st += KatSkoku_st;
    ZapiszCzteryWierzcholki(-x_wierz,y_wierz,GRUPOSC_ROTORA/2,x_trans,y_trans,PROSTOKAT_Z+GRUPOSC_ROTORA/2+z_trans);
  }
return true;
}


};





std::ostream& operator << ( std::ostream &Strm,const Graniastoslup &Pr);


#endif

