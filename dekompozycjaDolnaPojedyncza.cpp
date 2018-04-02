
#include"dekompozycjaDolnaPojedyncza.h"
#include<cstring>
#include<iostream>


void dekompozycjaDolnaPojedyncza(Linia* itr, Linia* l2) {


	Linia* nextLP = dynamic_cast<Linia*> (itr->getNastepny()->getNastepny());
	Linia* nextLD = dynamic_cast<Linia*> (l2->getNastepny()->getNastepny());
	Punkt* nextPP = dynamic_cast<Punkt*> (itr->getPunktDalejX()->getNastepny()->getNastepny());
	Punkt* nextPD = dynamic_cast<Punkt*> (l2->getPunktR()->getNastepny()->getNastepny());

	Linia* liniaGornaDoSkas = dynamic_cast<Linia*> (itr->getNastepny());
	Linia* liniaDolnaDoSkas = dynamic_cast<Linia*> (l2->getNastepny());

	Punkt* punktLW = dynamic_cast<Punkt*> (itr->getPunktDalejX());
	Punkt* punktPW = dynamic_cast<Punkt*> (liniaDolnaDoSkas->getPunktDalejX());
	Punkt* punktPD = dynamic_cast<Punkt*> (liniaDolnaDoSkas->getPunktBlizejX());
	Punkt* punktPZ = dynamic_cast<Punkt*> (itr->getPunktDalejX()->getNastepny());


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

