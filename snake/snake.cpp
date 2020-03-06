#include <iostream>
#include <conio.h>
#include "windows.h"
#include <vector>

using namespace std;

int kol=1;
const int height=20;
const int width = 80;
int fructX = (rand() % 70) + 2;
int fructY = (rand() % 16) + 2;
struct Snake
{
	int snakeX;
	int snakeY;
};
vector<Snake> vectsnake;
Snake mysnake;

bool GameOver = false;


int main() {
	setlocale(LC_ALL, "Russian");
	void body(vector<Snake> vect, bool bo);
	vectsnake.push_back(mysnake);
	vectsnake[0].snakeX = (width - 2) / 2;
	vectsnake[0].snakeY = (height - 2) / 2;
	body(vectsnake,GameOver);
}
void body(vector<Snake> vectsnake, bool GameOver = false) {
	void beforedrawing(vector <Snake> x);
	void napr(vector<Snake> x);
	while (!GameOver) {
		beforedrawing(vectsnake);
		napr(vectsnake);
	}
}
int tailTB(vector<Snake> vectsnake) {
	if ((vectsnake[vectsnake.size() - 2].snakeX + 1) == (vectsnake[vectsnake.size()-1].snakeX)) {
		return 1;
	}
	else if (vectsnake[vectsnake.size() - 2].snakeX == vectsnake[vectsnake.size()-1].snakeX + 1) {
		return -1;
	}
}
void movesTop(vector<Snake> vectsnake) {
	if ( vectsnake[0].snakeX==(fructX) && vectsnake[0].snakeY==fructY+1) 
	{
		vectsnake.push_back(mysnake);
		vectsnake[vectsnake.size() - 1].snakeX = vectsnake[vectsnake.size() - 2].snakeX;
		vectsnake[vectsnake.size() - 1].snakeY = vectsnake[vectsnake.size() - 2].snakeY+1;
		fructX = (rand() % 76) + 2;
		fructY = (rand() % 16) + 2;
		kol++;
		body(vectsnake);
	}
	else if(kol>1)
	{
		vectsnake.insert(vectsnake.begin(), vectsnake[vectsnake.size() - 1]);
		vectsnake[0].snakeY = vectsnake[1].snakeY - 1;
		vectsnake[0].snakeX = vectsnake[1].snakeX;
		vectsnake.pop_back();
		if (vectsnake[0].snakeY == -1) {
			vectsnake[0].snakeY = 18;
			body(vectsnake);
		}
		else {
			body(vectsnake);
		}
	}
	else {
		vectsnake[0].snakeY--;
		if (vectsnake[0].snakeY == -1) {
			vectsnake[0].snakeY = 18;
			body(vectsnake);
		}
		else {
			body(vectsnake);
		}
	}
}


void movesBot(vector<Snake> vectsnake) {
	if (vectsnake[0].snakeX == (fructX) && vectsnake[0].snakeY == fructY-1)
	{
		vectsnake.push_back(mysnake);
		vectsnake[vectsnake.size() - 1].snakeX = vectsnake[vectsnake.size() - 2].snakeX;
		vectsnake[vectsnake.size() - 1].snakeY = vectsnake[vectsnake.size() - 2].snakeY + 1;
		fructX = (rand() % 76) + 2;
		fructY = (rand() % 16) + 2;
		kol++;
		body(vectsnake);
	}
	else if (kol > 1)
	{
		vectsnake.insert(vectsnake.begin(), vectsnake[vectsnake.size() - 1]);
		vectsnake[0].snakeY = vectsnake[1].snakeY + 1;
		vectsnake[0].snakeX = vectsnake[1].snakeX;
		vectsnake.pop_back();
		if (vectsnake[0].snakeY == 19) {
			vectsnake[0].snakeY = 0;
			body(vectsnake);
		}
		else {
			body(vectsnake);
		}
	}
	else {
		vectsnake[0].snakeY++;
		if (vectsnake[0].snakeY == 19) {
			vectsnake[0].snakeY = 0;
			body(vectsnake);
		}
		else {
			body(vectsnake);
		}
	}
}


void movesLeft(vector<Snake> vectsnake) {
	if (vectsnake[0].snakeX == (fructX+1) && vectsnake[0].snakeY == fructY)
	{
		vectsnake.push_back(mysnake);
		vectsnake[vectsnake.size() - 1].snakeX = vectsnake[vectsnake.size() - 2].snakeX+1;
		vectsnake[vectsnake.size() - 1].snakeY = vectsnake[vectsnake.size() - 2].snakeY ;
		fructX = (rand() % 76) + 2;
		fructY = (rand() % 16) + 2;
		kol++;
		body(vectsnake);
	}
	else if (kol > 1)
	{
		vectsnake.insert(vectsnake.begin(), vectsnake[vectsnake.size() - 1]);
		vectsnake[0].snakeX = vectsnake[1].snakeX - 1;
		vectsnake[0].snakeY = vectsnake[1].snakeY;
		vectsnake.pop_back();
		if (vectsnake[0].snakeX == -1) {
			vectsnake[0].snakeX = 78;
			body(vectsnake);
		}
		else {
			body(vectsnake);
		}
	}
	else {
		vectsnake[0].snakeX--;
		if (vectsnake[0].snakeX == -1) {
			vectsnake[0].snakeX = 78;
			body(vectsnake);
		}
		else {
			body(vectsnake);
		}
	}
}


void movesRight(vector<Snake> vectsnake) {
	if (vectsnake[0].snakeX == (fructX-1) && vectsnake[0].snakeY == fructY )
	{
		vectsnake.push_back(mysnake);
		vectsnake[vectsnake.size() - 1].snakeX = vectsnake[vectsnake.size() - 2].snakeX+1;
		vectsnake[vectsnake.size() - 1].snakeY = vectsnake[vectsnake.size() - 2].snakeY;
		fructX = (rand() % 76) + 2;
		fructY = (rand() % 16) + 2;
		kol++;
		body(vectsnake);
	}
	else if (kol > 1)
	{
		vectsnake.insert(vectsnake.begin(), vectsnake[vectsnake.size() - 1]);
		vectsnake[0].snakeX = vectsnake[1].snakeX + 1;
		vectsnake[0].snakeY = vectsnake[1].snakeY;
		vectsnake.pop_back();
		if (vectsnake[0].snakeX == 79) {
			vectsnake[0].snakeX = 0;
			body(vectsnake);
		}
		else {
			body(vectsnake);
		}
	}
	else {
		vectsnake[0].snakeX++;
		if (vectsnake[0].snakeX == 79) {
			vectsnake[0].snakeX = 0;
			body(vectsnake);
		}
		else {
			body(vectsnake);
		}
	}
}

void beforedrawing(vector <Snake> vectsnake) {
	Snake temp;
	vector<Snake> vectfordrawing;
	void drawWindow(vector <Snake> x,vector <Snake> y);
	if (vectsnake.size()>1)
	{
		for (int i = 0; i < vectsnake.size(); i++) {
			vectfordrawing.push_back(mysnake);
			vectfordrawing[i].snakeX = vectsnake[i].snakeX;
			vectfordrawing[i].snakeY = vectsnake[i].snakeY;
		}
		for (int i = 0; i < vectsnake.size()-1; i++) {
			for (int j = 0;j < vectsnake.size() - 1; j++) {
				if (((vectfordrawing[j].snakeY*18)+vectfordrawing[j].snakeX) > ((vectfordrawing[j+1].snakeY * 18) + vectfordrawing[j+1].snakeX)) {
					temp = vectfordrawing[j];
					vectfordrawing[j] = vectfordrawing[j + 1];
					vectfordrawing[j + 1] = temp;
				}
			}
		}
		drawWindow(vectfordrawing,vectsnake);
	}
	else if (vectsnake.size()<2)
	{
		drawWindow(vectsnake,vectsnake);
	}
}

void napr(vector<Snake> vectsnakech) {
	

	switch (_getch()) {
		case 87:
			movesTop(vectsnakech);
		case 119:
			movesTop(vectsnakech);
		case 83:
			movesBot(vectsnakech);
		case 115:
			movesBot(vectsnakech);
		case 65:
			movesLeft(vectsnakech);
		case 97:
			movesLeft(vectsnakech);
		case 68:
			movesRight(vectsnakech);
		case 100:;
			movesRight(vectsnakech);
		}
	}
void drawWindow(vector<Snake> vectsnake,vector<Snake> truesnake) {
	int g=0;
	system("cls");
	for (int i = 0; i <= width; i++)
	{
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i <= height - 2; i++) {
		cout << "#";
		for (int j = 0; j <= width - 2; j++) {
			if (vectsnake[g].snakeY == i && vectsnake[g].snakeX == j)
			{
		
				cout << "@";
				if (vectsnake.size() > g + 1) {
					g++;
				}		
			}
			else if (i == fructY && j == fructX)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}

		cout << "#" << endl;
	}
	for (int i = 0; i <= width; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "SCORE:"<<kol-1;
	napr(truesnake);
}


