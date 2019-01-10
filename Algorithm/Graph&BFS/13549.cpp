//#include <iostream>
//#include <queue>
//#define MAX 100000
//using namespace std;
//bool check[100001];
//int dist[100001];
//int main(void) {
//	int n, k;
//	cin >> n >> k;
//
//	queue<int> q;
//	queue<int> next_q;
//	q.push(n);
//	check[n] = true;
//	while (!q.empty()) {
//		int node = q.front();
//		q.pop();
//
//
//		if (node == k)
//			break;
//
//		int new_node = node * 2;
//
//		//*
//		if (new_node <= MAX) {
//
//			if (check[new_node] == false) {
//				check[new_node] = true;
//				dist[new_node] = dist[node];
//				q.push(new_node);
//			}
//
//		}
//
//		new_node = node + 1;
//
//		//+
//		if (new_node <= MAX) {
//			if (check[new_node] == false) {
//				check[new_node] = true;
//				dist[new_node] = dist[node] + 1;
//				next_q.push(new_node);
//			}
//		}
//
//		//-
//		new_node = node - 1;
//		if (new_node >= 0) {
//			if (check[new_node] == false) {
//				check[new_node] = true;
//				dist[new_node] = dist[node] + 1;
//				next_q.push(new_node);
//			}
//		}
//
//
//
//		if (q.empty()) {
//			q = next_q;
//			next_q = queue<int>();
//		}
//	}
//
//
//	cout << dist[k];
//}



#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;
bool check[100001];
int dist[100001];
int main(void) {
	int n, k;
	cin >> n >> k;

	deque<int> q;
	
	q.push_front(n);
	check[n] = true;
	while (!q.empty()) {
		int node = q.front();
		q.pop_front();


		if (node == k)
			break;

		int new_node = node * 2;

		//*
		if (new_node <= MAX) {

			if (check[new_node] == false) {
				check[new_node] = true;
				dist[new_node] = dist[node];
				q.push_front(new_node);
			}

		}

		new_node = node + 1;

		//+
		if (new_node <= MAX) {
			if (check[new_node] == false) {
				check[new_node] = true;
				dist[new_node] = dist[node] + 1;
				q.push_back(new_node);
			}
		}

		//-
		new_node = node - 1;
		if (new_node >= 0) {
			if (check[new_node] == false) {
				check[new_node] = true;
				dist[new_node] = dist[node] + 1;
				q.push_back(new_node);
			}
		}


	}


	cout << dist[k];
}