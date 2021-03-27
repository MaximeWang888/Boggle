#pragma warning(disable:4996)
#include "listeDeMots.h"
#include "allocationDynamique.h"
#include "autresFonctions.h"

using namespace std;

int main() {
	listeDeMots liste;

	initialiser(liste, 1, 5);
	motTrouver(liste);
	afficheScore(liste);
	detruire(liste);
}


