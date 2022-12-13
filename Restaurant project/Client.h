#pragma once
#include<iostream>
#include<windows.h>
#include"Entities.h"
#include"Menu.h"
#include"FrontEnd.h"
using namespace std;

void Menu(double totaldebt, Client& c, Kitchen& k, Stock& s, Notification& n, Table& t);

void GuestPanel(double totaldebt, Client& c, Kitchen& k, Stock& s, Notification& n, Table& t) {
	while (true)
	{
		system("cls");
		SelectionsWord();
		mysetcolor(11, 0);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Back         [1]" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t          View menu    [2]" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Search meal  [3]" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Notification [4]" << "(" << t.notificationcount << ")" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Enter your select : ";
		int selectentrance;
		cin >> selectentrance;
		mysetcolor(7, 0);
		if (selectentrance == 1) {
			return;
		}
		else if (selectentrance == 2) {
			Menu(totaldebt, c, k, s, n, t);
		}
		else if (selectentrance == 3) {
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Enter meal name : ";
			int id123;
			int num = 1;
			for (size_t i = 0; i < 6; i++)
			{
				char meal = _getch();
				cout << meal;
				int b = k.GetMealsCount();
				id123 = int(meal);
				for (size_t i3 = 0; i3 < k.GetMealsCount(); i3++)
				{
					Meal meal1 = k.meals[i3];
					cout << endl;
					int i2 = 0;
					while (true)
					{
						char a = meal1.GetName()[i2];
						if (meal1.GetName()[i2] == meal) {
							string a = meal1.GetName();
							cout << "[" << meal1.GetID() << "] " << a << endl;
						}
						++i2;
						if (meal1.GetName().size() == i2) {
							break;
						}
					}
				}
				if (char(meal) >= 48 && char(meal) <= 57) {
					break;
				}
				else {
				}
			}
			system("cls");
			MealWord();
			id123 -= 48;
			k.ShowMealById(id123);
			mysetcolor(11, 0);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Order            [1]" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Add ingredients  [2]" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Enter your choice : ";
			int choice;
			cin >> choice;
			
			if (choice == 1) {
				mysetcolor(11, 0);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Enter count of meal : ";
				int countofmeal;
				cin >> countofmeal;

				if (countofmeal > 0) {
					auto meal = k.GetMealById(id123);
					string content = k.GetMealById(id123)->GetName();
					int tableNo = c.GetTableNo();
					totaldebt += countofmeal * meal->GetPrice();
					mysetcolor(11, 0);
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t          You must pay " << totaldebt << " $ " << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Continue       [1]" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Finish process [2]" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Enter your choice : ";
					int choice;
					cin >> choice;
					if (choice == 2) {
						Notification n(countofmeal, tableNo);
						n.AddMealToNotification(meal);
						SendNotification(n, k);
					}
					else if (choice == 1) {
						Notification n(countofmeal, tableNo);
						n.AddMealToNotification(meal);
						SendNotification(n, k);
						GuestPanel(totaldebt, c, k, s, n, t);
					}
				}
			}
			else if (choice == 2) {
				system("cls");
				s.ShowProductsToClient();
				mysetcolor(11, 0);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Enter number of ingredient : ";

				int ingcount;
				cin >> ingcount;
				auto product = s.GetProductByID(ingcount);
				cout << *product << endl;
				string productname = product->GetName();
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Enter " << productname << " count" << endl;
				int procount = 0;
				cin >> procount;
				if (s.CheckProductCount(ingcount, procount)) {
					auto meal = k.GetMealById(id123);
					meal->AddProduct(*product);
					cout << *meal << endl;

					system("cls");
					mysetcolor(2, 0);
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Product added successfully" << endl;
					mysetcolor(11, 0);
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Do you want how much " << meal->GetName() << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Enter quantity of meal : ";
					int quantitymeal;
					cin >> quantitymeal;
					if (quantitymeal > 0) {
						int tableNo = c.GetTableNo();
						string content = k.GetMealById(id123)->GetName();
						totaldebt += (meal->GetPrice() + (product->GetPrice() * procount)) * quantitymeal;
						mysetcolor(11, 0);
						cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Total cash : " << totaldebt << " $ " << endl;
						Notification n1(quantitymeal, tableNo);
						n1.AddMealToNotification(meal);
						SendNotification(n1, k);
					}
					else {
						mysetcolor(4, 0);
						cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Your select is incorrect" << endl;
						mysetcolor(7, 0);
					}
				}
				else {
					auto meal = k.GetMealById(id123);
					totaldebt += meal->GetPrice();
					mysetcolor(4, 0);
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t          Ingredients out of stock" << endl;
					mysetcolor(7, 0);
				}
			}
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
