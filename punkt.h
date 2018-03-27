#ifndef punkt_hpp
#define punkt_hpp

#include"skasowac.h"

class Punkt : public Skasowac {
	float x;
	float y;
//	Punkt* nastepny;
//	Punkt* poprzedni;
public:
	Punkt(float , float, Punkt* nastepny = nullptr);
	float getX() const;
	float getY() const;


//	Punkt* getNastepny() const;
//	void setNastepny(Punkt*);
//	void setPoprzedni(Punkt*);
};

#endif
