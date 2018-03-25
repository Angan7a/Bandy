#ifndef wierzcholek_hpp
#define wierzcholek_hpp

#include"linia.h"
#include"punkt.h"


class Wierzcholek {
	Punkt *p;
	Linia *l1;
	Linia *l2;
	Wierzcholek *nastepny;
	Wierzcholek *poprzedni;
public:
	Wierzcholek(Punkt* p, Linia* l1, Linia* l2 = nullptr, Wierzcholek* nastepny = nullptr, Wierzcholek* poprzedni = nullptr);
	void setNastepny(Wierzcholek*);
	void setPoprzedni(Wierzcholek*);
};

#endif
