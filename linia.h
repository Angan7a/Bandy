#ifndef linia_hpp
#define linia_hpp

#include"punkt.h"
#include"wielokat.h"


class Linia : public Wielokat {
	Punkt *p1;
	Punkt *p2;
	const char* kierunek;
public:
	Linia(Punkt*, Punkt*, const char*);

	Punkt* getP1() const;
	Punkt* getP2() const;
	void setP1(Punkt*);
	void setP2(Punkt*);
	virtual Wielokat* getNastepny() override;
};

#endif
