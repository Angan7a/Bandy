#include"wielokatDodatni.h"
#include<iostream>

WielokatDodatni::WielokatDodatni() {

}



void WielokatDodatni::wyswietlWynik() {
std::cout << pierwszyPunkt.empty() << std::endl;
if(!pierwszyPunkt.empty()) {
	for(auto itr = pierwszyPunkt.begin(); itr != pierwszyPunkt.end(); ++itr) {
		Punkt* p =  *(itr);
		while(p != nullptr) {
			std::cout << p->getX() << "    " << p->getY() << std::endl;

	//		std::cout << "WIELOKAT DODATNI" <<std::endl;
			p = dynamic_cast<Punkt*> (p->getNastepny());
		}
	}
} else {
	std::cout << "Pusty set" << std::endl;

}
}



WielokatDodatni::~WielokatDodatni(){
}
