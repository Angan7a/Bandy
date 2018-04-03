#include"dekompozycjaPrawa.h"
#include<cstring>


void dekompozycjaPrawa(Linia* liniaWyzsza, Linia* liniaNizsza) {
        if(std::strcmp(liniaWyzsza->getSrodekPo(), "prawej") == 0 &&
	   std::strcmp(liniaNizsza->getSrodekPo(), "prawej") == 0 ) {

		Linia* nextLPN = liniaNizsza->getNastepny();
		Linia* nextLPW = liniaWyzsza->getNastepny();
		Punkt* nextPPN = liniaNizsza->getPunktDalejX()->getNastepny();
		Punkt* nextPPW = liniaWyzsza->getPunktDalejX()->getNastepny();

		Punkt* punktW = liniaWyzsza->getPunktDalejX();
		Punkt* punktN = liniaNizsza->getPunktDalejX();

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

           //     Skasowac* psq = new Punkt(x, y);
                Punkt* ps = new Punkt(x, y);
         //       Skasowac* ng = new Linia(ps, itr->getPunktBlizejX(), "lewej");
                Linia* nowaLiniaDolna = new Linia(ps, itr->getPunktBlizejX(), "lewej");

		Linia* nextLPW = l1->getNastepny();
		Linia* nextLPN = itr->getNastepny();
		Punkt* nextPPW = l1->getPunktDalejX()->getNastepny();
		Punkt* nextPPN = itr->getPunktBlizejX()->getNastepny();

		Punkt* punktW = l1->getPunktDalejX();
		Punkt* punktN = itr->getPunktBlizejX();

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

