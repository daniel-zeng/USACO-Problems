//============================================================================
// Name        : 2017febS2.cpp
// Author      : Daniel Zeng
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VII;

//int main(){
void maxcross() {
	//setup I/O
	string file = "maxcross";
	string in = file + ".in";
	string out = file + ".out";

	ifstream fin(in.c_str());
	ofstream fout(out.c_str());

	int n, k, b;
	fin >> n >> k >> b;
	cout << n << " " << k << " " << b << endl;
	unordered_set<int> broken;

	//load in each broken light
	for (int i = 0; i < b; i++) {
		int id;
		fin >> id;
		broken.insert(id - 1);
		cout << id - 1 << endl;
	}
	cout << endl;

	int min = n + 100; 
	//find a min

	int runningSum = 0; //running sum of broken
	//compute the prefix
	for (int i = 0; i < n; i++) {
		bool brokenAtI = broken.count(i) != 0;	//true means it's broken
		cout << "at " << i << " it is: " << brokenAtI;
		if (brokenAtI) {
			runningSum++;
		}
		if (i >= k) {
			//look back i - k
			bool brokenAtIMK = broken.count(i - k) != 0;
			if (brokenAtIMK) {
				runningSum--;
			}
			//can't compute running sum if it's less than k - 1
			min = runningSum < min ? runningSum : min;
		}
		cout << " running sum is: " << runningSum << endl;

	}
	cout << "results: " << min << endl;
	fout << min << endl;
}
