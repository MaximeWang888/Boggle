#pragma warning(disable:4996)
#include "listeDeMots.h"
#include "allocationDynamique.h"
#include "autresFonctions.h"

int main() {
	listeDeMots liste;

	initialiser(liste, 1, 5);
	motTrouver(liste);

	trie(liste);
	supprimeDoublons(liste);
	afficher(liste);
	detruire(liste);
}


