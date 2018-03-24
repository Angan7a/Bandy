#include<iostream>
#include<stdio.h>
#include"punkt.h"


using namespace std;

int main() {
	char a[12];
	int c, w, alaram;
	while((scanf("%12s - %d, %d, %d", a, &c, &w, &alaram)) != EOF) {
		//cin >> a;
		cout << c << endl;
	}

	Punkt p1(9, 7);
	cout << p1.getX() << "   " << p1.getY() << endl;

return 0;
}
