#ifndef punkt_hpp
#define punkt_hpp

#include "wielokat.h"

class Punkt : public Wielokat{
	float x;
	float y;
public:
	Punkt(float , float );
	float getX() const;
	float getY() const;
	virtual Wielokat* getNastepny() override;
};

#endif
