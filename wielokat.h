#ifndef wielokat_hpp
#define wielokat_hpp

class Wielokat {
protected:
	Wielokat *nastepny;
	Wielokat *poprzedni;
public:
	Wielokat();
	virtual Wielokat* getNastepny() = 0;

	virtual ~Wielokat();
};

#endif
