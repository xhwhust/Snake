#pragma once
typedef struct Star {
	int x;
	int y;
}Star;
typedef struct Food {//保存食物坐标
	int x;
	int y;
	Food *next;
	Food *pre;
}Food;
typedef struct Poison {//保存毒草的坐标以及产生的所有毒草
	int x;
	int y;
	int style;
	Poison *next;
	Poison *pre;
}Poison;
typedef struct SnakeBody {//蛇的身体，保存节点
	int x;
	int y;
	struct SnakeBody *next;
	struct SnakeBody *pre;
}SnakeBody;
typedef struct Snake {//管理蛇的头和尾，还有各种参数
	SnakeBody *head;
	SnakeBody *tail;
	int dx;
	int dy;
	int food;
	int poison;
	int star;
	Food *pfood;//用来保存产生的食物和毒草的链表头
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