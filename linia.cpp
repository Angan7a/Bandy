#include"linia.h"
using namespace std;

Linia::Linia(shared_ptr<Punkt> p1, shared_ptr<Punkt> p2, const char* kierunek, shared_ptr<Linia> nastepny) : p1(p1), p2(p2), kierunek(kierunek), nastepny(nastepny) {

}

shared_ptr<Punkt> Linia::getP1() const {
	return p1;
}

shared_ptr<Punkt> Linia::getP2() const {
	return p2;
}

void Linia::setP1(shared_ptr<Punkt> p) {
	p1 = p;
}

void Linia::setP2(shared_ptr<Punkt> p) {
	p2 = p;
}

const char* Linia::getSrodekPo() {
	return kierunek;
}

shared_ptr<Punkt> Linia::getPunktBlizejX() const {
	if(this->getP1()->getY() < this->getP2()->getY()) {
		return this->getP1();
	}
	return this->getP2();
}

shared_ptr<Punkt> Linia::getPunktDalejX() const {
	if(this->getP1()->getY() > this->getP2()->getY()) {
		return this->getP1();
	}
	return this->getP2();
}

void Linia::setPunktBlizejX(shared_ptr<Punkt> p) {
	if(p1->getY() < p2->getY()){
		p1 = p;
	} else {
		p2 = p;
	}
}

void Linia::setPunktDalejX(shared_ptr<Punkt> p) {
	if(p1->getY() < p2->getY()){
		p2 = p;
	} else {
		p1 = p;
	}

}

shared_ptr<Punkt> Linia::getPunktL() const {
	if(this->getP1()->getX() < this->getP2()->getX()) {
		return this->getP1();
	}
	return this->getP2();
}

shared_ptr<Punkt> Linia::getPunktR() const {
	if(this->getP1()->getX() > this->getP2()->getX()) {
		return this->getP1();
	}
	return this->getP2();
}

void Linia::setPunktL(shared_ptr<Punkt> p) {
	if(p1->getX() < p2->getX()){
		p1 = p;
	} else {
		p2 = p;
	}
}

void Linia::setPunktR(shared_ptr<Punkt> p) {
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

shared_ptr<Linia> Linia::getNastepny() const{
	return nastepny;
}

void Linia::setNastepny(shared_ptr<Linia> linia){
	nastepny = linia;
}
