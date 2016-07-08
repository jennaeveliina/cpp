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
        
        //rakentaja ja tuhoaja esittelyt
        Ehdokas(std::string Enimi, std::string Epuolue, 
                std::string Evaalipiiri, int Eaanet, bool valittu, double vertailu );
        ~Ehdokas();
        
        //getterit ja setterit esittelyt
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
}
#endif
