#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

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

class Prostopadloscian : public Bryla
{

  public:
  Prostopadloscian(std::string nazwa){ this->nazwa=nazwa;}
bool StworzProstopadloscian( double x_trans = 0, double y_trans = 0 ,double z_trans = 0 )
{
 Wierz.clear();
  ZapiszCzteryWierzcholki(-PROSTOKAT_X,PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
  ZapiszCzteryWierzcholki(PROSTOKAT_X,PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
  ZapiszCzteryWierzcholki(PROSTOKAT_X,-PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
  ZapiszCzteryWierzcholki(-PROSTOKAT_X,-PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
  ZapiszCzteryWierzcholki(-PROSTOKAT_X,PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
 return true;
}

};




/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::ostream& operator << ( std::ostream       &Strm,
                            const Prostopadloscian    &Pr
                          );


#endif
