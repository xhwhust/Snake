#pragma once
typedef struct Star {
	int x;
	int y;
}Star;
typedef struct Food {//����ʳ������
	int x;
	int y;
	Food *next;
	Food *pre;
}Food;
typedef struct Poison {//���涾�ݵ������Լ����������ж���
	int x;
	int y;
	int style;
	Poison *next;
	Poison *pre;
}Poison;
typedef struct SnakeBody {//�ߵ����壬����ڵ�
	int x;
	int y;
	struct SnakeBody *next;
	struct SnakeBody *pre;
}SnakeBody;
typedef struct Snake {//�����ߵ�ͷ��β�����и��ֲ���
	SnakeBody *head;
	SnakeBody *tail;
	int dx;
	int dy;
	int food;
	int poison;
	int star;
	Food *pfood;//�������������ʳ��Ͷ��ݵ�����ͷ
	Poison *ppoison;
	Star *pstar;
	int length;
	int direction;
	int speed;
	int score;
	int poisonNum;
	int foodNum;
	int foodRate;
	int poisonRate;
	int starRate;
	int mushroom;
}Snake;
typedef struct Data {
	int prelength;
	int nowlength;
}Data;