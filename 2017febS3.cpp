//============================================================================
// Name        : 2017febS3.cpp
// Author      : Daniel Zeng
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VII;

//forward decs
int floodfill(VII &arr, VII &seen, int r, int c, unordered_set<string> &roads);
void printBoard(VII &arr);

int bounds = 0;

string stringConcat(int r1, int r2, int c1, int c2){
	string str = "";
	std::stringstream stream;
	stream << str << r1 << " " << r2 << " " << c1 << " " << c2;
	string ret = stream.str();

	return ret;
}

bool outBounds(int r, int c) {
	//return true if out of bounds
	if (r < 0 || r >= bounds) {
		return true;
	}
	if (c < 0 || c >= bounds) {
		return true;
	}
	return false;
}

int floodfill(VII &arr, VII &seen, int r, int c, unordered_set<string> &roads) {
	if (!outBounds(r, c) && seen[r][c] != 1) {
		seen[r][c] = 1;
		int sum = 0;
		if (arr[r][c] == 1)
			sum++;
		int row, col;
		string roadFind;

		row = r + 1;
		col = c;
		roadFind = stringConcat(r, row, c, col);
		if(roads.count(roadFind) != 1){
			sum += floodfill(arr, seen, row, col, roads);
		}
		row = r - 1;
		col = c;
		roadFind = stringConcat(r, row, c, col);
		if(roads.count(roadFind) != 1){
			sum += floodfill(arr, seen, row, col, roads);
		}
		row = r;
		col = c - 1;
		roadFind = stringConcat(r, row, c, col);
		if(roads.count(roadFind) != 1){
			sum += floodfill(arr, seen, row, col, roads);
		}
		row = r;
		col = c + 1;
		roadFind = stringConcat(r, row, c, col);
		if(roads.count(roadFind) != 1){
			sum += floodfill(arr, seen, row, col, roads);
		}
		return sum;
	}
	return 0;
}

//int main(){
void countcross() {
	string file = "countcross";
	string in = file + ".in";
	string out = file + ".out";

	ifstream fin(in.c_str());
	ofstream fout(out.c_str());

	int n, k, r;
	fin >> n >> k >> r;

	bounds = n;

	int totalPairs = k * (k - 1);
	int totalAccessible = 0;

	unordered_set<string> roads;

	//roads
	for (int i = 0; i < r; i++) {
		int r1, r2, c1, c2;
		fin >> r1 >> c1 >> r2 >> c2;
		string road = stringConcat(r1 - 1, r2 - 1, c1 - 1, c2 - 1);
		string road2 = stringConcat(r2 - 1, r1 - 1, c2 - 1, c1 - 1);
		roads.insert(road);
		roads.insert(road2);
	}

	//2d array
	VII grid(n, VI(n, 0));

	vector<pair<int, int>> cows;

	//cows
	for (int i = 0; i < k; i++) {
		int kr, kc; //row, col
		fin >> kr >> kc;
		kr--;
		kc--;
		pair<int, int> cow(kr, kc);
		cows.push_back(cow);
		grid[kr][kc] = 1;
	}

	//go through each cow
	for (int i = 0; i < k; i++) {
		pair<int, int> cow = cows[i];
		int kr = cow.first;
		int kc = cow.second;
		VII seen(n, VI(n, 0));
		int numCowsFlood = floodfill(grid, seen, kr, kc, roads) - 1;
		totalAccessible += numCowsFlood;
	}

	int nonAccessible = totalPairs - totalAccessible;
	fout << nonAccessible/2;
}
