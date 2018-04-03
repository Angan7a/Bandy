#ifndef linia_hpp
#define linia_hpp

#include"punkt.h"
#include<memory>
using namespace std;

class Linia {
	shared_ptr<Punkt> p1;
	shared_ptr<Punkt> p2;
	Linia* nastepny;
	const char* kierunek;
public:
	Linia(shared_ptr<Punkt>, shared_ptr<Punkt>, const char*, Linia* nastepny = nullptr);

	shared_ptr<Punkt> getP1() const;
	shared_ptr<Punkt> getP2() const;
	void setP1(shared_ptr<Punkt>);
	void setP2(shared_ptr<Punkt>);
	const char* getSrodekPo();
	shared_ptr<Punkt> getPunktBlizejX() const;
	shared_ptr<Punkt> getPunktDalejX() const;
	void setPunktBlizejX(shared_ptr<Punkt>);
	void setPunktDalejX(shared_ptr<Punkt>);
	shared_ptr<Punkt> getPunktL() const;
	shared_ptr<Punkt> getPunktR() const;
	void setPunktL(shared_ptr<Punkt>);
	void setPunktR(shared_ptr<Punkt>);
	bool czyPionowa() const;
	Linia* getNastepny() const;
	void setNastepny(Linia*);
};

#endif
