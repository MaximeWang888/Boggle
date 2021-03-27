/*******************************************************
Nom ......... : List.cpp
Auteurs ..... : Fabien RONDAN & Maxime WANG
Version ..... : 1.Release
********************************************************/

#pragma warning(disable:4996)
#include <iostream>

#include "listeDeMots.h"
#include "List.h"

using namespace std;


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


bool compare2(List& ref_list, unsigned int& idxList, unsigned int& nextIdxList, const unsigned int i) {
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


void saveCommonWordList(List& ref_list, unsigned int& idxList, unsigned int& nextIdxList, listeDeMots& finalWordList) {

	for (unsigned int i = 0; i < ref_list.listOfList[idxList].nombreDeMots - 1; i++)
	{
		if (compare2(ref_list, idxList, nextIdxList, i) == true) {
			
			ecrire(finalWordList, ref_list.listOfList[idxList].TabDeMots[i]);

		}
	}

}


void showCommonWordList(List& listOfWord, listeDeMots& finalWordList) {

	for (unsigned int idxList = 0; idxList < listOfWord.nombreDeListes; idxList++)
	{
		for (unsigned int nextIdxList = idxList + 1; nextIdxList < listOfWord.nombreDeListes; nextIdxList++)
		{
			saveCommonWordList(listOfWord, idxList, nextIdxList, finalWordList);
		}
	}

	Mot etoile = "*";
	ecrire(finalWordList, etoile);

}
