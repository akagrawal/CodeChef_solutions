#include<iostream>
#include<stdio.h>
using namespace std;
int main() 
{
	int t;
	cin >> t;
	long double U, V, X, ans;
	while (t--) {
		cin >> U >> V >> X;
		ans = X / (U + V);
		cout.precision(7);
		cout << fixed<<ans << endl;
	}	
	return 0;

}
