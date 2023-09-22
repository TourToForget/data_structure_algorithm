#include<iostream>
using namespace std;
template <typename T>
void sswap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
template <typename T>
void print(T a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << a[i]<<' ';

	}
	cout << endl;
}
template <typename T>
void count_sort(T a[], int len)
{
	int* r = new int[len];
	for (int i = 0; i < len; i++)
	{
		r[i] = 0;
	}
	for (int i = 1; i < len; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				r[i]++;
			}
			else
			{
				r[j]++;
			}
		}
	}
	int t = 0;
	while (t<len)
	{
		if (r[t] == t)
		{
			t++;
		}
		else
		{
			int s = r[t];
			sswap(a[s], a[t]);
			sswap<int>(r[s], r[t]);
		}
	}
	print(a, len);
}
template <typename T>
void select_sort(T a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int flag = i;
		for (int j = i; j < len; j++)
		{
			if (a[j] < a[flag])
			{
				flag = j;
			}
		}
		sswap(a[flag], a[i]);
	}
	print(a, len);
}
template <typename T>
void bubble_sort(T a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				sswap(a[j], a[j + 1]);
			}
		}
	}
	print(a, len);
}
template <typename T>
void insert_sort(T a[], int len)
{
	for (int i = 1; i < len; i++)
	{
		T temp = a[i];
		int j;
		for (j = i - 1; j >= 0 && a[j] > temp; j--)
		{
			a[j + 1] = a[j];
			
		}
		a[j + 1] = temp;
	}
	print(a, len);
}
int main()
{
	int n;
	cin >> n;
	int* p = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	print(p, n);
	insert_sort(p, n);

}