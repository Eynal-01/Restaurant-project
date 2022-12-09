#pragma once
#include<iostream>
#include"Entities.h"
using namespace std;

void GuestPanel(double totaldebt, Client& c, Kitchen& k, Stock& s, Notification&, Table1& t);

void Menu(double totaldebt, Client& c, Kitchen& k, Stock& s, Notification& n, Table1& t) {
	system("cls");
	c.ShowMenu();
	cout << "Enter your choice to view : ";
	int view;
	cin >> view;
	system("cls");
	k.ShowMealById(view);
	cout << "Order            [1]" << endl;
	cout << "Add ingredients  [2]" << endl;
	cout << "Enter your choice : ";
	int choice;
	cin >> choice;

	if (choice == 1) {
		cout << "Enter count of meal : ";
		int count;
		cin >> count;
		if (count > 0) {
			auto meal = k.GetMealById(view);

			string content = k.GetMealById(view)->GetName();
			string tableNo = c.GetTableNo();
			totaldebt += count * meal->GetPrice();
			cout << "You must pay " << totaldebt << " $ " << endl;
			cout << "Continue       [1]" << endl;
			cout << "Finish process [2]" << endl;
			cout << "Enter your choice : ";
			int choice;
			cin >> choice;
			if (choice == 2) {
				Notification n(count, content, tableNo);
				SendNotification(n, k);
			}
			else if (choice == 1) {
				GuestPanel(totaldebt, c, k, s, n, t);
			}
		}
	}
	else if (choice == 2) {
		system("cls");
		s.ShowProductsToClient();
		cout << "Enter number of ingredient : ";

		int ingcount;
		cin >> ingcount;
		auto product = s.GetProductByID(ingcount);
		cout << *product << endl;
		cout << "Enter " << product->GetName() << " count" << endl;
		int count = 0;
		cin >> count;
		if (s.ProductCount(ingcount, count)) {
			auto meal = k.GetMealById(view);
			meal->AddProduct(*product);
			cout << *meal << endl;
			system("cls");
			cout << "Product added successfully" << endl;
			cout << "Do you want how much " << meal->GetName() << endl;
			cout << "Enter quantity of meal : ";
			int quantitymeal;
			cin >> quantitymeal;
			if (quantitymeal > 0) {
				totaldebt += (meal->GetPrice() + (product->GetPrice() * count)) * quantitymeal;
				cout << "Total cash : " << totaldebt << " $ " << endl;
			}
			else {
				cout << "Your select is incorrect" << endl;
			}
		}
		else {
			auto meal = k.GetMealById(view);
			totaldebt += meal->GetPrice();
			cout << "Ingredients out of stock" << endl;
		}
	}
}