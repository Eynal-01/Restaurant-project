#pragma once
#include<iostream>
#include"Entities.h"
#include"Menu.h"
using namespace std;

void Menu(double totaldebt, Client& c, Kitchen& k, Stock& s, Notification& n, Table1& t);

void GuestPanel(double totaldebt, Client& c, Kitchen& k, Stock& s, Notification& n, Table1& t) {
	while (true)
	{
		system("cls");
		cout << "Back         [1]" << endl;
		cout << "View menu    [2]" << endl;
		cout << "Search meal  [3]" << endl;
		cout << "Notification [4]" << "(" << t.notificationcount << ")" << endl;
		cout << "Enter your select : ";

		int selectentrance;
		cin >> selectentrance;
		if (selectentrance == 1) {
			return;
		}
		else if (selectentrance == 2) {
			Menu(totaldebt, c, k, s, n, t);
		}
		else if (selectentrance == 3) {
            /*enum Directions { UP = 72, DOWN = 80, RIGHT = 77, LEFT = 75 };
            while (true)
            {
                system("cls");
                ShowGame();
                if (hasStoped) {
                    return;
                }
                char symbol = _getch();
                if (symbol == -32) {
                    symbol = _getch();
                    int no = symbol;
                    if (no == UP) {
                        if (!isEmpty(X, Y - 1)) {
                            continue;
                        }
                        game[Y][X] = 0;
                        Y--;
                    }
                    else if (no == DOWN) {
                        if (!isEmpty(X, Y + 1)) {
                            continue;
                        }
                        game[Y][X] = 0;
                        Y++;
                    }
                    else if (no == LEFT) {
                        if (!isEmpty(X - 1, Y)) {
                            continue;
                        }
                        game[Y][X] = 0;
                        X--;
                    }
                    else if (no == RIGHT) {
                        if (!isEmpty(X + 1, Y)) {
                            continue;
                        }
                        game[Y][X] = 0;
                        X++;
                    }
                    game[Y][X] = 1;
                }
            }
        }*/
			cout << "Enter meal name : ";
			
		}
		else if (selectentrance == 4) {
			for (size_t i = 0; i < t.notificationcount; i++)
			{
				t.clientnotification.Show();
			}
			t.notificationcount--;
			system("pause");
		}
	}
}