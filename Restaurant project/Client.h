#pragma once
#include<iostream>
#include"Entities.h"
#include"Menu.h"
using namespace std;

void Menu(double totaldebt, Client& c, Kitchen& k, Stock& s, Notification& n, Table& t);

void GuestPanel(double totaldebt, Client& c, Kitchen& k, Stock& s, Notification& n, Table& t) {
	while (true)
	{
		system("cls");
		cout << "\t\t\t\t\t\t\t\tBack         [1]" << endl;
		cout << "\t\t\t\t\t\t\t\tView menu    [2]" << endl;
		cout << "\t\t\t\t\t\t\t\tSearch meal  [3]" << endl;
		cout << "\t\t\t\t\t\t\t\tNotification [4]" << "(" << t.notificationcount << ")" << endl;
		cout << "\t\t\t\t\t\t\t\tEnter your select : ";

		int selectentrance;
		cin >> selectentrance;
		if (selectentrance == 1) {
			return;
		}
		else if (selectentrance == 2) {
			Menu(totaldebt, c, k, s, n, t);
		}
		else if (selectentrance == 3) {
           /* while (true)
            {
                system("cls");
                char symbol = _getch();
                
            }*/	
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