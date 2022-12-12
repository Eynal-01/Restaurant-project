#pragma once
#include<iostream>
#include"Entities.h"
#include"Client.h"
#include"FrontEnd.h"
using namespace std;

void Menu(double totaldebt, Client& c, Kitchen& k, Stock& s, Notification& n, Table& t) {
	system("cls");
	c.ShowMenu();
	cout << "\t\t\t\t\t\t\t\tEnter your choice to view : ";
	int view;
	cin >> view;
	
	system("cls");
	MealWord();
	k.ShowMealById(view);
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
			auto meal = k.GetMealById(view);

			string content = k.GetMealById(view)->GetName();
			int tableNo = c.GetTableNo();
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
			auto meal = k.GetMealById(view);
			meal->AddProduct(*product, procount);
			cout << *meal << endl;

			system("cls");
			cout << "\t\t\t\t\t\t\t\tProduct added successfully" << endl;
			cout << "\t\t\t\t\t\t\t\tDo you want how much " << meal->GetName() << endl;
			cout << "\t\t\t\t\t\t\t\tEnter quantity of meal : ";
			int quantitymeal;
			cin >> quantitymeal;
			if (quantitymeal > 0) {
				int tableNo = c.GetTableNo();
				string content = k.GetMealById(view)->GetName();
				totaldebt += (meal->GetPrice() + (product->GetPrice() * procount)) * quantitymeal;
				cout << "\t\t\t\t\t\t\t\tTotal cash : " << totaldebt << " $ " << endl;
				Notification n1( quantitymeal, tableNo);
				n1.AddMealToNotification(meal);
				SendNotification(n1, k);
			}
			else {
				cout << "\t\t\t\t\t\t\t\tYour select is incorrect" << endl;
			}
		}
		else {
			auto meal = k.GetMealById(view);
			totaldebt += meal->GetPrice();
			cout << "\t\t\t\t\t\t\t\tIngredients out of stock" << endl;
		}
	}
}