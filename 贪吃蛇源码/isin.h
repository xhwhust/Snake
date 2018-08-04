#pragma once
#include "struct.h"
#include <stdio.h>
int isInFood(Snake *p, Poison *poison) {
	Food *food = NULL;
	if (p->pfood != NULL) {
		food = p->pfood;
	}
	else {
		return 0;
	}
	while (food->next != NULL) {
		if (poison->x == food->x && poison->y == food->y) {
			return 1;
		}
		food = food->next;
	}
	if (poison->x == food->x && poison->y == food->y) {
		return 1;
	}
	return 0;
}
int isInFood(Snake *p, Food *newfood) {
	Food *food = NULL;
	if (p->pfood != NULL) {
		food = p->pfood;
	}
	else {
		return 0;
	}
	while (food->next != NULL) {
		if (newfood->x == food->x && newfood->y == food->y) {
			return 1;
		}
		food = food->next;
	}
	if (newfood->x == food->x && newfood->y == food->y) {
		return 1;
	}
	return 0;
}
int isInFood(Snake *p, Star *star) {
	Food *food = NULL;
	if (p->pfood != NULL) {
		food = p->pfood;
	}
	else {
		return 0;
	}
	while (food->next != NULL) {
		if (star->x == food->x && star->y == food->y) {
			return 1;
		}
		food = food->next;
	}
	if (star->x == food->x && star->y == food->y) {
		return 1;
	}
	return 0;
}
int isInPoison(Snake *p, Poison *newpoison) {
	Poison *poison = NULL;
	if (p->ppoison != NULL) {
		poison = p->ppoison;
	}
	else {
		return 0;
	}
	while (poison->next != NULL) {
		if (newpoison->x == poison->x && newpoison->y == poison->y) {
			return 1;
		}
		poison = poison->next;
	}
	if (newpoison->x == poison->x && newpoison->y == poison->y) {
		return 1;
	}
	return 0;
}
int isInPoison(Snake *p, Food *food) {
	Poison *poison = NULL;
	if (p->ppoison != NULL) {
		poison = p->ppoison;
	}
	else {
		return 0;
	}
	while (poison->next != NULL) {
		if (food->x == poison->x && food->y == poison->y) {
			return 1;
		}
		poison = poison->next;
	}
	if (food->x == poison->x && food->y == poison->y) {
		return 1;
	}
	return 0;
}
int isInPoison(Snake *p, Star *star) {
	Poison *poison = NULL;
	if (p->ppoison != NULL) {
		poison = p->ppoison;
	}
	else {
		return 0;
	}
	while (poison->next != NULL) {
		if (star->x == poison->x && star->y == poison->y) {
			return 1;
		}
		poison = poison->next;
	}
	if (star->x == poison->x && star->y == poison->y) {
		return 1;
	}
	return 0;
}
int isInSnakeBody(Snake *p, Food *food) {
	SnakeBody *pb = p->head;
	while (pb->next != NULL) {
		if (food->x == pb->x && food->y == pb->y) {
			return 1;
		}
		pb = pb->next;
	}
	if (food->x == pb->x && food->y == pb->y) {
		return 1;
	}
	return 0;
}
int isInSnakeBody(Snake *p, Poison *poison) {
	SnakeBody *pb = p->head;
	while (pb->next != NULL) {
		if (poison->x == pb->x && poison->y == pb->y) {
			return 1;
		}
		pb = pb->next;
	}
	if (poison->x == pb->x && poison->y == pb->y) {
		return 1;
	}
	return 0;
}
int isInSnakeBody(Snake *p, Star *star) {
	SnakeBody *pb = p->head;
	while (pb->next != NULL) {
		if (star->x == pb->x && star->y == pb->y) {
			return 1;
		}
		pb = pb->next;
	}
	if (star->x == pb->x && star->y == pb->y) {
		return 1;
	}
	return 0;
}