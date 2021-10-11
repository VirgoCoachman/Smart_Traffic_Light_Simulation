/*
 * traffic_manager.c
 *
 *  Created on: Sep 19, 2021
 *      Author: virgocoachman
 */

#include <stdio.h>
#include <stdlib.h>
#include "traffic_manager.h"
#include "led.h"
#include "main.h"

/**
 * Permet de comparer et de renvoyer la plus grande valeur entre deux nombres entiers
 * Elle nous servira à comparer les files de voies pour savoir laquelle est la plus longue, et attribuer la priorité en conséquence
 */
int great_between(int a, int b){
	if(a > b)
		return a;
	else if(a < b)
		return b;
	return -1;
}

/**
 * Fonction permettant de changer la priorité de voie: la voie pr
 * @paramètres
 * priority : est un tableau contenant les valeurs de priorités des deux voies du carrefour
 * 			 priority[0]: L'état de la priorité (0 ou 1) de la voie_1
 * 			 priority[1]: L'état de la priorité (0 ou 1) de la voie_2
 * 			 Si l'état de la priorité d'une voie est à 1, alors le feu vert s'allume sur cette voie alors
 * 			 sur l'autre voie qui a la priorité à 0 a un feu rouge allumé
 * index : indique la voie qui doit recevoir la priorité 1. Si index = 0, alors priority[0] sera égal à 1 et priority[1] à 0
 * 			si index = 1, alors priority[1] sera égal à 1 et priority[0] à 0
 */
void switching_priority(int *priority, int index){
	priority[index] = 1;
	switch(index){
	case 0:
		priority[1] = 0;
		break;
	case 1:
		priority[0] = 0;
		break;
	}
}

/**
 * Permet de comparer la longueur des toutes les 4 files et de faire basculer la priorité en cas de besoin
 * 		et commande l'allumage de feux selon la priorité des voies
 * Retourne la file la plus longue
 * @paramètres:
 * a, b, c ,d : les pointeurs sur les compteurs respectivement de la file_a, file_b, file_c et file_d
 */
int analyse_queues_situation(int *a, int *b, int *c, int *d, int *priority){
	int length = 0;
	// queue_1 = la file (a ou b) la plus longue sur la voie_1
	int queue_1 = great_between(*a, *b);
	// queue_1 = la file (a ou b) la plus longue sur la voie_2
	int queue_2 = great_between(*c, *d);
	int ans = great_between(queue_1, queue_2);

	if(queue_1 == ans){
		switching_priority(priority, 0);
		length = *a + *b;
	} else if(-1 == ans){
		if(priority[0])
			length = *a + *b;
		else
			length = *c + *d;
	}
	else{
		switching_priority(priority, 1);
		length = *c + *d;
	}

	if(length != 0){
		int i = get_queue_big_priority(priority);
		blink_led_on(i);
	}

	return length;
}

/**
 * Retourne l'index de la voie la plus prioritaire
 */
int get_queue_big_priority(int *priority)
{
	if(priority[0])
		return 0;
	return 1;
}




