#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<cstring>
using namespace std;
bool check(int x, int y, vector<int> fam) {
	return fam[x] == fam[y] ? true : x == fam[y] ? true : y == fam[x] ? true : false;
}
void _union(int x, int y, vector<int> &fam) {
	if (fam[x] > fam[y]) {
		int temp = fam[x];
		for (int i = 0; i < fam.size(); i++)if (fam[i] == temp)fam[i] = fam[y];
	}
	else {
		int temp = fam[y];
		for (int i = 0; i < fam.size(); i++)if (fam[i] == temp)fam[i] = fam[x];
	}
}
void print(vector<int> fam) {
	for (int i = 0; i < fam.size(); i++) {
		if (fam[i] == i) {
			cout << " {" << i;
			for (int j = i+1; j < fam.size(); j++) {
				if (fam[j] == i)cout << "," << j;
			}
			cout << "}";
		}
	}
	cout << endl;
}
int main() {
	vector<int>fam;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)fam.push_back(i);
	string str;
	while (cin >> str, str[0] != '-') {
		int num1, num2, i;
		if (str[0] == 'F') {
			cout << str << " ";
			for (i = 0; i < str.length(); i++)if (isdigit(str[i]))break;
			num1 = stoi(str.substr(i, str.length()));
			cin >> str;
			cout << str << ": ";
			for (i = 0; i < str.length(); i++)if (isdigit(str[i]))break;
			num2 = stoi(str.substr(i, str.length()));
			if (check(num1, num2, fam))cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else {
			for (i = 0; i < str.length(); i++)if (isdigit(str[i]))break;
			num1 = stoi(str.substr(i, str.length()));
			int flag = 0;
			for (; i < str.length(); i++) {
				if (isdigit(str[i])) {
					if (flag == 0)continue;
					else break;
				}
				else {
					if (flag == 0)flag = 1;
				}
			}
			num2 = stoi(str.substr(i, str.length()));
			_union(num1, num2, fam);
			cout << str << ":";
			print(fam);
		}
	}
}