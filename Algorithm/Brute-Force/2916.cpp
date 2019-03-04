#include <iostream>
using namespace std;
int a[10];
bool d[360];
int main(void) {

	int n, t;
	cin >> n >> t;

	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	d[0] = true;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k <360 ; k++) {
			for (int j = 0; j < 360; j++) {
				if (d[j] == false)
					continue;

				d[(j+a[i]) % 360] = true;
				d[(j-a[i] + 360)%360] = true;
			}
		}
	}
	
	while (t--) {
		int x;
		cin >> x;
		if (d[x])
			cout << "YES" << "\n";
		else
			cout<<"NO"<<"\n";
	}

}