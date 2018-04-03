#include"przekaz.h"

#include<memory>
using namespace std;

Przekaz::Przekaz() {
}

shared_ptr<Linia> Przekaz::getPrzekazPierwszy() const {
	return pierwszy;
}

shared_ptr<Linia> Przekaz::getPrzekazDrugi() const {
	return drugi;
}

void Przekaz::setPrzekazPierwszy(shared_ptr<Linia> p) {
	pierwszy = p;
}

void Przekaz::setPrzekazDrugi(shared_ptr<Linia> p) {
	drugi = p;
}

