#pragma once
#include<iostream>
#include"Entities.h"
using namespace std;

class FileHelper {
public:
	static string filename;

	static void Save(Stock& stock) {
		ofstream fout(filename, ios::app);
		if (fout.is_open()) {
			fout << stock.GetIngredientsCount() << endl;
			for (size_t i = 0; i < stock.GetIngredientsCount(); i++)
			{
				fout << stock.products[i].GetName() << " " << stock.products[i].GetPrice() <<
					" " << stock.products[i].GetCalories() << " " << stock.products[i].GetProductCount() << endl;
			}fout.close();
		}
	}

	/*static void SaveProduct(const Product& p) {
		ofstream fout(filename, ios::app);
		if (fout.is_open()) {
			fout << "Name : " << p.GetName() << endl;
			fout << "Calories : " << p.GetCalories() << endl;
			fout << "Count : " << p.GetProductCount() << endl;
			fout << endl;
			fout.close();
		}
	}*/

	/*static Stock Read() {
		Stock stock;
		ifstream fin(filename);

		if (fin.is_open()) {

			int count;
			fin >> count;

			for (size_t i = 0; i < count; i++)
			{
				Product* p = new Product;
				string name;
				double price;
				double calories;
				int count;

				fin >> name >> calories;
				p->SetName(name);
				p->SetPrice(price);
				p->SetCalories(calories);
				p->SetProductCount(count);
				stock.AddProduct(*p);
			}
			fin.close();
			return stock;
		}
	}*/
};