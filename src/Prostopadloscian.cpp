#include "Prostopadloscian.hh"






std::ostream &operator<<(std::ostream &Strm, const Prostopadloscian &Pr)
{
    for (int i = 0; i < Pr.get_wymiar(); i++)
    {
        Strm << Pr[i] << std::endl;
        if ((i+1) % 4 == 0)
            Strm << std::endl;
    }
    return Strm;
}
