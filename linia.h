#ifndef linia_hpp
#define linia_hpp

#include"punkt.h"


class Linia {
	Punkt p1;
	Punkt p2;
public:
	Linia(Punkt, Punkt);

	Punkt getP1() const;
	Punkt getP2() const;
	void setP1(Punkt);
	void setP2(Punkt);

};

#endif
