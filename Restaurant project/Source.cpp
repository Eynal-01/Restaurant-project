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

string FileHelper::filename = "products.txt";

void main() {

	Product p("Tomato", 0.4, 18, 100);
	Product p1("Olive", 0.5, 115, 1000);
	Product p2("Mashroom", 0.8, 22, 1000);
	Product p3("Flour", 1, 364, 100);
	Product p4("Chicken fillet", 2, 239, 200);
	Product p5("Mayonnaise", 2.5, 679.7, 150);
	Product p6("Beans", 1, 347, 200);
	Product p7("Cucumber", 0.7, 30, 120);
	Product p8("Cucumber pickle", 1, 10.7, 130);
	Product p9("Carrot", 1, 41, 140);
	Product p10("Potato", 1, 76.7, 150);

	Stock stock;
	stock.AddProduct(p);
	stock.AddProduct(p1);
	stock.AddProduct(p2);
	stock.AddProduct(p3);
	stock.AddProduct(p4);
	stock.AddProduct(p5);
	stock.AddProduct(p6);
	stock.AddProduct(p7);
	stock.AddProduct(p8);
	stock.AddProduct(p9);
	stock.AddProduct(p10);

	Meal f(20, "Margarita");
	f.AddProduct(p);
	f.AddProduct(p1);
	f.AddProduct(p2);
	f.AddProduct(p3);

	Meal f1(25, "Sezar");
	f1.AddProduct(p);
	f1.AddProduct(p1);
	f1.AddProduct(p3);
	f1.AddProduct(p4);

	Meal f2(40, "Capital salad");
	f2.AddProduct(p4);
	f2.AddProduct(p5);
	f2.AddProduct(p6);
	f2.AddProduct(p7);
	f2.AddProduct(p8);
	f2.AddProduct(p9);
	f2.AddProduct(p10);

	Kitchen k;
	k.AddMeal(f);
	k.AddMeal(f1);
	k.AddMeal(f2);

	Client c("Table 1");
	c.AddMenu(k);
	double totaldebt = 0;

	FileHelper::Save(stock);

	Table1 t;
	//Stock obj = FileHelper::Read();
	//obj.ShowProduct();

	Notification n;
	while (true)
	{
		system("cls");
		cout << "CLIENT [1]" << endl;
		cout << "ADMIN  [2]" << endl;
		cout << "Enter select : ";
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
				cout << "Enter username : ";
				string username;
				getline(cin, username);
				system("cls");
				cout << "Enter Password: ";
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
						cout << "Enter Password: ";
					}
				}
				cout << endl;
				if (username == "admin") {
					if (password == "admin") {
						AdminPanel(k, stock, c, n, t);
						break;
					}
					else {
						cout << "Wrong password!" << endl;
					}
				}
				else {
					cout << "Wrong username!" << endl;
				}
			}
		}
		else {
			cout << "Your select is incorrect!!!\nPlease enter retry" << endl;
		}
		system("pause");
	}
}

//class JobPosting {
//public:
//	string companyName;
//	int count;
//	Worker** appliers;
//
//	JobPosting() {}
//
//	JobPosting(const string& companyName) :companyName(companyName) {
//
//	}
//
//	Worker** GetAppliers()const {
//		return appliers;
//	}
//
//	void AddApplier(const Worker& applier) {
//		auto newappliers = new Worker * [count + 1] {};
//		for (size_t i = 0; i < count; i++)
//		{
//			newappliers[i] = appliers[i];
//		}
//		newappliers[count] = new Worker(applier);
//		++count;
//		appliers = newappliers;
//		newappliers = nullptr;
//	}
//
//
//	void ShowAppliers() {
//		cout << "Company name : " << companyName << endl;
//		for (size_t i = 0; i < count; i++)
//		{
//			appliers[i]->Show();
//		}
//	}
//
//};
//
//
//class FileHelper {
//public:
//	static string filename;
//
//	static void Save(const JobPosting& jp) {
//		ofstream fout(filename, ios::app);
//		if (fout.is_open()) {
//			fout << jp.companyName << endl;
//			fout << jp.count << endl;
//			for (size_t i = 0; i < jp.count; i++)
//			{
//				fout << jp.appliers[i]->GetName() << " " << jp.appliers[i]->GetAge() << endl;
//			}
//			fout.close();
//		}
//	}
//
//
//	static JobPosting Read() {
//		JobPosting jp;
//		ifstream fin(filename);
//
//		if (fin.is_open()) {
//			string companyName = "";
//			fin >> companyName;
//			jp.companyName = companyName;
//
//			int count;
//			fin >> count;
//
//			for (size_t i = 0; i < count; i++)
//			{
//				Worker* w = new Worker;
//				string name;
//				int age;
//
//				fin >> name >> age;
//				w->SetName(name);
//				w->SetAge(age);
//
//				jp.AddApplier(*w);
//			}
//			fin.close();
//
//			return jp;
//		}
//	}
//};
//
//string FileHelper::filename = "job.txt";
//
//
//void main() {
//	Worker w1("Gulshen", 25);
//	Worker w2("Ayshen", 29);
//	Worker w3("Aysel", 35);
//	Worker w4("John", 20);
//
//	JobPosting jp("IT_STEP_MMC");
//	jp.AddApplier(w2);
//	jp.AddApplier(w1);
//	jp.AddApplier(w3);
//	jp.AddApplier(w4);
//
//	//FileHelper::Save(jp);
//
//	JobPosting obj = FileHelper::Read();
//	obj.ShowAppliers();
//}