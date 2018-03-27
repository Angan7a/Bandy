#include"punkt.h"

Punkt::Punkt(float x, float y, Punkt* nastepny, Punkt* poprzedni) : x(x), y(y), nastepny(nastepny), poprzedni(poprzedni) {

}

float Punkt::getX() const {
	return x;
}

float Punkt::getY() const {
	return y;
}

Punkt* Punkt::getNastepny() const {
	return nastepny;
}

void Punkt::setNastepny(Punkt* p) {
	nastepny = p;
}

void Punkt::setPoprzedni(Punkt* p) {
	nastepny = p;
}
