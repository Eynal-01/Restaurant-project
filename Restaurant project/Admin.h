#pragma once
#include<iostream>
#include"Entities.h"
#include"FrontEnd.h"
using namespace std;

void AdminPanel(Kitchen& k, Stock& s, Client& c, Notification& n, Table& t, Meal& m) {
	system("cls");
	mysetcolor(6, 0);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tKITCHEN [1]" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tSTOCK   [2]" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tBACK    [3]" << endl;
	mysetcolor(11, 0);			  	   
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tEnter select : ";
	int adminselect = 0;
	cin >> adminselect;
	mysetcolor(7, 0);
	if (adminselect == 1) {
		system("cls");
		KitchenWord();
		k.ShowNameOfMeals();
		cout << endl;
		mysetcolor(6, 0);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tDelete meal   [1]" << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tUpdate meal   [2]" << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tAdd meal      [3]" << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tNotifications [4]";
		mysetcolor(4, 0);
		cout << "(" << k.notificationCount << ")" << endl << endl;
		mysetcolor(11, 0);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tEnter your select : ";
		int processselect;
		cin >> processselect;
		if (processselect == 1) {
			while (true)
			{
				mysetcolor(11, 0);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tEnter ID of meal for deletion : ";
				int ID;
				cin >> ID;
				if (ID <= k.GetMealsCount()) {
					--ID;
					auto mealtodelete = k.GetMealById(ID);
					k.DeleteMealByID(ID);
					//system("cls");
					k.ShowNameOfMeals();
					AdminPanel(k, s, c, n, t, m);
				}
				else {
					mysetcolor(4, 0);
					cout << "\t\t\t\t\t\t\t\t\t\t\t\tThis meal there is not found in our kitchen" << endl;
					mysetcolor(7, 0);
				}
			}
		}
		else if (processselect == 2) {
			while (true)
			{
				mysetcolor(11, 0);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tEnter ID of meal for updation : ";
				int ID;
				cin >> ID;
				k.UpdateMeal(ID);
				mysetcolor(2, 0);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tMeal updated successfully" << endl;
				system("pause");
				AdminPanel(k, s, c, n, t, m);
			}
		}
		else if (processselect == 3) {
			k.ShowNameOfMeals();
			k.AddMeal();
			k.ShowNameOfMeals();
			system("pause");
			AdminPanel(k, s, c, n, t, m);
		}
		else if (processselect == 4) {
			/*if (k.notificationCount > 1) {
				k.notificationCount--;*/
			for (size_t i = 0; i < k.notificationCount; i++)
			{
				k.notification.Show();
			}
			//}
			k.notificationCount--;
			mysetcolor(6, 0);
			cout << "Reject [1]\nAccept [2]" << endl;
			mysetcolor(11, 0);
			cout << "Enter your answer : ";
			int answer;
			cin >> answer;
			int count;
			if (answer == 1) {
				int tableNo = c.GetTableNo();
				int count;
				mysetcolor(4, 0);
				static string content = "We can't preparing your order. Because we are very busy now";
				mysetcolor(7, 0);
				ClientNotification n(content, tableNo);
				SendNotificationToClient(n, t);
			}
			else if (answer == 2) {
				int tableNo = c.GetTableNo();
				mysetcolor(2, 0);
				static string content = "We preparing your order. Please wait 10 minutes";
				mysetcolor(7, 0);
				ClientNotification n(content, tableNo);
				SendNotificationToClient(n, t);
			}
		}
	}
	else if (adminselect == 2) {
		system("cls");
		StockWord();
		s.ShowProduct();
		while (true)
		{
			mysetcolor(6, 0);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tDelete ingredients  [1]" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tAdd ingredients     [2]" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tUpdate ingredients  [3]" << endl;
			mysetcolor(11, 0);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tEnter your select : ";
			int select;
			cin >> select;
			if (select == 1) {
				mysetcolor(11, 0);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tEnter number of ingredient : ";
				int number;
				cin >> number;
				--number;
				if (number <= s.GetIngredientsCount()) {
					s.DeleteIngredientsByID(number);
					system("cls");
					s.ShowProduct();
					system("pause");
					AdminPanel(k, s, c, n, t, m);
				}
			}
			else if (select == 2) {
				s.ShowProduct();
				s.AddProductToStock();
				s.ShowProduct();
				system("pause");
				AdminPanel(k, s, c, n, t, m);
			}
			else if (select == 3) {
				s.ShowProduct();
				system("cls");
				s.UpdateIngredient();
				s.ShowProduct();
				system("pause");
				AdminPanel(k, s, c, n, t, m);
			}
		}
	}
	else if (adminselect == 3) {
		return;
		AdminPanel(k, s, c, n, t, m);
	}
}