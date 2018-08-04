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
		fprintf_s(fp, "%d", poison->style);//1��������
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
	fprintf_s(fp, "%d", p->direction);//����
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->length);//����
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->score);//����
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->speed);//�ٶ�
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->food);//�Ƿ���ʳ��
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->poison);//�Ƿ��ж���
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->star);//�Ƿ�������
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->foodRate);//ʳ���������
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->poisonRate);//���ݲ�������
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->starRate);//���ǲ�������
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->foodNum);//ʳ������
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", p->poisonNum);//��������
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