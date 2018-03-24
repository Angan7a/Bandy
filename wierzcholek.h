#ifndef wierzcholek_hpp
#define wierzcholek_hpp

#include"linia.h"
#include"punkt.h"


class Wierzcholek {
	Punkt p;
	Linia *l1;
	Linia *l2;
	Wierzcholek *nastepny;
	Wierzcholek *poprzedni;
public:
	Wierzcholek(Punkt, Linia*, Linia*, Wierzcholek*, Wierzcholek*);

};

#endif
