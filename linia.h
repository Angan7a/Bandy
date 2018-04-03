#ifndef linia_hpp
#define linia_hpp

#include"punkt.h"
//#include"skasowac.h"


class Linia {
	Punkt *p1;
	Punkt *p2;
	Linia* nastepny;
	const char* kierunek;
public:
	Linia(Punkt*, Punkt*, const char*, Linia* nastepny = nullptr);

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
	bool czyPionowa() const;
	Linia* getNastepny() const;
	void setNastepny(Linia*);
};

#endif
