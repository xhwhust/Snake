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
#include "save.h"
IMAGE bk, f1, f2, m1, m2, xx1, xx2, boom1, boom2;
//===========================================================
int score = 0;
int createMoreFood = 0;
char name[20];
int mushNum = 10;
//static CRITICAL_SECTION cs;
//===========================================================
Snake* createSnake();
void printSnake(Snake *p);
void slowMove(Snake *p);
void printTail(Snake *p, int k);
Food* createFood(Snake *p);
void isEat(Snake *p);
void isDead(Snake *p);
void isHit(Snake *p);
void addHead(Snake *p);
void cutTail(Snake *p, int k);
void isPoison(Snake *p);
Poison* createPoison(Snake *p, Food *food);
void dead();
void* updateProgressBar(void *data);
Star* createStar(Snake *p);
void isEatStar(Snake *p);
void victory();
int getScore();
void saveScore(int score);
void saveProgress(Snake *p);
void rankingSave();
void getName();
void hidePoison(Snake *p);
void showPoison(Snake *p);
Poison* createMushroom(Snake *p, int n);
void clearMushroom(Snake *p);
//int isInSnakeBody(Snake *p, Food *food);
//int isInSnakeBody(Snake *p, Poison *poison);
//int isInFood(Snake *p, Poison *poison);
//int isInFood(Snake *p, Food *newfood);
//int isInPoison(Snake *p, Food *food);
//int isInPoison(Snake *p, Poison *newpoison);
//===========================================================
int main() {
	//initgraph(630, 420);
	//getName();
	initgraph(630, 445);
	//loadimage(&bk, "d:\\snakefile\\p2.jpg", 630, 420);
	loadimage(&bk, "d:\\snakefile\\infinite.jpg", 630, 420);//初始化背景图片
	putimage(0, 0, &bk);
	loadimage(&f1, "d:\\snakefile\\jl.jpg", 21, 21);
	loadimage(&f2, "d:\\snakefile\\ym.jpg", 21, 21);
	loadimage(&m1, "d:\\snakefile\\mushroom1.jpg", 15, 15);
	loadimage(&m2, "d:\\snakefile\\mushroom2.jpg", 15, 15);
	loadimage(&xx1, "d:\\snakefile\\xx1.jpg", 15, 15);
	loadimage(&xx2, "d:\\snakefile\\xx2.jpg", 15, 15);
	loadimage(&boom1, "d:\\snakefile\\potato1.jpg", 15, 15);
	loadimage(&boom2, "d:\\snakefile\\potato2.jpg", 15, 15);
	Snake *snake = createSnake();
	printSnake(snake);//产生并且打印一条最初的蛇
	char c;//保存键盘读取的字符
	Food *food = NULL;//食物
	Poison *poison = NULL;
	Star *star = NULL;
	int prelength = snake->length;//用来保证在蛇的长度没有发生改变的情况下，不会重复产生毒草
	settextstyle(15, 0, _T("宋体"));
	outtextxy(0, 425, _T("分数为："));
	char s[50];
	int maxscore = getScore();
	sprintf_s(s, "%d", maxscore);
	outtextxy(100, 425, _T("最高分数："));
	outtextxy(175, 425, s);
	outtextxy(220, 425, _T("蛇的长度为："));
	sprintf_s(s, "%d", snake->length);
	outtextxy(310, 425, s);
	//settextstyle(15, 0, _T("宋体"));
	//outtextxy(0, 420, _T("蛇的长度为："));
	//setfillcolor(GREEN);
	//bar(0,420,21,420+21);
	//char s[5];
	//PlaySound(TEXT("d:\\snakefile\\chinax.wav"), NULL, SND_FILENAME | SND_ASYNC);
	PlaySound(TEXT("d:\\snakefile\\we.wav"), NULL, SND_FILENAME | SND_ASYNC);
	while (1) {
		//if (createMoreFood % 100 == 0) {
			//mushNum += 1;
		//}
		//sprintf_s(s, "%d", createMoreFood);
		//outtextxy(400, 425, s);
		sprintf_s(s, "%d ", snake->length);
		outtextxy(310, 425, s);
		if (snake->length > 20 && createMoreFood % 100 == 0) {
			snake->score += 30;
			//outtextxy(340, 425,"增长啦！！！");
		}
		score = snake->score;
		sprintf_s(s, "%d ", snake->score);
		outtextxy(60, 425, s);
		createMoreFood++;
		if (!snake->star && createMoreFood % snake->starRate == 0) {
			if (snake->starRate > 160) {
				snake->starRate -= 20;
			}
			snake->star = 1;
			star = createStar(snake);
			snake->pstar = star;
		}
		if (!snake->food || createMoreFood % snake->foodRate == 0) {//如果不存在食物，则产生食物
			snake->food = 1;
			snake->foodNum++;
			food = createFood(snake);//保存产生的食物坐标
			if (snake->pfood == NULL) {
				snake->pfood = food;
			}
			else {
				Food* f = snake->pfood;
				while (f->next != NULL) {
					f = f->next;
				}
				f->next = food;
				food->pre = f;
			}
		}
		//毒草产生条件：1.初始时或者被吃掉时（以保证毒草只增不减）
		//              2.蛇的长度刚好是一个数的倍数
		if (!snake->poison || ((snake->length) % 2 == 0 && snake->length != prelength) || createMoreFood % snake->poisonRate == 0) {
			snake->poison = 1;//产生毒草后标记为1
			snake->poisonNum++;
			poison = createPoison(snake, food);
			if (snake->ppoison == NULL) {
				snake->ppoison = poison;
			}
			else {
				Poison *p = snake->ppoison;
				while (p->next != NULL) {
					p = p->next;
				}
				p->next = poison;
				poison->pre = p;
			}
		}
		/*if (createMoreFood % 79 == 0 && snake->mushroom == 0) {
			snake->mushroom = 1;
			Poison *ps = createMushroom(snake,mushNum);	
			Poison *pr = snake->ppoison;
			while (pr->next != NULL) {
				pr = pr->next;
			}
			pr->next = ps;
			ps->pre = pr;
		}
		if (createMoreFood % 119 == 0 && snake->mushroom) {
			snake->mushroom = 0;
			clearMushroom(snake);
		}
		//========================
		if (createMoreFood % 3 == 0) {
			hidePoison(snake);
		}
		else if(snake->mushroom){
			showPoison(snake);
		}*/
		//========================
		prelength = snake->length;//操作完成后，保存当前长度
		if (_kbhit()) {//如果键盘输入，则读取
			if (c = _getch()) {
				if (c == 27) {
					exit(0);
					closegraph();
				}
				if (c == ' ') {
					PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
					saveProgress(snake);
					IMAGE x;
					loadimage(&x, "d:\\snakefile\\savesuccessful.jpg", 630, 445);
					putimage(0, 0, &x);
					_getch();
					closegraph();
					exit(0);
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
		if (snake->star) {
			isEatStar(snake);
		}
		isPoison(snake);//判断是否吃到了毒草
		isDead(snake);//判断是否撞到自己的身体
		isHit(snake);//判断是否撞墙
	}
	_getch();
	closegraph();
	return 0;
}
//===========================================================
void clearMushroom(Snake *p) {
	Poison *head = p->ppoison;
	Poison *ps;
	Poison *t;
	while (head->next->style != 0) {
		head = head->next;
	}
	ps = head->next;
	IMAGE temp;
	while (ps->style == 0) {
		SetWorkingImage(&bk);
		getimage(&temp, (ps->x) - 7, (ps->y) - 7, 15, 15);
		SetWorkingImage();
		putimage((ps->x) - 7, (ps->y) - 7, &temp);
		t = ps;
		ps = ps->next;
		free(t);
	}
	head->next = ps;
	ps->pre = head;
}
Poison* createMushroom(Snake *p,int n) {
	srand((unsigned)time(NULL));
	Poison *head = (Poison*)malloc(sizeof(Poison)); 
	Poison *ps = (Poison*)malloc(sizeof(Poison));
	ps = head;
	int k = 0;
	while (k < n) {
		Poison *poison = (Poison*)malloc(sizeof(Poison));
		poison->next = NULL;
		poison->pre = NULL;
		//poison->style = rand() % 3;
		poison->style = 0;
		poison->x = (rand() % 41) * 15 + 7;
		poison->y = (rand() % 27) * 15 + 7;
		while ((p->star && poison->x == p->pstar->x && poison->y == p->pstar->y) || isInSnakeBody(p, poison) || isInFood(p, poison) || isInPoison(p, poison)) {
			poison->x = (rand() % 41) * 15 + 7;
			poison->y = (rand() % 27) * 15 + 7;
		}
		if (poison->style == 1) {//1是土豆雷
			putimage((poison->x) - 7, (poison->y) - 7, &boom2, NOTSRCERASE);//掩码
			putimage((poison->x) - 7, (poison->y) - 7, &boom1, SRCINVERT);//精灵
		}
		else {
			putimage((poison->x) - 7, (poison->y) - 7, &m2, NOTSRCERASE);//掩码
			putimage((poison->x) - 7, (poison->y) - 7, &m1, SRCINVERT);//精灵
		}
		if (head == NULL) {
			head = poison;
		}
		else {
			ps->next = poison;
			poison->pre = ps;
			ps = poison;
		}
		k++;
	}
	//setfillcolor(GREEN);
	//bar((poison->x) - 7, (poison->y) - 7, (poison->x) - 7 + 14, (poison->y) - 7 + 14);
	return head;
}
void hidePoison(Snake *p) {
	Poison *ps = p->ppoison;
	IMAGE temp;
	while (ps != NULL) {
		if (ps->style != 1) {
			SetWorkingImage(&bk);
			getimage(&temp,(ps->x)-7,(ps->y)-7,15,15);
			SetWorkingImage();
			putimage((ps->x) - 7, (ps->y) - 7,&temp);
		}
		ps = ps->next;
	}
}
void showPoison(Snake *p) {
	Poison *ps = p->ppoison;
	while (ps != NULL) {
		if (ps->style != 1) {
			putimage((ps->x) - 7, (ps->y) - 7, &m2, NOTSRCERASE);//掩码
			putimage((ps->x) - 7, (ps->y) - 7, &m1, SRCINVERT);//精灵
		}
		ps = ps->next;
	}
}
void rankingSave() {
	FILE *fp = NULL;
	fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\player.txt", "r+");
	fscanf_s(fp, "%s", name, 20);
	fclose(fp);
	fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\ranking.txt", "a+");
	fprintf(fp, "%s", "\n");
	fprintf(fp, "%s", name);
	fprintf(fp, "%s", "\n");
	fprintf(fp, "%d", score);
	fclose(fp);
	int i = 0;
	if (fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\num.txt", "r") == 0) {
		fscanf_s(fp, "%d", &i);
		fclose(fp);
		i++;
		fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\num.txt", "w+");
		fprintf_s(fp, "%d", i);
		fclose(fp);
	}
	else {
		fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\num.txt", "w+");
		fprintf_s(fp, "%d", 1);
		fclose(fp);
	}
}
void getName() {
	system("mode con cols=40 lines=10");
	printf("敢问英雄大名！\n");
	scanf_s("%s", name, 20);
}
/*void saveProgress(Snake *p) {
	IMAGE save;
	getimage(&save,0,0,630,420);
	saveimage("d:\\snakefile\\resource\\InfiniteResource\\save.jpg",&save);
	//=============================
	FILE *fp = NULL;
	fopen_s(&fp,"d:\\snakefile\\resource\\InfiniteResource\\snake.txt","w+");
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
	fprintf_s(fp, "%d", foodRate);//食物产生速率
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", poisonRate);//毒草产生速率
	fprintf_s(fp, "%s", "\n");
	fprintf_s(fp, "%d", starRate);//星星产生速率
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
}*/
int getScore() {
	FILE *fp = NULL;
	int score = 0;
	if (fopen_s(&fp, "d:\\snakefile\\resource\\InfiniteScore.txt", "r+") == 0) {
		fscanf_s(fp, "%d", &score);
		fclose(fp);
	}
	return score;
}
void saveScore(int score) {
	FILE *fp = NULL;
	fopen_s(&fp, "d:\\snakefile\\resource\\InfiniteScore.txt", "w+");
	fprintf_s(fp, "%d", score);
	fclose(fp);
}
void isEatStar(Snake *p) {
	if (p->head->x == p->pstar->x && p->head->y == p->pstar->y) {
		p->star = 0;
		int k = 0;
		Poison *poison = p->ppoison;
		while (k < 10 && poison != NULL) {
			SetWorkingImage(&bk);
			IMAGE i;
			getimage(&i, (poison->x) - 7, (poison->y) - 7, 15, 15);
			SetWorkingImage();
			putimage((poison->x) - 7, (poison->y) - 7, &i);
			k++;
			poison = poison->next;
		}
		if (k < 10) {
			p->poison = 0;
			p->poisonNum = 0;
			poison = p->ppoison;
			p->ppoison = NULL;
			while (poison->next != NULL) {
				Poison *temp = poison;
				poison = poison->next;
				free(temp);
			}
			free(poison);
		}
		else {
			p->poisonNum -= 10;
			p->ppoison = poison;
			poison = poison->pre;
			p->ppoison->pre = NULL;
			while (poison->pre != NULL) {
				Poison *temp = poison;
				poison = poison->pre;
				free(temp);
			}
			free(poison);
		}
	}
}
void* updateProgressBar(void *data) {
	//EnterCriticalSection(&cs);
	Data *d = (Data*)data;
	if (d->nowlength == 32) {
		victory();
	}
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
void dead() {
	if (score > getScore()) {
		saveScore(score);
	}
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
	IMAGE lose;
	loadimage(&lose, "d:\\snakefile\\lose.jpg", 630, 420);
	putimage(0, 0, &lose);
	rankingSave();
	//putimage(0, 0, &bk);
	//setbkmode(TRANSPARENT);
	//outtextxy(280, 210, "游戏结束！");
	_getch();
	closegraph();
	exit(0);
}
void victory() {
	putimage(0, 0, &bk);
	setbkmode(TRANSPARENT);
	outtextxy(260, 210, "恭喜你游戏胜利！");
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
	/*IMAGE img;
	SetWorkingImage(&bk);
	getimage(&img, (pb->x) - 7, (pb->y) - 7, 15, 15);
	SetWorkingImage();
	putimage((pb->x) - 7, (pb->y) - 7, &img);*/
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
	//pthread_t thread;
	//pthread_create(&thread,NULL,updateProgressBar,(void*)data);
	//DeleteCriticalSection(&cs);
}
void isHit(Snake *p) {//判断是否撞到边界
	if (p->head->x < 0 || p->head->x > 640 || p->head->y < 0 || p->head->y > 420) {
		dead();
	}
}
void isDead(Snake *p) {//判断是否撞到自己
	SnakeBody *pb = p->head->next;
	while (pb != NULL) {
		if (p->head->x == pb->x && p->head->y == pb->y) {
			dead();
		}
		pb = pb->next;
	}
}
void isEat(Snake *p) {
	Food *food = p->pfood;
	int i = 1;
	while (i && food != NULL) {
		if (p->head->x == food->x && p->head->y == food->y) {
			p->foodNum--;
			if (food->pre != NULL) {
				if (food->next != NULL) {
					food->pre->next = food->next;
					food->next->pre = food->pre;
				}
				else {
					food->pre->next = NULL;
				}
				free(food);
				i = 0;
			}
			else {
				p->pfood = food->next;
				if (p->pfood != NULL) {
					p->pfood->pre = NULL;
				}
				free(food);
				i = 0;
			}
			p->score += 10;
			if (p->speed < 20) {
				p->speed++;
			}
			addHead(p);
			p->food = 0;
			Data *data = (Data*)malloc(sizeof(Data));
			data->prelength = p->length;
			data->nowlength = p->length + 1;
			//InitializeCriticalSection(&cs);
			//pthread_t thread;
			//pthread_create(&thread, NULL, updateProgressBar, (void*)data);
			//DeleteCriticalSection(&cs);
			p->length++;
		}
		if (i) {
			food = food->next;
		}
	}
	/*if (food->flag && p->head->x == food->x && p->head->y == food->y) {
	food->flag = 0;
	addHead(p);
	p->food = 0;
	Data *data = (Data*)malloc(sizeof(Data));
	data->prelength = p->length;
	data->nowlength = p->length + 1;
	pthread_t thread;
	pthread_create(&thread, NULL, updateProgressBar, (void*)data);
	p->length++;
	}*/
}
void isPoison(Snake *p) {
	Poison *poison = p->ppoison;
	int i = 1;
	while (i && poison != NULL) {
		if (p->head->x == poison->x && p->head->y == poison->y) {
			p->poisonNum--;
			if (p->length == 1) {
				dead();
			}
			if (poison->style == 1) {
				if (p->score - 20 > 0) {
					p->score -= 20;
				}
				else {
					p->score = 0;
				}
				cutTail(p, (p->length) / 2);
			}
			else {
				if (p->score - 15 > 0) {
					p->score -= 15;
				}
				else {
					p->score = 0;
				}
				cutTail(p, 1);
				p->speed--;
			}
			p->poison = 0;
			if (poison->pre != NULL) {
				if (poison->next != NULL) {
					poison->pre->next = poison->next;
					poison->next->pre = poison->pre;
				}
				else {
					poison->pre->next = NULL;
				}
				free(poison);
				i = 0;
			}
			else {
				p->ppoison = poison->next;
				if (p->ppoison != NULL) {
					p->ppoison->pre = NULL;
				}
				free(poison);
				i = 0;
			}
		}
		if (i) {
			poison = poison->next;
		}
	}
	/*if (poison->flag && p->head->x == poison->x && p->head->y == poison->y) {
	poison->flag = 0;
	if (p->length == 1) {
	dead();
	}
	//cutTail(p, (p->length) / 2);
	cutTail(p, 1);
	p->poison = 0;
	}*/
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
			//setfillcolor(RED);
			setfillcolor(RGB(153, 51, 250));
			bar((p->head->x) - 7, (p->head->y) - 7, (p->head->x) - 7 + 14, (p->head->y) - 7 + 14);
			Sleep(20);
		}
	}
	if (p->direction == 1 || p->direction == 2) {
		for (int k = 0; k < 5; k++) {
			int i = (p->dy) / 5;
			p->head->y += i;
			//setfillcolor(RED);
			setfillcolor(RGB(153, 51, 250));
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
			//setfillcolor(RED);
			setfillcolor(RGB(153, 51, 250));
			bar((p->head->x) - 7, (p->head->y) - 7, (p->head->x) - 7 + 14, (p->head->y) - 7 + 14);
			printTail(p, k);
			Sleep(p->speed);
		}
	}
	if (p->direction == 1 || p->direction == 2) {
		for (int k = 0; k < 5; k++) {
			int i = (p->dy) / 5;
			p->head->y += i;
			//setfillcolor(RED);
			setfillcolor(RGB(153, 51, 250));
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
		//setfillcolor(RED);
		setfillcolor(RGB(153, 51, 250));
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
		//setfillcolor(RED);
		setfillcolor(RGB(153, 51, 250));
		bar(0, i, 14, i + 14);
		SetWorkingImage();
		putimage((p->tail->x) - 7, (p->tail->y) - 7, &img);
	}
}
void printSnake(Snake *p) {//打印整条蛇的函数
	SnakeBody *pb = p->head;
	//setfillcolor(RED);
	setfillcolor(RGB(153, 51, 250));
	while (pb->next != NULL) {
		bar((pb->x) - 7, (pb->y) - 7, (pb->x) - 7 + 14, (pb->y) - 7 + 14);
		pb = pb->next;
	}
	bar((pb->x) - 7, (pb->y) - 7, (pb->x) - 7 + 14, (pb->y) - 7 + 14);
}
Food* createFood(Snake *p) {//创造食物
	srand((unsigned)time(NULL));
	Food *food = (Food*)malloc(sizeof(Food));
	food->next = NULL;
	food->pre = NULL;
	food->x = (rand() % 41) * 15 + 7;
	food->y = (rand() % 27) * 15 + 7;
	while ((p->star && food->x == p->pstar->x && food->y == p->pstar->y) || isInSnakeBody(p, food) || isInPoison(p, food) || isInFood(p, food)) {
		food->x = (rand() % 41) * 15 + 7;
		food->y = (rand() % 27) * 15 + 7;
	}
	putimage((food->x) - 10, (food->y) - 10, &f2, NOTSRCERASE);//掩码
	putimage((food->x) - 10, (food->y) - 10, &f1, SRCINVERT);//精灵
	return food;
}
Star* createStar(Snake *p) {
	srand((unsigned)time(NULL));
	Star *star = (Star*)malloc(sizeof(Star));
	star->x = (rand() % 40 + 1) * 15 + 7;
	star->y = (rand() % 26 + 1) * 15 + 7;
	while (isInSnakeBody(p, star) || isInPoison(p, star) || isInFood(p, star)) {
		star->x = (rand() % 41) * 15 + 7;
		star->y = (rand() % 27) * 15 + 7;
	}
	putimage((star->x) - 7, (star->y) - 7, &xx2, NOTSRCERASE);//掩码
	putimage((star->x) - 7, (star->y) - 7, &xx1, SRCINVERT);//精灵
	return star;
}
Poison* createPoison(Snake *p, Food *food) {//创造毒草
	srand((unsigned)time(NULL));
	Poison *poison = (Poison*)malloc(sizeof(Poison));
	poison->next = NULL;
	poison->pre = NULL;
	poison->style = rand() % 3;
	//poison->style = 1;
	poison->x = (rand() % 41) * 15 + 7;
	poison->y = (rand() % 27) * 15 + 7;
	while ((p->star && poison->x == p->pstar->x && poison->y == p->pstar->y) || isInSnakeBody(p, poison) || isInFood(p, poison) || isInPoison(p, poison)) {
		poison->x = (rand() % 41) * 15 + 7;
		poison->y = (rand() % 27) * 15 + 7;
	}
	if (poison->style == 1) {//1是土豆雷
		putimage((poison->x) - 7, (poison->y) - 7, &boom2, NOTSRCERASE);//掩码
		putimage((poison->x) - 7, (poison->y) - 7, &boom1, SRCINVERT);//精灵
	}
	else {
		putimage((poison->x) - 7, (poison->y) - 7, &m2, NOTSRCERASE);//掩码
		putimage((poison->x) - 7, (poison->y) - 7, &m1, SRCINVERT);//精灵
	}
	//setfillcolor(GREEN);
	//bar((poison->x) - 7, (poison->y) - 7, (poison->x) - 7 + 14, (poison->y) - 7 + 14);
	return poison;
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
	p->score = 0;
	p->foodNum = 0;
	p->poisonNum = 0;
	p->foodRate = 180;
	p->poisonRate = 60;
	p->starRate = 360;
	p->mushroom = 0;
	p->dx = 15;
	p->dy = 0;
	p->pfood = NULL;
	p->ppoison = NULL;
	return p;
}