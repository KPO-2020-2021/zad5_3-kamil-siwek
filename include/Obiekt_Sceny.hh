#ifndef OBIEKT_SCENY_HH
#define OBIEKT_SCENY_HH
#include <string>
#include <memory>

using namespace std;

class Obiekt_Sceny
{

public:

virtual bool czy_kolizja(shared_ptr <Obiekt_Sceny> ob)=0;
virtual std::string get_nazwa() =0;
};





#endif
