#include<iostream>
using namespace std;
typedef unsigned long long int ulli;
typedef long long int lli;
ulli arr[31];
ulli products[200000];
ulli  n, k,t;
ulli ans;
int l, r, L, R;
int index;
bool flag = true;
void Sort(int left, int right);
void Merge(int left, int right);
ulli temp[100000];
ulli num;
void search(int left, int right)
{
	if (left == right)
	{
		if (num<=k / products[left])
			ans += left - L;
 
		else 
		    ans += left - L-1;
		    
		return;
	}
	if (left + 1 == right)
	{
		if (num>(k / products[left]))
			ans += left - L-1;
		else if (num>(k / products[right]))
			ans += left - L;
		else
			ans += right - L;
		return;
	} 
	int mid = (left + right) / 2;
	if (num <=(k / products[mid]))
	{
		search(mid + 1, right);
	}
	else search(left, mid);
}
 
 
 
void dfs(int i, ulli prod)
{
	if ((i == l + 1 && flag) || i == n + 1)
	{
		//	//cout << "i " << i << " prod " << prod << endl;
 
		products[index] = prod;
		index++;
		return;
	}
 
	else if (arr[i] <= k / (prod))
	{
		dfs(i + 1, prod*arr[i]);
	}
	dfs(i + 1, prod);
 
}
 
 
void Sort(int left, int right)
{
	//cout << "left " << left << " " << right << endl;
		if (left == right)
	{
		return;
	}
	
	if (left + 1 == right)
	{
		//cout << "left+1=right " << left << " " << right << endl;
		if (products[left] > products[right])
		{
			t = products[left];
			products[left] = products[right];
			products[right] = t;
		}
		return;
	}
 
	else
	{
		Sort(left, (left + right) / 2);
		Sort(((left + right) / 2) + 1, right);
		Merge(left, right);
	}
}
 
 
void Merge(int left, int right)
{
	//cout << "merge " << left << " " << right << endl;
	for (int i = left; i <= right; i++)
	{
		//cout << "arr " << products[i] << " ";
	}
 
	int mid = (left + right) / 2;
	int i = left, j = mid + 1, l = 0;
 
	while (i <= mid && j <= right)
	{
		if (products[i] <= products[j])
		{
			temp[l] = products[i];
			i++;
			l++;
		}
		//cout << "l  " << l << " ";
		if (products[i] >= products[j])
		{
			temp[l] = products[j];
			j++;
			l++;
		}
	}
	//cout << "l  " << l << " ";
	while (i <= mid)
	{
		temp[l] = products[i];
		i++;
		l++;
	}
	//cout << "l  " << l << " ";
	while (j <= right)
	{
		temp[l] = products[j];
		j++;
		l++;
	}
	//cout << " " << l << endl;
 
	for (int i = 0; i < l; i++)
	{
		////cout << "prod " << temp[i]<<" ";
		products[i + left] = temp[i];
	}
	return;
}
 
 
int main()
{
	ans = 0;
	cin >> n >> k;
 
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	l = n / 2;
	r = n / 2 + 1;
	index = 1;
	dfs(1, 1);
	int left = index - 1;
	L = left;
	flag = false;
	//cout << endl;
	dfs(l + 1, 1);
	int right = index - 1;
	// 1->left, left+1 to right
	//cout << left << " " << right << " " << index << endl;;
 
	Sort(left + 1, right);
 
	//  //cout<<"done";
	for (int i = 1; i <= left; i++)
	{
		num = products[i];
		search(left + 1, right);
	}
 
	cout <<ans - 1;
	//cin >> n;
	return 0;
} 
