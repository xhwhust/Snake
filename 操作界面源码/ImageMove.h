#pragma once
#include <graphics.h>
void imageDown(IMAGE a, IMAGE b) {
	IMAGE temp1;
	IMAGE temp2;
	putimage(0, 0, &a);
	for (int k = 2; k <= 420; k += 2) {//ÏÂÒÆ
		SetWorkingImage(&a);
		getimage(&temp2, 0, 0, 630, 420 - k);
		SetWorkingImage(&b);
		getimage(&temp1, 0, 420 - k, 630, k);
		SetWorkingImage();
		putimage(0, 0, &temp1);
		putimage(0, k, &temp2);
		Sleep(2);
	}
}
void imageUp(IMAGE a, IMAGE b) {
	IMAGE temp1;
	IMAGE temp2;
	putimage(0, 0, &a);
	for (int k = 2; k <= 420; k += 2) {//ÉÏÒÆ
		SetWorkingImage(&a);
		getimage(&temp1, 0, k, 630, 420 - k);
		SetWorkingImage(&b);
		getimage(&temp2, 0, 0, 630, k);
		SetWorkingImage();
		putimage(0, 0, &temp1);
		putimage(0, 420 - k, &temp2);
		Sleep(2);
	}
}
void imageRight(IMAGE a, IMAGE b) {
	IMAGE temp1;
	IMAGE temp2;
	putimage(0, 0, &a);
	for (int k = 3; k <= 630; k += 3) {//ÓÒÒÆ
		SetWorkingImage(&b);
		getimage(&temp1, 630 - k, 0, 630, 420);
		SetWorkingImage(&a);
		getimage(&temp2, 0, 0, 630 - k, 420);
		SetWorkingImage();
		putimage(k, 0, &temp2);
		putimage(0, 0, &temp1);
		Sleep(2);
	}
}
void imageLeft(IMAGE a, IMAGE b) {
	IMAGE temp1;
	IMAGE temp2;
	putimage(0, 0, &a);
	for (int k = 3; k <= 630; k += 3) {//×óÒÆ
		SetWorkingImage(&a);
		getimage(&temp1, k, 0, 630 - k, 420);
		SetWorkingImage(&b);
		getimage(&temp2, 0, 0, k, 420);
		SetWorkingImage();
		putimage(0, 0, &temp1);
		putimage(630 - k, 0, &temp2);
		Sleep(2);
	}
}