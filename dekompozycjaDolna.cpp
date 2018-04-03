
#include"dekompozycjaDolna.h"
#include<cstring>
#include<memory>

using namespace std;


void dekompozycjaDolna(shared_ptr<Linia> itr, shared_ptr<Linia> l1) {

	shared_ptr<Punkt> punktR = l1->getNastepny()->getPunktR();
        shared_ptr<Punkt> punktL = itr->getPunktR();

        shared_ptr<Linia> liniaD = itr->getNastepny();
        shared_ptr<Linia> liniaR = l1->getNastepny();

	shared_ptr<Linia> nextLP = l1->getNastepny()->getNastepny();
        shared_ptr<Linia> nextLD = itr->getNastepny()->getNastepny();
        shared_ptr<Punkt> nextPP = punktR->getNastepny();
        shared_ptr<Punkt> nextPD = punktL->getNastepny()->getNastepny();


//        Skasowac* psqL = new Punkt(punktL->getX(), punktL->getY());
        shared_ptr<Punkt> psL = make_shared<Punkt> (punktL->getX(), punktL->getY());
//        Skasowac* psqR = new Punkt(punktR->getX(), punktR->getY());
        shared_ptr<Punkt> psR = make_shared<Punkt> (punktR->getX(), punktR->getY());
  //      Skasowac* ng = make_shared<Linia>(psL, psL, "dole");
        shared_ptr<Linia> nowaLiniaGorna = make_shared<Linia>(psL, psL, "dole");

	l1->getNastepny()->setPunktR(psR);

	liniaD->setPunktDalejX(psL);
        itr->setPunktR(punktR);

	//flow obwiedni
        itr->getPunktL()->setNastepny(punktR); // punkt
        punktR->setNastepny(nextPP);   //punkt
        itr->setNastepny(nextLP);  //linia

	//flow do skasowania
	l1->getPunktDalejX()->setNastepny(psR); //punkt
	psR->setNastepny(psL); //punkt
	psL->setNastepny(liniaD->getPunktBlizejX());  //punkt
	liniaD->getPunktBlizejX()->setNastepny(nextPD);  //punkt
	l1->setNastepny(liniaR);
	liniaR->setNastepny(liniaD);
	liniaD->setNastepny(nextLD);

}

