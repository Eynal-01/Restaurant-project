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
            int count1 = stock.GetIngredientsCount();
            fout << count1 << endl;
            for (size_t i = 0; i < stock.products.size(); i++)
            {
                fout << stock.products[i].GetName() << " " << stock.products[i].GetPrice() << " " << stock.products[i].GetCalories() << " " << stock.products[i].GetProductCount() << endl;
            }
            fout.close();
        }
    }
    static Stock Read() {
        Stock stock;
        ifstream fin(filename);
        int count1;
        fin >> count1;
        if (fin.is_open()) {
            for (size_t i = 0; i < count1; i++)
            {
                Product p;
                string name;
                double price;
                double calories;
                int count;
                fin >> name;
                fin >> price;
                fin >> calories;
                fin >> count;
                p.SetName(name);
                p.SetPrice(price);
                p.SetCalories(calories);
                p.SetProductCount(count);
                stock.AddProduct(p);
            }
            fin.close();
            return stock;
        }
    }
};
string FileHelper::filename = "products.txt";