//============================================================================
// Name        : 2017janB2.cpp
// Author      : Daniel Zeng
//============================================================================

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;
typedef vector<int> VI;
typedef vector<VI> VII;
#define X first
#define Y second

int solve(int f, int s, int num) {
	bool win;
	if (f == s)
		return 0;
	if (num == 0) {
		if (f == 1)
			win = s == 3;
		if (f == 2)
			win = s == 1;
		if (f == 3)
			win = s == 2;
	} else {
		if (f == 1)
			win = s == 2;
		if (f == 2)
			win = s == 3;
		if (f == 3)
			win = s == 1;
	}
	return win ? 1 : 0;
}

void hps() {
	string file = "hps";
	string in = file + ".in";
	string out = file + ".out";

	ifstream fin(in.c_str());
	ofstream fout(out.c_str());

	int n;
	fin >> n;
	cout << n;

	int c1 = 0, c2 = 0;
	int first, second;

	for (int i = 0; i < n; i++) {
		fin >> first >> second;
		c1 += solve(first, second, 0);
		c2 += solve(first, second, 1);
	}
	int max2 = max(c1, c2);
	fout << max2;
}
