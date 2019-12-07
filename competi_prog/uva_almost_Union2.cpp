#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int parent[200001];
int arr[200001];
int sum[200001];
int people, count, dex;
int iden[200001];
int its_Parent(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = its_Parent(parent[x]);
}
void set(int x, int y)
{
	int temp1 = its_Parent(x);
	int temp2 = its_Parent(y);
	if (temp1 != temp2)
	{
		parent[temp2] = temp1;
		arr[temp1] += arr[temp2];
		sum[temp1] += sum[temp2];
	}
}
void move(int x)
{
	int p = its_Parent(iden[x]);
	arr[p]--;
	sum[p] -= x;
	iden[x] = ++dex;
	parent[dex] = dex;
	arr[dex] = 1;
	sum[dex] = x;
}
int main()
{
	while (scanf("%d%d", &people, &count) != EOF)
	{
		dex = people;
		for (int i = 0; i <= people; i++)
		{
			parent[i] = i;
			arr[i] = 1;
			sum[i] = i;
			iden[i] = i;
		}
		int cmd;
		int x, y;
		while (count--)
		{
			cin >> cmd;
			if (cmd == 1)
			{
				cin >> x >> y;
				set(iden[x], iden[y]);
			}
			else if (cmd == 2)
			{
				cin >> x >> y;
				int temp1 = its_Parent(iden[x]);
				int temp2 = its_Parent(iden[y]);
				if (temp1 != temp2)
				{
					move(x);
					set(iden[x], iden[y]);
				}
			}
			else
			{
				cin >> x;
				int p = its_Parent(iden[x]);
				cout << arr[p] << " " << sum[p] << endl;
			}
		}
	}
}