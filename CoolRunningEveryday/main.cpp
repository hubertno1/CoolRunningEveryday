/*
	������ܿ�����־
	1��������Ŀ
	2�������ز�
	3��������Ϸ����
		ʵ�ʵĿ�������
		���ڳ�ѧ�ߣ���õķ�ʽ��������û��������֣���Ҫʲôдʲô
		
		ѡ��ͼ�ο������������
		������ܣ��ǻ��ڡ�easyx��ͼ�ο��
		1)������Ϸ����
		2�������Ϸ����		
			a.3�ر�����ͬ���ٶ��ƶ�
			b.ѭ������������ʵ��
		3��ʵ����Ϸ����
			a.���ر�����Դ
			b.��Ⱦ�����꣩
			�������⣺����ͼƬ��png��ʽͼƬ���ֺ�ɫ


*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <graphics.h>
#include "tools.h"

#define WIN_WIDTH 1012
#define WIN_HEIGHT 396					//396

//����ͼƬ
IMAGE imgBgs[3];
int bgX[3];		//����ͼƬ��X����
int bgSpeed[3] = { 1, 2, 4 };


//��Ϸ�ĳ�ʼ��
void init() {
	//������Ϸ����
	initgraph(WIN_WIDTH, WIN_HEIGHT);

	
	//���ر�����Դ
	char name[64];
	for (int i = 0; i < 3; i++) {
		
		//"res/bg001.png"	"res/bg002.png"		"res/bg003.png"
		sprintf(name, "res/bg%03d.png", i + 1);
		loadimage(&imgBgs[i], name);

		bgX[i] = 0;
		//
	}
	
}

//ʵ������������ͬ�ٶȵķֱ��ƶ����Ӷ������Ӿ�3D��
void fly() {
	for (int i = 0; i < 3; i++) {
		bgX[i] -= bgSpeed[i];
		if (bgX[i] < -WIN_WIDTH) {
			bgX[i] = 0;
		}
	}
}





//��Ⱦ����Ϸ������  (��Ⱦ���Ǵ�ӡ����˼)
void updateBg() {

	putimagePNG2(bgX[0],   0, &imgBgs[0]);			//��һ�ر���������   0
	putimagePNG2(bgX[1], 119, &imgBgs[1]);			//119
	putimagePNG2(bgX[2], 330, &imgBgs[2]);			//330
}




int main(void)
{
	init();
	
	while (1) {


		//updateBg() ÿ����Ⱦ�Ķ��Ǹ��º�����꣬��Ҫ����x�����꣬ͼƬ�����ƶ����������Ͻ�ͼƬ������Ϊ-2��-4����Ե�һ�㱳����
		BeginBatchDraw();
		updateBg();
		EndBatchDraw();
		
		fly();

		Sleep(30);
	}


	system("PAUSE");

	return 0;
}
