/* c++ harjoitustyö
 * 
 * Jenna Halmetoja
 * Tampereen yliopisto, syksy 2015
 */
#ifndef VAALIT_H
#define VAALIT_H
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
}
#endif
