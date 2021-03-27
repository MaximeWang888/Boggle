#pragma warning(disable:4996)
#include "listeDeMots.h"
#include "allocationDynamique.h"
#include "autresFonctions.h"

int main() {
	listeDeMots liste, liste2;

	initialiser(liste, 1, 5);
	initialiser(liste2, 1, 5);
	motTrouver(liste);
	motTrouver(liste2);

	trie(liste);
	supprimeDoublons(liste);
	trie(liste2);
	supprimeDoublons(liste2);

	showCommomWord(liste, liste2);

	detruire(liste);
	detruire(liste2);
}


