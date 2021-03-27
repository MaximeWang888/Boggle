/*******************************************************
Nom ......... : Main.cpp
Auteurs ..... : Fabien RONDAN & Maxime WANG
Version ..... : 1.Release
********************************************************/

#pragma warning(disable:4996)

#include <iostream>

#include "Exos.h"

using namespace std;

int main() {
	int num;
	cin >> num;
	switch (num) {
	case 1:
		exo1(); break;
	case 2:
		exo2(); break; 
	case 3:
		exo3(); break;
	case 4:
		exo4(); break;
	case 5:
		exo5(); break;
	case 6:
		exo6(); break;
	}
}
