#include "skasowac.h"

Skasowac::Skasowac(char w) : skasowac(w) {
}

char Skasowac::czySkasowac() const {
	return skasowac;
}

void Skasowac::setSkasowac(char w) {
	skasowac = w;
}

Skasowac::~Skasowac() {
}

