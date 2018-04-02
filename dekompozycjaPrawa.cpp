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
        } else if(std::strcmp(liniaWyzsza->getSrodekPo(), "prawej") == 0 &&
	          std::strcmp(liniaNizsza->getSrodekPo(), "lewej") == 0 ) {

		Linia* l1 = liniaWyzsza;
		Linia* itr = liniaNizsza;

                float x = l1->getPunktDalejX()->getX();
                float y = l1->getPunktDalejX()->getY();

                Skasowac* psq = new Punkt(x, y);
                Punkt* ps = dynamic_cast<Punkt*>(psq);
                Skasowac* ng = new Linia(ps, itr->getPunktBlizejX(), "lewej");
                Linia* nowaLiniaDolna = dynamic_cast<Linia*>(ng);

		Linia* nextLPW = dynamic_cast<Linia*> (l1->getNastepny());
		Linia* nextLPN = dynamic_cast<Linia*> (itr->getNastepny());
		Punkt* nextPPW = dynamic_cast<Punkt*> (l1->getPunktDalejX()->getNastepny());
		Punkt* nextPPN = dynamic_cast<Punkt*> (itr->getPunktBlizejX()->getNastepny());

		Punkt* punktW = dynamic_cast<Punkt*> (l1->getPunktDalejX());
		Punkt* punktN = dynamic_cast<Punkt*> (itr->getPunktBlizejX());

		itr->setPunktBlizejX(punktW);
		l1->setPunktDalejX(ps);

		//flow obwiedni
		itr->getPunktDalejX()->setNastepny(punktW); // punkt
		punktW->setNastepny(nextPPW);  //punkt
		itr->setNastepny(nextLPW);  //linia
		//flow do skasowania
		l1->getPunktBlizejX()->setNastepny(ps); // punkt
		ps->setNastepny(punktN); //punkt
		punktN->setNastepny(nextPPN);   //punkt
		l1->setNastepny(nowaLiniaDolna);  //linia
		nowaLiniaDolna->setNastepny(nextLPN);  //linia
	}

}

