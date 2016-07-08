/* c++ harjoitustyö
 * 
 * Jenna Halmetoja
 * Tampereen yliopisto, syksy 2015
 */
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
}

#endif
