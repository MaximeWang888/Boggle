/*******************************************************
Nom ......... : listeDeMots.h
Auteurs ..... : Fabien RONDAN & Maxime WANG
Version ..... : 1.Release
********************************************************/

#pragma once
#include "Structures.h"


/**
 * @brief Initialise une liste de mots
 * Allocation en mémoire dynamique d'une liste de mots
 * de capacité (capa) extensible par pas d'extension (p).
 * @see detruire, pour sa désallocation en fin d'utilisation
 * @param [out] ref_liste : la liste de mots.
 * @param [in] capa : capacité de la liste.
 * @param [in] p : pas d'extension de capacité.
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
 * @brief Désalloue la liste de mots en mémoire dynamique.
 * @see initialiser, la liste de mots a déjà été alloué
 * @param [out] ref_liste : la liste de mots.
 */
void detruire(listeDeMots& ref_liste);


/**
 * @brief Ecrit le mot en paramètre dans la liste de mots.
 * @param [out] ref_liste : La liste de mots auquel on va insérer notre mot
 * et augmente sa capacité si le nombreDeMots >= la capicité.
 * @param [in] mot : Le mot à insérer dans la liste de mots. 
*/
void ecrire(listeDeMots& ref_liste, const Mot& mot);


/**
 * @brief Permet de saisir une liste de mots au clavier.
 * @param [in, out] ref_liste : La liste de mots auquel on insère le mot saisit en entrée et
 * on incrémente à chaque fois le nombre de mots d'un (+1).
*/
void motTrouver(listeDeMots& ref_liste);


/**
 * @brief Affiche à l’écran le nombre de points que la liste de mots représente.
 * @param [in] ref_liste : La liste de mots auquel on va lire la taille de chaque mots pour afficher
 * à l'écran le nombre de points que la liste de mots représente.
*/
void afficheScore(listeDeMots& ref_liste);


/**
 * @brief Permet de trier la liste de mots saisie au clavier.
 * @param [in, out] ref_liste : La liste de mots auquel on va trier ses mots.
*/
void tri(listeDeMots& ref_liste);


/**
 * @brief Permet de supprimer les mots de la liste retrouver en doublons et
 * réalloue à la fin un tableau de la bonne taille (nombre de mots y compris l'étoile).
 * @param [in, out] ref_liste : La liste de mots auquel on supprime les mots répétés.
*/
void supprimeDoublons(listeDeMots& ref_liste);


/**
 * @brief Renvoie "true" si l'un des mots de la seconde liste apparaissent dans la première,
 * renvoie "false" si les mots de la seconde liste n'apparaissent pas dans la première.
 * @param [in] ref_liste1 : La liste de mots auquel on va comparer avec le mot de la seconde liste.
 * @param [in] ref_liste2 : La seconde liste de mots auquel on va le comparer avec les mots de la première liste.
 * @param [in] i : L'index position du mot de la seconde liste auquel on va comparer avec les autres.
 * mots de la première liste.
 * @return Un Boolean soit "true" soit "false".
*/
bool compare(listeDeMots& ref_liste1, listeDeMots& ref_liste2, const unsigned int i);


/**
 * @brief Le boolean modifie le comportement de la fonction, "true" est la valeur
 * par défaut, la fonction affiche à l’écran les mots de la seconde liste apparaissant
 * dans la première. Si on insère "false", la fonction affiche à l’écran les mots de la
 * seconde liste n’apparaissant pas dans la première.
 * @param [in] ref_liste1 : La première liste de mots auquel on va comparer avec
 * la deuxième liste de mots.
 * @param [in] ref_liste2 : La deuxième liste de mots auquel on va comparer avec
 * la première liste de mots.
 * @param [in] boolean : Un boolean définie par défaut "true".
*/
void showCommomWord(listeDeMots& ref_liste1, listeDeMots& ref_liste2, bool boolean = true);


/**
 * @brief Initialise une liste de mots de capacité augmenté
 * Allocation en mémoire dynamique d'une liste de mots
 * de capacité (capa) extensible par pas d'extension (p) et
 * on repasse la liste de mots de la nouvelle liste dans l'ancienne liste 'ref_liste'.
 * @see detruire, pour sa désallocation en fin d'utilisation
 * @param [in, out] ref_liste : La liste de mots auquel on va augmenter sa capacité
 * si le nombre de mots >= la capacité.
*/
void listeDynamique(listeDeMots& ref_liste);