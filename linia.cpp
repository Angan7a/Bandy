#include"linia.h"


Linia::Linia(Punkt* p1, Punkt* p2, const char* kierunek) : p1(p1), p2(p2), kierunek(kierunek) {

}

Punkt* Linia::getP1() const {
	return p1;
}

Punkt* Linia::getP2() const {
	return p2;
}

void Linia::setP1(Punkt* p) {
	p1 = p;
}

void Linia::setP2(Punkt* p) {
	p2 = p;
}


