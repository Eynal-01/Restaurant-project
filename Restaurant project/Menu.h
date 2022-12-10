#pragma once
#include<iostream>
#include"Entities.h"
#include"Client.h"
using namespace std;

//void GuestPanel(double totaldebt, Client& c, Kitchen& k, Stock& s, Notification&, Table1& t);

void Menu(double totaldebt, Client& c, Kitchen& k, Stock& s, Notification& n, Table& t) {
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
		static int countofmeal;
		cin >> countofmeal;
		
		if (countofmeal > 0) {
			auto meal = k.GetMealById(view);

			string content = k.GetMealById(view)->GetName();
			string tableNo = c.GetTableNo();
			totaldebt += countofmeal * meal->GetPrice();
			cout << "You must pay " << totaldebt << " $ " << endl;
			cout << "Continue       [1]" << endl;
			cout << "Finish process [2]" << endl;
			cout << "Enter your choice : ";
			int choice;
			cin >> choice;
			if (choice == 2) {
				Notification n(countofmeal, tableNo);
				n.AddMealToNotification(meal);
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
		string productname = product->GetName();
		cout << "Enter " << productname << " count" << endl;
		int procount = 0;
		cin >> procount;
		if (s.CheckProductCount(ingcount, procount)) {
			auto meal = k.GetMealById(view);
			meal->AddProduct(*product, procount);
			cout << *meal << endl;

			system("cls");
			cout << "Product added successfully" << endl;
			cout << "Do you want how much " << meal->GetName() << endl;
			cout << "Enter quantity of meal : ";
			int quantitymeal;
			cin >> quantitymeal;
			if (quantitymeal > 0) {
				string tableNo = c.GetTableNo();
				string content = k.GetMealById(view)->GetName();
				totaldebt += (meal->GetPrice() + (product->GetPrice() * procount)) * quantitymeal;
				cout << "Total cash : " << totaldebt << " $ " << endl;
				Notification n1( quantitymeal, tableNo);
				n1.AddMealToNotification(meal);
				SendNotification(n1, k);
				/*AddIngredientNotification add(productname, procount);
				SendAddIngredient(add, k);*/
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