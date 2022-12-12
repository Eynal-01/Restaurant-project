#pragma once
#include<iostream>
#include<windows.h>
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
            cout << "Enter meal name : ";
			Meal m;
            int num = 1;
            for (size_t i = 0; i < 6; i++)
            {
                char meal = _getch();
                cout << meal;
                int b = k.GetMealsCount();
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
                            cout << "[" << num << "] " << a << endl;
                        }
                        ++i2;
                        if (meal1.GetName().size() == i2) { 
							m = meal1;
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
			k.ShowMealById(m.GetID());
			cout << "\t\t\t\t\t\t\t\tOrder            [1]" << endl;
			cout << "\t\t\t\t\t\t\t\tAdd ingredients  [2]" << endl;
			cout << "\t\t\t\t\t\t\t\tEnter your choice : ";
			int choice;
			cin >> choice;

			if (choice == 1) {
				cout << "\t\t\t\t\t\t\t\tEnter count of meal : ";
				static int countofmeal;
				cin >> countofmeal;

				if (countofmeal > 0) {
					auto meal = k.GetMealById(m.GetID());
					string content = k.GetMealById(m.GetID())->GetName();
					string tableNo = c.GetTableNo();
					totaldebt += countofmeal * meal->GetPrice();
					cout << "\t\t\t\t\t\t\t\tYou must pay " << totaldebt << " $ " << endl;
					cout << "\t\t\t\t\t\t\t\tContinue       [1]" << endl;
					cout << "\t\t\t\t\t\t\t\tFinish process [2]" << endl;
					cout << "\t\t\t\t\t\t\t\tEnter your choice : ";
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
				cout << "\t\t\t\t\t\t\t\tEnter number of ingredient : ";

				int ingcount;
				cin >> ingcount;
				auto product = s.GetProductByID(ingcount);
				cout << *product << endl;
				string productname = product->GetName();
				cout << "\t\t\t\t\t\t\t\tEnter " << productname << " count" << endl;
				int procount = 0;
				cin >> procount;
				if (s.CheckProductCount(ingcount, procount)) {
					auto meal = k.GetMealById(m.GetID());
					meal->AddProduct(*product, procount);
					cout << *meal << endl;

					system("cls");
					cout << "\t\t\t\t\t\t\t\tProduct added successfully" << endl;
					cout << "\t\t\t\t\t\t\t\tDo you want how much " << meal->GetName() << endl;
					cout << "\t\t\t\t\t\t\t\tEnter quantity of meal : ";
					int quantitymeal;
					cin >> quantitymeal;
					if (quantitymeal > 0) {
						string tableNo = c.GetTableNo();
						string content = k.GetMealById(m.GetID())->GetName();
						totaldebt += (meal->GetPrice() + (product->GetPrice() * procount)) * quantitymeal;
						cout << "\t\t\t\t\t\t\t\tTotal cash : " << totaldebt << " $ " << endl;
						Notification n1(quantitymeal, tableNo);
						n1.AddMealToNotification(meal);
						SendNotification(n1, k);
					}
					else {
						cout << "\t\t\t\t\t\t\t\tYour select is incorrect" << endl;
					}
				}
				else {
					auto meal = k.GetMealById(m.GetID());
					totaldebt += meal->GetPrice();
					cout << "\t\t\t\t\t\t\t\tIngredients out of stock" << endl;
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
