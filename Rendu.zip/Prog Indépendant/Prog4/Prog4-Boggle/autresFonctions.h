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

/**
 * @brief Renvoie "true" si l'un des mots de la seconde liste apparaissent dans la première,
 * renvoie "false" si les mots de la seconde liste n'apparaissent pas dans la première.
 * @param [in] ref_liste1 La liste de mots auquel on va comparer avec le mot de la seconde liste.
 * @param [in] ref_liste2 La seconde liste de mots auquel on va le comparer avec les mots de la première liste.
 * @param [in] i L'index position du mot de la seconde liste auquel on va comparer avec les autres.
 * mots de la première liste.
 * @return Un Boolean soit "true" soit "false".
*/
bool compare(listeDeMots& ref_liste1, listeDeMots& ref_liste2, const unsigned int i);

/**
 * @brief Le boolean modifie le comportement de la fonction, "true" est la valeur
 * par défaut la fonction affiche à l’écran les mots de la seconde liste apparaissant
 * dans la première. Si on insère "false", la fonction affiche à l’écran les mots de la
 * seconde liste n’apparaissant pas dans la première.
 * @param [in] ref_liste1 La liste des mots de la première liste de mots.
 * @param [in] ref_liste2 La liste des mots de la deuxième liste de mots.
 * @param [in] boolean Un boolean définie par défaut "true".
*/
void showCommomWord(listeDeMots& ref_liste1, listeDeMots& ref_liste2, bool boolean = true);