/*
	天天酷跑开发日志
	1、创建项目
	2、导入素材
	3、创建游戏界面
		实际的开发流程
		对于初学者，最好的方式，建议从用户界面入手，需要什么写什么
		
		选择图形库或者其它引擎
		天天酷跑，是基于“easyx”图形库的
		1)创建游戏窗口
		2）设计游戏背景		
			a.3重背景不同的速度移动
			b.循环滚动背景的实现
		3）实现游戏背景
			a.加载背景资源
			b.渲染（坐标）
			遇到问题：背景图片的png格式图片出现黑色


*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <graphics.h>
#include "tools.h"

#define WIN_WIDTH 1012
#define WIN_HEIGHT 396					//396

//背景图片
IMAGE imgBgs[3];
int bgX[3];		//背景图片的X坐标
int bgSpeed[3] = { 1, 2, 4 };


//游戏的初始化
void init() {
	//创建游戏窗口
	initgraph(WIN_WIDTH, WIN_HEIGHT);

	
	//加载背景资源
	char name[64];
	for (int i = 0; i < 3; i++) {
		
		//"res/bg001.png"	"res/bg002.png"		"res/bg003.png"
		sprintf(name, "res/bg%03d.png", i + 1);
		loadimage(&imgBgs[i], name);

		bgX[i] = 0;
		//
	}
	
}

//实现三个背景不同速度的分别移动，从而产生视觉3D感
void fly() {
	for (int i = 0; i < 3; i++) {
		bgX[i] -= bgSpeed[i];
		if (bgX[i] < -WIN_WIDTH) {
			bgX[i] = 0;
		}
	}
}





//渲染“游戏背景”  (渲染就是打印的意思)
void updateBg() {

	putimagePNG2(bgX[0],   0, &imgBgs[0]);			//第一重背景，白云   0
	putimagePNG2(bgX[1], 119, &imgBgs[1]);			//119
	putimagePNG2(bgX[2], 330, &imgBgs[2]);			//330
}




int main(void)
{
	init();
	
	while (1) {


		//updateBg() 每次渲染的都是更新后的坐标，需要更新x轴坐标，图片向左移动，所以左上角图片的坐标为-2，-4（针对第一层背景）
		BeginBatchDraw();
		updateBg();
		EndBatchDraw();
		
		fly();

		Sleep(30);
	}


	system("PAUSE");

	return 0;
}
