#ifndef linia_hpp
#define linia_hpp

#include"punkt.h"
#include"skasowac.h"


class Linia : public Skasowac {
	Punkt *p1;
	Punkt *p2;
	const char* kierunek;
public:
	Linia(Punkt*, Punkt*, const char*);

	Punkt* getP1() const;
	Punkt* getP2() const;
	void setP1(Punkt*);
	void setP2(Punkt*);
	const char* getSrodekPo();
	Punkt* getPunktBlizejX() const;
	Punkt* getPunktDalejX() const;
	void setPunktBlizejX(Punkt*);
	void setPunktDalejX(Punkt*);
	Punkt* getPunktL() const;
	Punkt* getPunktR() const;
	void setPunktL(Punkt*);
	void setPunktR(Punkt*);
};

#endif
