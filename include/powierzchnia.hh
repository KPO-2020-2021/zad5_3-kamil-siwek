#pragma once
#include "Bryla.h"
/*!
 * \brief Kalasa opisujaca prostopadloscian
 *
 *nieniejsza klasa zawiera metody oraz paremetry potrzebne do opisu prostopadloscianu
 */
class  Powierzchnia
{
 int SIZE_X;
  int SIZE_Y;
   std::vector<Wektor3D > point;
   std::string nazwa;
   public:
    string get_nazwa(){return nazwa;}
    Powierzchnia( double dlugosc,double szeroksc,double glebokosc, std::string nazwa)
    {
         this->nazwa=nazwa;
        SIZE_X=SIZE_Y=0;
        Wektor3D tmp;
          for(int i=-dlugosc/2; i<=dlugosc/2; i+=50){
       for(int j=-szeroksc/2; j<=szeroksc/2; j+=50){
                tmp[0]=i;
                tmp[1]=j;
                tmp[2]=glebokosc;

                point.push_back(tmp);

               SIZE_X++;
        }
        SIZE_Y++;
    }
    }

bool Zapis()
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(nazwa);
  if (!StrmPlikowy.is_open())
    {

    return false;
  }

    for(int i=0; i<SIZE_X; i++){
        if(i%SIZE_Y==0)
        StrmPlikowy<<std::endl;
        StrmPlikowy<<point[i]<<std::endl;
    }
  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}


};