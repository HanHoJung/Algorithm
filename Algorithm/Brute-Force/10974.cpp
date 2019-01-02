#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool next_permutation(vector<int> &arr) {


	int index = arr.size() - 1;

	//step1:오름차순 찾기
	while (index > 0 && arr[index - 1] > arr[index])
		index--;


	if (index == 0) {
		return false;
	}

	//step2:arr[k]와 바꿀 수 찾기
	int k = index - 1;
	int n = arr.size() - 1;
	while (arr[k] > arr[n])
		n--;

	swap(arr[k], arr[n]);


	//step3:정렬
	n = arr.size() - 1;

	while (index <= n) {
		swap(arr[index], arr[n]);
		index++;
		n--;

	}



	return true;
}

int main(void) {

	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}



	do {


		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}

		cout << "\n";


	} while (next_permutation(arr));





}