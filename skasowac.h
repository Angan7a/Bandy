#ifndef skasowac_hpp
#define skasowac_hpp

class Skasowac {
	char skasowac;
public:
	Skasowac(char skasowac = '0');
	char czySkasowac() const;
	void setSkasowac(char);
	virtual ~Skasowac();
};

#endif
