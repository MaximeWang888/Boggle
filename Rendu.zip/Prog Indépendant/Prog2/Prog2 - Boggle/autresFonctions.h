#pragma once
#include "listeDeMots.h"

/**
 * @brief Permet de saisir une liste de mots au clavier.
 * @param [in,out] ref_liste On incrémente de un le compteur à chaque fois
 * qu'on saisit un mot et on insère le mot dans la liste de mots.
*/
void motTrouver(listeDeMots& ref_liste);

/**
 * @brief Affiche à l’écran le nombre de points que la liste de mots représente.
 * @param [in] ref_liste Le conteneur auquel on veut lire les mots présent dans la liste de mots.
*/
void afficheScore(listeDeMots& ref_liste);

/**
 * @brief Permet de trier la liste de mots saisie au clavier.
 * @param [in, out] ref_liste La liste de mots auquel on va trier ses mots.
*/
void trie(listeDeMots& ref_liste);

/**
 * @brief Permet de supprimer les mots de la liste retrouver en doublons et 
 * réalloue à la fin un tableau de la bonne taille (nombre de mots y compris l'étoile).
 * @param [in] ref_liste La liste de mots auquel on supprime les mots répétés.
 * @pre Une liste de deux mots au minimum.
*/
void supprimeDoublons(listeDeMots& ref_liste);