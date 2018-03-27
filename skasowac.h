#ifndef skasowac_hpp
#define skasowac_hpp

class Skasowac {
	char skasowac;
protected:
	Skasowac *nastepny;
public:
	Skasowac(Skasowac* n = nullptr, char skasowac = '0');

	char getSkasowac() const;
	void setSkasowac(char);

        Skasowac* getNastepny() const;
        void setNastepny(Skasowac*);

	virtual ~Skasowac();
};

#endif
