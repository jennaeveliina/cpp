/* c++ harjoitustyö
 * 
 * Jenna Halmetoja
 * Tampereen yliopisto, syksy 2015
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include "vaalit.h"
namespace cpp_ehdokas
{
   //ehdokas toteutus
    std::string nimi;
    std::string puolue;
    std::string vaalipiiri;
    double aanet;
    bool valittu = false;
    double vertailu;

    //rakentaja ja tuhoaja
    Ehdokas::Ehdokas(std::string Enimi, std::string Epuolue, 
                     std::string Evaalipiiri, int Eaanet, bool valinta, double verr)
    {
        nimi = Enimi;
        puolue = Epuolue;
        vaalipiiri = Evaalipiiri;
        aanet = Eaanet;
        valittu = valinta;
        vertailu  = verr;
    }
    Ehdokas::~Ehdokas()
    {
    }
    
    //getterit ja setterit
    void Ehdokas::asetaValittu(bool tulos)
    {
        valittu = tulos;
    }
    
    void Ehdokas::asetaNimi(std::string nimiSyote)
    {
        nimi = nimiSyote;
    }
    
    void Ehdokas::asetaPuolue(std::string syote)
    {
        puolue = syote;
    }
    
    void Ehdokas::asetaVaalipiiri(std::string vp)
    {
        vaalipiiri = vp;
    }
    
    void Ehdokas::aseta_Aanet(double aanimaara)
    {
        aanet = aanimaara;
    }
    
    bool Ehdokas::palautaValittu()
    {
        return valittu;
    }  
          
    void Ehdokas::asetaVertailu(double vert)
    {
        vertailu = vert;
    }
    
    double Ehdokas::palautaVertailu()
    {
        return vertailu;
    }
    
    std::string Ehdokas::palautaNimi()
    {
        return nimi;
    }
    
    std::string Ehdokas::palautaPuolue()
    {
        return puolue;
    }
    
    std::string Ehdokas::palautaVaalipiiri()
    {
        return vaalipiiri;
    }
    
    double Ehdokas::palauta_Aanet()
    {
        return aanet;
    }

    //vertaillaan ehdokkaisen nimiä
    bool Ehdokas::vertaaEhdokas(const Ehdokas &a, const Ehdokas &b)
    {  
        if (a.vaalipiiri != b.vaalipiiri)
        {
           return (a.vaalipiiri < b.vaalipiiri);
        }
        else if (a.puolue != b.puolue)
        {
           return (a.puolue < b.puolue);
        }
        else
        {
            return (a.nimi < b.nimi);
        }
    }
    
    //vertaillaan vertailulukuja kun äänet on laskettu
    bool Ehdokas::vertaaVertailu(const Ehdokas &a, const Ehdokas &b)
    {
        if (a.vaalipiiri != b.vaalipiiri)
        {
            return a.vaalipiiri < b.vaalipiiri;
        }
        else
        {
            return a.vertailu > b.vertailu;
        }
    }
           
    //vertaillaan ehdokkaita nimen mukaan
    bool Ehdokas::vertaaNimi(const Ehdokas &a, const Ehdokas &b)
    {
        if(a.puolue != b.puolue)
        {
            return a.nimi<b.nimi;
        }
        else
        {
            return a.puolue<b.puolue;
        }
    }
    
    //vertaillaan ehdokkaiden ääniä
    bool Ehdokas::vertaaAanet(const Ehdokas &a, const Ehdokas &b)
    {
        if (a.puolue == b.puolue)
        {
            return a.aanet > b.aanet;
        }
        else
        {
            return a.puolue > b.puolue;
        }   
    }
}
