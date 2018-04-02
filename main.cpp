#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>

#include"punkt.h"
#include"wierzcholek.h"
#include"linia.h"
#include"dekompozycjaKrzyzowa.h"
#include"dekompozycjaPrawa.h"
#include"dekompozycjaLewa.h"
#include"dekompozycjaDolna.h"
#include"dekompozycjaDolnaPojedyncza.h"
#include"wielokatDodatni.h"

using namespace std;

int main() {
	WielokatDodatni wd;
/*	float center, width, alarm;
	while((scanf("%12s - %f, %f, %f", a, &center, &width, &alarm)) != EOF) {
		Punkt *p1 = new Punkt(center - width/2, 0);
		Punkt *p2 = new Punkt(center - width/2, alarm);
		Punkt *p3 = new Punkt(center + width/2, alarm);
		Punkt *p4 = new Punkt(center + width/2, 0);
*/
	char a[12];
        float p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y;
        while((scanf("%12s - (%f, %f)(%f, %f)(%f, %f)(%f, %f)", a, &p1x, &p1y, &p2x, &p2y, &p3x, &p3y, &p4x, &p4y)) != EOF) {
                int byl = 0;
		wd.dodaj(p1x, p1y, p2x, p2y, p3x, p3x, p4x, p4y);
	}
		wd.wyswietlWynik();

return 0;
}

