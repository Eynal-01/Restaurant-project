#pragma once
#include<iostream>
#include"Entities.h"
#include"Client.h"
#include"FrontEnd.h"
using namespace std;

void Menu(double totaldebt, Client& c, Kitchen& k, Stock& s, Notification& n, Table& t) {
	system("cls");
	c.ShowMenu();
	mysetcolor(11, 0);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tEnter your choice to view : ";
	int view;
	cin >> view;
	mysetcolor(7, 0);
	system("cls");
	MealWord();
	k.ShowMealById(view);
	mysetcolor(11, 0);
	cout << "Order            [1]" << endl;
	cout << "Add ingredients  [2]" << endl;
	cout << "Enter your choice : ";
	int choice;
	cin >> choice;

	if (choice == 1) {
		cout << "\t\t\t\t\t\t\t\tEnter count of meal : ";
		static int countofmeal;
		cin >> countofmeal;
		
		if (countofmeal > 0) {
			auto meal = k.GetMealById(view);

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
		mysetcolor(11, 0);
		cout << "Enter number of ingredient : ";

		int ingcount;
		cin >> ingcount;
		mysetcolor(7, 0);
		mysetcolor(6, 0);
		auto product = s.GetProductByID(ingcount);
		cout << *product << endl;
		string productname = product->GetName();
		mysetcolor(11, 0);
		cout << "Enter " << productname << " count" << endl;
		int procount = 0;
		cin >> procount;
		mysetcolor(7, 0);
		if (s.CheckProductCount(ingcount, procount)) {
			auto meal = k.GetMealById(view);
			meal->AddProduct(*product);
			cout << *meal << endl;

			system("cls");
			mysetcolor(2, 0);
			cout << "Product added successfully" << endl;
			mysetcolor(11, 0);
			cout << endl;
			cout << "Do you want how much " << meal->GetName() <<" ?" << endl;
			cout << "Enter quantity of meal : ";
			int quantitymeal;
			cin >> quantitymeal;
			mysetcolor(7, 0);
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
				mysetcolor(4, 0);
				cout << "\t\t\t\t\t\t\t\tYour select is incorrect" << endl;
				mysetcolor(7, 0);
			}
		}
		else {
			auto meal = k.GetMealById(view);
			totaldebt += meal->GetPrice();
			mysetcolor(4, 0);
			cout << "\t\t\t\t\t\t\t\tIngredients out of stock" << endl;
			mysetcolor(7, 0);
		}
	}
}