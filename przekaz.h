#ifndef przekaz_hpp
#define przekaz_hpp

#include<memory>
#include"linia.h"
using namespace std;

class Przekaz {
	shared_ptr<Linia> pierwszy;
	shared_ptr<Linia> drugi;
public:
	Przekaz();

	shared_ptr<Linia> getPrzekazPierwszy() const;
	shared_ptr<Linia> getPrzekazDrugi() const;
	void setPrzekazPierwszy(shared_ptr<Linia>);
	void setPrzekazDrugi(shared_ptr<Linia>);
};

#endif
