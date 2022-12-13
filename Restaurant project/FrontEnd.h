#pragma once
#include<iostream>
using namespace std;

void mysetcolor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}

void StockWord() {

	mysetcolor(6, 0);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t ____________________________  _________  ____   __." << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t /   _____/\\__    ___/\\_____  \\ \\_   ___ \\|    |/ _|" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t \\_____  \\   |    |    /   |   \\/    \\  \\/|      <  " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t /        \\  |    |   /    |    \\     \\___|    |  \\ " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t/_______  /  |____|   \\_______  /\\______  /____|__ \\" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t      \\/                    \\/        \\/        \\/" << endl;
	mysetcolor(7, 0);
}

void KitchenWord() {

	mysetcolor(6, 0);
	cout << "\t\t\t\t\t\t\t\t\t\t\t ____  __._______________________   ___ ______________ _______   " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t|    |/ _|   \\__    ___/\\_   ___ \\ /   |   \\_   _____/ \\      \\  " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t|      < |   | |    |   /    \\  \\//    ~    \\    __)_  /   |   \\ " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t|    |  \\|   | |    |   \\     \\___\\    Y    /        \\/    |    \\" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t|____|__ \\___| |____|    \\______  /\\___|_  /_______  /\\____|__  /" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t        \\/                      \\/       \\/        \\/         \\/ " << endl;
	mysetcolor(7, 0);
}

void MealWord() {

	mysetcolor(3, 0);
	cout << "   _____                 __   " << endl;
	cout << "  /     \\   ____ _____  |  |  " << endl;
	cout << " /  \\ /  \\_/ __ \\__   \\\ |  |  " << endl;
	cout << "/    Y    \\  ___/ / __ \\\|  |__" << endl;
	cout << "\\____|__  /\\___  >____  /____/" << endl;
	cout << "        \\/     \\/     \\/      " << endl;
	mysetcolor(7, 0);
}

void RestaurantName() {

	mysetcolor(6, 0);
	cout << endl << endl;
	cout << " \t\t\t\t\t\t\t\t\t$$\\                      $$\\      $$\\                           $$\\           	 " << endl;
	cout << " \t\t\t\t\t\t\t\t\t$$ |                     $$$\\    $$$ |                          $$ |          	 " << endl;
	cout << " \t\t\t\t\t\t\t\t\t$$ |      $$$$$$\\        $$$$\\  $$$$ | $$$$$$\\  $$$$$$$\\   $$$$$$$ | $$$$$$\\  	 " << endl;
	cout << " \t\t\t\t\t\t\t\t\t$$ |      \\____$$\\       $$\\$$\\$$ $$ |$$  __$$\\ $$  __$$\\ $$  __$$ |$$  __$$\\ 	 " << endl;
	cout << " \t\t\t\t\t\t\t\t\t$$ |      $$$$$$$ |      $$ \\$$$  $$ |$$ /  $$ |$$ |  $$ |$$ /  $$ |$$$$$$$$ |	 " << endl;
	cout << " \t\t\t\t\t\t\t\t\t$$ |     $$  __$$ |      $$ |\\$  /$$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |$$   ____|	 " << endl;
	cout << " \t\t\t\t\t\t\t\t\t$$$$$$$$\\\\$$$$$$$ |      $$ | \\_/ $$ |\\$$$$$$  |$$ |  $$ |\\$$$$$$$ |\\$$$$$$$\\ 	 " << endl;
	cout << " \t\t\t\t\t\t\t\t\t\\________|\\_______|      \\__|     \\__| \\______/ \\__|  \\__| \\_______| \\_______|	 " << endl;
	mysetcolor(7, 0);
}

void RestaurantWord() {

	mysetcolor(6, 0);
	cout << "\t\t\t\t\t\t\t\t\t\t                    _                              _    " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t                   | |                            | |   " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t      _ __ ___  ___| |_ __ _ _   _ _ __ __ _ _ __ | |_  " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t     | '__/ _ \\/ __| __/ _` | | | | '__/ _` | '_ \\| __| " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t     | | |  __/\\__ \\ || (_| | |_| | | | (_| | | | | |_  " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t     |_|  \\___||___/\\__\\__,_|\\__,_|_|  \\__,_|_| |_|\\__| " << endl;
	mysetcolor(7, 0);
}

void WelcomeWord() {

	mysetcolor(6, 0);
	cout << "\t\t\t\t\t\t\t\t\t\t __      _____________.____   _________  ________      _____  ___________" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t/  \\    /  \\_   _____/|    |  \\_   ___ \\ \\_____  \\    /     \\ \\_   _____/" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\\   \\/\\/   /|    __)_ |    |  /    \\  \\/  /   |   \\  /  \\ /  \\ |    __)_ " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t \\        / |        \\|    |__\\     \____ /    |    \\/    Y    \\|        \\" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t  \\__/\\  /  /_______ /|_______ \\______  /\\_______  /\\____|__  /_______  /" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t       \\/          \\/         \\/      \\/         \\/         \\/        \\/ " << endl;
	mysetcolor(7, 0);
}

void SelectionsWord() {

	mysetcolor(6, 0);
	cout << "\t\t\t\t\t\t\t\t  ____________________.____     _______________________________.___________    _______    _________" << endl;
	cout << "\t\t\t\t\t\t\t\t /   _____/\\_   _____/|    |    \\_   _____/\\_   ___ \\__    ___/|   \\_____  \\   \\      \\  /   _____/" << endl;
	cout << "\t\t\t\t\t\t\t\t \\_____  \\  |    __)_ |    |     |    __)_ /    \\  \\/ |    |   |   |/   |   \\  /   |   \\ \\_____  \\ " << endl;
	cout << "\t\t\t\t\t\t\t\t /        \\ |        \\|    |___  |        \\      \\____|    |   |   /    |    \\/    |    \\/        \\" << endl;
	cout << "\t\t\t\t\t\t\t\t/_______  //_______  /|_______ \\/_______  / \\______  /|____|   |___\\_______  /\\____|__  /_______  /" << endl;
	cout << "\t\t\t\t\t\t\t\t        \\/         \\/         \\/        \\/         \\/                      \\/         \\/        \\/ " << endl;
	mysetcolor(7, 0);
}

void MenuWord() {

	mysetcolor(6, 0);
	cout << "   _____  ___________ _______   ____ ___ " << endl;
	cout << "  /     \\ \\_   _____/ \\      \\ |    |   \\" << endl;
	cout << " /  \\ /  \\ |    __)_  /   |   \\|    |   /" << endl;
	cout << "/    Y    \\|        \\/    |    \\    |  / " << endl;
	cout << "\\____|__  /_______  /\\____|__  /______/  " << endl;
	cout << "        \\/        \\/         \\/          " << endl;
	mysetcolor(7, 0);
}