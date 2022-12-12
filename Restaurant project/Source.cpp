#include<iostream>
#include<assert.h>
#include<string>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include"Entities.h"
#include"Admin.h"
#include"Stack.h"
#include"Menu.h"
#include"Client.h"
#include"FileHelper.h"
using namespace std;

int Meal::ID = 1;
int Product::ID = 1;

void main() {

	Product p("Tomato", 0.4, 18, 100);
	Product p1("Olive", 0.5, 115, 100);
	Product p2("Mashroom", 0.8, 22, 100);
	Product p3("Flour", 1, 364, 100);
	Product p4("Fillet", 2, 239, 100);
	Product p5("Mayonnaise", 2.5, 679.7, 100);
	Product p6("Beans", 1, 347, 100);
	Product p7("Cucumber", 0.7, 30, 100);
	Product p8("Carrot", 1, 41, 100);
	Product p9("Potato", 1, 76.7, 100);

	Stock stock1;
	stock1.AddProduct(p);
	stock1.AddProduct(p1);
	stock1.AddProduct(p2);
	stock1.AddProduct(p3);
	stock1.AddProduct(p4);
	stock1.AddProduct(p5);
	stock1.AddProduct(p6);
	stock1.AddProduct(p7);
	stock1.AddProduct(p8);
	stock1.AddProduct(p9);

	Meal f(20, "Margarita");
	f.AddProduct(p, 2);
	f.AddProduct(p1, 1);
	f.AddProduct(p2, 3);
	f.AddProduct(p3, 1);

	Meal f1(25, "Sezar");
	f1.AddProduct(p, 1);
	f1.AddProduct(p1, 2);
	f1.AddProduct(p3, 2);
	f1.AddProduct(p4, 3);

	Meal f2(40, "Capital salad");
	f2.AddProduct(p4, 4);
	f2.AddProduct(p5, 3);
	f2.AddProduct(p6, 2);
	f2.AddProduct(p7, 1);
	f2.AddProduct(p8, 3);
	f2.AddProduct(p9, 2);

	Kitchen k;
	k.AddMeal(f);
	k.AddMeal(f1);
	k.AddMeal(f2);

	Client c("Table 1");
	c.AddMenu(k);
	double totaldebt = 0;

	//FileHelper::Save(stock1);

	Stock stock = FileHelper::Read();

	Meal m;

	Table t;

	Notification n;
	while (true)
	{
		system("cls");
		RestaurantName();
		cout << endl << endl;
		RestaurantWord();
		cout << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tCLIENT [1]" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tADMIN  [2]" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tEnter select : ";
		int select;
		cin >> select;
		if (select == 1) {
			GuestPanel(totaldebt, c, k, stock, n, t);
		}
		else if (select == 2) {
			system("cls");
			while (true)
			{
				cin.ignore();
				cin.clear();
				system("cls");
				cout << "\t\t\t\t\t\t\t\tEnter username : ";
				string username;
				getline(cin, username);
				system("cls");
				cout << "\t\t\t\t\t\t\t\tEnter Password: ";
				string password, P;
				char p;
				p = _getch();
				while (p != 13)
				{
					if (p == 8)
					{
						P.resize(P.length() - 1);
						cout << P;
						password.resize(password.length() - 1);
					}
					else {
						P = P + "*";
						cout << P;
						password.push_back(p);
					}
					p = _getch();
					if (p != 13) {
						system("cls");
						cout << "\t\t\t\t\t\t\t\tEnter Password: ";
					}
				}
				cout << endl;
				if (username == "admin") {
					if (password == "admin") {
						AdminPanel(k, stock, c, n, t, m);
						break;
					}
					else {
						cout << "\t\t\t\t\t\t\t\tWrong password!" << endl;
					}
				}
				else {
					cout << "\t\t\t\t\t\t\t\tWrong username!" << endl;
				}
			}
		}
		else {
			cout << "\t\t\t\t\t\t\t\tYour select is incorrect!!!\n\t\t\t\t\t\t\t\tPlease enter retry" << endl;
		}
		system("pause");
	}
}