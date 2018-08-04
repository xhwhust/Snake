#pragma once
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <string.h>
void getMapDRank() {
	setbkmode(TRANSPARENT);
	settextstyle(25, 0, _T("宋体"));
	FILE *fp = NULL;
	if (fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\map4\\num.txt", "r") != 0) {
		outtextxy(230, 150, _T("No Information"));
	}
	else {
		int k = 0;
		int n = 0;
		char name[20];
		int sc = 0;
		char first[20] = "NULL"; char second[20] = "NULL"; char third[20] = "NULL";
		int score[3] = { 1000,1000,1000 };
		fscanf_s(fp, "%d", &n);
		fclose(fp);
		fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\map4\\ranking.txt", "r");
		while (k < n) {
			fscanf_s(fp, "%s", name, 20);
			fscanf_s(fp, "%d", &sc);
			if (sc < score[0]) {
				strcpy_s(third, second);
				strcpy_s(second, first);
				strcpy_s(first, name);
				score[2] = score[1];
				score[1] = score[0];
				score[0] = sc;
			}
			else if (sc < score[1]) {
				strcpy_s(third, second);
				strcpy_s(second, name);
				score[2] = score[1];
				score[1] = sc;
			}
			else if (sc < score[2]) {
				strcpy_s(third, name);
				score[2] = sc;
			}
			k++;
		}
		fclose(fp);
		for (int i = 0; i < 3; i++) {
			if (score[i] == 1000) {
				score[i] = 0;
			}
		}
		char temp[20];
		settextstyle(20, 0, _T("宋体"));
		sprintf_s(temp, "%d", score[0]);
		outtextxy(240, 120, first);
		outtextxy(340, 120, temp);
		sprintf_s(temp, "%d", score[1]);
		outtextxy(240, 180, second);
		outtextxy(340, 180, temp);
		sprintf_s(temp, "%d", score[2]);
		outtextxy(240, 240, third);
		outtextxy(340, 240, temp);
	}
}
void getMapCRank() {
	setbkmode(TRANSPARENT);
	settextstyle(25, 0, _T("宋体"));
	FILE *fp = NULL;
	if (fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\map3\\num.txt", "r") != 0) {
		outtextxy(230, 150, _T("No Information"));
	}
	else {
		int k = 0;
		int n = 0;
		char name[20];
		int sc = 0;
		char first[20] = "NULL"; char second[20] = "NULL"; char third[20] = "NULL";
		int score[3] = { 1000,1000,1000 };
		fscanf_s(fp, "%d", &n);
		fclose(fp);
		fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\map3\\ranking.txt", "r");
		while (k < n) {
			fscanf_s(fp, "%s", name, 20);
			fscanf_s(fp, "%d", &sc);
			if (sc < score[0]) {
				strcpy_s(third, second);
				strcpy_s(second, first);
				strcpy_s(first, name);
				score[2] = score[1];
				score[1] = score[0];
				score[0] = sc;
			}
			else if (sc < score[1]) {
				strcpy_s(third, second);
				strcpy_s(second, name);
				score[2] = score[1];
				score[1] = sc;
			}
			else if (sc < score[2]) {
				strcpy_s(third, name);
				score[2] = sc;
			}
			k++;
		}
		fclose(fp);
		for (int i = 0; i < 3; i++) {
			if (score[i] == 1000) {
				score[i] = 0;
			}
		}
		char temp[20];
		settextstyle(20, 0, _T("宋体"));
		sprintf_s(temp, "%d", score[0]);
		outtextxy(240, 120, first);
		outtextxy(340, 120, temp);
		sprintf_s(temp, "%d", score[1]);
		outtextxy(240, 180, second);
		outtextxy(340, 180, temp);
		sprintf_s(temp, "%d", score[2]);
		outtextxy(240, 240, third);
		outtextxy(340, 240, temp);
	}
}
void getMapBRank() {
	setbkmode(TRANSPARENT);
	settextstyle(25, 0, _T("宋体"));
	FILE *fp = NULL;
	if (fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\map2\\num.txt", "r") != 0) {
		outtextxy(230, 150, _T("No Information"));
	}
	else {
		int k = 0;
		int n = 0;
		char name[20];
		int sc = 0;
		char first[20] = "NULL"; char second[20] = "NULL"; char third[20] = "NULL";
		int score[3] = { 1000,1000,1000 };
		fscanf_s(fp, "%d", &n);
		fclose(fp);
		fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\map2\\ranking.txt", "r");
		while (k < n) {
			fscanf_s(fp, "%s", name, 20);
			fscanf_s(fp, "%d", &sc);
			if (sc < score[0]) {
				strcpy_s(third, second);
				strcpy_s(second, first);
				strcpy_s(first, name);
				score[2] = score[1];
				score[1] = score[0];
				score[0] = sc;
			}
			else if (sc < score[1]) {
				strcpy_s(third, second);
				strcpy_s(second, name);
				score[2] = score[1];
				score[1] = sc;
			}
			else if (sc < score[2]) {
				strcpy_s(third, name);
				score[2] = sc;
			}
			k++;
		}
		fclose(fp);
		for (int i = 0; i < 3; i++) {
			if (score[i] == 1000) {
				score[i] = 0;
			}
		}
		char temp[20];
		settextstyle(20, 0, _T("宋体"));
		sprintf_s(temp, "%d", score[0]);
		outtextxy(240, 120, first);
		outtextxy(340, 120, temp);
		sprintf_s(temp, "%d", score[1]);
		outtextxy(240, 180, second);
		outtextxy(340, 180, temp);
		sprintf_s(temp, "%d", score[2]);
		outtextxy(240, 240, third);
		outtextxy(340, 240, temp);
	}
}
void getMapARank() {
	setbkmode(TRANSPARENT);
	settextstyle(25, 0, _T("宋体"));
	FILE *fp = NULL;
	if (fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\map1\\num.txt", "r") != 0) {
		outtextxy(230, 150, _T("No Information"));
	}
	else {
		int k = 0;
		int n = 0;
		char name[20];
		int sc = 0;
		char first[20] = "NULL"; char second[20] = "NULL"; char third[20] = "NULL";
		int score[3] = {1000,1000,1000};
		fscanf_s(fp, "%d", &n);
		fclose(fp);
		fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\map1\\ranking.txt", "r");
		while (k < n) {
			fscanf_s(fp, "%s", name, 20);
			fscanf_s(fp, "%d", &sc);
			if (sc < score[0]) {
				strcpy_s(third, second);
				strcpy_s(second, first);
				strcpy_s(first, name);
				score[2] = score[1];
				score[1] = score[0];
				score[0] = sc;
			}
			else if (sc < score[1]) {
				strcpy_s(third, second);
				strcpy_s(second, name);
				score[2] = score[1];
				score[1] = sc;
			}
			else if (sc < score[2]) {
				strcpy_s(third, name);
				score[2] = sc;
			}
			k++;
		}
		fclose(fp);
		for (int i = 0; i < 3; i++) {
			if (score[i] == 1000) {
				score[i] = 0;
			}
		}
		char temp[20];
		settextstyle(20, 0, _T("宋体"));
		sprintf_s(temp, "%d", score[0]);
		outtextxy(240, 120, first);
		outtextxy(340, 120, temp);
		sprintf_s(temp, "%d", score[1]);
		outtextxy(240, 180, second);
		outtextxy(340, 180, temp);
		sprintf_s(temp, "%d", score[2]);
		outtextxy(240, 240, third);
		outtextxy(340, 240, temp);
	}
}
void getInfiniteRank() {
	setbkmode(TRANSPARENT);
	settextstyle(25, 0, _T("宋体"));
	FILE *fp = NULL;
	if (fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\num.txt", "r") != 0) {
		outtextxy(230, 150, _T("No Information"));
	}
	else {
		int k = 0;
		int n = 0;
		char name[20];
		int sc = 0;
		char first[20] = "NULL"; char second[20] = "NULL"; char third[20] = "NULL";
		int score[3] = { 0 };
		fscanf_s(fp, "%d", &n);
		fclose(fp);
		fopen_s(&fp, "d:\\snakefile\\resource\\Ranking\\ranking.txt", "r");
		while (k < n) {
			fscanf_s(fp, "%s", name, 20);
			fscanf_s(fp, "%d", &sc);
			if (sc > score[0]) {
				strcpy_s(third, second);
				strcpy_s(second, first);
				strcpy_s(first, name);
				score[2] = score[1];
				score[1] = score[0];
				score[0] = sc;
			}
			else if (sc > score[1]) {
				strcpy_s(third, second);
				strcpy_s(second, name);
				score[2] = score[1];
				score[1] = sc;
			}
			else if (sc > score[2]) {
				strcpy_s(third, name);
				score[2] = sc;
			}
			k++;
		}
		fclose(fp);
		char temp[20];
		settextstyle(20, 0, _T("宋体"));
		sprintf_s(temp, "%d", score[0]);
		outtextxy(240, 120, first);
		outtextxy(340, 120, temp);
		sprintf_s(temp, "%d", score[1]);
		outtextxy(240, 180, second);
		outtextxy(340, 180, temp);
		sprintf_s(temp, "%d", score[2]);
		outtextxy(240, 240, third);
		outtextxy(340, 240, temp);
	}
}