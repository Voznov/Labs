#include <iostream>

using namespace std;

class N
{
public:
	int num;
	N* next;

	N(int num_)
	{
		num = num_;
		next = nullptr;
	}

	N(int num_, N* next_)
	{
		num = num_;
		next = next_;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	N *head = nullptr, *mid = nullptr, *tail = nullptr;
	int size = 0;

	string tmp1;
	int tmp2;

	for (int i = 0; i < n; ++i)
	{
		cin >> tmp1;

		switch (tmp1[0])
		{
		case '+':
			cin >> tmp2;
			if (size)
			{
				tail->next = new N(tmp2);
				tail = tail->next;
				if (size % 2 == 0)
					mid = mid->next;
			}
			else
				head = mid = tail = new N(tmp2);
			++size;
			break;
		case '*':
			cin >> tmp2;
			if (size)
			{
				mid->next = new N(tmp2, mid->next);
				if (size % 2 == 0)
					mid = mid->next;
				if (size == 1)
					tail = tail->next;
			}
			else
				head = mid = tail = new N(tmp2);
			++size;
			break;
		case '-':
			cout << head->num << '\n';
			head = head->next;
			if (size % 2 == 0)
				mid = mid->next;
			--size;
			break;
		}
		//cout << "\"" << tmp1 << (tmp1[0] != '-' ? " " + to_string(tmp2) : "") << "\"\n"; //
		//if (size) { cout << "head=" << head->num << "; mid=" << mid->num << "; tail=" << tail->num << "\n->"; N *it = head; while (it != nullptr) { cout << ' ' << it->num; it = it->next; } cout << endl; } //
	}

	return 0;
}
