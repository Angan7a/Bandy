#include"linia.h"


Linia::Linia(Punkt* p1, Punkt* p2, const char* kierunek, Linia* nastepny) : p1(p1), p2(p2), kierunek(kierunek), nastepny(nastepny) {

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

const char* Linia::getSrodekPo() {
	return kierunek;
}

Punkt* Linia::getPunktBlizejX() const {
	if(this->getP1()->getY() < this->getP2()->getY()) {
		return this->getP1();
	}
	return this->getP2();
}

Punkt* Linia::getPunktDalejX() const {
	if(this->getP1()->getY() > this->getP2()->getY()) {
		return this->getP1();
	}
	return this->getP2();
}

void Linia::setPunktBlizejX(Punkt* p) {
	if(p1->getY() < p2->getY()){
		p1 = p;
	} else {
		p2 = p;
	}
}

void Linia::setPunktDalejX(Punkt* p) {
	if(p1->getY() < p2->getY()){
		p2 = p;
	} else {
		p1 = p;
	}

}

Punkt* Linia::getPunktL() const {
	if(this->getP1()->getX() < this->getP2()->getX()) {
		return this->getP1();
	}
	return this->getP2();
}

Punkt* Linia::getPunktR() const {
	if(this->getP1()->getX() > this->getP2()->getX()) {
		return this->getP1();
	}
	return this->getP2();
}

void Linia::setPunktL(Punkt* p) {
	if(p1->getX() < p2->getX()){
		p1 = p;
	} else {
		p2 = p;
	}
}

void Linia::setPunktR(Punkt* p) {
	if(p1->getX() < p2->getX()){
		p2 = p;
	} else {
		p1 = p;
	}
}

bool Linia::czyPionowa() const {
	if(this->getP1()->getX() == this->getP2()->getX()) {
		return 1;
	}
	return 0;
}

Linia* Linia::getNastepny() const{
	return nastepny;
}

void Linia::setNastepny(Linia* linia){
	nastepny = linia;
}
