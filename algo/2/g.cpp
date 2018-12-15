#include <iostream>

using namespace std;

class Prop
{
public:
	int _min;
	int _max;
	int count;

	Prop()
	{
	}
	Prop(int i)
	{
		_min = i;
		_max = i;
		count = 1;
	}

	void change(Prop &x)
	{
		_min = min(_min, x._min);
		_max = max(_max, x._max);
		count += x.count;
	}
};

int *p, *r;
Prop *pr;

int ge(int a)
{
	if (p[a] != a)
		p[a] = ge(p[a]);
	return p[a];
}

void un(int a, int b)
{
	a = ge(a);
	b = ge(b);

	if (a == b)
		return;
	if (r[a] == r[b])
		++r[a];
	if (r[a] < r[b])
	{
		p[a] = b;
		pr[b].change(pr[a]);
	}
	else
	{
		p[b] = a;
		pr[a].change(pr[b]);
	}
}

int main()
{
	int n;
	cin >> n;
	p = new int[n + 1];
	r = new int[n + 1];
	pr = new Prop[n + 1];

	for (int i = 1; i <= n; ++i)
	{
		p[i] = i;
		r[i] = 0;
		pr[i] = Prop(i);
	}

	string s;
	int tmp1, tmp2;
	while(cin >> s)
	{
		cin >> tmp1;
		if (s[0] == 'u')
		{
			cin >> tmp2;
			un(tmp1, tmp2);
		}
		else
		{
			int result = ge(tmp1);
			cout << pr[result]._min << ' ' << pr[result]._max << ' ' << pr[result].count << '\n';
		}
	}

	return 0;
}
