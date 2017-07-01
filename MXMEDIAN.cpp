#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t, n, m, maxi, z;
	cin >> t;
	long long int count[100001];
	long long int c = 0;
	while (t--)
	{
		c = 0;
		m = 0;
		cin >> n;
		//	int *num = new int[(2 * n)];
 
		for (int i = 0; i < 2 * n; i++)
		{
			cin >> count[i];
		}
 
		sort(count, count + 2 * n);
		cout << count[(3 * n - 1) / 2]<<endl;
		int i = 0, j = n;
		for (int i = 0; i < n; i++)
		{
			cout << count[i] << " " << count[i + n] << " ";
		}
		cout << endl;
	}
	//cin >> t;
	return 0;
} 
