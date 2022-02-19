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
#define WIN_HEIGHT 396

//背景图片
IMAGE imgBgs[3];
int bgX[3];		//背景图片的X坐标


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

//渲染“游戏背景”  (渲染就是打印的意思)
void updateBg() {
	putimagePNG(bgX[0],   0, &imgBgs[0]);			//第一重背景，白云
	putimagePNG(bgX[1], 119, &imgBgs[1]);
	putimagePNG(bgX[2], 330, &imgBgs[2]);
}




int main(void)
{
	init();
	
	updateBg();
	//...
	
	system("PAUSE");

	return 0;
}
