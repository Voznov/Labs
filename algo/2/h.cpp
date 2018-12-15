#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[200200], r[200200];
int p_[200200], r_[200200];
int total[200200];
vector<int>* u[200200];

bool rule(int a, int b)
{
	return total[a] < total[b];
}

int ge(int a)
{
	if (p[a] != a)
		p[a] = ge(p[a]);
	return p[a];
}

int ge_(int a)
{
	if (p_[a] != a)
		p_[a] = ge_(p_[a]);
	return p_[a];
}

void un_(int a, int b)
{
	a = ge_(a);
	b = ge_(b);

	if (a == b)
		return;
	if (r_[a] == r_[b])
		++r_[a];
	if (r_[a] < r_[b])
		p_[a] = b;
	else
		p_[b] = a;
}

void un(int a, int b)
{
	a = ge(a);
	b = ge(b);

	if (a == b)
		return;

	vector<int> v, ua = *(u[a]), ub = *(u[b]);
	sort(ua.begin(), ua.end(), rule);
	sort(ub.begin(), ub.end(), rule);
	int ia = 0, ib = 0;
	while (ia < ua.size() && ib < ub.size())
	{
		int ca = total[ua[ia]];
		int cb = total[ub[ib]];
		if (ca == cb)
		{
			un_(ua[ia], ub[ib]);
			v.push_back(ge_(ua[ia]));

			++ia; ++ib;
			continue;
		}

		if (ca < cb)
		{
			v.push_back(ge_(ua[ia]));

			++ia;
			continue;
		}

		if (ca > cb)
		{
			v.push_back(ge_(ub[ib]));

			++ib;
			continue;
		}
	}

	while (ia < ua.size())
	{
		v.push_back(ge_(ua[ia]));
		++ia;
	}

	while (ib < ub.size())
	{
		v.push_back(ge_(ub[ib]));
		++ib;
	}

	if (r[a] == r[b])
		++r[a];
	if (r[a] < r[b])
	{
		p[a] = b;
		delete u[b];
		u[b] = &v;
	}
	else
	{
		p[b] = a;
		delete u[b];
		u[a] = &v;
	}

	delete &ua;
	delete &ub;
}

void ad(int a, int exp)
{
	a = ge(a);
	for (int i = 0; i < u[a]->size(); ++i)
		total[ge_(u[a]->at(i))] += exp;
}

int main()
{
	int n;
	cin >> n;
	//p = new int[n + 1];
	//r = new int[n + 1];
	//p_ = new int[n + 1];
	//r_ = new int[n + 1];
	//total = new int[n + 1];
	//u = new vector<int>[n + 1];

	for (int i = 1; i <= n; ++i)
	{
		p[i] = i;
		r[i] = 0;
		p_[i] = i;
		r_[i] = 0;
		total[i] = 0;
		u[i] = new vector<int>;
		(u[i])->push_back(i);
	}

	int m;
	cin >> m;

	string s;
	int tmp1, tmp2;
	for (int i = 0; i < m; ++i)
	{
		cin >> s >> tmp1;
		if (s[0] == 'a')
		{
			cin >> tmp2;
			ad(tmp1, tmp2);
		}
		if (s[0] == 'j')
		{
			cin >> tmp2;
			un(tmp1, tmp2);
		}
		if (s[0] == 'g')
		{
			int result = ge_(tmp1);
			cout << total[result] << '\n';
		}
		//cout << "s=" << s << "; tmp1=" << tmp1 << "; tmp2=" << tmp2 << endl; //
	}

	return 0;
}
