#pragma once
#include "listeDeMots.h"

/**
 * @brief Permet de saisir une liste de mots au clavier.
 * @param [in,out] ref_liste On incr�mente de un le compteur � chaque fois
 * qu'on saisit un mot et on ins�re le mot dans la liste de mots.
*/
void motTrouver(listeDeMots& ref_liste);

/**
 * @brief Affiche � l��cran le nombre de points que la liste de mots repr�sente.
 * @param [in] ref_liste Le conteneur auquel on veut lire les mots pr�sent dans la liste de mots.
*/
void afficheScore(listeDeMots& ref_liste);

/**
 * @brief Permet de trier la liste de mots saisie au clavier.
 * @param [in, out] ref_liste La liste de mots auquel on va trier ses mots.
*/
void trie(listeDeMots& ref_liste);

/**
 * @brief Permet de supprimer les mots de la liste retrouver en doublons et 
 * r�alloue � la fin un tableau de la bonne taille (nombre de mots y compris l'�toile).
 * @param [in] ref_liste La liste de mots auquel on supprime les mots r�p�t�s.
 * @pre Une liste de deux mots au minimum.
*/
void supprimeDoublons(listeDeMots& ref_liste);