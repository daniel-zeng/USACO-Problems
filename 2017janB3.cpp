//============================================================================
// Name        : 2017janB3.cpp
// Author      : Daniel Zeng
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VII;

void printGrid(VS &arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

void flip(VS &arr, int r, int c) {
	for (int i = 0; i <= r; i++) {
		for (int j = 0; j <= c; j++) {
			if (arr[i][j] == '1'){
				arr[i][j] = '0';
			}else if (arr[i][j] == '0'){
				arr[i][j] = '1';
			}
		}
	}
}

void cowtip() {
	string file = "cowtip";
	string in = file + ".in";
	string out = file + ".out";

	ifstream fin(in.c_str());
	ofstream fout(out.c_str());

	//read input
	int n;

	fin >> n;
	int n2 = n - 1;

	VS grid(n);
	for (int i = 0; i < n; i++) {
		fin >> grid[i];
	}
	int count = 0;

	for (int r = n2; r >= 0; r--) {
		for (int c = n2; c >= 0; c--) {
			char curr = grid[r][c];
			if (curr == '1') {
				flip(grid, r, c);
				count++;
			}

		}

	}
	fout << count;

}
