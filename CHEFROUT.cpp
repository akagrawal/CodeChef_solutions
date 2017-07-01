#include<iostream>
using namespace std;
int main() 
{
	int t;
	cin >> t;
	int c, e, s;
	bool flag = true;
	char *ch = new char[100010];
	while(t--) 
	{   
		flag = true;
		c = e = s = 0;
		cin >> ch;
		int i = 0;
		while (ch[i] != '\0') 
		{
			if (ch[i] == 'C') 
			{  
				c = 1;
				if (e == 1 || s == 1)
				{
					flag = false;
					break;
				}
 
			}
			else if(ch[i]=='E')
			{
				e = 1;
				if ( s == 1)
				{
					flag = false;
					break;
				}
			}
			else if (ch[i]== 'S')
			{
				s = 1;	
			}
 
			i++;
		}
		if (flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	//cin >> t;
	return 0;
} 
