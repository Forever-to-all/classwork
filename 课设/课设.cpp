#include <graphics.h>	
#include<string.h>
#include<string>
#include<cstring>
#include<stdio.h>
#include <sstream>
#include <conio.h>
#include<Windows.h>
#include<mmsystem.h>
#include<fstream>
#include<iostream>
#pragma comment(lib,"winmm.lib")
using namespace std;

bool login();
void play();
void show1();
void show2();
void startup();
void updatewithuser();
void updatewithoutuser();

int humanx;
int humany;
int hlength;
static int bkx;
int humanstatus;
int jumpm;
int squattime=0;
ExMessage msg;
ExMessage m;
IMAGE img;
IMAGE bk;
IMAGE stand;
IMAGE squat;
IMAGE run;

int main()
{
	/*int sw = GetSystemMetrics(SM_CXSCREEN);
	int sh = GetSystemMetrics(SM_CXSCREEN);
	int x = (sw - 890) / 2;
	int y = (sh - 470) / 2;*/

	initgraph(890,470);
	play();
	/*
	if (login()) {
		play();
	}
	*/
}
bool login() {	//登录函数

	show1();										//登录背景

	/*mciSendString("open Fever.mp3", NULL, 0, NULL);
	mciSendString("play Fever.mp3", NULL, 0, NULL);*/

	settextcolor(WHITE);
	setbkmode(TRANSPARENT);					
	setbkcolor(WHITE);
	settextstyle(40, 0, "楷体");

	outtextxy(670, 150, "登录");
	line(680, 190, 735, 190);//登录字样
	outtextxy(670, 250, "注册");
	line(680, 290, 735, 290);//注册字样
	
	static int juage1=0;
	static int juage2 = 0;
	static int juage3 = 0;
	char name[50] = { 0 };
	char mima[50] = { 0 };
	char mima1[50] = { 0 };
	static int i = 0;
	static int j = 0;
	static int k = 0;
	//std::string playernum = R"(D:\\新项目\\课设\\用户数据\\playernum.txt)";
	//std::string player = R"("D:\\新项目\\课设\\用户数据\\player.txt")";
	//std::string playertemp = R"(D:\\新项目\\课设\\用户数据\\playertemp.txt)";
	std::string playertemp;
	std::string playermes;
	//登录界面主循环
	while (1) {

		peekmessage(&msg);
		if (msg.message == WM_LBUTTONDOWN && msg.x > 670 && msg.x < 745 && msg.y>150 && msg.y < 190&& juage1 == 0) {//点击登录
			juage1 = 1;
			cleardevice();
			show1();			
			settextcolor(WHITE);
			settextstyle(40, 0, "楷体");
			setlinecolor(WHITE);
			outtextxy(470, 110, "NAME");
			fillroundrect(550, 100, 850, 150, 20, 20);//name栏
			outtextxy(470, 180, "密码");
			fillroundrect(550, 170, 850, 220, 20, 20);//密码栏
			outtextxy(580, 250, "登入");
			line(590, 290, 645, 290);//登入按钮
			settextstyle(20, 0, "宋体");
			outtextxy(480, 260, "返回");//返回按钮
			for (int a=0; a < 49; a++) {
					name[a] = { 0 };
					mima[a] = { 0 };
			}
			i = 0;
			j = 0; 
			k = 0;
		}
		else if (msg.message == WM_LBUTTONDOWN && msg.x > 670 && msg.x < 745 && msg.y>250 && msg.y < 290&& juage1 == 0) {//点击注册
			juage1 = 2;
			cleardevice();
			show1();
			settextcolor(WHITE);
			settextstyle(40, 0, "楷体");
			setlinecolor(WHITE);
			outtextxy(470, 90, "NAME");
			fillroundrect(550, 80, 850, 130, 20, 20);//name栏
			outtextxy(470, 160, "密码");
			fillroundrect(550, 150, 850, 200, 20, 20);//密码栏
			outtextxy(390, 230, "确认密码");
			fillroundrect(550, 220, 850, 270, 20, 20);//确认密码栏
			outtextxy(580, 300, "注册");
			line(590, 340, 645, 340);//注册按钮
			settextstyle(20, 0, "宋体");
			outtextxy(480, 310, "返回");//返回按钮
			for (int a = 0; a < 49; a++) {
				name[a] = { 0 };
				mima[a] = { 0 };
				mima1[a] = { 0 };
			}
			i = 0;
			j = 0;
			k = 0;
		}
		//登录程序----------------------------------------------------------------------------------------------------------------
		if (juage1 == 1) {

			if (msg.message == WM_LBUTTONDOWN && msg.x > 550 && msg.x < 850 && msg.y>100 && msg.y < 150) {
				juage2 = 1;
				setlinecolor(WHITE);
				line(555, 180, 555, 210);
				setlinecolor(BLACK);
				line(555, 110, 555, 140);//提示竖线
			}
			else if (msg.message == WM_LBUTTONDOWN && msg.x > 550 && msg.x < 850 && msg.y>170 && msg.y < 220) {
				juage2 = 2;
				setlinecolor(WHITE);
				line(555, 110, 555, 140);
				setlinecolor(BLACK);
				line(555, 180, 555, 210);//提示竖线
			}
			//输入name--------------------------------
			if (juage2 == 1) {
				Sleep(10);
				if (msg.message == WM_KEYDOWN) {
					name[i] = msg.vkcode;
					if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[j] >= '1' && name[j] <= '9') || name[j] == '0') {
						i++;
					}
					else if(name[i]==8) {
						i--;
						name[i] = { 0 };
					}
					if (name[i] == '\r') {
						name[i] = '\0';
					}
				}
				settextcolor(BLACK);
				settextstyle(40, 0, "楷体");
				outtextxy(560, 110, name);
			}
		
			//输入密码----------------------------------
			if (juage2==2) {  
				Sleep(10);
				if (msg.message == WM_KEYDOWN) {
			
					mima[j] = msg.vkcode;
					if ((mima[j] >= 'a' && mima[j] <= 'z')|| (mima[j] >= 'A' && mima[j] <= 'Z')|| (mima[j] >= '1' && mima[j] <= '9')||mima[j]=='0') {
						j++;
					}
					else if (name[i] == 8) {
						i--;
						name[i] = { 0 };
					}
					if (mima[j] == '\r') {
						mima[j] = '\0';
					}
				}
				settextcolor(BLACK);
				settextstyle(40, 0, "楷体");
				outtextxy(560, 180, mima);
			}
			//登入-------------------------------------
			if (msg.message == WM_LBUTTONDOWN && msg.x > 580 && msg.x < 655 && msg.y>250 && msg.y < 290) {

				if (name[0] == '\0') {
					MessageBox(0, "请输入name", "提示", MB_OK | MB_SYSTEMMODAL);
				}
				else if (mima[0] == '\0') {
					MessageBox(0, "请输入密码", "提示", MB_OK | MB_SYSTEMMODAL);
				}
				else {
					std::ifstream fin("player");
					while (getline(fin, playermes)) {
						std::ofstream fout("playertemp");
						fout << name;
						fout << mima;
						fout.close();
						std::ifstream fin1("playertemp");
						getline(fin1, playertemp);
						if (playertemp.compare(playermes)==0) {
							MessageBox(0, "登录成功", "提示", MB_OK | MB_SYSTEMMODAL);
							return 1;
						}
						else {
							MessageBox(0, "登录失败", "提示", MB_OK | MB_SYSTEMMODAL);
						}
					}
				}
			}
			//返回------------------------------------------
			if (msg.message == WM_LBUTTONDOWN && msg.x > 480 && msg.x < 530 && msg.y>260 && msg.y < 287) {
				cleardevice();
				show1();
				settextcolor(WHITE);
				setlinecolor(WHITE);
				settextstyle(40, 0, "楷体");
				outtextxy(670, 150, "登录");
				line(680, 190, 735, 190);//登录字样
				outtextxy(670, 250, "注册");
				line(680, 290, 735, 290);//注册字样
				juage1 = 0; 
				juage2 = 0;
				
			}
		}
		//注册程序----------------------------------------------------------------------------------------------
		if (juage1 == 2) {

			

			if (msg.message == WM_LBUTTONDOWN && msg.x > 550 && msg.x < 850 && msg.y>80 && msg.y < 130) {//点击name栏
				juage3 = 1;
				setlinecolor(WHITE);
				line(555, 150, 555, 200);
				line(555, 220, 555, 270);
				setlinecolor(BLACK);
				line(555, 85, 555, 125);//提示竖线
			}
			else if (msg.message == WM_LBUTTONDOWN && msg.x > 550 && msg.x < 850 && msg.y>150 && msg.y < 200) {//点击密码栏
				juage3 = 2;
				setlinecolor(WHITE);
				line(555, 80, 555, 130);
				line(555, 220, 555, 270);
				setlinecolor(BLACK);
				line(555, 155, 555, 195);//提示竖线
			}
			else if(msg.message == WM_LBUTTONDOWN && msg.x > 550 && msg.x < 850 && msg.y>220 && msg.y < 270){//点击确认密码栏
				juage3 = 3;
				setlinecolor(WHITE);
				line(555, 80, 555, 130);
				line(555, 150, 555, 200);
				setlinecolor(BLACK);
				line(555, 225, 555, 265);//提示竖线
			}
			//输入name--------------------------------
			if (juage3 == 1) {
				Sleep(10);
				if (msg.message == WM_KEYDOWN) {

					name[i] = msg.vkcode;
					if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[j] >= '1' && name[j] <= '9') || name[j] == '0') {
						i++;
					}
					else if (name[i] == 8) {
						i--;
						name[i] = { 0 };
					}
					if (name[i] == '\r') {
						name[i] = '\0';
					}
				}
				settextcolor(BLACK);
				settextstyle(40, 0, "楷体");
				outtextxy(560, 90, name);
			}
			//输入密码----------------------------------
			if (juage3 == 2) {
				Sleep(10);
				if (msg.message == WM_KEYDOWN) {

					mima[j] = msg.vkcode;
					if ((mima[j] >= 'a' && mima[j] <= 'z') || (mima[j] >= 'A' && mima[j] <= 'Z') || (mima[j] >= '1' && mima[j] <= '9') || mima[j] == '0') {
						j++;
					}
					else if (name[i] == 8) {
						i--;
						name[i] = { 0 };
					}
					if (mima[j] == '\r') {
						mima[j] = '\0';
					}
				}
				settextcolor(BLACK);
				settextstyle(40, 0, "楷体");
				outtextxy(560, 160, mima);
			}
			//输入确认密码------------------------------
			if (juage3 == 3) {
				Sleep(10);
				if (msg.message == WM_KEYDOWN) {

					mima1[k] = msg.vkcode;
					if ((mima1[k] >= 'a' && mima1[k] <= 'z') || (mima1[k] >= 'A' && mima1[k] <= 'Z') || (mima1[k] >= '1' && mima1[k] <= '9') || mima1[k] == '0') {
						k++;
					}
					else if (name[i] == 8) {
						i--;
						name[i] = { 0 };
					}
					if (mima1[k] == '\r') {
						mima1[k] = '\0';
					}
				}
				settextcolor(BLACK);
				settextstyle(40, 0, "楷体");
				outtextxy(560, 230, mima1);
			}
			//点击注册--------------------------
			if (msg.message == WM_LBUTTONDOWN && msg.x > 580 && msg.x < 655 && msg.y>300 && msg.y < 340) {

				if (name[0] == '\0') {
					MessageBox(0, "请输入name", "提示", MB_OK | MB_SYSTEMMODAL);
				}
				else if (mima[0] == '\0') {
					MessageBox(0, "请输入密码", "提示", MB_OK | MB_SYSTEMMODAL);
				}
				else if(strcmp(mima,mima1)!=0){
					MessageBox(0, "两次密码不同", "提示", MB_OK | MB_SYSTEMMODAL);
				}
				else {
					//储存新注册玩家信息
					std::ofstream fout("player", ios::app);
					fout << name;
					fout << mima;
					fout << "\n";
					fout.close();
					MessageBox(0, "注册成功", "提示", MB_OK | MB_SYSTEMMODAL);
				}
			}
			//点击返回------------------------
			if (msg.message == WM_LBUTTONDOWN && msg.x > 480 && msg.x < 530 && msg.y>310 && msg.y < 337) {
				cleardevice();
				show1();
				settextcolor(WHITE);
				setlinecolor(WHITE);
				settextstyle(40, 0, "楷体");
				outtextxy(670, 150, "登录");
				line(680, 190, 735, 190);//登录字样
				outtextxy(670, 250, "注册");
				line(680, 290, 735, 290);//注册字样
				juage1 = 0;
				juage2 = 0;
			}
		}
	}
}
void play() {

	startup();

	while (1) {
		Sleep(1);
		show2();
		
		updatewithuser();

		updatewithoutuser();

		
	}
}
void startup() {
	humanx = 100;
	humany = 380;
	bkx = 0;
	humanstatus = 0;
	jumpm = 248;
	hlength = 40;
	loadimage(&bk, "bk.png", 1310, 470);
	
	//loadimage(&squat, "下蹲.jpg", 40, 40);
	loadimage(&run, "奔跑.jpg", 40, 40);
	//img = stand;
}
void show1() {
	IMAGE pic;
		loadimage(&pic, "开始背景.jpg", 890, 470);
		putimage(0, 0, &pic);	
}
void show2() {
	BeginBatchDraw();
	cleardevice();
	putimage(bkx, 0, &bk);//背景
	putimage(bkx + 1309, 0, &bk);
	loadimage(&stand, "站立.jpg", hlength, hlength);
	putimage(humanx, humany, &stand, SRCPAINT);
	EndBatchDraw();
}
void updatewithuser() {
	peekmessage(&m);
	//人物状态判断------------------------
	if ((m.vkcode == 'w' || m.vkcode == 'W')&& humanstatus==0 && humany==380) {
		humanstatus = 1;
	}
	else if ((m.vkcode == 's' || m.vkcode == 'S')&&humanstatus==0 && humany == 380) {
		humanstatus = 3;
	}
}
void updatewithoutuser() {
	//场景前进----------------------------
	bkx--;
	bkx--;
	bkx = bkx%1310;
	//跳跃程序----------------------------
	if (humanstatus == 1 && humany  > jumpm) {
		humany -= 4;
	}
	if (humany == jumpm) {
		humanstatus = 2;
	}
	if (humanstatus == 2) {
		humany += 4;
	}
	if (humanstatus == 2 && humany == 380) {
		humanstatus = 0;
	}
	//下蹲程序-----------------------------
	if (humanstatus == 3) {
		hlength -= 5;
		humany += 5;
	}
	if (hlength == 20 && humanstatus == 3) {
		humanstatus = 4;
	}
	if (humanstatus == 4 && squattime < 50) {
		squattime++;
	}
	if (squattime == 50) {
		hlength += 5;
		humany -= 5;
	}
	if (humanstatus == 4 && hlength == 40) {
		squattime = 0;
		humanstatus = 0;
	}
}

