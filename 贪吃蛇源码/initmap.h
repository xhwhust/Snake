#pragma once
int map[42][28] = { { 0 } };
void initmapD() {
	int i = 0;
	int j = 0;
	i = 13; j = 7;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 12; j = 8;
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 11; j = 9;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 15; j = 9;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 10; j = 10;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 16; j = 10;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 27; j = 7;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 26; j = 8;
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 25; j = 9;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 29; j = 9;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 24; j = 10;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 30; j = 10;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 5; j = 14;
	for (int k = 0; k < 6; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 5; j = 18;
	for (int k = 0; k < 6; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 31; j = 14;
	for (int k = 0; k < 6; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 31; j = 18;
	for (int k = 0; k < 6; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 18; j = 22;
	for (int k = 0; k < 6; k++) {
		map[i][j] = 1;
		i++;
	}
}
//=========================================================
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//=========================================================
void initmapC() {
	int i = 0;
	int j = 0;
	i = 3; j = 4;
	for (int k = 0; k < 3; k++) {
		map[i][j] = 1;
		j++;
	}
	i = 10; j = 7;
	for (int k = 0; k < 3; k++) {
		map[i][j] = 1;
		j++;
	}
	i = 7; j = 3;
	for (int k = 0; k < 3; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 4; j = 10;
	for (int k = 0; k < 3; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 17; j = 2;
	for (int k = 0; k < 3; k++) {
		map[i][j] = 1;
		j++;
	}
	i = 14; j = 9;
	for (int k = 0; k < 5; k++) {
		map[i][j] = 1;
		j++;
	}
	i = 27; j = 14;
	for (int k = 0; k < 5; k++) {
		map[i][j] = 1;
		j++;
	}
	i = 21; j = 7;
	for (int k = 0; k < 5; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 16; j = 20;
	for (int k = 0; k < 5; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 20; j = 13;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 20; j = 14;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 7; j = 17;
	for (int k = 0; k < 5; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 30; j = 10;
	for (int k = 0; k < 5; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 24; j = 23;
	for (int k = 0; k < 3; k++) {
		map[i][j] = 1;
		j++;
	}
	i = 3; j = 21;
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		j++;
	}
	j -= 1;
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 35; j = 3;
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		i++;
	}
	i -= 1;
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		j++;
	}
	i = 31; j = 18;
	for (int k = 0; k < 3; k++) {
		map[i][j] = 1;
		j++;
	}
	i = 35; j = 17;
	for (int k = 0; k < 3; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 32; j = 24;
	for (int k = 0; k < 3; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 38; j = 21;
	for (int k = 0; k < 3; k++) {
		map[i][j] = 1;
		j++;
	}
}
//==============================================================
//BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
//==============================================================
void initmapB() {
	int i = 0;
	int j = 0;
	i = 10; j = 5;
	for (int k = 0; k < 8; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 24; j = 5;
	for (int k = 0; k < 8; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 13; j = 6;
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		j++;
	}
	i = 14; j = 6;
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		j++;
	}
	i = 27; j = 6;
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		j++;
	}
	i = 28; j = 6;
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		j++;
	}
	i = 13; j = 13;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 13; j = 14;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 13; j = 20;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 13; j = 21;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 13; j = 26;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 13; j = 27;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	//===================
	i = 27; j = 13;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 27; j = 14;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 27; j = 20;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 27; j = 21;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 27; j = 26;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 27; j = 27;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 20; j = 14;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 19; j = 15;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i += 3;
	}
	i = 18; j = 16;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i += 5;
	}
	i = 17; j = 17;
	for (int k = 0; k < 2; k++) {
		map[i][j] = 1;
		i += 7;
	}
	i = 3; j = 13;
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 6; j = 13;
	for (int k = 0; k < 6; k++) {
		map[i][j] = 1;
		j++;
	}
	i = 35; j = 13;
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 35; j = 13;
	for (int k = 0; k < 6; k++) {
		map[i][j] = 1;
		j++;
	}
}
//=============================================================
//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
//=============================================================
void initmapA() {
	int i = 0;
	int j = 0;
	i = 7; j = 7;
	for (int k = 0; k < 7; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 7; j = 7;
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		j++;
	}
	i = 28; j = 7;
	for (int k = 0; k < 7; k++) {
		map[i][j] = 1;
		i++;
	}
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		j++;
	}
	i = 7; j = 20;
	for (int k = 0; k < 7; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 7; j = 20;
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		j--;
	}
	i = 28; j = 20;
	for (int k = 0; k < 7; k++) {
		map[i][j] = 1;
		i++;
	}
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		j--;
	}
	i = 19; j = 12;
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 19; j = 13;
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 19; j = 14;
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		i++;
	}
	i = 19; j = 15;
	for (int k = 0; k < 4; k++) {
		map[i][j] = 1;
		i++;
	}
}