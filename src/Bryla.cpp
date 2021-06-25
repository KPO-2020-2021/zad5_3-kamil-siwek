#include "Bryla.h"




  void Bryla::zamien_srodek(Wektor3D srodek)
  {
    this->srodek=srodek;
  }

    Wektor3D Bryla::zwroc_srodek()
  {
   return srodek;
  }

   Wektor3D &Bryla::operator [](int i)
  {
      return  Wierz[i];
  }

  Wektor3D Bryla::operator [](int i) const
  {
      return  Wierz[i];
 }


Bryla::Bryla()
{
    //ctor
}

Bryla::~Bryla()
{
    //dtor
}
std::ostream &operator<<(std::ostream &Strm, const Bryla &Pr)
{
    for (int i = 0; i < Pr.get_wymiar(); i++)
    {
        Strm << Pr[i] << std::endl;
        if ((i+1) % 4 == 0)
            Strm << std::endl;
    }
    return Strm;
}