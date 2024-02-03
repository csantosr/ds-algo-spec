#include <iostream>

using namespace std;

int main() {
	int money;
	cin >> money;
	int coins = 0;
	coins += (int)(money / 10);
	money = money % 10;
	coins += (int)(money / 5);
	money = money % 5;
	coins += (int)(money / 1);
	money = money % 1;
	cout << coins;
}
