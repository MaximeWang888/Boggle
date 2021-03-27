#pragma warning(disable:4996)
#include <iostream>
#include <cassert>
#include "allocationDynamique.h"
#include "autresFonctions.h"

using namespace std;


void motTrouver(listeDeMots& ref_liste) {
	bool isAlreadyInput = true;

	while (isAlreadyInput)
	{
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
	cout << nbPoints << endl;
}


void tri(listeDeMots& ref_liste){

	for (unsigned int i = 0; i < ref_liste.nombreDeMots - 1; i++)
	{
		for (unsigned int y = i+1; y < ref_liste.nombreDeMots - 1; y++)
		{
			if(strcmp(ref_liste.TabDeMots[i], ref_liste.TabDeMots[y]) > 0){
				Mot permute;
				strcpy(permute, ref_liste.TabDeMots[i]); 
				strcpy(ref_liste.TabDeMots[i], ref_liste.TabDeMots[y]);
				strcpy(ref_liste.TabDeMots[y], permute);
			}
		}
	}
}


void supprimeDoublons(listeDeMots& ref_liste) {
	assert(ref_liste.nombreDeMots > 2);

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
	//detruire(ref_liste);
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


void ajouterListe(List& ref_list) {
	bool saisiList = true;

	for (int i = 0; saisiList == true; i++)
	{	
		if (ref_list.nombreDeListes >= ref_list.capacite)
		{
			listeDeMots* listeMot = new listeDeMots[ref_list.capacite + 2];

			for (int k = 0; k <= i; k++)
			{
				initialiser(listeMot[i], 1, 5);
			}
			
			if (ref_list.capacite != 0) {
				for (unsigned int j = 0; j < ref_list.nombreDeListes; j++)
				{
					listeMot[j] = ref_list.listOfList[j];
				}
				delete[] ref_list.listOfList;
			}

			ref_list.listOfList = listeMot;
			ref_list.capacite = ref_list.capacite + 2;

		}

		initialiser(ref_list.listOfList[i], 1, 5);
		motTrouver(ref_list.listOfList[i]);
		ref_list.nombreDeListes++;

		if (strcmp(ref_list.listOfList[i].TabDeMots[0], "*") == 0) {
			saisiList = false;
			ref_list.nombreDeListes--;
		}
	}
}

void afficherListe(List& ref_list) {
	for (unsigned int i = 0; i < ref_list.nombreDeListes; i++)
	{
		for (unsigned int l = 0; l < ref_list.listOfList[i].nombreDeMots; l++)
		{
			cout << ref_list.listOfList[i].TabDeMots[l] << endl;
		}
	}
}


bool compare2(List& ref_list, int& idxList, int& nextIdxList, const unsigned int i) {
	bool isTheSameWord = false;

	for (unsigned int j = 0; j < ref_list.listOfList[nextIdxList].nombreDeMots - 1; j++)
	{
		if (strcmp(ref_list.listOfList[idxList].TabDeMots[i], ref_list.listOfList[nextIdxList].TabDeMots[j]) == 0)
		{
			isTheSameWord = true;
			return isTheSameWord;
		}
	}

	return isTheSameWord;
}


void saveCommonList(List& ref_list, int& idxList, int& nextIdxList,listeDeMots& finalWordList) {

	for (unsigned int i = 0; i < ref_list.listOfList[idxList].nombreDeMots - 1; i++)
	{
		if (compare2(ref_list, idxList, nextIdxList, i) == true) {
			
			ecrire(finalWordList, ref_list.listOfList[idxList].TabDeMots[i]);

		}
	}

}


void showCommonList(List& listOfWord, listeDeMots& finalWordList) {

	for (int idxList = 0; idxList < listOfWord.nombreDeListes; idxList++)
	{
		for (int nextIdxList = idxList + 1; nextIdxList < listOfWord.nombreDeListes; nextIdxList++)
		{
			saveCommonList(listOfWord, idxList, nextIdxList, finalWordList);
		}
	}

	Mot etoile = "*";
	ecrire(finalWordList, etoile);

}
