#include "Dron.hh"
int dron::id=0;
dron::dron(PzG::LaczeDoGNUPlota  &Lacze):Lacze(Lacze)
{
id++;

Pr=new Prostopadloscian("../datasets/prostopadloscian"+to_string(id)+".dat");

for(int i=0; i<4; i++)
{
    Sm[i]= new Graniastoslup("../datasets/graniastoslup"+to_string(id)+to_string(i)+".dat");
}
 
    Lacze.DodajNazwePliku(Pr->get_nazwa().c_str());
    for(int i=0; i<4; i++)
    Lacze.DodajNazwePliku(Sm[i]->get_nazwa().c_str());




    ZapiszDrona(1*rand()%360,rand()%240-120,rand()%240-120,0);


}

bool  dron::obsluga_drona()
{
    double kat,suma_katow=0;
    Macierz3x3 M,M_drogi,M_Wir;
    Wektor3D Wek;
    double droga,szyb_dr, szyb_wir;
    char znak;
    Lacze.Rysuj();
    for(int i=0; i<4; i++)
    {
        Wek=(*Sm[i])[0];
        Wek[2]-=2.5;
        Sm[i]->zamien_srodek (Wek);
    }

    while(1)
    {


        cin >> znak;
        switch(znak)
        {

        case 'o':
        {
            cout<<"podaj kat ";
            cin >> kat;
            suma_katow+=kat;

            for(int i=0; i<kat; i++)
            {

                M.set_kat(1);
                M.srodek(Pr->zwroc_srodek());
                M = obrot_z(M);
                for(int i=0; i<Pr->get_wymiar(); i++)
                {
                    (*Pr)[i]=M*(*Pr)[i];
                }
                for(int i=0; i<4; i++)
                {
                    for(int j=0; j<Sm[i]->get_wymiar(); j++)
                    {
                        (*Sm[i])[j]=M*(*Sm[i])[j];
                    }
                }

                zapis_do_plikow();
                usleep(50000);

                Lacze.Rysuj();
            }
            for(int i=0; i<4; i++)
            {
                Wek=(*Sm[i])[0];
                Wek[2]-=2.5;
                Sm[i]->zamien_srodek (Wek);
            }
        }
        break;
        case 'p':
        {
            kat=90;
            cout<<"podaj dorge"<<endl;
            cin>>droga;
            double droga_w=50;
            szyb_dr=2;
            szyb_wir=10;

            Wek[0]=szyb_dr*cos(kat*M_PI/180);
            Wek[1]=0;
            Wek[2]=szyb_dr*sin(kat*M_PI/180);
            M_drogi.set_kat(suma_katow);
            M_drogi = obrot_z(M_drogi);

            Wek=M_drogi*Wek;
            for(int i=0; i<droga_w/szyb_dr; i++)
            {

                Pr->zamien_srodek ( Pr->zwroc_srodek()+Wek);
                for(int i=0; i<Pr->get_wymiar(); i++)
                    (*Pr)[i]=(*Pr)[i]+Wek;
                for(int i=0; i<4; i++)
                    for(int j=0; j<Sm[i]->get_wymiar(); j++)
                        (*Sm[i])[j]=(*Sm[i])[j]+Wek;
                for(int k=0; k<4; k++)
                {
                    M.set_kat(szyb_wir);
                    M.srodek(Sm[k]->zwroc_srodek());
                    M = obrot_z(M);
                    Sm[k]->zamien_srodek (Sm[k]->zwroc_srodek()+ Wek);
                    for(int j=0; j<Sm[k]->get_wymiar(); j++)
                    {
                        (*Sm[k])[j]=M*(*Sm[k])[j];
                    }
                }
                usleep(50000);
                zapis_do_plikow();
                Lacze.Rysuj();
                for(int j=0; j<4; j++);

            }
kat=0;
            Wek[0]=szyb_dr*cos(kat*M_PI/180);
            Wek[1]=0;
            Wek[2]=szyb_dr*sin(kat*M_PI/180);
            M_drogi.set_kat(suma_katow);
            M_drogi = obrot_z(M_drogi);

            Wek=M_drogi*Wek;
            for(int i=0; i<droga/szyb_dr; i++)
            {

                Pr->zamien_srodek ( Pr->zwroc_srodek()+Wek);
                for(int i=0; i<Pr->get_wymiar(); i++)
                    (*Pr)[i]=(*Pr)[i]+Wek;
                for(int i=0; i<4; i++)
                    for(int j=0; j<Sm[i]->get_wymiar(); j++)
                        (*Sm[i])[j]=(*Sm[i])[j]+Wek;
                for(int k=0; k<4; k++)
                {
                    M.set_kat(szyb_wir);
                    M.srodek(Sm[k]->zwroc_srodek());
                    M = obrot_z(M);
                    Sm[k]->zamien_srodek (Sm[k]->zwroc_srodek()+ Wek);
                    for(int j=0; j<Sm[k]->get_wymiar(); j++)
                    {
                        (*Sm[k])[j]=M*(*Sm[k])[j];
                    }
                }
                usleep(50000);
                zapis_do_plikow();
                Lacze.Rysuj();
                for(int j=0; j<4; j++);

            }
            kat=-90;
            Wek[0]=szyb_dr*cos(kat*M_PI/180);
            Wek[1]=0;
            Wek[2]=szyb_dr*sin(kat*M_PI/180);
            M_drogi.set_kat(suma_katow);
            M_drogi = obrot_z(M_drogi);

            Wek=M_drogi*Wek;
            for(int i=0; i<droga_w/szyb_dr; i++)
            {

                Pr->zamien_srodek ( Pr->zwroc_srodek()+Wek);
                for(int i=0; i<Pr->get_wymiar(); i++)
                    (*Pr)[i]=(*Pr)[i]+Wek;
                for(int i=0; i<4; i++)
                    for(int j=0; j<Sm[i]->get_wymiar(); j++)
                        (*Sm[i])[j]=(*Sm[i])[j]+Wek;
                for(int k=0; k<4; k++)
                {
                    M.set_kat(szyb_wir);
                    M.srodek(Sm[k]->zwroc_srodek());
                    M = obrot_z(M);
                    Sm[k]->zamien_srodek (Sm[k]->zwroc_srodek()+ Wek);
                    for(int j=0; j<Sm[k]->get_wymiar(); j++)
                    {
                        (*Sm[k])[j]=M*(*Sm[k])[j];
                    }
                }
                usleep(50000);
                zapis_do_plikow();
                Lacze.Rysuj();
                for(int j=0; j<4; j++);

            }
        }
        break;
        case 'k':
        {


            return false;
        }
        }

    }
    return true;
}


void dron::zapis_do_plikow()
{
    ofstream korpus(Pr->get_nazwa());
    korpus<<(*Pr);
    korpus.close();
    ofstream sm(Sm[0]->get_nazwa());
    sm<< *Sm[0];
    sm.close();
    ofstream sm1(Sm[1]->get_nazwa());
    sm1<< *Sm[1];
    sm1.close();
    ofstream sm2(Sm[2]->get_nazwa());
    sm2<< *Sm[2];
    sm2.close();
    ofstream sm3(Sm[3]->get_nazwa());
    sm3<< *Sm[3];
    sm3.close();
}

bool dron::ZapiszDrona(
    double       Kat_st ,
    double       x_trans ,
    double       y_trans ,
    double       z_trans
)
{

    if (!Pr->StworzProstopadloscian(x_trans,y_trans,z_trans)) return false;
    if (!Sm[0]->StworzGraniastoslup6(
                Kat_st,
                x_trans+PROSTOKAT_X,
                y_trans+PROSTOKAT_Y,
                z_trans
            )) return false;
    if (!Sm[1]->StworzGraniastoslup6(
                -Kat_st,
                x_trans-PROSTOKAT_X,
                y_trans+PROSTOKAT_Y,
                z_trans
            )) return false;
    if (!Sm[2]->StworzGraniastoslup6(
                Kat_st,
                x_trans-PROSTOKAT_X,
                y_trans-PROSTOKAT_Y,
                z_trans
            )) return false;
    if (!Sm[3]->StworzGraniastoslup6(
                -Kat_st,
                x_trans+PROSTOKAT_X,
                y_trans-PROSTOKAT_Y,
                z_trans
            )) return false;
    zapis_do_plikow();
    return true;
}




bool dron::AnimacjaRuchuDrona(PzG::LaczeDoGNUPlota  & Lacze,unsigned int IloscIteracji,double Kat_Zmiana_st,double x_Zmiana,double y_Zmiana,double z_Zmiana)
{
    for (unsigned int Ind = 0;  Ind < IloscIteracji; ++Ind)
    {
        if (!ZapiszDrona(Ind*Kat_Zmiana_st,Ind*x_Zmiana,y_Zmiana,Ind*z_Zmiana)) return false;
        Lacze.Rysuj();
        usleep(200000);
    }
    return true;
}

bool Dron::czy_kolizja(shared_ptr<Obiekt_Sceny> ob)
{
 

        Wektor3D srodek_Drona = kopia.zwroc_srodek();
        Wektor3D srodek_Obiektu = ob->zwroc_srodek();
        double l = sqrt(pow(srodek_Drona[0] - srodek_Obiektu[0], 2) + pow(srodek_Drona[1] - srodek_Obiektu[1], 2) + pow(srodek_Drona[2] - srodek_Obiektu[2], 2));
        if (promien_ + ob->promien() >= l)
        {
            return true;
        }
    
    return false;
}