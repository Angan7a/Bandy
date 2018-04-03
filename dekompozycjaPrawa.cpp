#include"dekompozycjaPrawa.h"
#include<cstring>
#include<memory>
using namespace std;

void dekompozycjaPrawa(Linia* liniaWyzsza, Linia* liniaNizsza) {
        if(std::strcmp(liniaWyzsza->getSrodekPo(), "prawej") == 0 &&
	   std::strcmp(liniaNizsza->getSrodekPo(), "prawej") == 0 ) {

		Linia* nextLPN = liniaNizsza->getNastepny();
		Linia* nextLPW = liniaWyzsza->getNastepny();
		shared_ptr<Punkt> nextPPN = liniaNizsza->getPunktDalejX()->getNastepny();
		shared_ptr<Punkt> nextPPW = liniaWyzsza->getPunktDalejX()->getNastepny();

		shared_ptr<Punkt> punktW = liniaWyzsza->getPunktDalejX();
		shared_ptr<Punkt> punktN = liniaNizsza->getPunktDalejX();

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
                shared_ptr<Punkt> ps = make_shared<Punkt>(x, y);
         //       Skasowac* ng = new Linia(ps, itr->getPunktBlizejX(), "lewej");
                Linia* nowaLiniaDolna = new Linia(ps, itr->getPunktBlizejX(), "lewej");

		Linia* nextLPW = l1->getNastepny();
		Linia* nextLPN = itr->getNastepny();
		shared_ptr<Punkt> nextPPW = l1->getPunktDalejX()->getNastepny();
		shared_ptr<Punkt> nextPPN = itr->getPunktBlizejX()->getNastepny();

		shared_ptr<Punkt> punktW = l1->getPunktDalejX();
		shared_ptr<Punkt> punktN = itr->getPunktBlizejX();

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

