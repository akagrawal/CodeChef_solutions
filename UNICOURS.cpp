#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	int n,c;
	int occupied = 0; //occupied till the course
	while (t--)
	{
		cin >> n;
		occupied = 0;
		for(int i=0;i<n;i++)
		{
			cin >> c;
			if (c > occupied)
				occupied = c;
		}
 
		cout << n - occupied << endl;
		
	}
	//cin >> t;
	return 0;
} 
