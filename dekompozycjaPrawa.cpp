#include"dekompozycjaPrawa.h"
#include<cstring>


void dekompozycjaPrawa(Linia* liniaWyzsza, Linia* liniaNizsza) {
        if(std::strcmp(liniaWyzsza->getSrodekPo(), "prawej") == 0 &&
	   std::strcmp(liniaNizsza->getSrodekPo(), "prawej") == 0 ) {

		Linia* nextLPN = dynamic_cast<Linia*> (liniaNizsza->getNastepny());
		Linia* nextLPW = dynamic_cast<Linia*> (liniaWyzsza->getNastepny());
		Punkt* nextPPN = dynamic_cast<Punkt*> (liniaNizsza->getPunktDalejX()->getNastepny());
		Punkt* nextPPW = dynamic_cast<Punkt*> (liniaWyzsza->getPunktDalejX()->getNastepny());

		Punkt* punktW = dynamic_cast<Punkt*> (liniaWyzsza->getPunktDalejX());
		Punkt* punktN = dynamic_cast<Punkt*> (liniaNizsza->getPunktDalejX());

		liniaNizsza->setPunktDalejX(punktW);
		liniaWyzsza->setPunktDalejX(punktN);

		//flow obwiedni
		liniaNizsza->getPunktBlizejX()->setNastepny(punktW); // punkt
		punktW->setNastepny(nextPPW);  //punkt
		liniaNizsza->setNastepny(nextLPW);  //linia
		//flow do skasowania
		liniaWyzsza->getPunktBlizejX()->setNastepny(punktN); // punkt
		punktN->setNastepny(nextPPN);   //punkt
		liniaWyzsza->setNastepny(nextLPN);  //linia
        } else {

	//
	}



}

