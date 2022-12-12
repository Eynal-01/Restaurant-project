#pragma once
#include<iostream>
#include<assert.h>
#include<string>
#include<list>
#include<vector>
#include"Stack.h"
using namespace std;

class ClientNotification {
	string content;
	string tableNo;
public:
	ClientNotification() = default;
	ClientNotification(const string& content, const string& tableNo) {
		SetContent(content);
		SetTableNo(tableNo);
	}

#pragma region Setters
	void SetContent(const string& content) {
		if (!content.empty()) {
			this->content = content;
		}
		//throw "Content is null of client notification";
	}
	void SetTableNo(const string& tableNo) {
		if (!tableNo.empty()) {
			this->tableNo = tableNo;
		}
		//throw "No of table is empty";
	}
#pragma endregion

#pragma region Getters
	string GetTableNo()const noexcept {
		return tableNo;
	}
	string GetContent()const noexcept {
		return content;
	}
#pragma endregion

	friend ostream& operator<<(ostream& out, const ClientNotification& clientnotifications);
};

ostream& operator<<(ostream& out, const ClientNotification& clientnotifications) {
	out << "Content : " << clientnotifications.GetContent() << endl;
	out << "Table NO : " << clientnotifications.GetTableNo() << endl;
	return out;
}

class Product {
	int id;
	double price;
	double calories;
	string name;
public:
	static int productCount;
	static int ID;
	Product() = default;
	Product(const string& name, const double& price, const double& calories, const int& productCount) {
		SetID(ID++);
		SetName(name);
		SetPrice(price);
		SetCalories(calories);
		SetProductCount(productCount);
	}
#pragma region Setters
	void SetName(const string& name) {
		assert(!name.empty() && "Name of product is null");
		this->name = name;
	}
	void SetCalories(const double& calories) {
		assert(calories > 0 && "Calories of product is negative or equal to 0");
		this->calories = calories;
	}
	void SetPrice(const double& price) {
		assert(price >= 0 && "Price of product is negative or equal to 0");
		this->price = price;
	}
	void SetID(const int& id) {
		this->id = id;
	}
	void SetProductCount(const int& productCount) {
		assert(productCount > 0 && "Product count will be more than 0");
		this->productCount = productCount;
	}
#pragma endregion

#pragma region Getters
	double GetPrice()const {
		return price;
	}
	double GetCalories()const {
		return calories;
	}
	string GetName()const {
		return name;
	}
	int GetID()const {
		return id;
	}
	static int GetProductCount() {
		return productCount;
	}
#pragma endregion

	friend ostream& operator<<(ostream& out, const Product& products);
};

ostream& operator<<(ostream& out, const Product& products) {
	out << "Product name : " << products.GetName() << endl;
	out << "Product calories : " << products.GetCalories() << endl;
	return out;
}

int Product::productCount = 0;

class Meal {
	int id;
	double price;
	string name;
	double allCalories;
public:
	Stack<Product>products;
	static int productcount;
	static int ID;
	Meal() = default;
	Meal(const double& price, const string& name) {
		SetId(ID++);
		SetName(name);
		SetPrice(price);
	}
#pragma region Setters
	void SetId(const int& id) {
		this->id = id;
	}
	void SetName(const string& name) {
		assert(!name.empty() && "Name of Meal is null");
		this->name = name;
	}
	void SetPrice(const double& price) {
		assert(price > 0 && "Price of Meal is negative or equal to 0");
		this->price = price;
	}
#pragma endregion

#pragma region Getters
	int GetID()const {
		return id;
	}
	double GetPrice()const {
		return price;
	}
	string GetName()const {
		return name;
	}
	void GetAllCalories() {
		for (size_t i = 0; i < products.GetSize(); i++)
		{
			allCalories += products[i].GetCalories();
		}
	}
	int GetProductCount()const noexcept {
		return Product::GetProductCount();
	}
#pragma endregion

	Product* GetProductByID(int id) {
		for (size_t i = 0; i < products.GetSize(); i++)
		{
			if (products[i].GetID() == id) {
				return &products[i];
			}
			//throw "This ingredient is unavailable";
		}
	}

	void UpdateProduct() {
		cout << "Enter id of product : ";
		int id;
		cin >> id;
		auto prod = GetProductByID(id);
		cout << "Name [1]" << endl;
		cout << "Price [2]" << endl;
		cout << "Calories [3]" << endl;
		cout << "Count [4]" << endl;
		cout << "Enter your select : ";
		int select;
		cin >> select;
		if (select == 1) {
			cin.ignore();
			cin.clear();
			cout << "Enter new name of product : ";
			string newname;
			getline(cin, newname);
			prod->SetName(newname);
		}
		else if (select == 2) {
			cout << "Enter new price of product : ";
			double newprice;
			cin >> newprice;
			prod->SetPrice(newprice);
		}
		else if (select == 3) {
			cout << "Enter new calories of product : ";
			double newcalories;
			cin >> newcalories;
			prod->SetCalories(newcalories);
		}
		else if (select == 4) {
			cout << "Enter new quantity of product : ";
			int newquantity;
			cin >> newquantity;
			prod->SetProductCount(newquantity);
		}
	}

	void AddProduct(Product& product, const int& productcount) {
		for (size_t i = 0; i < productcount; i++)
		{
			products.Push(product);
		}
	}
	void ShowIngredients() {
		products.Show();
	}
	void ShowMealsName()const {
		cout << GetName() << endl;
	}

	friend ostream& operator<<(ostream& out, Meal& meal);
};

ostream& operator<<(ostream& out, Meal& meal) {
	out << "ID of meal : " << meal.id << endl << endl;
	out << "Name of Meal : " << meal.name << endl << endl;
	meal.products.Show();
	meal.GetAllCalories();
	out << "Calories of Meal : " << meal.allCalories << endl << endl;
	return out;
}

class Notification {
	int quantity;
	string tableNo;
public:
	Stack<Meal>meals;
	Notification() = default;
	Notification(const int& quantity, const string& tableNo) {
		SetNotificationQuantity(quantity);
		SetTableNo(tableNo);
	}
#pragma region Setters

	void SetNotificationQuantity(const int& quantity) {
		if (quantity > 0) {
			this->quantity = quantity;
		}
		//throw "Quantity of notification is null";
	}
	void SetTableNo(const string& tableNo) {
		if (!tableNo.empty()) {
			this->tableNo = tableNo;
		}
		//throw "No of table is empty";
	}
#pragma endregion

#pragma region Getters
	int GetQuantity()const noexcept {
		return quantity;
	}
	string GetTableNo()const noexcept {
		return tableNo;
	}
#pragma endregion

	void AddMealToNotification(Meal* meal) {
		meals.Push(*meal);
	}

	friend ostream& operator<<(ostream& out, const Notification& notifications);
};

ostream& operator<<(ostream& out, Notification& notifications) {
	for (size_t i = 0; i < notifications.meals.GetSize(); i++)
	{
		out << notifications.meals[i] << endl;
	}
	out << "Meal count : " << notifications.GetQuantity() << endl;
	out << "Table no : " << notifications.GetTableNo() << endl;

	return out;
}

class Table {
	string message;
	string tableNo;
public:
	static int notificationcount;
	Stack<ClientNotification>clientnotification;
	Stack<Notification>notifications;
	Table() = default;
	Table(const int& notif) {
		SetCount(notificationcount);
	}

#pragma region Setters
	void SetMessage(const string& message) {
		this->message = message;
	}
	void SetCount(const int& notificationcount) {
		this->notificationcount = notificationcount;
	}
#pragma endregion
#pragma region Getters
	string GetMessage() const {
		return message;
	}
	int GetNotificationCount()const {
		return notificationcount;
	}
	
#pragma endregion

	void AddNotification(const Notification& notification) {
		notifications.Push(notification);
	}
};

int Table::notificationcount = 0;

class Kitchen {
public:
	Stack<Notification>notification;
	Stack<Meal>meals;
	static int notificationCount;
	Kitchen() = default;
	Kitchen(const int& notificationCount, const string& Meal) {
		SetNotificationCount(notificationCount);
	}

	void SetNotificationCount(const int& notificationCount) {
		assert(notificationCount >= 0 && "Notification count is negative number");
		this->notificationCount = notificationCount;
	}

	int GetNotificationCount()const {
		return notificationCount;
	}


	void AddMeal(Meal& meal) {
		meals.Push(meal);
	}

	void ShowNameOfMeals() {
		for (size_t i = 0; i < meals.GetSize(); i++)
		{
			cout << "\t\t\t\t\t\t\t\t" << meals[i].GetID() << " " << meals[i].GetName() << " - " << meals[i].GetPrice() << " $ " << endl;
		}
	}

	void Show()const {
		meals.Show();
	}

	void ShowMealById(int id) {
		for (size_t i = 0; i < meals.GetSize(); i++)
		{
			if (meals[i].GetID() == id) {
				cout << meals[i];
			}
		}
	}

	Meal* GetMealById(int id) {
		for (size_t i = 0; i < meals.GetSize(); i++)
		{
			if (meals[i].GetID() == id) {
				return &meals[i];
			}
		}
	}

	void DeleteMealByID(int index = 0) {
		meals.Pop(index);
	}

	void AddMeal() {
		cout << "Enter name of meal : ";
		string namemeal;
		getline(cin, namemeal);
		cout << "Enter price of meal : ";
		double price;
		cin >> price;
		cout << "Enter ingredients count : ";
		int count;
		cin >> count;
		for (size_t i = 0; i < count; i++)
		{
			cout << "Enter name of ingredient : ";
			string ingname;
			getline(cin, ingname);
			cout << "Enter price of ingredient : ";
			double ingprice;
			cin >> ingprice;
			cout << "Enter calories of ingredient : ";
			double caloriesing;
			cin >> caloriesing;
		}
	}

	int GetMealsCount() {
		return meals.GetSize();
	}

	void UpdateMeal(int id) {
		auto meal = GetMealById(id);
		cout << "Name [1]" << endl;
		cout << "Price [2]" << endl;
		cout << "Irigredients [3]" << endl;
		cout << "Enter your select : ";
		int select;
		cin >> select;
		if (select == 1) {
			cin.ignore();
			cin.clear();
			cout << "Enter new name of meal : ";
			string newname;
			getline(cin, newname);
			meal->SetName(newname);
		}
		else if (select == 2) {
			cout << "Enter new price of meal : ";
			double newprice;
			cin >> newprice;
			meal->SetPrice(newprice);
		}
		else if (select == 3) {
			meal->ShowIngredients();
			meal->UpdateProduct();
		}
	}
};

int Kitchen::notificationCount = 0;

class Client {
	Stack<Kitchen>menu;
	Stack<Table>table;
public:
	string tableNo;
	Client() = default;
	Client(const string& tableNo) {
		SetTableNo(tableNo);
	}
	void AddMenu(Kitchen& kitchen) {
		menu.Push(kitchen);
	}
	void SetTableNo(const string& tableNo) {
		if (!tableNo.empty()) {
			this->tableNo = tableNo;
		}
		//throw "Number of table is empty";
	}
	void ShowMenu() {
		for (size_t i = 0; i < menu.GetSize(); i++)
		{
			menu[i].ShowNameOfMeals();
		}
	}

	string GetTableNo()const noexcept {
		return tableNo;
	}

	string GetTable() {
		cout << "Enter table NO : ";
		string tableNo;
		getline(cin, tableNo);
		return tableNo;
	}
};

class Stock {
public:
	vector<Product>products;
	Stock() = default;

	void AddProduct(Product& product) {
		products.push_back(product);
	}

	Product* GetProductByID(int index = -1) {
		for (size_t i = 0; i < products.size(); i++)
		{
			if (products[i].GetID() == index) {
				return &products[i];
			}
			//throw "This ingredient is unavailable";
		}
	}

	int GetIngredientsCount()const {
		return products.size();
	}

	int GetOneProductCount()const {
		Product* prod;
		return prod->GetProductCount();
	}

	bool CheckProductCount(int index, int count) {
		Product* product = GetProductByID(index);
		if (count <= product->GetProductCount()) {
			int temp = product->GetProductCount() - count;
			products[index].SetProductCount(temp);
			return true;
		}
		else {
			cout << "This count very high" << endl;
			cout << "Press any keyy and back to client menu" << endl;
			system("pause");
			return false;
		}
	}

	void DeleteIngredientsByID(int index = -1) {
		if (index == -1) {
			products.pop_back();
		}
		else {
			products.erase(products.begin() + index);
		}
	}

	void ShowProduct() {
		for (size_t i = 0; i < products.size(); i++)
		{
			cout << "\t\t\t\t\t\t\t\t\tID : " << products[i].GetID() << "\n\t\t\t\t\t\t\t\t\tName of product : " << products[i].GetName() <<
				"\n\t\t\t\t\t\t\t\t\tCount of product : " << products[i].GetProductCount() << endl
				<< "\t\t\t\t\t\t\t\t\tPrice of product : " << products[i].GetPrice() << endl << endl;
		}
	}

	void ShowProductsToClient() {
		for (size_t i = 0; i < products.size(); i++)
		{
			cout << "ID : " << products[i].GetID() << "\nName of ingredient : " << products[i].GetName() <<
				"\nCalories of ingredient : " << products[i].GetCalories() << endl << endl;
		}
	}

	void UpdateIngredient() {
		ShowProduct();
		cout << "Name     [1]" << endl;
		cout << "Price    [2]" << endl;
		cout << "Calories [3]" << endl;
		cout << "Count    [4]" << endl;
		cout << "Which feature you want to update : ";
		int feature;
		cin >> feature;
		if (feature == 1) {
			cout << "Enter number of ingredient : ";
			int num;
			cin >> num;
			Product* p = GetProductByID(num);
			system("cls");
			cout << p << endl;
			cin.clear();
			cin.ignore();
			cout << "Enter new name of ingredient : ";
			string newname;
			getline(cin, newname);
			p->SetName(newname);
		}
		else if (feature == 2) {
			cout << "Enter number of ingredient : ";
			int num;
			cin >> num;
			Product* p = GetProductByID(num);
			cout << "Enter new price of ingredient : ";
			double newprice;
			cin >> newprice;
			p->SetPrice(newprice);
		}
		else if (feature == 3) {
			cout << "Enter number of ingredient : ";
			int num;
			cin >> num;
			Product* p = GetProductByID(num);
			cout << "Enter new calories of ingredient : ";
			double newcalories;
			cin >> newcalories;
			p->SetCalories(newcalories);
		}
		else if (feature == 4) {
			cout << "Enter number of ingredient : ";
			int num;
			cin >> num;
			Product* p = GetProductByID(num);
			cout << "Enter new quantity of ingredient : ";
			int quantity;
			cin >> quantity;
			p->SetProductCount(quantity);
		}
	}

	void AddProductToStock() {
		cin.clear();
		cin.ignore();
		cout << "Enter name of new ingredient : ";
		string name;
		getline(cin, name);
		cout << "Enter price of new ingredient : ";
		double price;
		cin >> price;
		cout << "Enter calory of new ingredient : ";
		double calory;
		cin >> calory;
		cout << "Enter count of new ingredient : ";
		int count;
		cin >> count;
		Product p(name, price, calory, count);
		products.push_back(p);
		//FileHelper::SaveProduct(p);
	}
};

void SendNotificationToClient(ClientNotification& n, Table& t) {
	t.clientnotification.Push(n);
	t.notificationcount++;
}

void SendNotification(Notification& n1, Kitchen& k) {
	k.notification.Push(n1);
	k.notificationCount++;
}

//void SendAddIngredient(AddIngredientNotification& add, Kitchen& k) {
//	k.notification.Push(add);
//	k.notificationCount++;
//}