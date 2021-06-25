#ifndef PLASKOWYZ_HH
#define PLASKOWYZ_HH

#include "Bryla.h"

class Plaskowyz : public Bryla
{

public:
bool StworzPlaskowyz( double x_trans = 0, double y_trans = 0 ,double z_trans = 0 )
{
 Wierz.clear();
  ZapiszCzteryWierzcholki(-PROSTOKAT_X,PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
  ZapiszCzteryWierzcholki(PROSTOKAT_X,PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
  ZapiszCzteryWierzcholki(PROSTOKAT_X,-PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
  ZapiszCzteryWierzcholki(-PROSTOKAT_X,-PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
  ZapiszCzteryWierzcholki(-PROSTOKAT_X,PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
 return true;
}
 
    Plaskowyz(double x_trans , double y_trans ,double z_trans  ,std::string nazwa)
  { this->nazwa=nazwa;
  StworzPlaskowyz(x_trans,y_trans,z_trans);
  }
  

};


std::ostream &operator<<(std::ostream &Strm, const Plaskowyz &Pr)
{
    for (int i = 0; i < Pr.get_wymiar(); i++)
    {
        Strm << Pr[i] << std::endl;
        if ((i+1) % 4 == 0)
            Strm << std::endl;
    }
    return Strm;
}





#endif 