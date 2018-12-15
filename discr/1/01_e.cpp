#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
	vector<Node*> parents;
	int deep = 0;
	vector<bool> results;
	int size = 0;

	bool result;

	Node()
	{
	};

	void add(Node *parent)
	{
		parents.push_back(parent);
		deep = max(deep, parent->deep + 1);
		++size;
	}

	void run()
	{
		int key = 0;
		for (int i = 0; i < parents.size(); ++i)
			key = 2 * key + parents[i]->result;
		result = results[key];
		//cout << endl << "run: key=" << key << "; result=" << result << endl << "	parents:";
		//for (int i = 0; i < parents.size(); ++i)
		//	cout << " " << parents[i]->result;
	}
};

int main()
{
	int n;
	cin >> n;
	
	vector<bool> in;
	vector<Node*> nodeIn;
	Node a[n + 1];
	//a = (Node*) malloc((n + 1) * sizeof(Node));
	for (int i = 1; i <= n; ++i)
	{
	//	a[i] = Node();
		int size;
		cin >> size;
		if (!size)
		{
			in.push_back(false);
			nodeIn.push_back(a + i);
		}
		else
		{
			int p;
			for (int j = 0; j < size; ++j)
			{
				cin >> p;
				a[i].add(a + p);
			}

			for (int j = 0; j < (1 << size); ++j)
			{
				cin >> p;
				a[i].results.push_back(p);
			}
		}
	}

	cout << a[n].deep << endl;

	int inSize = nodeIn.size();
	for (int i = 0; i < (1 << inSize); ++i)
	{
		int _i = i;
		for (int j = inSize - 1; j >= 0; --j)
		{
			in[j] = (_i % 2);
			_i /= 2;
		}

		for (int j = 0; j < inSize; ++j)
			nodeIn[j]->result = in[j];
		for (int j = 1; j <= n; ++j)
			if (a[j].size)
				a[j].run();

		cout << a[n].result;

		//cout << endl << "D:";
		//for (int j = 0; j < inSize; ++j)
		//	cout << " " << nodeIn[j]->result;
		//cout << endl;
	}


	return 0;
}
