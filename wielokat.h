#ifndef wielokat_hpp
#define wielokat_hpp
#include<set>
#include"linia.h"
#include"punkt.h"
#include"skasowac.h"

using namespace std;







class Wielokat {
protected:
//static constexpr auto cmpPunkty = [](Punkt* a, Punkt* b) { return a->getX() < b->getX(); };
struct cmpPionowe {
    bool operator() (const Linia* a, const Linia* b) const {
	return a->getPunktBlizejX()->getX() < b->getPunktBlizejX()->getX() || a->getPunktDalejX()->getY() < b->getPunktDalejX()->getY();
    }
};

struct cmpPoziome {
    bool operator() (const Linia* a, const Linia* b) const {
	return a->getPunktL()->getX() < b->getPunktL()->getX() ||  a->getPunktL()->getY() < b->getPunktL()->getY();
    }
};
struct cmpPunkty {
    bool operator() (const Punkt* a, const Punkt* b) const {
	return a->getX() < b->getX() || a->getY() < b->getY();
    }
};


        set<Punkt*, cmpPunkty> pierwszyPunkt;
        set<Linia*, cmpPionowe> pierwszaLinia;
        set<Linia*, cmpPionowe> liniePionowe;
        set<Linia*, cmpPoziome> liniePoziome;
public:
/*bool fncomp (Linia* a, Linia* b) {
	return a->getPunktBlizejX()->getX() < b->getPunktBlizejX()->getX() || a->getPunktDalejX()->getY() < b->getPunktDalejX()->getY();}
	 bool(*fn_pt)(Linia*,Linia*) = fncomp;
*/
	Wielokat();
	void dodaj(int, int, int, int, int, int, int, int);
	void zbadajL1(Linia*);
	void zbadajL2(Linia*, Linia*, Linia*);
	void zbadajL3(Linia*);
	void skasujNiepotrzebneLIP(Linia*, Punkt*);
	virtual void wyswietlWynik()=0;
	virtual ~Wielokat();
};

#endif
