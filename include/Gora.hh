#ifndef GORA_HH
#define GORA_HH

#include "Bryla.h"
class Gora : public Bryla
{

public:
bool StworzGora( double x_trans = 0, double y_trans = 0 ,double z_trans = 0 )
{
 Wierz.clear();

  Wektor3D Wek;
      Wek[0]=x_trans;
    Wek[1]=y_trans;
    Wek[2]=PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);
      Wek[0]=-PROSTOKAT_X+x_trans;
    Wek[1]=PROSTOKAT_Y+y_trans;
    Wek[2]=-PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);
      Wek[0]=-PROSTOKAT_X+x_trans;
    Wek[1]=PROSTOKAT_Y+y_trans;
    Wek[2]= -PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);
      Wek[0]=x_trans;
    Wek[1]=y_trans;
    Wek[2]=-PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);

         Wek[0]=x_trans;
    Wek[1]=y_trans;
    Wek[2]=PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);
      Wek[0]=PROSTOKAT_X+x_trans;
    Wek[1]=PROSTOKAT_Y+y_trans;
    Wek[2]=-PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);
      Wek[0]=PROSTOKAT_X+x_trans;
    Wek[1]=PROSTOKAT_Y+y_trans;
    Wek[2]= -PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);
      Wek[0]=x_trans;
    Wek[1]=y_trans;
    Wek[2]=-PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);

     Wek[0]=x_trans;
    Wek[1]=y_trans;
    Wek[2]=PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);
      Wek[0]=PROSTOKAT_X+x_trans;
    Wek[1]=-PROSTOKAT_Y+y_trans;
    Wek[2]=-PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);
      Wek[0]=PROSTOKAT_X+x_trans;
    Wek[1]=-PROSTOKAT_Y+y_trans;
    Wek[2]= -PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);
      Wek[0]=x_trans;
    Wek[1]=y_trans;
    Wek[2]=-PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);


     Wek[0]=x_trans;
    Wek[1]=y_trans;
    Wek[2]=PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);
      Wek[0]=-PROSTOKAT_X+x_trans;
    Wek[1]=-PROSTOKAT_Y+y_trans;
    Wek[2]=-PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);
      Wek[0]=-PROSTOKAT_X+x_trans;
    Wek[1]=-PROSTOKAT_Y+y_trans;
    Wek[2]= -PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);
      Wek[0]=x_trans;
    Wek[1]=y_trans;
    Wek[2]=-PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);

    Wek[0]=x_trans;
    Wek[1]=y_trans;
    Wek[2]=PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);
      Wek[0]=-PROSTOKAT_X+x_trans;
    Wek[1]=PROSTOKAT_Y+y_trans;
    Wek[2]=-PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);
      Wek[0]=-PROSTOKAT_X+x_trans;
    Wek[1]=PROSTOKAT_Y+y_trans;
    Wek[2]= -PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);
      Wek[0]=x_trans;
    Wek[1]=y_trans;
    Wek[2]=-PROSTOKAT_Z+z_trans;
   Wierz.push_back(Wek);


/*
  ZapiszCzteryWierzcholki(PROSTOKAT_X,PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
  ZapiszCzteryWierzcholki(-PROSTOKAT_X,-PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
  ZapiszCzteryWierzcholki(-PROSTOKAT_X,-PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
  ZapiszCzteryWierzcholki(-PROSTOKAT_X,PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
  */
 return true;
}
  Gora(double x_trans , double y_trans,double z_trans,std::string nazwa)
  { this->nazwa=nazwa;
  StworzGora(x_trans,y_trans,z_trans);
  }

};

std::ostream &operator<<(std::ostream &Strm, const Gora &Pr)
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