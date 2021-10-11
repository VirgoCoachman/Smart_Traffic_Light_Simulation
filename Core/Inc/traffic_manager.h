/*
 * traffic_manager.h
 *
 *  Created on: Sep 19, 2021
 *      Author: virgocoachman
 */

#ifndef TRAFFIC_MANAGER_H_
#define TRAFFIC_MANAGER_H_



int analyse_queues_situation(int *, int *, int *, int *, int *);
int get_queue_big_priority(int *priority);
int great_between(int a, int b);
void switching(int *priority, int index);
void display_queues(int *a, int *b, int *c, int *d);


#endif /* TRAFFIC_MANAGER_H_ */
