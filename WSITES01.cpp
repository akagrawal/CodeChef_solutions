#include<iostream>
using namespace std;
char *web = new char[200010];
char *filters = new char[200010];
char *filters_final = new char[200010];
char sign;
int answer = 0;
struct Node
{
	Node *c[26];
	bool leaf;
	char sign, ch;
};
int index = 0;
Node *root = new Node();
 
void print_filters(Node *p, int level)
{
	Node *q;
	for (int i = 0; i < 26; i++)
	{
		if (p->c[i])
		{
			q = p->c[i];
			filters[level] = q->ch;
			if (q->sign == '-')
			{
				answer++;
				for (int j = 0; j <= level; j++)
				{
					//cout<<filters[j];
					filters_final[j + index] = filters[j];
				}
				//cout << endl;
				index += level + 1;
				filters_final[index] = '\0';
				index++;
			}
			else
			{
				print_filters(q, level + 1);
			}
		}
	}
	return;
}
 
 
 
bool insert()
{
	int i = 0;
	Node *p = root, *q;
	while (web[i] != '\0')
	{
		if (p->c[web[i] - 'a'] == NULL)
		{
			p->c[web[i] - 'a'] = new Node();
			q = p->c[web[i] - 'a'];
			for (int i = 0; i < 26; i++)
				q->c[i] = NULL;
			q->sign = sign;
			q->ch = web[i];
			q->leaf = false;
			i++;
			if (web[i] == '\0')
				q->leaf = true;
			p = q;
		}
		else
		{
			q = p->c[web[i] - 'a'];
			if (sign == '+')
			{
				if (q->leaf && q->sign == '-')
					return 0;
				else
				{
					if (web[i + 1] == '\0')
						q->leaf = true;
					q->sign = '+';
					p = q;
					i++;
				}
			}
			else
			{
				if (web[i + 1] == '\0' && q->sign == '+')
					return 0;
				i++;
				p = q;
			}
		}
	}
	return 1;
}
 
int main()
{
	int n;
	cin >> n;
 
	for (int i = 0; i < 26; i++)
	{
		root->c[i] = NULL;
		root->leaf = 0;
	}
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		cin >> sign;
		cin >> web;
		if (insert())
			continue;
		else
		{
			cout << -1;
			flag = false;
			break;
		}
	}
	if (flag)
	{
		print_filters(root, 0);
		cout << answer << endl;
		//	cout << index << endl;
		for (int i = 0; i <= index; i++)
		{
			if (filters_final[i])
			{
				//cout << i << " ";
				cout << filters_final[i];
			}
 
			else
				cout << endl;
		}
 
	}
	//	cin >> n;
	return 0;
}
