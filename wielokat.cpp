#include "wielokat.h"
#include <iostream>

Wielokat::Wielokat() {

}

void Wielokat::dodaj(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y, int p4x, int p4y) {

	Skasowac *p11 = new Punkt(p1x, p1y);
	Skasowac *p22 = new Punkt(p2x, p2y);
	Skasowac *p33 = new Punkt(p3x, p3y);
	Skasowac *p44 = new Punkt(p4x, p4y);
	Punkt* p1 = dynamic_cast<Punkt*>(p11);
	Punkt* p2 = dynamic_cast<Punkt*>(p22);
	Punkt* p3 = dynamic_cast<Punkt*>(p33);
	Punkt* p4 = dynamic_cast<Punkt*>(p44);


	Skasowac *l11 = new Linia(p1, p2, "prawej");
	Skasowac *l22 = new Linia(p2, p3, "dol");
	Skasowac *l33 = new Linia(p3, p4, "lewej");
	Linia* l1 = dynamic_cast<Linia*>(l11);
	Linia* l2 = dynamic_cast<Linia*>(l22);
	Linia* l3 = dynamic_cast<Linia*>(l33);

	p1->setNastepny(p2);
        p2->setNastepny(p3);
        p3->setNastepny(p4);

        l1->setNastepny(l2);
        l2->setNastepny(l3);

        liniePoziome.insert( l2 );
        liniePionowe.insert( l1 );
        liniePionowe.insert( l3 );

	if(pierwszyPunkt.empty()) {
        	pierwszyPunkt.insert(p1);
                pierwszaLinia.insert(l1);
	} else {
		for(auto it = liniePionowe.begin(); it != liniePionowe.end(); ++it) {
			std::cout << (*it)->getPunktBlizejX()->getX() <<std::endl;
		}
		std::cout << "BadamL1" << std::endl;
		zbadajL1(l1);
		std::cout << "BadamL2" << std::endl;
		zbadajL2(l1, l2, l3);
		std::cout << "BadamL3" << std::endl;
		zbadajL3(l3);
		std::cout << "Sakuje punkty i linie" << std::endl;
		skasujNiepotrzebneLIP(l1, p1);
	}
//	wyswietlWynik();

}



Wielokat::~Wielokat() {

}
