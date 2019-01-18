#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int k;
vector<int> arr;
vector<int> brr;
vector<char> sign;

int main(void) {
	cin >> k;
	
	for (int i = 0; i < k; i++) {
		char c;
		cin >> c;
		sign.push_back(c);
	}

	for (int i = 0; i < k+1; i++) {
		arr.push_back(i);
	}

	for (int j = 9; j>= 9-k; j--) {
		brr.push_back(j);
	}

	do {
		bool check = false;

		for (int i = 0; i < k; i++) {
			if (sign[i] == '>') {
				if (brr[i] < brr[i + 1]) {
					check = true;
					break;
				}
			}

			else {
				if (brr[i] > brr[i + 1]) {
					check = true;
					break;
				}

			}
		}

		if (!check) {

			for (int i = 0; i < k + 1; i++) {
				cout << brr[i];

			}
			cout << "\n";
			break;
		}

		

	} while (prev_permutation(brr.begin(), brr.end()));


	do {
		bool check = false;

		for (int i = 0; i < k; i++) {
			if (sign[i] == '>') {
				if (arr[i] < arr[i + 1]) {
					check = true;
					break;
				}
			}

			else {
				if (arr[i] > arr[i + 1]) {
					check = true;
					break;
				}

			}
		}

		if (!check) {
			
			for (int i = 0; i <k+1; i++) {
				cout << arr[i];
				
			}
			cout << "\n";
			break;
		}



	} while (next_permutation(arr.begin(), arr.end()));

	



	

}