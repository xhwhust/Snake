#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <pthread.h>
#pragma comment(lib, "pthreadVC2.lib")
#include <Windows.h>
#pragma comment(lib,"winmm.lib")
#include "struct.h"
#include "isin.h"
#include "initmap.h"
IMAGE bk, f1, f2, m1, m2, xx1, xx2, boom1, boom2, win;
int fooddata[42][28] = { { 0 } };
int poisondata[42][28] = { { 0 } };
int poisonstyle[42][28] = { { 0 } };
int score = 0;
char name[20];
int mushroom = 0;
int mushNum = 10;
//static CRITICAL_SECTION cs;
//===========================================================
Snake* createSnake();
void printSnake(Snake *p);
void slowMove(Snake *p);
void printTail(Snake *p, int k);
void createFood(Snake *p);
void isEat(Snake *p);
void isDead(Snake *p);
void isHit(Snake *p);
void addHead(Snake *p);
void cutTail(Snake *p, int k);
void isPoison(Snake *p);
void createPoison(Snake *p);
void dead(Snake *p);
void* updateProgressBar(void *data);
void victory();
void isHitWall(Snake *p);
int getScore();
void saveScore(int score);
void rankingSave();
void hidePoison();
void showPoison();
void clearPoison();
void createMushroom(Snake *p, int n);
//int isInSnakeBody(Snake *p, Food *food);
//int isInSnakeBody(Snake *p, Poison *poison);
//int isInFood(Snake *p, Poison *poison);
//int isInFood(Snake *p, Food *newfood);
//int isInPoison(Snake *p, Food *food);
//int isInPoison(Snake *p, Poison *newpoison);
//===========================================================
int main() {
	initgraph(630, 460);
	//initgraph(630, 440);
	initmapD();//地图初始化
			   //loadimage(&bk, "snakefile\\pic2.jpg", 630, 420);
	loadimage(&bk, "d:\\snakefile\\map-4.jpg", 630, 420);//初始化背景图片
	putimage(0, 0, &bk);
	loadimage(&f1, "d:\\snakefile\\jl.jpg", 21, 21);
	loadimage(&f2, "d:\\snakefile\\ym.jpg", 21, 21);
	loadimage(&m1, "d:\\snakefile\\mushroom1.jpg", 15, 15);
	loadimage(&m2, "d:\\snakefile\\mushroom2.jpg", 15, 15);
	loadimage(&xx1, "d:\\snakefile\\xx1.jpg", 15, 15);
	loadimage(&xx2, "d:\\snakefile\\xx2.jpg", 15, 15);
	loadimage(&boom1, "d:\\snakefile\\potato1.jpg", 15, 15);
	loadimage(&boom2, "d:\\snakefile\\potato2.jpg", 15, 15);
	loadimage(&win, "d:\\snakefile\\win.jpg", 630, 420);
	Snake *snake = createSnake();
	printSnake(snake);//产生并且打印一条最初的蛇
	char c;//保存键盘读取的字符
	int prelength = snake->length;//用来保证在蛇的长度没有发生改变的情况下，不会重复产生毒草
	int createMoreFood = 0;
	settextstyle(15, 0, _T("宋体"));
	outtextxy(0, 445, _T("当前吃到食物数量："));
	//setfillcolor(GREEN);
	//bar(0,420,21,420+21);
	char s[50];
	int maxscore = getScore();
	sprintf_s(s, "%d", maxscore);
	outtextxy(180, 445, _T("通关最少食物数量："));
	outtextxy(320, 445, s);
	//PlaySound(TEXT("d:\\snakefile\\Trespassing.wav"), NULL, SND_FILENAME | SND_ASYNC);
	//PlaySound(TEXT("d:\\snakefile\\dragon.wav"), NULL, SND_FILENAME | SND_ASYNC);
	//PlaySound(TEXT("d:\\snakefile\\because.wav"), NULL, SND_FILENAME | SND_ASYNC);
	PlaySound(TEXT("d:\\snakefile\\mirror.wav"), NULL, SND_FILENAME | SND_ASYNC);
	while (1) {
		if (createMoreFood % 100 == 0) {
			mushNum++;
		}
		score = snake->score;
		if (snake->length == 31) {
			victory();
		}
		sprintf_s(s, "%d ", snake->score);
		outtextxy(140, 445, s);
		createMoreFood++;
		if (!snake->food || createMoreFood == 1 || createMoreFood % 120 == 0) {//如果不存在食物，则产生食物
			createFood(snake);//保存产生的食物坐标
		}
		//毒草产生条件：1.初始时或者被吃掉时（以保证毒草只增不减）
		//              2.蛇的长度刚好是一个数的倍数
		if (!snake->poison || createMoreFood == 1 || ((snake->length) % 2 == 0 && snake->length != prelength) || createMoreFood % 60 == 0) {
			createPoison(snake);
		}
		if (mushroom && createMoreFood % 3 == 0) {
			hidePoison();
		}
		else if(mushroom){
			showPoison();
		}
		if (!mushroom && createMoreFood % 79 == 0) {
			mushroom = 1;
			createMushroom(snake, mushNum);
		}
		if (mushroom && createMoreFood % 129 == 0) {
			mushroom = 0;
			clearPoison();
		}
		prelength = snake->length;//操作完成后，保存当前长度
		if (_kbhit()) {//如果键盘输入，则读取
			if (c = _getch()) {
				if (c == 27) {
					exit(0);
					closegraph();
				}
				c = _getch();
				if (c == 72 && snake->direction != 2) {
					snake->direction = 1;
					snake->dx = 0;
					snake->dy = -15;
				}
				if (c == 80 && snake->direction != 1) {
					snake->direction = 2;
					snake->dx = 0;
					snake->dy = 15;
				}
				if (c == 75 && snake->direction != 4) {
					snake->direction = 3;
					snake->dx = -15;
					snake->dy = 0;
				}
				if (c == 77 && snake->direction != 3) {
					snake->direction = 4;
					snake->dx = 15;
					snake->dy = 0;
				}
			}
		}
		slowMove(snake);//移动蛇
		isEat(snake);//判断是否吃到了食物
		isPoison(snake);//判断是否吃到了毒草
		isDead(snake);//判断是否撞到自己的身体
		isHit(snake);//判断是否撞到边界
		isHitWall(snake);//判断是否撞墙
	}
	_getch();
	closegraph();
	return 0;
}
//===========================================================
void createMushroom(Snake *p ,int n) {
	int k = 0;
	while (k < n) {
		srand((unsigned)time(NULL));
		Poison *poison = (Poison*)malloc(sizeof(Poison));
		int x = 0;
		int y = 0;
		x = rand() % 42;
		y = rand() % 28;
		poison->x = x * 15 + 7;
		poison->y = y * 15 + 7;
		while (map[x][y] || fooddata[x][y] || poisondata[x][y] || isInSnakeBody(p, poison)) {
			x = rand() % 42;
			y = rand() % 28;
			poison->x = x * 15 + 7;
			poison->y = y * 15 + 7;
		}
		poisondata[x][y] = 1;
		//poisonstyle[x][y] = rand() % 4 + 1;
		poisonstyle[x][y] = 2;
		if (poisonstyle[x][y] != 1) {
			putimage((poison->x) - 7, (poison->y) - 7, &m2, NOTSRCERASE);//掩码
			putimage((poison->x) - 7, (poison->y) - 7, &m1, SRCINVERT);//精灵
		}
		else {
			putimage((poison->x) - 7, (poison->y) - 7, &boom2, NOTSRCERASE);//掩码
			putimage((poison->x) - 7, (poison->y) - 7, &boom1, SRCINVERT);//精灵
		}
		free(poison);
		k++;
	}
}
void clearPoison() {
	IMAGE temp;
	for (int i = 0; i < 42; i++) {
		for (int j = 0; j < 28; j++) {
			if (poisonstyle[i][j] != 1 && poisonstyle[i][j] != 0) {
				poisondata[i][j] = 0;
				poisonstyle[i][j] = 0;
				SetWorkingImage(&bk);
				getimage(&temp, i * 15, j * 15, 15, 15);
				SetWorkingImage();
				putimage(i * 15, j * 15, &temp);
			}
		}
	}
}
void hidePoison() {
	IMAGE temp;
	for (int i = 0; i < 42; i++) {
		for (int j = 0; j < 28; j++) {
			if (poisonstyle[i][j] != 1 && poisonstyle[i][j] != 0) {
				SetWorkingImage(&bk);
				getimage(&temp, i * 15, j * 15, 15, 15);
				SetWorkingImage();
				putimage(i * 15, j * 15, &temp);
			}
		}
	}
}
void showPoison() {
	for (int i = 0; i < 42; i++) {
		for (int j = 0; j < 28; j++) {
			if (poisonstyle[i][j] != 1 && poisonstyle[i][j] != 0) {
				putimage(i * 15, j * 15, &m2, NOTSRCERASE);//掩码
				putimage(i * 15, j * 15, &m1, SRCINVERT);//精灵
			}
		}
	}
}
void rankingSave() {
	FILE *fp = NULL;
	fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\player.txt", "r+");
	fscanf_s(fp, "%s", name, 20);
	fclose(fp);
	fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\map4\\ranking.txt", "a+");
	fprintf(fp, "%s", "\n");
	fprintf(fp, "%s", name);
	fprintf(fp, "%s", "\n");
	fprintf(fp, "%d", score);
	fclose(fp);
	int i = 0;
	if (fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\map4\\num.txt", "r") == 0) {
		fscanf_s(fp, "%d", &i);
		fclose(fp);
		i++;
		fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\map4\\num.txt", "w+");
		fprintf_s(fp, "%d", i);
		fclose(fp);
	}
	else {
		fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\map4\\num.txt", "w+");
		fprintf_s(fp, "%d", 1);
		fclose(fp);
	}
}
int getScore() {
	FILE *fp = NULL;
	int score = 0;
	if (fopen_s(&fp, "d:\\snakefile\\resource\\map4score.txt", "r+") == 0) {
		fscanf_s(fp, "%d", &score);
		fclose(fp);
	}
	return score;
}
void saveScore(int score) {
	FILE *fp = NULL;
	fopen_s(&fp, "d:\\snakefile\\resource\\map4score.txt", "w+");
	fprintf_s(fp, "%d", score);
	fclose(fp);
}
void isHitWall(Snake *p) {
	if (map[(p->head->x - 7) / 15][(p->head->y - 7) / 15]) {
		dead(p);
	}
}
void* updateProgressBar(void *data) {
	//EnterCriticalSection(&cs);
	Data *d = (Data*)data;
	if (d->prelength < d->nowlength) {
		for (int i = 0; i < (d->nowlength) - (d->prelength); i++) {
			for (int k = 0; k < 7; k++) {
				IMAGE green;
				IMAGE m;
				loadimage(&green, "d:\\snakefile\\progressbar1.jpg", 21, 21);
				//======
				//getimage(&m, (d->prelength + i - 2) * 21 + (k + 1) * 3, 420, 21 - (k + 1) * 3, 21);
				//SetWorkingImage(&green);
				//putimage(0, 0, &m);
				//SetWorkingImage();
				//======
				putimage((d->prelength + i - 2) * 21 + (k + 1) * 3, 420, &green);
				Sleep(30);
			}
			Sleep((15 * i - i * i) / 10 * 2);
		}
	}
	if (d->prelength > d->nowlength) {
		for (int i = 0; i < (d->prelength) - (d->nowlength); i++) {
			for (int k = 0; k < 7; k++) {
				IMAGE black;
				loadimage(&black, "d:\\snakefile\\black.jpg", 21, 21);
				putimage((d->prelength - i - 1) * 21 - (k + 1) * 3, 420, &black);
				//setfillcolor(BLACK);
				//bar((d->prelength - i) * 21 - (k + 1) * 3, 420, (d->prelength - i) * 21 - (k + 1) * 3 + 21, 420 + 21);
				Sleep(30);
			}
			Sleep((15 * i - i * i) / 10 * 2);
		}
	}
	//LeaveCriticalSection(&cs);
	pthread_exit((void *)0);
	return 0;
}
void dead(Snake *p) {
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
	PlaySound(TEXT("d:\\snakefile\\gameover.wav"), NULL, SND_FILENAME | SND_ASYNC);
	IMAGE lose;
	loadimage(&lose, "d:\\snakefile\\lose.jpg", 630, 444);
	putimage(0, 0, &lose);
	//putimage(0, 0, &bk);
	//setbkmode(TRANSPARENT);
	//outtextxy(280, 140, "游戏结束！");
	//_getch();
	_getch();
	closegraph();
	exit(0);
}
void victory() {
	rankingSave();
	if (getScore() != 0 && score < getScore()) {
		saveScore(score);
	}
	else if (getScore() == 0) {
		saveScore(score);
	}
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
	putimage(0, 0, &win);
	//putimage(0, 0, &bk);
	//putimage(0, 0, &bk);
	//setbkmode(TRANSPARENT);
	//outtextxy(260, 140, "恭喜你游戏胜利！");
	//Sleep(1000);
	_getch();
	_getch();
	closegraph();
	exit(0);
}
void cutTail(Snake *p, int k) {
	p->length -= k;
	SnakeBody *pb = p->tail;
	for (int i = 0; i < k; i++) {
		pb = pb->pre;
	}
	while (pb != NULL) {
		IMAGE img;
		SetWorkingImage(&bk);
		getimage(&img, (pb->x) - 7, (pb->y) - 7, 15, 15);
		SetWorkingImage();
		putimage((pb->x) - 7, (pb->y) - 7, &img);
		pb = pb->next;
	}
	for (int i = 0; i < k; i++) {//删除蛇的链表中的节点
		p->tail = p->tail->pre;
		SnakeBody *temp = p->tail->next;
		free(temp);
		p->tail->next = NULL;
	}
	Data *data = (Data*)malloc(sizeof(Data));
	data->prelength = (p->length) + k;
	data->nowlength = p->length;
	//InitializeCriticalSection(&cs);
	pthread_t thread;
	pthread_create(&thread, NULL, updateProgressBar, (void*)data);
	//DeleteCriticalSection(&cs);
}
void isHit(Snake *p) {//判断是否撞到边界
	if (p->head->x < 0 || p->head->x > 640 || p->head->y < 0 || p->head->y > 420) {
		dead(p);
	}
}
void isDead(Snake *p) {//判断是否撞到自己
	SnakeBody *pb = p->head->next;
	while (pb != NULL) {
		if (p->head->x == pb->x && p->head->y == pb->y) {
			dead(p);
		}
		pb = pb->next;
	}
}
void isEat(Snake *p) {
	if (fooddata[(p->head->x - 7) / 15][(p->head->y - 7) / 15]) {
		p->score++;
		fooddata[(p->head->x - 7) / 15][(p->head->y - 7) / 15] = 0;
		if (p->speed < 20) {
			p->speed++;
		}
		addHead(p);
		Data *data = (Data*)malloc(sizeof(Data));
		data->prelength = p->length;
		data->nowlength = p->length + 1;
		p->length++;
		p->food = 0;
		//InitializeCriticalSection(&cs);
		pthread_t thread;
		pthread_create(&thread, NULL, updateProgressBar, (void*)data);
		//DeleteCriticalSection(&cs);
	}
}
void isPoison(Snake *p) {
	if (poisondata[(p->head->x - 7) / 15][(p->head->y - 7) / 15]) {
		poisondata[(p->head->x - 7) / 15][(p->head->y - 7) / 15] = 0;
		if (p->length == 1) {
			dead(p);
		}
		p->poison = 0;
		if (poisonstyle[(p->head->x - 7) / 15][(p->head->y - 7) / 15] != 1) {
			if (p->speed > 12) {
				p->speed--;
			}
			cutTail(p, 1);
		}
		else {
			cutTail(p, (p->length) / 2);
		}
		poisonstyle[(p->head->x - 7) / 15][(p->head->y - 7) / 15] = 0;
	}
}
void addHead(Snake *p) {
	SnakeBody *newhead = (SnakeBody*)malloc(sizeof(SnakeBody));
	newhead->x = p->head->x;
	newhead->y = p->head->y;
	p->head->pre = newhead;
	newhead->next = p->head;
	newhead->pre = NULL;
	p->head = newhead;
	if (p->direction == 3 || p->direction == 4) {
		for (int k = 0; k < 5; k++) {
			int i = (p->dx) / 5;
			p->head->x += i;
			setfillcolor(RGB(135, 206, 235));
			bar((p->head->x) - 7, (p->head->y) - 7, (p->head->x) - 7 + 14, (p->head->y) - 7 + 14);
			Sleep(20);
		}
	}
	if (p->direction == 1 || p->direction == 2) {
		for (int k = 0; k < 5; k++) {
			int i = (p->dy) / 5;
			p->head->y += i;
			setfillcolor(RGB(135, 206, 235));
			bar((p->head->x) - 7, (p->head->y) - 7, (p->head->x) - 7 + 14, (p->head->y) - 7 + 14);
			Sleep(20);
		}
	}
}
void slowMove(Snake *p) {
	SnakeBody *newhead = (SnakeBody*)malloc(sizeof(SnakeBody));
	newhead->x = p->head->x;
	newhead->y = p->head->y;
	p->head->pre = newhead;
	newhead->next = p->head;
	newhead->pre = NULL;
	p->head = newhead;
	if (p->direction == 3 || p->direction == 4) {
		for (int k = 0; k < 5; k++) {
			int i = (p->dx) / 5;
			p->head->x += i;
			setfillcolor(RGB(135, 206, 235));
			bar((p->head->x) - 7, (p->head->y) - 7, (p->head->x) - 7 + 14, (p->head->y) - 7 + 14);
			printTail(p, k);
			Sleep(p->speed);
		}
	}
	if (p->direction == 1 || p->direction == 2) {
		for (int k = 0; k < 5; k++) {
			int i = (p->dy) / 5;
			p->head->y += i;
			setfillcolor(RGB(135, 206, 235));
			bar((p->head->x) - 7, (p->head->y) - 7, (p->head->x) - 7 + 14, (p->head->y) - 7 + 14);
			printTail(p, k);
			Sleep(p->speed);
		}
	}
	SnakeBody *temp = p->tail;
	p->tail = p->tail->pre;
	free(temp);
	p->tail->next = NULL;
}
void printTail(Snake *p, int k) {//打印尾巴，分五次打印，以保证流畅
	int dx = (p->tail->x) - (p->tail->pre->x);
	int dy = (p->tail->y) - (p->tail->pre->y);
	dx = -dx;
	dy = -dy;
	if (dx != 0) {
		IMAGE img;
		int i = (dx / 5)*(k + 1);
		SetWorkingImage(&bk);
		getimage(&img, (p->tail->x) - 7, (p->tail->y) - 7, 15, 15);
		SetWorkingImage(&img);
		setfillcolor(RGB(135, 206, 235));
		bar(i, 0, i + 14, 14);
		SetWorkingImage();
		putimage((p->tail->x) - 7, (p->tail->y) - 7, &img);
	}
	if (dy != 0) {
		IMAGE img;
		int i = (dy / 5)*(k + 1);
		SetWorkingImage(&bk);
		getimage(&img, (p->tail->x) - 7, (p->tail->y) - 7, 15, 15);
		SetWorkingImage(&img);
		setfillcolor(RGB(135, 206, 235));
		bar(0, i, 14, i + 14);
		SetWorkingImage();
		putimage((p->tail->x) - 7, (p->tail->y) - 7, &img);
	}
}
void printSnake(Snake *p) {//打印整条蛇的函数
	SnakeBody *pb = p->head;
	setfillcolor(RGB(135, 206, 235));
	while (pb->next != NULL) {
		bar((pb->x) - 7, (pb->y) - 7, (pb->x) - 7 + 14, (pb->y) - 7 + 14);
		pb = pb->next;
	}
	bar((pb->x) - 7, (pb->y) - 7, (pb->x) - 7 + 14, (pb->y) - 7 + 14);
}
void createFood(Snake *p) {//创造食物
	p->food = 1;
	srand((unsigned)time(NULL));
	int x = 0;
	int y = 0;
	x = rand() % 42;
	y = rand() % 28;
	Food *food = (Food*)malloc(sizeof(Food));
	food->x = x * 15 + 7;
	food->y = y * 15 + 7;
	while (map[x][y] || fooddata[x][y] || poisondata[x][y] || isInSnakeBody(p, food)) {
		x = rand() % 42;
		y = rand() % 28;
		food->x = x * 15 + 7;
		food->y = y * 15 + 7;
	}
	fooddata[x][y] = 1;
	putimage((food->x) - 10, (food->y) - 10, &f2, NOTSRCERASE);//掩码
	putimage((food->x) - 10, (food->y) - 10, &f1, SRCINVERT);//精灵
	free(food);
}
void createPoison(Snake *p) {//创造毒草
	p->poison = 1;
	srand((unsigned)time(NULL));
	Poison *poison = (Poison*)malloc(sizeof(Poison));
	int x = 0;
	int y = 0;
	x = rand() % 42;
	y = rand() % 28;
	poison->x = x * 15 + 7;
	poison->y = y * 15 + 7;
	while (map[x][y] || fooddata[x][y] || poisondata[x][y] || isInSnakeBody(p, poison)) {
		x = rand() % 42;
		y = rand() % 28;
		poison->x = x * 15 + 7;
		poison->y = y * 15 + 7;
	}
	poisondata[x][y] = 1;
	//poisonstyle[x][y] = rand() % 4 + 1;
	poisonstyle[x][y] = 1;
	if (poisonstyle[x][y] != 1) {
		putimage((poison->x) - 7, (poison->y) - 7, &m2, NOTSRCERASE);//掩码
		putimage((poison->x) - 7, (poison->y) - 7, &m1, SRCINVERT);//精灵
	}
	else {
		putimage((poison->x) - 7, (poison->y) - 7, &boom2, NOTSRCERASE);//掩码
		putimage((poison->x) - 7, (poison->y) - 7, &boom1, SRCINVERT);//精灵
	}
	free(poison);
}
Snake* createSnake() {//创造蛇
	Snake *p;
	SnakeBody *head;
	SnakeBody *tail;
	p = (Snake*)malloc(sizeof(Snake));
	head = (SnakeBody*)malloc(sizeof(SnakeBody));
	tail = (SnakeBody*)malloc(sizeof(SnakeBody));
	head->x = 1 * 15 + 7;
	head->y = 0 * 15 + 7;
	tail->x = 0 * 15 + 7;
	tail->y = 0 * 15 + 7;
	head->next = tail;
	head->pre = NULL;
	tail->next = NULL;
	tail->pre = head;
	p->head = head;
	p->tail = tail;
	p->food = 0;
	p->poison = 0;
	p->star = 0;
	p->length = 1;
	p->direction = 4;
	p->speed = 20;
	p->dx = 15;
	p->dy = 0;
	p->pfood = NULL;
	p->ppoison = NULL;
	p->score = 0;
	return p;
}