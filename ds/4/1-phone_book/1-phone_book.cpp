#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
	unordered_map<int, string> book;
	vector<string> finds;
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		string query;
		cin >> query;
		if (query[0] == 'a') {
			int number;
			string name;
			cin >> number >> name;
			book[number] = name;
		} else if (query[0] == 'd') {
			int number;
			cin >> number;
			book.erase(number);
		} else {
			int number;
			cin >> number;
			if (book.find(number) == book.end()) {
				finds.push_back("not found");
			} else {
				finds.push_back(book.at(number));
			}
		}
	}
	for (string f : finds) {
		cout << f << endl;
	}
}
