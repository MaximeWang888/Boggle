/*******************************************************
Nom ......... : listeDeMots.h
Auteurs ..... : Fabien RONDAN & Maxime WANG
Version ..... : 1.Release
********************************************************/

#pragma once
#include "Structures.h"


/**
 * @brief Initialise une liste de mots
 * Allocation en m�moire dynamique d'une liste de mots
 * de capacit� (capa) extensible par pas d'extension (p).
 * @see detruire, pour sa d�sallocation en fin d'utilisation
 * @param [out] ref_liste : la liste de mots.
 * @param [in] capa : capacit� de la liste.
 * @param [in] p : pas d'extension de capacit�.
 * @pre capa>0 et p>0
 */
void initialiser(listeDeMots& ref_liste, unsigned int capa, unsigned int p);


 /**
  * @brief Permet d'afficher la liste de mots.
  * @param [in] ref_liste : La liste de mots auquel on va afficher toutes ces valeurs.
  * @pre ref_liste.nombreDeMots < ref_liste.capacite 
 */
void afficher(const listeDeMots& ref_liste);


/**
 * @brief D�salloue la liste de mots en m�moire dynamique.
 * @see initialiser, la liste de mots a d�j� �t� allou�
 * @param [out] ref_liste : la liste de mots.
 */
void detruire(listeDeMots& ref_liste);


/**
 * @brief Ecrit le mot en param�tre dans la liste de mots.
 * @param [out] ref_liste : La liste de mots auquel on va ins�rer notre mot
 * et augmente sa capacit� si le nombreDeMots >= la capicit�.
 * @param [in] mot : Le mot � ins�rer dans la liste de mots. 
*/
void ecrire(listeDeMots& ref_liste, const Mot& mot);


/**
 * @brief Permet de saisir une liste de mots au clavier.
 * @param [in, out] ref_liste : La liste de mots auquel on ins�re le mot saisit en entr�e et
 * on incr�mente � chaque fois le nombre de mots d'un (+1).
*/
void motTrouver(listeDeMots& ref_liste);


/**
 * @brief Affiche � l��cran le nombre de points que la liste de mots repr�sente.
 * @param [in] ref_liste : La liste de mots auquel on va lire la taille de chaque mots pour afficher
 * � l'�cran le nombre de points que la liste de mots repr�sente.
*/
void afficheScore(listeDeMots& ref_liste);


/**
 * @brief Permet de trier la liste de mots saisie au clavier.
 * @param [in, out] ref_liste : La liste de mots auquel on va trier ses mots.
*/
void tri(listeDeMots& ref_liste);


/**
 * @brief Permet de supprimer les mots de la liste retrouver en doublons et
 * r�alloue � la fin un tableau de la bonne taille (nombre de mots y compris l'�toile).
 * @param [in, out] ref_liste : La liste de mots auquel on supprime les mots r�p�t�s.
*/
void supprimeDoublons(listeDeMots& ref_liste);


/**
 * @brief Renvoie "true" si l'un des mots de la seconde liste apparaissent dans la premi�re,
 * renvoie "false" si les mots de la seconde liste n'apparaissent pas dans la premi�re.
 * @param [in] ref_liste1 : La liste de mots auquel on va comparer avec le mot de la seconde liste.
 * @param [in] ref_liste2 : La seconde liste de mots auquel on va le comparer avec les mots de la premi�re liste.
 * @param [in] i : L'index position du mot de la seconde liste auquel on va comparer avec les autres.
 * mots de la premi�re liste.
 * @return Un Boolean soit "true" soit "false".
*/
bool compare(listeDeMots& ref_liste1, listeDeMots& ref_liste2, const unsigned int i);


/**
 * @brief Le boolean modifie le comportement de la fonction, "true" est la valeur
 * par d�faut, la fonction affiche � l��cran les mots de la seconde liste apparaissant
 * dans la premi�re. Si on ins�re "false", la fonction affiche � l��cran les mots de la
 * seconde liste n�apparaissant pas dans la premi�re.
 * @param [in] ref_liste1 : La premi�re liste de mots auquel on va comparer avec
 * la deuxi�me liste de mots.
 * @param [in] ref_liste2 : La deuxi�me liste de mots auquel on va comparer avec
 * la premi�re liste de mots.
 * @param [in] boolean : Un boolean d�finie par d�faut "true".
*/
void showCommomWord(listeDeMots& ref_liste1, listeDeMots& ref_liste2, bool boolean = true);


/**
 * @brief Initialise une liste de mots de capacit� augment�
 * Allocation en m�moire dynamique d'une liste de mots
 * de capacit� (capa) extensible par pas d'extension (p) et
 * on repasse la liste de mots de la nouvelle liste dans l'ancienne liste 'ref_liste'.
 * @see detruire, pour sa d�sallocation en fin d'utilisation
 * @param [in, out] ref_liste : La liste de mots auquel on va augmenter sa capacit�
 * si le nombre de mots >= la capacit�.
*/
void listeDynamique(listeDeMots& ref_liste);