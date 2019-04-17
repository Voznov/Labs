#include <iostream>
#include <limits>

using namespace std;

const long long zero = numeric_limits<long long>::max();

struct rangetree
{
	rangetree(int);
	rangetree(long long*, int);
	~rangetree();
	long long get(int, int);
	void set(int, int, const long long&);
	void add(int, int, const long long&);

	long long *min_, *set_, *add_;
	bool* isset_;
	int n_;
	void update(int);
	long long get(int, int, int, int, int);
	void set(int, int, int, int, int, const long long&);
	void add(int, int, int, int, int, const long long&);
};

rangetree::rangetree(int m)
{
	for (n_ = 1; n_ < m; n_ *= 2);
	min_ = new long long[2 * n_];
	set_ = new long long[2 * n_];
	add_ = new long long[2 * n_];
	isset_ = new bool[2 * n_];
	for (int i = 0; i < 2 * n_; i++)
	{
		min_[i] = zero;
		add_[i] = 0;
		isset_[i] = false;
	}
}

rangetree::rangetree(long long* b, int m)
{
	for (n_ = 1; n_ < m; n_ *= 2);
	min_ = new long long[2 * n_];
	set_ = new long long[2 * n_];
	add_ = new long long[2 * n_];
	isset_ = new bool[2 * n_];
	for (int i = n_; i < n_ + m; i++)
		min_[i] = b[i - n_];
	for (int i = n_ + m; i < 2 * n_; i++)
		min_[i] = zero;
	for (int i = n_ - 1; i >= 1; i--)
		min_[i] = min(min_[2 * i], min_[2 * i + 1]);
	for (int i = 0; i < 2 * n_; i++)
	{
		add_[i] = 0;
		isset_[i] = false;
	}
}

rangetree::~rangetree()
{
	delete[] min_;
	delete[] add_;
	delete[] isset_;
	delete[] set_;
}

long long rangetree::get(int l, int r)
{
	return get(1, 0, n_, l, r);
}

long long rangetree::get(int v, int lb, int rb, int l, int r)
{
	update(v);
	if (r <= lb || rb <= l)
		return zero;
	if (l <= lb && rb <= r)
		return min_[v];
	return min(
		get(2 * v, lb, (lb + rb) / 2, l, r),
		get(2 * v + 1, (lb + rb) / 2, rb, l, r)
	);
}

void rangetree::set(int l, int r, const long long& val)
{
	set(1, 0, n_, l, r, val);
}

void rangetree::set(int v, int lb, int rb, int l, int r, const long long& val)
{
	update(v);
	if (r <= lb || rb <= l)
		return;
	if (l <= lb && rb <= r)
	{
		set_[v] = val;
		isset_[v] = true;
		min_[v] = val;
		add_[v] = 0;
		return;
	}
	set(2 * v, lb, (lb + rb) / 2, l, r, val);
	set(2 * v + 1, (lb + rb) / 2, rb, l, r, val);
	update(v);
}

void rangetree::add(int l, int r, const long long& val)
{
	add(1, 0, n_, l, r, val);
}

void rangetree::add(int v, int lb, int rb, int l, int r, const long long& val)
{
	update(v);
	if (r <= lb || rb <= l)
		return;
	if (l <= lb && rb <= r)
	{
		min_[v] += val;
		add_[v] = val;
		return;
	}
	add(2 * v, lb, (lb + rb) / 2, l, r, val);
	add(2 * v + 1, (lb + rb) / 2, rb, l, r, val);
	update(v);
}

void rangetree::update(int v)
{
	if (v >= n_)
	{
		add_[v] = 0;
		if (isset_[v])
		{
			isset_[v] = false;
			min_[v] = set_[v];
		}
		return;
	}
	if (add_[v] != 0)
	{
		if (isset_[2 * v])
			set_[2 * v] += add_[v];
		else
			add_[2 * v] += add_[v];
		min_[2 * v] += add_[v];
		if (isset_[2 * v + 1])
			set_[2 * v + 1] += add_[v];
		else
			add_[2 * v + 1] += add_[v];
		min_[2 * v + 1] += add_[v];
		add_[v] = 0;
	}
	if (isset_[v])
	{
		set_[2 * v] = set_[v];
		min_[2 * v] = set_[v];
		isset_[2 * v] = true;
		set_[2 * v + 1] = set_[v];
		min_[2 * v + 1] = set_[v];
		isset_[2 * v + 1] = true;
		add_[2 * v] = 0;
		add_[2 * v + 1] = 0;
		isset_[v] = false;
	}
	min_[v] = min(min_[2 * v], min_[2 * v + 1]);
}

long long * arr;

int main() {
	int n;
	cin >> n;
	arr = new long long[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	rangetree t(arr, n);

	string s;
	while (cin >> s) {
		long long a, b;
		cin >> a >> b;
		switch (s[2]) {
		case 'n':
			{
				cout << t.get(a - 1, b)  << endl;
				break;
			}
		case 't':
			{
				long long x;
				cin >> x;
				t.set(a - 1, b, x);
				break;
			}
		case 'd':
			{
				long long x;
				cin >> x;
				t.add(a - 1, b, x);
				break;
			}
		}
	}

	return 0;
}
