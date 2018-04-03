#include"punkt.h"
using namespace std;

Punkt::Punkt(float x, float y, shared_ptr<Punkt> nastepny) : x(x), y(y), nastepny(nastepny) {

}

float Punkt::getX() const {
	return x;
}

float Punkt::getY() const {
	return y;
}

shared_ptr<Punkt> Punkt::getNastepny() const {
	return nastepny;
}

void Punkt::setNastepny( shared_ptr<Punkt> p) {
	nastepny = p;
}
/*
void Punkt::setPoprzedni(Punkt* p) {
	nastepny = p;
}
*/
