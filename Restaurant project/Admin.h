#pragma once
#include<iostream>
#include"Entities.h"
using namespace std;

void AdminPanel(Kitchen& k, Stock& s, Client& c, Notification& n, Table& t) {
	system("cls");
	cout << "KITCHEN [1]" << endl;
	cout << "STOCK   [2]" << endl;
	cout << "BACK    [3]" << endl;
	cout << "Enter select : ";
	int adminselect = 0;
	cin >> adminselect;
	if (adminselect == 1) {
		system("cls");
		cout << "\t\t\t\t\t\t===KITCHEN===" << endl << endl;
		k.ShowNameOfMeals();
		cout << endl;
		cout << "Delete meal   [1]" << endl << endl;
		cout << "Update meal   [2]" << endl << endl;
		cout << "Add meal      [3]" << endl << endl;
		cout << "Notifications [4]" << "(" << k.notificationCount << ")" << endl << endl;

		cout << "Enter your select : ";
		int processselect;
		cin >> processselect;
		if (processselect == 1) {
			while (true)
			{
				cout << "Enter ID of meal for deletion : ";
				int ID;
				cin >> ID;
				if (ID <= k.GetMealsCount()) {
					--ID;
					auto mealtodelete = k.GetMealById(ID);
					k.DeleteMealByID(ID);
					system("cls");
					k.ShowNameOfMeals();
					AdminPanel(k, s, c, n, t);
				}
				else {
					cout << "This meal there is not found in our kitchen" << endl;
				}
			}
		}
		else if (processselect == 2) {
			while (true)
			{
				cout << "Enter ID of meal for updation : ";
				int ID;
				cin >> ID;
				k.UpdateMeal(ID);
				cout << "Meal updated successfully" << endl;
				system("pause");
				AdminPanel(k, s, c, n, t);
			}
		}
		else if (processselect == 3) {
			k.ShowNameOfMeals();
			k.AddMeal();
			k.ShowNameOfMeals();
			system("pause");
			AdminPanel(k, s, c, n, t);
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
			cout << "Reject [1]\nAccept [2]" << endl;
			cout << "Enter your answer : ";
			int answer;
			cin >> answer;
			int count;
			if (answer == 1) {
				string tableNo = c.GetTableNo();
				int count;
				static string content = "We can't preparing your order. Because we are very busy now";
				ClientNotification n(content, tableNo);
				SendNotificationToClient(n, t);
			}
			else if (answer == 2) {
				string tableNo = c.GetTableNo();
				static string content = "We preparing your order. Please wait 10 minutes";
				ClientNotification n(content, tableNo);
				SendNotificationToClient(n, t);
			}
		}
	}
	else if (adminselect == 2) {
		system("cls");
		cout << "=====STOCK=====" << endl;
		s.ShowAllProducts();
		cout << "Delete ingredients  [1]" << endl;
		cout << "Add ingredients     [2]" << endl;
		cout << "Update ingredients  [3]" << endl;
		while (true)
		{
			cout << "Enter your select : ";
			int select;
			cin >> select;
			if (select == 1) {
				cout << "Enter number of ingredient : ";
				int number;
				cin >> number;
				--number;
				if (number <= s.GetIngredientsCount()) {
					s.DeleteIngredientsByID(number);
					system("cls");
					s.ShowProduct();
					system("pause");
					AdminPanel(k, s, c, n, t);
				}
			}
			else if (select == 2) {
				s.ShowProduct();
				s.AddProductToStock();
				s.ShowProduct();
				system("pause");
				AdminPanel(k, s, c, n, t);
			}
			else if (select == 3) {
				s.ShowProduct();
				system("cls");
				s.UpdateIngredient();
				s.ShowProduct();
				system("pause");
				AdminPanel(k, s, c, n, t);
			}
		}
	}
	else if (adminselect == 3) {
		return;
	}
}