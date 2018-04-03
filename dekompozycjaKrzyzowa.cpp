#include"dekompozycjaKrzyzowa.h"
#include<cstring>
#include<memory>

using namespace std;
Przekaz* dekompozycjaKrzyzowa(shared_ptr<Linia> liniaPozioma, shared_ptr<Linia> liniaPionowa) {

	float x =  liniaPionowa->getPunktBlizejX()->getX();
	float y = liniaPozioma->getPunktL()->getY();
	Przekaz *przekaz = new Przekaz();
	//utwórz dwa punkty - po(punkt obwiedni), ps(do skasowania)
      //  Skasowac* poq = new Punkt(x, y);
      //  Skasowac* psq = new Punkt(x, y);
	shared_ptr<Punkt> po = make_shared<Punkt>(x, y);
	shared_ptr<Punkt> ps = make_shared<Punkt>(x, y);
        // skróc linie pozioma do punktu przecia
        if(std::strcmp(liniaPionowa->getSrodekPo(), "prawej") == 0) {
		shared_ptr<Linia> nextLG = liniaPionowa->getNastepny();
		shared_ptr<Linia> nextLR = liniaPozioma->getNastepny();
		shared_ptr<Punkt> nextPG = liniaPionowa->getPunktDalejX()->getNastepny();
		shared_ptr<Punkt> nextPR = liniaPozioma->getPunktR()->getNastepny();

//		Skasowac* nr = make_shared<Linia>(ps, liniaPozioma->getPunktR(), "dol");
		shared_ptr<Linia> nowaLiniaPrawa = make_shared<Linia>(ps, liniaPozioma->getPunktR(), "dol");
//		Skasowac* ng = make_shared<Linia>(po, liniaPionowa->getPunktDalejX(), "prawej");
		shared_ptr<Linia> nowaLiniaGorna =  make_shared<Linia>(po, liniaPionowa->getPunktDalejX(), "prawej");

        	liniaPozioma->setPunktR(po);
		liniaPionowa->setPunktDalejX(ps);
		//flow obwiedni
		liniaPozioma->getPunktL()->setNastepny(po); // punkt
		po->setNastepny(nowaLiniaGorna->getPunktDalejX()); //punkt
		nowaLiniaGorna->getPunktDalejX()->setNastepny(nextPG); //punkt
		liniaPozioma->setNastepny(nowaLiniaGorna); //linia
		nowaLiniaGorna->setNastepny(nextLG); //linia
		//dodanie lini poz i pion
//		liniePoziome.insert(liniaPozioma);
		//flow do skasowania
		liniaPionowa->getPunktBlizejX()->setNastepny(ps);//punkt
		ps->setNastepny(nowaLiniaPrawa->getPunktR());//punkt
		nowaLiniaPrawa->getPunktR()->setNastepny(nextPR);//punkt
		liniaPionowa->setNastepny(nowaLiniaPrawa); //linie
		nowaLiniaPrawa->setNastepny(nextLR); //linia
		przekaz->setPrzekazPierwszy(nowaLiniaPrawa);
		przekaz->setPrzekazDrugi(nowaLiniaGorna);
		return przekaz;
          } else {

		shared_ptr<Linia> nextLD = liniaPionowa->getNastepny();
		shared_ptr<Linia> nextLR = liniaPozioma->getNastepny();
		shared_ptr<Punkt> nextPD = liniaPionowa->getPunktBlizejX()->getNastepny();
		shared_ptr<Punkt> nextPR = liniaPozioma->getPunktR()->getNastepny();

//		Skasowac* nr = make_shared<Linia>(liniaPozioma->getPunktR(), po, "dol");
		shared_ptr<Linia> nowaLiniaPrawa = make_shared<Linia>(liniaPozioma->getPunktR(), po, "dol");
//		Skasowac* nd = make_shared<Linia>(ps, liniaPionowa->getPunktBlizejX(), "lewej");
		shared_ptr<Linia> nowaLiniaDolna = make_shared<Linia>(ps, liniaPionowa->getPunktBlizejX(), "lewej");


        	liniaPozioma->setPunktR(ps);
		liniaPionowa->setPunktBlizejX(po);

		//flow obwiedni
		liniaPionowa->getPunktDalejX()->setNastepny(po);
		po->setNastepny(nowaLiniaPrawa->getPunktR());
		nowaLiniaPrawa->getPunktR()->setNastepny(nextPR);
		liniaPionowa->setNastepny(nowaLiniaPrawa);
		nowaLiniaPrawa->setNastepny(nextLR);


		//flow do skasowania
		liniaPozioma->getPunktL()->setNastepny(ps);
		ps->setNastepny(nowaLiniaDolna->getPunktBlizejX());
		nowaLiniaDolna->getPunktBlizejX()->setNastepny(nextPD);
		liniaPozioma->setNastepny(nowaLiniaDolna);
		nowaLiniaDolna->setNastepny(nextLD);
		przekaz->setPrzekazPierwszy(nowaLiniaPrawa);
		przekaz->setPrzekazDrugi(nowaLiniaDolna);
	//	liniePoziome->insert(nowaLiniaPrawa);
		return przekaz;

	}



}

