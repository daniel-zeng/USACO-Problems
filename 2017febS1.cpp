//============================================================================
// Name        : 2017febS1.cpp
// Author      : Daniel Zeng
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VII;

//int main() {
void helpcross() {
	//setup I/O
	string file = "helpcross";
	string in = file + ".in";
	string out = file + ".out";

	ifstream fin(in.c_str());
	ofstream fout(out.c_str());

	int n, c;
	fin >> c >> n; //chickens, cows

	VI chickens(c);
	//chickens
	for (int i = 0; i < c; i++) {
		int ti;
		fin >> ti;
		chickens[i] = ti;
	}
	sort(chickens.begin(), chickens.end());

	//cows
	vector<pair<int, int>> cows;
	for (int i = 0; i < n; i++) {
		int aj, bj;
		fin >> aj >> bj;
		pair<int, int> cow(aj, bj);
		cows.push_back(cow);
	}
	sort(cows.begin(), cows.end());

	cout << "end reading data" << endl << endl;
	int sum = 0;

	//end time swapping
	for (int i = 1; i < n; i++) {
		pair<int, int> prev = cows[i - 1];
		pair<int, int> cow = cows[i];
		if(cow.second < prev.second && cow.first != cow.second){
			int temp;
			temp = cows[i].second;
			cows[i].second = cows[i - 1].second;
			cows[i - 1].second = temp;
		}
	}

	int ch = 0, cow = 0;
	while (ch < chickens.size() && cow < cows.size()) {
		int chickT = chickens[ch];
		int cowAJ = cows[cow].first;
		int cowBJ = cows[cow].second;
		if (cowAJ > chickT) {
			ch++;
		} else if (cowBJ < chickT) {
			cow++;
		} else {
			ch++;
			cow++;
			sum++;
		}
	}
	cout << "result: " << sum;
	fout << sum;
}
