
#include"dekompozycjaDolnaPojedyncza.h"
#include<cstring>
#include<iostream>
#include<memory>
using namespace std;

void dekompozycjaDolnaPojedyncza(Linia* itr, Linia* l2) {


	Linia* nextLP = itr->getNastepny()->getNastepny();
	Linia* nextLD = l2->getNastepny()->getNastepny();
	shared_ptr<Punkt> nextPP = itr->getPunktDalejX()->getNastepny()->getNastepny();
	shared_ptr<Punkt> nextPD = l2->getPunktR()->getNastepny()->getNastepny();

	Linia* liniaGornaDoSkas = itr->getNastepny();
	Linia* liniaDolnaDoSkas = l2->getNastepny();

	shared_ptr<Punkt> punktLW = itr->getPunktDalejX();
	shared_ptr<Punkt> punktPW = liniaDolnaDoSkas->getPunktDalejX();
	shared_ptr<Punkt> punktPD = liniaDolnaDoSkas->getPunktBlizejX();
	shared_ptr<Punkt> punktPZ = itr->getPunktDalejX()->getNastepny();


	liniaGornaDoSkas->setPunktR(punktPW);
	liniaGornaDoSkas->setPunktL(punktLW);
	liniaDolnaDoSkas->setPunktDalejX(punktPW);
	liniaDolnaDoSkas->setPunktBlizejX(punktPD);
	l2->setPunktR(punktPZ);

	//flow obwiedni
	l2->getPunktL()->setNastepny(punktPZ); // punkt
	punktPZ->setNastepny(nextPP);  //punkt
	l2->setNastepny(nextLP);  //linia
	//flow do skasowania
	itr->getPunktBlizejX()->setNastepny(punktLW); // punkt
	punktLW->setNastepny(punktPW);   //punkt
	punktPW->setNastepny(punktPD);   //punkt
	punktPD->setNastepny(nextPD);   //punkt
	itr->setNastepny(liniaGornaDoSkas);  //linia
	liniaGornaDoSkas->setNastepny(liniaDolnaDoSkas); //linia
	liniaDolnaDoSkas->setNastepny(nextLD); //linia

}

