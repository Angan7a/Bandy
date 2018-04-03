#ifndef punkt_hpp
#define punkt_hpp

#include<memory>
using namespace std;

class Punkt {
	float x;
	float y;
	shared_ptr<Punkt> nastepny;
//	Punkt* poprzedni;
public:
	Punkt(float , float, shared_ptr<Punkt> nastepny = nullptr);
	float getX() const;
	float getY() const;


	shared_ptr<Punkt> getNastepny() const;
	void setNastepny(shared_ptr<Punkt>);
//	void setNastepny(Punkt*);
//	void setPoprzedni(Punkt*);
};

#endif
