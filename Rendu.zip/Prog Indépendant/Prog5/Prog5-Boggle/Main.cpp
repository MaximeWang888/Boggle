#pragma warning(disable:4996)

#include "listeDeMots.h"
#include "allocationDynamique.h"
#include "autresFonctions.h"


int main() {
	List listOfLists;
	listeDeMots finalWordList;
	initialiser(finalWordList, 1, 5);
										
	ajouterListe(listOfLists);			
	showCommonList(listOfLists, finalWordList);
	tri(finalWordList);
	
	supprimeDoublons(finalWordList);
	afficher(finalWordList);

	detruire(finalWordList);

	for(int i = 0; i < listOfLists.nombreDeListes ; i++){

		detruire(listOfLists.listOfList[i]);

	}

}

