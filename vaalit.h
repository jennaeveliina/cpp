/* c++ harjoitustyö
 * 
 * Jenna Halmetoja
 * Tampereen yliopisto, syksy 2015
 */
#ifndef VAALITT
#define VAALITT
#include <string>
#include <vector>
using namespace std;
namespace cpp_puolue
{
    class Puolue{

        std::string lyhenne;
        int paikkoja;
        double vertailu;
        
        public:        
        Puolue(std::string nimi, double vertaa);
        ~Puolue();
        
        void asetaNimi(std::string syote);
        std::string palautaNimi();
        void asetaPaikat(int syote);
        int palautaPaikat();
        void asetaVertailu (double a);    
        double palautaVertailu();
        static bool vertaaPuolue(const Puolue &a, const Puolue &b);  
    };
    
    //puolue luokan toteutus
    string lyhenne;
    int paikkoja;
    double vertailu;
    
    Puolue::Puolue(string nimi, double verta)
    {
        lyhenne = nimi;
        vertailu = verta;
    }
    Puolue::~Puolue()
    {
        
    }
    void Puolue::asetaNimi(string syote)
    {
        lyhenne = syote;
    }
    string Puolue::palautaNimi()
    {
        return lyhenne;
    }
    
    void Puolue::asetaVertailu (double a)
    {
        vertailu = a;
    }
    
    double Puolue::palautaVertailu()
    {
        return vertailu;
    }
    void Puolue::asetaPaikat(int syote)
    {
        paikkoja = syote;
    }
    
    int Puolue::palautaPaikat()
    {
        return paikkoja;
    }
    bool Puolue::vertaaPuolue(const Puolue &a, const Puolue &b)
    {
        return (a.lyhenne < b.lyhenne);
    }
}

//Vaalipiirin esittely
namespace cpp_vaalipiiri
{
    class Vaalipiiri
    {
      
        public:
        std::string nimi;
        int lkm;
        double vertailu;
        
        Vaalipiiri(string syoteNimi, int syoteLkm, double vertailu);
        ~Vaalipiiri();
        void asetaNimi(std::string syote);
        void asetaVertailu(double syote);
        void asetaLkm (int maara);
        std::string palautaNimi(); 
        int palautaLkm();
        double palautaVertailu();
        static bool vertaaVp(const Vaalipiiri &a, const Vaalipiiri &b);
        
    };
    //vaalipiirin toteutus    
    string nimi;
    int lkm = 0;
    double vertailu;
    
    
  
    Vaalipiiri::Vaalipiiri(string syoteNimi, int syoteLkm, double vertailuLuku)
    {
       nimi = syoteNimi;
       lkm = syoteLkm;
       vertailu = vertailuLuku;
    }
    Vaalipiiri::~Vaalipiiri()
    {
        
    }
    void Vaalipiiri::asetaNimi(string syote)
    {
        nimi = syote;
    }
    void Vaalipiiri::asetaLkm (int maara)
    {
        lkm = maara;
    }
   
    void Vaalipiiri::asetaVertailu(double syote)
    {
        vertailu = syote;
    }
    
    double Vaalipiiri::palautaVertailu()
    {
        return vertailu;
    }
    
    string Vaalipiiri::palautaNimi()
    {
        return nimi;
    }
    int Vaalipiiri::palautaLkm()
    {
        return lkm;
    }
    //
    bool Vaalipiiri::vertaaVp(const Vaalipiiri &a, const Vaalipiiri &b)
    {
       return (a.nimi < b.nimi); 
    }
        
        
}
//Ehdokasluokan esittely
namespace cpp_ehdokas
{
    class Ehdokas
    {
        
        public:
        std::string nimi;
        std::string puolue;
        std::string vaalipiiri;
        double aanet;
        bool valittu;
        double vertailu;

        Ehdokas(std::string Enimi, std::string Epuolue, 
                std::string Evaalipiiri, int Eaanet, bool valittu, double vertailu );
        ~Ehdokas();
        void asetaValittu(bool tulos);
        void asetaVertailu(double tulos);
        void asetaNimi(std::string nimiSyote);
        void asetaPuolue(std::string syote);
        void asetaVaalipiiri(std::string vp);
        void aseta_Aanet(double aanet);
        bool palautaValittu();
        std::string palautaNimi();
        std::string palautaPuolue();
        std::string palautaVaalipiiri();
        double palauta_Aanet();
        double palautaVertailu();
        static bool vertaaEhdokas(const Ehdokas &a, const Ehdokas &b);
        static bool vertaaNimi(const Ehdokas &a, const Ehdokas &b);
        static bool vertaaAanet(const Ehdokas &a, const Ehdokas &b);
        static bool vertaaVertailu(const Ehdokas &a, const Ehdokas &b);

    };
       
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

//yleisfunktioita, selkeyden vuoksi omassa namespacessaan
namespace cpp_yleiset{

    //tarkistetaan onko nimi jo lisätty listalle
    template<typename T>
    bool tarkistaKopiot(std::vector<T> &lista, string a)
    {
        bool loytyyListalta = false;
        if (lista.size() > 0){
            for (unsigned int i = 0; i<lista.size(); i++)
            {
                if (lista[i].palautaNimi() == a)
                {
                    loytyyListalta = true;
                }
                
            }
        }
        return loytyyListalta;
    }
    
    //lasketaan äänet puolueiden sisällä vaalipiireittäin
    template <typename T, typename Y, typename R>        
    void laskePuolueenAanet(vector<T> &ehdokasLista, vector<Y> &puolueLista, vector<R> &Vpiiri)
    {
        //vaalipiiri kerrallaan, lasketaan puolueiden saamat äänet
        for (unsigned int i=0; i<Vpiiri.size(); i++)
        {
            string vp = Vpiiri[i].palautaNimi();
            for (unsigned int j = 0; j<puolueLista.size(); j++)
            {
                double yhteisAanet = 0;
                string nykyinenPuolue = puolueLista[j].palautaNimi();
                for (unsigned int k = 0; k<ehdokasLista.size(); k++)
                {
                    if (ehdokasLista[k].palautaPuolue() == nykyinenPuolue && ehdokasLista[k].palautaVaalipiiri() == vp)
                    {
                        yhteisAanet += ehdokasLista[k].palauta_Aanet();
                    }
                }
                double jarjestysLuku = 1;
                for (unsigned int l = 0; l<ehdokasLista.size(); l++)
                {
                    if (ehdokasLista[l].palautaPuolue() == nykyinenPuolue && ehdokasLista[l].palautaVaalipiiri() == vp)  
                    {
                        ehdokasLista[l].asetaVertailu(yhteisAanet/jarjestysLuku);
                        jarjestysLuku++;
                    }
                }
            }
        }
    }
    
    //tulostetaan vaalipiirit, jos edustajia useampi lykätään perään "(edustajaa)" 
    //ja jos yksi niin "(edustaja)"
    template <typename T, typename Y>
    void vpTulostus(vector <T> &vpLista, vector <Y> &eLista, bool tulosLaskettu)
    {
        for(unsigned int i = 0; i < vpLista.size(); i++)
        {
            if(vpLista[i].palautaLkm() > 1)
            {
                cout << vpLista[i].palautaNimi()<< " (" << vpLista[i].palautaLkm() <<" edustajaa)"<<endl;
            }
            else
            {
                cout <<  vpLista[i].palautaNimi()<< " (" << vpLista[i].palautaLkm() <<" edustaja)"<<endl;
            } 
            
            for(unsigned int j = 0; j < eLista.size(); j++)
            {
                if (vpLista[i].palautaNimi() == eLista[j].palautaVaalipiiri() && eLista[j].palautaValittu() == true) 
                {
                    cout<<"  "<<eLista[j].palautaNimi()<<" "<<eLista[j].palautaPuolue()<< " "<< eLista[j].palauta_Aanet()<<endl;
                }                
            }
        
        }
    }
    
    //tulostetaan puolueen ehdokkaat
    template <typename T, typename Y>
    void puolueTulostus(vector <T> &puolue, vector <Y> &valitutEhdokkaat)
    {
        //lasketaan puolueen hyväksytyt ehdokkaat
        for (unsigned int i=0; i<puolue.size(); i++)
        { 
            int aania = 0;
            string tarkasteltava = puolue[i].palautaNimi();
            
            //lasketaan puolueen max äänet
            for(unsigned int j = 0; j<valitutEhdokkaat.size(); j++)
            {
                if (valitutEhdokkaat[j].palautaPuolue() == tarkasteltava && valitutEhdokkaat[j].palautaValittu() == true )
                {
                    aania++;
                }
                
            }
            //ehdokkaat äänet suluissa
            cout<<tarkasteltava<<" ("<<aania<<")"<<endl;
            
            //jos tarkasteltava puolue on sama kuin puolue vectorissa ja jos ehdokas valittu
            //tulostetaan valitu ehdokkaat>vaalipiiri>äänet välilyönnein eroteltuna
            for (unsigned int k = 0; k<valitutEhdokkaat.size(); k++)
            {
                if (valitutEhdokkaat[k].palautaPuolue() == tarkasteltava && valitutEhdokkaat[k].palautaValittu() == true )
                {
                    cout<<"  "<<valitutEhdokkaat[k].palautaNimi()<<" "<<valitutEhdokkaat[k].palautaVaalipiiri()<<" "<<valitutEhdokkaat[k].palauta_Aanet()<<endl;
                }
                
            }
        }
    }
}
    

#endif
