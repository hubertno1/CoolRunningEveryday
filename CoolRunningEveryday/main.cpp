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
#define WIN_HEIGHT 396

//����ͼƬ
IMAGE imgBgs[3];
int bgX[3];		//����ͼƬ��X����


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

//��Ⱦ����Ϸ������  (��Ⱦ���Ǵ�ӡ����˼)
void updateBg() {
	putimagePNG(bgX[0],   0, &imgBgs[0]);			//��һ�ر���������
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
