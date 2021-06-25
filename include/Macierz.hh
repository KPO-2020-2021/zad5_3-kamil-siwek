#ifndef Macierz_HH
#define Macierz_HH


#include <iostream>
#include "Wektor.hh"
using namespace std;
/*!
 * \file
 * \brief Ten plik powinien zawierać definicję szablonu Macierz<>
 *
 * Ten plik powinien zawierać definicję szablonu Macierz<>.
 * W tym celu należy przerobić definicję klasy Macierz2x2.
 */




/*!
 * \brief  Krótki opis czego to jest szablon
 *
 *  Tutaj trzeba opisac szablon. Jakie pojecie on modeluje
 *  i jakie ma glowne cechy.
 */
/* szablon Macierz oparta na szablonie Wektor
zawiera funkcje typu:
-zeruj
-wypisz
-ustaw kat
-przeciazenie opratora Macierz*Macierz
-przeciazenie opratora Macierz*wektor
-przeciazenie opratora Macierz+Macierz
-przeciazenie opratora [] oraz ()
*/
template <int Wymiar>
class Macierz
{

    Wektor<Wymiar> M[Wymiar];
    double kat;
    Wektor<Wymiar> srodek_obrotu;
public:


    void srodek(Wektor<Wymiar> srodek_obrotu)
    {
        this->srodek_obrotu=srodek_obrotu;
    }

    Macierz()
    {
        for(int i=0; i<Wymiar; i++)
        {
            for(int j=0; j<Wymiar; j++)
                M[i][j]=0;
        }
    }


    double get_kat()
    {
        return kat;
    };

    void set_kat( double kat)
    {
        this->kat=kat*M_PI/180;
    };

    Wektor<Wymiar> operator *(Wektor<Wymiar> W)
    {
        Wektor<Wymiar> Wynik;
        for(int i=0; i<Wymiar; i++)
        {
            for(int j=0; j<Wymiar; j++)
            {
                Wynik[i]+=M[i][j]*(W[j]-srodek_obrotu[j]);
            }
            Wynik[i]+=srodek_obrotu[i];
        }
        return Wynik;
    }



    Wektor<Wymiar>  &operator[](int i)
    {
        return M[i];
    }
    double &operator()(int i, int j)
    {
        return M[i][j];
    }
    double operator()(int i, int j)const
    {
        return M[i][j];
    }

};




/*!
 * \brief Przeciążenie dla wejścia musi także być szablonem
 *
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
template <int Wymiar>
inline
std::ostream& operator << (std::ostream &Strm, const Macierz<Wymiar> &Wek)
{

    for(int i=0; i<Wymiar; i++)
    {
        for(int j=0; j<Wymiar; j++)
            cout<<Wek(i,j)<<" ";

        cout<<endl;
    }
    return Strm;
}


#endif
