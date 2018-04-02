
#include"dekompozycjaDolna.h"
#include<cstring>
#include<iostream>


void dekompozycjaDolna(Linia* itr, Linia* l1) {

	Punkt* punktR = dynamic_cast<Punkt*> ((dynamic_cast<Linia*> (l1->getNastepny()))->getPunktR());
        Punkt* punktL = dynamic_cast<Punkt*> (itr->getPunktR());

        Linia* liniaD = dynamic_cast<Linia*> (itr->getNastepny());

	Linia* nextLP = dynamic_cast<Linia*> (l1->getNastepny()->getNastepny());
        Linia* nextLD = dynamic_cast<Linia*> (itr->getNastepny()->getNastepny());
        Punkt* nextPP = dynamic_cast<Punkt*> (punktR->getNastepny());
        Punkt* nextPD = dynamic_cast<Punkt*> (punktL->getNastepny()->getNastepny());


        Skasowac* psqL = new Punkt(punktL->getX(), punktL->getY());
        Punkt* psL = dynamic_cast<Punkt*>(psqL);
        Skasowac* psqR = new Punkt(punktR->getX(), punktR->getY());
        Punkt* psR = dynamic_cast<Punkt*>(psqR);
        Skasowac* ng = new Linia(psL, psL, "dole");
        Linia* nowaLiniaGorna = dynamic_cast<Linia*>(ng);

	dynamic_cast<Linia*> (l1->getNastepny())->setPunktR(psR);

	liniaD->setPunktDalejX(psL);
        itr->setPunktR(punktR);

	//flow obwiedni
        itr->getPunktL()->setNastepny(punktR); // punkt
        punktR->setNastepny(nextPP);   //punkt
        itr->setNastepny(nextLP);  //linia

	//flow do skasowania
	l1->getPunktDalejX()->setNastepny(psR);
	psR->setNastepny(psL);
	psL->setNastepny(liniaD->getPunktBlizejX());
	liniaD->getPunktBlizejX()->setNastepny(nextPD);

	std::cout << "jestem w dekompopzycji Dolnej" <<std::endl;

}

