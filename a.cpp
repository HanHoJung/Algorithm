#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long init(vector<long long> &arr, vector<long long> &tree,int start, int end, int index) {

	if (start == end)
		return tree[index] = arr[start];


	int mid = (start + end) / 2;

	tree[index] = init(arr, tree, start, mid, index * 2) + init(arr, tree, mid + 1, end, index * 2 + 1);
	return tree[index];

}



void update(vector<long long> & arr, vector<long long> & tree,int start, int end,int node, int index, long long diff){

	if (!(start <= index && index <= end))
		return;

	tree[node] += diff;

	int mid = (start + end) / 2;

	if (start != end) {
		update(arr, tree, start, mid, node * 2, index, diff);
		update(arr, tree, mid + 1, end, node * 2 + 1, index, diff);

	}

}

long long sum(vector<long long> &arr, vector<long long> & tree, int start, int end, int left, int right, int node) {

	if (right < start || end < left)
		return 0;

	if (left <= start && right <= end)
		return tree[node];

	int mid = (start + end) / 2;

	return sum(arr, tree, start, mid,left,right, node * 2) + sum(arr, tree, mid + 1, end, left, right, node * 2 + 1);


}

int main(void) {
	int n, m, k;
	cin >> n >> m >> k;
	vector<long long> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int h = (int)ceil(log2(n));
	vector<long long> tree((1 << (h + 1)));

	init(arr, tree, 0, n - 1, 1);

	cout << tree[1] << "\n";

	m = m + k;

	while (m--) {

		int order;
		cin >> order;

		if (order == 1) {
			int pos;
			int val;
			cin >> pos >> val;

			long long diff = val - arr[pos-1];
			update(arr, tree, 0, n - 1,1, pos-1, diff);

		}

		if (order == 2) {
			int left;
			int right;
			cin >> left >> right;
			cout << sum(arr, tree,0,n-1,left-1,right-1, 1) << "\n";

		}


	}


}