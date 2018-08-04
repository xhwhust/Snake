#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <graphics.h>
#include <string.h>
#include "ImageMove.h"
#include "getRank.h"
//UP -32 72
//DOWN -32 80
//LEFT -32 75
//RIGHT -32 77
//enter 13
//空格 32
//ESC 27
void SnakeBegin();
void Loadin();
void getInfiniteRank();
int main() {
	Loadin();
	return 0;
}
void Loadin() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);//获取光标信息
	cci.bVisible = FALSE;//隐藏光标
	SetConsoleCursorInfo(hOut, &cci);//设置光标信息
									 //========================================
	char name[20];
	char c;
	int n = 0;
	char password[20];
	system("mode con cols=40 lines=10");
	while (1) {
		n = 0;
		system("cls");
		printf("1.登陆\n");
		printf("2.试玩\n");
		printf("3.注册账号\n");
		printf("Esc(退出)\n");
		c = _getch();
		if (c == 27) {
			exit(0);
		}else if (c == '2') {
			system("C:\\Users\\xhw\\source\\repos\\SmartSnake\\Debug\\map1.exe");
		}
		else if (c == '1') {
			system("cls");
			printf("请输入用户名：");
			scanf_s("%s", name, 20);
			printf("请输入密码：");
			scanf_s("%s", password, 20);
			FILE *fp = NULL;
			FILE *f = NULL;
			if (fopen_s(&fp, "d:\\snakefile\\resource\\UserData\\data.txt", "r") != 0) {
				printf("error\n");
				Sleep(500);
			}
			else {
				fopen_s(&f, "d:\\snakefile\\resource\\UserData\\num.txt", "r");
				int num = 0;
				int k = 0;
				char pw[20];
				char str[20];
				fscanf_s(f, "%d", &num);
				while (k < num) {
					fscanf_s(fp, "%s", str, 20);
					fscanf_s(fp, "%s", pw, 20);
					if (strcmp(name, str) == 0 && strcmp(password, pw) == 0) {
						FILE *t = NULL;
						fopen_s(&t,"d:\\snakefile\\resource\\Ranking\\player.txt","w+");
						fprintf_s(t,"%s",name);
						fclose(t);
						SnakeBegin();
						n = 1;
					}
					k++;
				}
				fclose(fp);
				fclose(f);
				if (n == 0) {
					printf("error\n");
					Sleep(500);
				}
			}
		}
		else if (c == '3') {
			system("cls");
			printf("请输入用户名：");
			scanf_s("%s", name, 20);
			printf("请输入密码：");
			scanf_s("%s", password, 20);
			FILE *fp = NULL;
			if (fopen_s(&fp, "d:\\snakefile\\resource\\UserData\\data.txt", "a+") == 0) {
				fprintf_s(fp, "%s", "\n");
				fprintf_s(fp, "%s", name);
				fprintf_s(fp, "%s", "\n");
				fprintf_s(fp, "%s", password);
				fclose(fp);
			}
			int i = 0;
			if (fopen_s(&fp, "d:\\snakefile\\resource\\UserData\\num.txt", "r") == 0) {
				fscanf_s(fp, "%d", &i);
				fclose(fp);
				i++;
				fopen_s(&fp, "d:\\snakefile\\resource\\UserData\\num.txt", "w+");
				fprintf_s(fp, "%d", i);
				fclose(fp);
			}
			else {
				fopen_s(&fp, "d:\\snakefile\\resource\\UserData\\num.txt", "w+");
				fprintf_s(fp, "%d", 1);
				fclose(fp);
			}
			system("cls");
			printf("注册成功");
			Sleep(500);
		}
	}
}
void SnakeBegin() {
	initgraph(630, 420);
	IMAGE begin, newgame, choose, ranking, con, rankingbk;
	IMAGE map1, map2, map3, map4;
	IMAGE map1rank, map2rank, map3rank, map4rank;
	int style = 0;
	char c;
	loadimage(&begin, "d:\\snakefile\\begin.jpg", 630, 420);
	loadimage(&newgame, "d:\\snakefile\\newgame.jpg", 630, 420);
	loadimage(&choose, "d:\\snakefile\\choose.jpg", 630, 420);
	loadimage(&ranking, "d:\\snakefile\\ranking.jpg", 630, 420);
	loadimage(&con, "d:\\snakefile\\continue.jpg", 630, 420);
	loadimage(&rankingbk, "d:\\snakefile\\rankingbk.jpg", 630, 420);
	loadimage(&map1, "d:\\snakefile\\map-1.jpg", 630, 420);
	loadimage(&map2, "d:\\snakefile\\map-2.jpg", 630, 420);
	loadimage(&map3, "d:\\snakefile\\map-3.jpg", 630, 420);
	loadimage(&map4, "d:\\snakefile\\map-4.jpg", 630, 420);
	putimage(0, 0, &begin);
	while (1) {
		if (_kbhit()) {
			c = _getch();
			if (c == 27) {
				closegraph();
				exit(0);
			}
			if (style == 11 && c == 13) {
				system("C:\\Users\\xhw\\source\\repos\\SmartSnake\\Debug\\infinitesave.exe");
				style = 1;
				putimage(0, 0, &newgame);
			}else if (style == 1 && c == 13) {
				system("C:\\Users\\xhw\\source\\repos\\SmartSnake\\Debug\\infinite.exe");
			}else if (style == 21 && c == 13) {
				system("C:\\Users\\xhw\\source\\repos\\SmartSnake\\Debug\\map1.exe");
				style = 1;
				putimage(0, 0, &newgame);
			}else if (style == 22 && c == 13) {
				system("C:\\Users\\xhw\\source\\repos\\SmartSnake\\Debug\\map2.exe");
				style = 1;
				putimage(0, 0, &newgame);
			}else if (style == 23 && c == 13) {
				system("C:\\Users\\xhw\\source\\repos\\SmartSnake\\Debug\\map3.exe");
				style = 1;
				putimage(0, 0, &newgame);
			}else if (style == 24 && c == 13) {
				system("C:\\Users\\xhw\\source\\repos\\SmartSnake\\Debug\\map4.exe");
				style = 1;
				putimage(0, 0, &newgame);
			}
			if (style == 0) {
				imageUp(begin, newgame);
				style = 1;
			}else if (c == -32) {
				c = _getch();
				if (style == 34 && c == 80) {
					loadimage(&map4rank, "d:\\snakefile\\rankingbk.jpg", 630, 420);
					SetWorkingImage(&map4rank);
					setbkmode(TRANSPARENT);
					settextstyle(25, 0, _T("宋体"));
					outtextxy(230, 60, _T("地图四排行榜"));
					getMapDRank();
					SetWorkingImage();
					imageUp(map3rank, map4rank);
					style = 35;
				}
				else if (style == 35 && c == 72) {
					imageDown(map4rank, map3rank);
					style = 34;
				}
				else if (style == 33 && c == 80) {
					loadimage(&map3rank, "d:\\snakefile\\rankingbk.jpg", 630, 420);
					SetWorkingImage(&map3rank);
					setbkmode(TRANSPARENT);
					settextstyle(25, 0, _T("宋体"));
					outtextxy(230, 60, _T("地图三排行榜"));
					getMapCRank();
					SetWorkingImage();
					imageUp(map2rank, map3rank);
					style = 34;
				}
				else if (style == 34 && c == 72) {
					imageDown(map3rank, map2rank);
					style = 33;
				}
				else if (style == 32 && c == 80) {
					loadimage(&map2rank, "d:\\snakefile\\rankingbk.jpg", 630, 420);
					SetWorkingImage(&map2rank);
					setbkmode(TRANSPARENT);
					settextstyle(25, 0, _T("宋体"));
					outtextxy(230, 60, _T("地图二排行榜"));
					getMapBRank();
					SetWorkingImage();
					imageUp(map1rank, map2rank);
					style = 33;
				}
				else if (style == 33 && c == 72) {
					imageDown(map2rank, map1rank);
					style = 32;
				}
				else if (style == 31 && c == 80) {
					loadimage(&map1rank, "d:\\snakefile\\rankingbk.jpg", 630, 420);
					SetWorkingImage(&map1rank);
					setbkmode(TRANSPARENT);
					settextstyle(25, 0, _T("宋体"));
					outtextxy(230, 60, _T("地图一排行榜"));
					getMapARank();
					SetWorkingImage();
					imageUp(rankingbk, map1rank);
					style = 32;
				}
				else if (style == 32 && c == 72) {
					imageDown(map1rank,rankingbk);
					style = 31;
				}
				else if (style == 3 && c == 80) {
					loadimage(&rankingbk, "d:\\snakefile\\rankingbk.jpg", 630, 420);
					SetWorkingImage(&rankingbk);
					setbkmode(TRANSPARENT);
					settextstyle(25, 0, _T("宋体"));
					outtextxy(230, 60, _T("无尽模式排行榜"));
					getInfiniteRank();
					SetWorkingImage();
					imageUp(ranking,rankingbk);
					style = 31;
				}
				else if (style == 31 && c == 72) {
					imageDown(rankingbk,ranking);
					style = 3;
				}
				else if (style == 1 && c == 80) {
					imageUp(newgame,con);
					style = 11;
				}
				else if (style == 11 && c == 72) {
					imageDown(con,newgame);
					style = 1;
				}else if (style == 1 && c == 77) {
					//imageLeft(newgame, choose);
					putimage(0, 0, &choose);
					style = 2;
				}else if (style == 2 && c == 75) {
					//imageRight(choose,newgame);
					putimage(0, 0, &newgame);
					style = 1;
				}else if (style == 2 && c == 77) {
					//imageLeft(choose, ranking);
					putimage(0, 0, &ranking);
					style = 3;
				}else if (style == 3 && c == 75) {
					//imageRight(ranking,choose);
					putimage(0, 0, &choose);
					style = 2;
				}else if (style == 2 && c == 80) {//从此以下为具体地图
					imageUp(choose, map1);
					style = 21;
				}else if (style == 21 && c == 80) {
					imageUp(map1, map2);
					style = 22;
				}else if (style == 22 && c == 80) {
					imageUp(map2, map3);
					style = 23;
				}else if (style == 23 && c == 80) {
					imageUp(map3, map4);
					style = 24;
				}else if (style == 21 && c == 72) {
					imageDown(map1, choose);
					style = 2;
				}else if (style == 22 && c == 72) {
					imageDown(map2, map1);
					style = 21;
				}else if (style == 23 && c == 72) {
					imageDown(map3,map2);
					style = 22;
				}else if (style == 24 && c == 72) {
					imageDown(map4,map3);
					style = 23;
				}
			}
		}
	}
	_getch();
	closegraph();
}
