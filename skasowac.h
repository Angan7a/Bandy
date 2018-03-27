#ifndef skasowac_hpp
#define skasowac_hpp

class Skasowac {
	char skasowac;
	Skasowac *nastepny;
	Skasowac *poprzedni;
public:
	Skasowac(char skasowac = '0');

	char czySkasowac() const;
	void setSkasowac(char);
        void setNastepny(Skasowac*);
        void setPoprzedni(Skasowac*);

	virtual ~Skasowac();
};

#endif
