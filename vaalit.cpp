/* c++ harjoitustyö
 * 
 * Jenna Halmetoja
 * Tampereen yliopisto, syksy 2015
 *
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

#include "vaalit.h"

using namespace std;
using cpp_yleiset::tarkistaKopiot;
using namespace cpp_puolue;
using namespace cpp_ehdokas;
using namespace cpp_vaalipiiri;
int main(int argc, char *argv[])
{
    string komento;
    string kasky;
    bool lopeta = false;
    bool tulosLaskettu = false;
    vector<Puolue> puolueLista;
    vector<Puolue> puolueLista2;
    vector<Ehdokas> ehdokasLista;
    vector<Ehdokas> ehdokasListaTulos;
    vector<Ehdokas> valitut;
    vector<Vaalipiiri> vaalipiiriLista;
    
    //pääsilmukka
    while (lopeta == false)
    {
        //luetaan komennot rivi kerrallaan ja otetaan ne talteen
        getline(cin, komento);
        istringstream iss(komento);
        iss>>kasky;
        
        //lisätään puolueeseen komennon mukaiset tiedot
        if(kasky == "lisaaPuolue")
        {
            iss>>kasky;
            
            if(!(cpp_yleiset::tarkistaKopiot(puolueLista, kasky.c_str())))
            {
                puolueLista.push_back(Puolue(kasky.c_str(),0));
            }
            
            //lajitellaan puolueet aakkosjärjestykseen
            sort(puolueLista.begin(), puolueLista.end(), Puolue::vertaa);
            
        }
        //lisätään vaalipiiriin komennon mukaiset tiedot
        else if (kasky == "lisaaVaalipiiri")
        {
            //mitä kohtaa syötettä luetaan
            int monesko = 0;
            //jos nimi tai vaalipiiri, jossa monta osaa
            int moniOsainen = 0;
            string vpNimi;
            string valimerkki;
            int edustajienLkm;
            
            while (iss>>kasky)
            {

                //otetaan talteen myös moniosaiset vaalipiirin nimet, 
                //nimien erottimena '/'
                if (kasky != "/")
                {
                if (monesko == 0)
                {
                    if (moniOsainen == 0)
                    {
                        vpNimi += kasky;
                    }
                    else
                    {
                         vpNimi = vpNimi + " " + kasky;
                    }
                }
                else if (monesko == 1)
                {
                    edustajienLkm = atoi(kasky.c_str());
                }

                moniOsainen++;

                }
                else
                {
                    monesko++; 
                    moniOsainen = 0;
                }
            }
        //tarkastetan ettei kopioita, jonka jälkeen 
        //järjestetään aakkosjärjestykseen
        if(!(cpp_yleiset::tarkistaKopiot(vaalipiiriLista, vpNimi.c_str())))
        {
            vaalipiiriLista.push_back(Vaalipiiri(vpNimi.c_str(), edustajienLkm, 0));
        }
        else
        {
            cpp_yleiset::palautaListalta(vaalipiiriLista, vpNimi.c_str()).asetaLkm(edustajienLkm);
        }
        
        sort(vaalipiiriLista.begin(), vaalipiiriLista.end(), Vaalipiiri::vertaaVp);

        }
        
        else if (kasky == "lisaaEhdokas")
        {
          /*otetaan talteen ehdokkaan nimi, puolue, 
            vaalipiiri ja äänimäärä. 
            Poistetaan syötteestä /-merkit */
          string ehdokkaanNimi="";
          string ehdokkaanPuolue = "";
          string ehdokkaanVp = "";
          int ehdokkaanAanet=0;
          //mitä kohtaa syötettä luetaan
          int monesko = 0;
          //jos nimi tai vaalipiiri, jossa monta osaa
          int moniOsainen = 0;
          while (iss>>kasky)
          {

              //tiedetään monesko tietue menossa

              if (kasky != "/")
              {
                if (monesko == 0)
                {
                    if (moniOsainen == 0)
                    {
                        ehdokkaanNimi += kasky;
                    }
                    else
                    {
                         ehdokkaanNimi = ehdokkaanNimi + " " + kasky;
                    }
                }
                else if (monesko == 1)
                {
                    ehdokkaanPuolue = kasky;
                }
                else if (monesko == 2)
                {
                    if (moniOsainen == 0)
                    {
                        ehdokkaanVp += kasky;
                    }
                    else
                    {
                         ehdokkaanVp = ehdokkaanVp +" " + kasky;
                    }
                }
                else if (monesko == 3)
                {
                    ehdokkaanAanet = atoi(kasky.c_str());
                }
                moniOsainen = moniOsainen + 1;
              }
              else if (kasky == "/")
              {
                  monesko = monesko + 1;
                  moniOsainen = 0;
              }
              kasky = "";
              
          }
          
          ehdokasLista.push_back(Ehdokas(ehdokkaanNimi,ehdokkaanPuolue, 
                         ehdokkaanVp,ehdokkaanAanet, false, 0));
      
            sort(ehdokasLista.begin(), ehdokasLista.end(), Ehdokas::vertaa);
            kasky == "";
        }
        
        //lasketaan vaalien tulos
        else if (kasky == "laskeTulos")
        {
            tulosLaskettu = true;
            //asetetaan ehdokkaat jarjestykseen puolue>aanet
            sort(ehdokasLista.begin(), ehdokasLista.end(), Ehdokas::vertaaAanet);

            cpp_yleiset::laskePuolueenAanet(ehdokasLista, puolueLista, vaalipiiriLista);
            sort(ehdokasLista.begin(), ehdokasLista.end(), Ehdokas::vertaaVertailu);  
          
            //muutetaan niiden ehdokkaiden valintastatus, jotka pääsevät läpi
            for (unsigned int i = 0; i<vaalipiiriLista.size(); i++)
            {
                string vaalipiiri = vaalipiiriLista[i].palautaNimi();
                int vaalipiirinEhdokkaat = vaalipiiriLista[i].palautaLkm();
                int apu = 1;
                
                //
                for (unsigned int j = 0; j<ehdokasLista.size(); j++)
                {
                    if (ehdokasLista[j].palautaVaalipiiri() == vaalipiiri && apu<=vaalipiirinEhdokkaat)
                    {
                        ehdokasLista[j].asetaValittu(true);
                        apu++;
                    }
                }
            }
        }
        
        //puolueiden tulostus
        else if (kasky == "puolueet")
        {
          cout<<"Puolueet:"<<endl;
          if(tulosLaskettu == false)
          {
            for(unsigned int i = 0; i < puolueLista.size(); i++){

                cout<<puolueLista[i].palautaNimi()<<endl;
            }
          }
          else
          {
              
              cpp_yleiset::puolueTulostus(puolueLista, ehdokasLista);
          }
        }

        else if (kasky == "vaalipiirit")
        {
            cout<< "Vaalipiirit:"<<endl;
            sort(ehdokasLista.begin(), ehdokasLista.end(), Ehdokas::vertaaNimi);
            cpp_yleiset::vpTulostus(vaalipiiriLista, ehdokasLista, tulosLaskettu);

        }        
        
        else if (kasky == "ehdokkaat")
        {
         //järjestetään vp>puolue>nimi   
         sort(ehdokasLista.begin(), ehdokasLista.end(), Ehdokas::vertaa);             
         cout<< "Ehdokkaat:"<<endl;


            for(unsigned int i =0; i < ehdokasLista.size(); i++){

                //tulostaa listan alkiot
                cout<<ehdokasLista[i].palautaNimi()<<" "<< ehdokasLista[i].palautaPuolue()<<" "
                <<ehdokasLista[i].palautaVaalipiiri()<<" "<< ehdokasLista[i].palauta_Aanet();
                if(ehdokasLista[i].palautaValittu() == true && tulosLaskettu)
                {
                    cout<<" (valittu)"<<endl;
                }
                else
                {
                    cout<<endl;
                }
            
            }
            
        }
        
        else if (kasky == "lopeta")
        {
            lopeta = true;

        }
kasky = "";        
    }
    return 0;
}
