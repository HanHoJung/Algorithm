#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int upper_bound(vector<long long> arr,int key) {
	
	int left = 0;
	int right = arr.size() - 1;

	while (left < right) {
		int mid = (left + right) / 2;
		if (arr[mid] <= key) {
			left = mid + 1;
		}
		else if (arr[mid] > key) {
			right = mid;
		}

	}
	return left;
}

int lower_bound(vector<long long> arr, int key) {

	int left = 0;
	int right = arr.size() - 1;

	while (left < right) {
		int mid = (left + right) / 2;
		if (arr[mid] >= key) {
			right= mid;
		}
		else if (arr[mid] <key) {
			left = mid + 1;
		}

	}

	return left;
}

int main(void) {
	
	int t;
	cin >> t;

	int n, m;
	cin >> n;
	vector<int> A(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	cin >> m;
	vector<int> B(m);
	for (int j = 0; j < m; j++) {
		cin >> B[j];

	}


	vector<long long> cumA;
	vector<long long> cumB;


	//ДЉРћЧе

	for (int i = 0; i < n; i++) {
		long long sum = 0;

		for (int j = i; j < n; j++) {
			sum = sum + A[j];
			cumA.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++) {
		long long sum = 0;
		for (int j = i; j < m; j++) {
			sum = sum + B[j];
			cumB.push_back(sum);
		}
	}



	sort(cumA.begin(), cumA.end());
	sort(cumB.begin(), cumB.end());




	n = cumA.size();
	m = cumB.size();
	long long cnt = 0;
	long long search;

	
	for (int i = 0; i < cumA.size(); i++) {
		search = t - cumA[i];
		

		auto p = equal_range(cumB.begin(), cumB.end(), search);
		cnt = cnt + (p.second - p.first);

	}


	
	cout << cnt << "\n";


	

}


