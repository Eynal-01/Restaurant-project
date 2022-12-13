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
	Meal f(20, "Margarita");
	f.AddProduct(p );
	f.AddProduct(p1 );
	f.AddProduct(p2 );
	f.AddProduct(p3 );

	Product p4("Fillet", 2, 239, 100);
	Product p5("Mayonnaise", 2.5, 679.7, 100);
	Product p6("Beans", 1, 347, 100);
	Meal f1(25, "Sezar");
	f1.AddProduct(p4 );
	f1.AddProduct(p5 );
	f1.AddProduct(p6);
	
	Product p7("Cucumber", 0.7, 30, 100);
	Product p8("Carrot", 1, 41, 100);
	Product p9("Potato", 1, 76.7, 100);
	Product p10("Meat", 11, 70, 100);
	Meal f2(40, "Capital salad");
	f2.AddProduct(p7);
	f2.AddProduct(p8);
	f2.AddProduct(p9);
	f2.AddProduct(p10);

	Kitchen k;
	k.AddMeal(f);
	k.AddMeal(f1);
	k.AddMeal(f2);

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
	stock1.AddProduct(p10);
	
	double totaldebt = 0;

	//FileHelper::Save(stock1);

	Stock stock = FileHelper::Read();

	Meal m;
	Table t;
	Client c;
	Notification n;

	while (true)
	{
		system("cls");
		RestaurantName();
		cout << endl << endl;
		RestaurantWord();
		cout << endl << endl;
		mysetcolor(11, 0);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t CLIENT [1]" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t ADMIN  [2]" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tEnter select : ";
		mysetcolor(7, 0);
		int select;
		cin >> select;
		if (select == 1) {
			system("cls");
			WelcomeWord();
			cout << endl << endl;
			mysetcolor(11, 0);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t TABLE 1 [1]\n\t\t\t\t\t\t\t\t\t\t\t\t\t TABLE 2 [2]\n\t\t\t\t\t\t\t\t\t\t\t\t\t TABLE 3 [3]\n\t\t\t\t\t\t\t\t\t\t\t\t\t TABLE 4 [4]\n\t\t\t\t\t\t\t\t\t\t\t\t\t TABLE 5 [5]\n\t\t\t\t\t\t\t\t\t\t\t\t\t Enter table NO : ";
			mysetcolor(7, 0);
			int tableNo;
			cin >> tableNo;
			Client c(tableNo);
			c.AddMenu(k);
			GuestPanel(totaldebt, c, k, stock, n, t);
		}
		else if (select == 2) {
			system("cls");
			while (true)
			{
				cin.ignore();
				cin.clear();
				system("cls");
				mysetcolor(11, 0);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t    Enter username : ";
				string username;
				getline(cin, username);
				system("cls");
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t    Enter Password: ";
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
						cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t    Enter Password: ";
					}
				}
				cout << endl;
				if (username == "admin") {
					if (password == "admin") {
						AdminPanel(k, stock, c, n, t, m);
						break;
					}
					else {
						mysetcolor(4, 0);
						cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t    Wrong password!" << endl;
						mysetcolor(7, 0);
					}
				}
				else {
					mysetcolor(4, 0);
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t    Wrong username!" << endl;
					mysetcolor(7, 0);
				}
			}
		}
		else {
			mysetcolor(4, 0);
			cout << "\t\t\t\t\t\t\t\tYour select is incorrect!!!\n\t\t\t\t\t\t\t\tPlease enter retry" << endl;
			mysetcolor(7, 0);
		}
		system("pause");
	}
}