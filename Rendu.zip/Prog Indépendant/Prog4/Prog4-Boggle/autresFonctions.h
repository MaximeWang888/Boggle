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

/**
 * @brief Renvoie "true" si l'un des mots de la seconde liste apparaissent dans la premi�re,
 * renvoie "false" si les mots de la seconde liste n'apparaissent pas dans la premi�re.
 * @param [in] ref_liste1 La liste de mots auquel on va comparer avec le mot de la seconde liste.
 * @param [in] ref_liste2 La seconde liste de mots auquel on va le comparer avec les mots de la premi�re liste.
 * @param [in] i L'index position du mot de la seconde liste auquel on va comparer avec les autres.
 * mots de la premi�re liste.
 * @return Un Boolean soit "true" soit "false".
*/
bool compare(listeDeMots& ref_liste1, listeDeMots& ref_liste2, const unsigned int i);

/**
 * @brief Le boolean modifie le comportement de la fonction, "true" est la valeur
 * par d�faut la fonction affiche � l��cran les mots de la seconde liste apparaissant
 * dans la premi�re. Si on ins�re "false", la fonction affiche � l��cran les mots de la
 * seconde liste n�apparaissant pas dans la premi�re.
 * @param [in] ref_liste1 La liste des mots de la premi�re liste de mots.
 * @param [in] ref_liste2 La liste des mots de la deuxi�me liste de mots.
 * @param [in] boolean Un boolean d�finie par d�faut "true".
*/
void showCommomWord(listeDeMots& ref_liste1, listeDeMots& ref_liste2, bool boolean = true);