#pragma once
#include "struct.h"
#include <graphics.h>
#include <stdio.h>
void saveProgress(Snake *p) {
	IMAGE save;
	getimage(&save, 0, 0, 630, 420);
	saveimage("d:\\snakefile\\resource\\InfiniteResource\\save.jpg", &save);
	//=============================
	FILE *fp = NULL;
	fopen_s(&fp, "d:\\snakefile\\resource\\InfiniteResource\\snake.txt", "w+");
	SnakeBody *sp = p->head;
	while (sp != NULL) {
		fprintf_s(fp, "%d", sp->x);
		fprintf_s(fp, "%s", "\n");
		fprintf_s(fp, "%d", sp->y);
		fprintf_s(fp, "%s", "\n");
		sp = sp->next;
	}
	fclose(fp);
	//==============================
	fopen_s(&fp, "d:\\snakefile\\resource\\InfiniteResource\\poison.txt", "w+");
	Poison *poison = p->ppoison;
	while (poison != NULL) {
		fprintf_s(fp, "%d", poison->x);
		fprintf_s(fp, "%s", "\n");
		fprintf_s(fp, "%d", poison->y);
		fprintf_s(fp, "%s", "\n");
		fprintf_s(fp, "%d", poison->style);//1是土豆雷
		fprintf_s(fp, "%s", "\n");
		poison = poison->next;
	}
	fclose(fp);
	//==============================
	fopen_s(&fp, "d:\\snakefile\\resource\\InfiniteResource\\food.txt", "w+");
	Food *food = p->pfood;
	while (food != NULL) {
		fprintf_s(fp, "%d", food->x);
		fprintf_s(fp, "%s", "\n");
		fprintf_s(fp, "%d", food->y);
		fprintf_s(fp, "%s", "\n");
		food = food->next;
	}
	fclose(fp);
	//==============================
	fopen_s(&fp, "d:\\snakefile\\resource\\InfiniteResource\\snakedata.txt", "w+");
	fprintf_s(fp, "%d", p->direction);//方向
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->length);//长度
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->score);//分数
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->speed);//速度
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->food);//是否有食物
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->poison);//是否有毒草
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->star);//是否有星星
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->foodRate);//食物产生速率
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->poisonRate);//毒草产生速率
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->starRate);//星星产生速率
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->foodNum);//食物数量
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->poisonNum);//毒草数量
	fprintf_s(fp, "%s", "\n");
	fclose(fp);
	//==============================
	if (p->star) {
		fopen_s(&fp, "d:\\snakefile\\resource\\InfiniteResource\\star.txt", "w+");
		fprintf_s(fp, "%d", p->pstar->x);
		fprintf_s(fp, "%s", "\n");
		fprintf_s(fp, "%d", p->pstar->y);
		fprintf_s(fp, "%s", "\n");
		fclose(fp);
	}
}