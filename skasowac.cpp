#include "skasowac.h"

Skasowac::Skasowac(Skasowac* n, char w) : skasowac(w), nastepny(n) {
}

char Skasowac::czySkasowac() const {
	return skasowac;
}

void Skasowac::setSkasowac(char w) {
	skasowac = w;
}


Skasowac* Skasowac::getNastepny() const {
        return nastepny;
}

void Skasowac::setNastepny(Skasowac* p) {
        nastepny = p;
}




Skasowac::~Skasowac() {
}

