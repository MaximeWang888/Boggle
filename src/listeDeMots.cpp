/*******************************************************
Nom ......... : ListeDeMots.cpp
Auteurs ..... : Fabien RONDAN & Maxime WANG
Version ..... : 1.Release
********************************************************/

#pragma warning(disable:4996)
#include <iostream>
#include <cassert>

#include "listeDeMots.h"

using namespace std;


void initialiser(listeDeMots& ref_liste, unsigned int capa, unsigned int p) {
	assert(capa > 0 || p > 0);

	ref_liste.capacite = capa;
	ref_liste.pasExtension = p;
	ref_liste.TabDeMots = new Mot[capa];
	ref_liste.nombreDeMots = 0;
}


void afficher(const listeDeMots& ref_liste) {
	assert(ref_liste.nombreDeMots <= ref_liste.capacite);

	for (unsigned int i = 0; i < ref_liste.nombreDeMots; i++)
	{
		cout << ref_liste.TabDeMots[i] << endl;
	}

}


void detruire(listeDeMots& ref_liste) {
	delete[] ref_liste.TabDeMots;
}


void ecrire(listeDeMots& ref_liste, const Mot& mot) {
	
		if (ref_liste.nombreDeMots >= ref_liste.capacite) {

			int nouvelleTaille = (ref_liste.nombreDeMots + 1) * ref_liste.pasExtension;

			Mot* nouvelleListe = new Mot[nouvelleTaille];

			for (unsigned int j = 0; j < ref_liste.capacite; j++)
			{
				strcpy(nouvelleListe[j], ref_liste.TabDeMots[j]);
			}
			delete[] ref_liste.TabDeMots;
			ref_liste.TabDeMots = nouvelleListe;
			ref_liste.capacite = nouvelleTaille ;

			// Changement du Pas d'Extention en fonction de la taille de la liste
			if (ref_liste.capacite <= 5000) { ref_liste.pasExtension = 4; }
			if (ref_liste.capacite <= 50000) { ref_liste.pasExtension = 3; }
			if (ref_liste.capacite <= 100000) { ref_liste.pasExtension = 2; }

		}

		strcpy(ref_liste.TabDeMots[ref_liste.nombreDeMots], mot);
		ref_liste.nombreDeMots++;

}


void motTrouver(listeDeMots& ref_liste) {
	bool isAlreadyInput = true;

	while (isAlreadyInput)
	{
		listeDynamique(ref_liste);

		cin >> ref_liste.TabDeMots[ref_liste.nombreDeMots];
		ref_liste.nombreDeMots++;

		if (strcmp(ref_liste.TabDeMots[ref_liste.nombreDeMots - 1], "*") == 0) {
			isAlreadyInput = false;
		}

	}
}


void afficheScore(listeDeMots& ref_liste) {
	unsigned int nbPoints = 0;

	for (unsigned int i = 0; i < ref_liste.nombreDeMots; i++) {
		unsigned int lenghtofString = strlen(ref_liste.TabDeMots[i]);
		if (lenghtofString >= 8) { nbPoints = nbPoints + 11; }
		if (lenghtofString == 7) { nbPoints = nbPoints + 5; }
		if (lenghtofString == 6) { nbPoints = nbPoints + 3; }
		if (lenghtofString == 5) { nbPoints = nbPoints + 2; }
		if (lenghtofString == 3 || lenghtofString == 4) { nbPoints = nbPoints + 1; }
	}
	cout << nbPoints;
}


void tri(listeDeMots& ref_liste) {

	for (unsigned int i = 0; i < ref_liste.nombreDeMots - 2; i++)
	{
		for (unsigned int y = 0; y < ref_liste.nombreDeMots - 2 - i; y++)
		{
			if (strcmp(ref_liste.TabDeMots[y], ref_liste.TabDeMots[y + 1]) > 0) {
				Mot permute;
				strcpy(permute, ref_liste.TabDeMots[y]);
				strcpy(ref_liste.TabDeMots[y], ref_liste.TabDeMots[y + 1]);
				strcpy(ref_liste.TabDeMots[y + 1], permute);
			}
		}
	}
}


void supprimeDoublons(listeDeMots& ref_liste) {

	for (unsigned int i = 0, j = 1; j < ref_liste.nombreDeMots - 1; i++, j++)
	{
		if (strcmp(ref_liste.TabDeMots[i], ref_liste.TabDeMots[j]) == 0) {
			for (unsigned int k = j + 1, l = j; k < ref_liste.nombreDeMots + 1; k++, l++)
			{
				strcpy(ref_liste.TabDeMots[l], ref_liste.TabDeMots[k]);
			}
			j = j - 1;
			i = i - 1;
			ref_liste.nombreDeMots -= 1;
		}
	}

	Mot* liste = new Mot[ref_liste.nombreDeMots];
	for (unsigned int i = 0; i < ref_liste.nombreDeMots; i++)
	{
		strcpy(liste[i], ref_liste.TabDeMots[i]);

	}
	delete[] ref_liste.TabDeMots;

	ref_liste.capacite = ref_liste.nombreDeMots;
	ref_liste.TabDeMots = liste;
}


bool compare(listeDeMots& ref_liste1, listeDeMots& ref_liste2, const unsigned int i) {
	bool isTheSameWord = false;
	for (unsigned int j = 0; j < ref_liste1.nombreDeMots - 1; j++)
	{
		if (strcmp(ref_liste1.TabDeMots[j], ref_liste2.TabDeMots[i]) == 0)
		{
			isTheSameWord = true;
			return isTheSameWord;
		}
	}
	return isTheSameWord;
}


void showCommomWord(listeDeMots& ref_liste1, listeDeMots& ref_liste2, bool boolean) {
	for (unsigned int i = 0; i < ref_liste2.nombreDeMots; i++)
	{
		if (compare(ref_liste1, ref_liste2, i) == boolean) {

			cout << ref_liste2.TabDeMots[i] << endl;
		}
	}
	if (boolean)
		cout << "*" << endl;
	cout << endl << endl;
}


void listeDynamique(listeDeMots& ref_liste) {

	if (ref_liste.nombreDeMots >= ref_liste.capacite) {

		int nouvelleTaille = (ref_liste.nombreDeMots + 1) * ref_liste.pasExtension;

		Mot* nouvelleListe = new Mot[nouvelleTaille];

		for (unsigned int j = 0; j < ref_liste.capacite; j++)
		{
			strcpy(nouvelleListe[j], ref_liste.TabDeMots[j]);
		}

		delete[] ref_liste.TabDeMots;
		ref_liste.TabDeMots = nouvelleListe;
		ref_liste.capacite = nouvelleTaille;

		// Changement du Pas d'Extention en fonction de la taille de la liste
		if (ref_liste.capacite <= 5) { ref_liste.pasExtension = 4; }
		if (ref_liste.capacite <= 20) { ref_liste.pasExtension = 3; }
		if (ref_liste.capacite <= 60) { ref_liste.pasExtension = 2; }

	}
}