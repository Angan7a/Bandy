#include"dekompozycjaLewa.h"
#include<cstring>
#include<memory>
using namespace std;

Linia* dekompozycjaLewa(Linia* l1, Linia* itr) {
//        if(std::strcmp(liniaWyzsza->getSrodekPo(), "prawej") == 0 &&
//	   std::strcmp(liniaNizsza->getSrodekPo(), "lewej") == 0 ) {

	      	float x = itr->getPunktR()->getX();
       		float y = itr->getPunktR()->getY();

//	        Skasowac* poq = new Punkt(x, y);
        	shared_ptr<Punkt> po = make_shared<Punkt>(x, y);
         //       Skasowac* ng = new Linia(po, l1->getPunktDalejX(), "prawej");
                Linia* nowaLiniaGorna = new Linia(po, l1->getPunktDalejX(), "prawej");




		Linia* nextLP = l1->getNastepny();
		Linia* nextLD = itr->getNastepny();
		shared_ptr<Punkt> nextPP = l1->getPunktDalejX()->getNastepny();
		shared_ptr<Punkt> nextPD = itr->getPunktR()->getNastepny();

		shared_ptr<Punkt> punktW = l1->getPunktDalejX();
		shared_ptr<Punkt> punktN = itr->getPunktR();

		l1->setPunktDalejX(itr->getPunktR());
		itr->setPunktR(po);

		//flow obwiedni
		itr->getPunktL()->setNastepny(po); // punkt
		po->setNastepny(punktW);   //punkt
		punktW->setNastepny(nextPP);   //punkt
		itr->setNastepny(nowaLiniaGorna);  //linia
		nowaLiniaGorna->setNastepny(nextLP);  //linia

		//flow do skasowania
		l1->getPunktBlizejX()->setNastepny(punktN); // punkt
		punktN->setNastepny(nextPD);  //punkt
		l1->setNastepny(nextLD);  //linia

		return nowaLiniaGorna;
  /*      } else if(std::strcmp(liniaWyzsza->getSrodekPo(), "prawej") == 0 &&
	          std::strcmp(liniaNizsza->getSrodekPo(), "lewej") == 0 ) {

		Linia* l1 = liniaWyzsza;
		Linia* itr = liniaNizsza;

		Linia* nextLPW = dynamic_cast<Linia*> (l1->getNastepny());
		Linia* nextLPN = dynamic_cast<Linia*> (itr->getNastepny());
		shared_ptr<Punkt> nextPPW = dynamic_cast<shared_ptr<Punkt>> (l1->getPunktDalejX()->getNastepny());
		shared_ptr<Punkt> nextPPN = dynamic_cast<shared_ptr<Punkt>> (itr->getPunktBlizejX()->getNastepny());

		shared_ptr<Punkt> punktW = dynamic_cast<shared_ptr<Punkt>> (l1->getPunktDalejX());
		shared_ptr<Punkt> punktN = dynamic_cast<shared_ptr<Punkt>> (itr->getPunktBlizejX());

		itr->setPunktBlizejX(punktW);
		l1->setPunktDalejX(punktN);

		//flow obwiedni
		itr->getPunktDalejX()->setNastepny(punktW); // punkt
		punktW->setNastepny(nextPPW);  //punkt
		itr->setNastepny(nextLPW);  //linia
		//flow do skasowania
		l1->getPunktBlizejX()->setNastepny(punktN); // punkt
		punktN->setNastepny(nextPPN);   //punkt
		l1->setNastepny(nextLPN);  //linia


	//
	}

*/

}

