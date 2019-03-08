#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int d[502][502];
int sum[502];
int a[501];
int main(void) {

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		memset(d, 0, sizeof(d));
		memset(sum, 0, sizeof(sum));

		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			sum[i] = sum[i - 1] + a[i];
		}

		for (int j = 2; j <= n; j++) 
		{
			for (int i=j-1; i>0; i--)
			{
				d[i][j] = -1;
				
				for(int k=i; k<j; k++)
				{
					if (d[i][j] == -1)
						d[i][j] = d[i][k] + d[k + 1][j];

					d[i][j] = min(d[i][j], d[i][k]+d[k + 1][j]);
					

				}

				d[i][j] += sum[j]-sum[i - 1] ;

			}

		}
		cout << d[1][n] << "\n";

	}

}