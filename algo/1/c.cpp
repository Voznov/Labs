#include <iostream>

using namespace std;

long long inverseCount = 0;

int* merge(int* left, int* right, int leftSize, int rightSize)
{
	int* result = (int*) malloc((leftSize + rightSize) * sizeof(int));
	int itLeft = 0, itRight = 0, i = 0;
	while (itLeft < leftSize && itRight < rightSize)
	{
		if (left[itLeft] < right[itRight])
			result[i++] = left[itLeft++];
		else
		{
			inverseCount += (leftSize - itLeft);
			result[i++] = right[itRight++];
		}
	}
	while (itLeft < leftSize)
		result[i++] = left[itLeft++];
	while (itRight < rightSize)
		result[i++] = right[itRight++];
	
	return result;
}

void mergeSort(int l, int r, int* v)
{
	if (l + 1 >= r)
		return;
	int m = (l + r) / 2;

	mergeSort(l, m, v);
	mergeSort(m, r, v);

	int* left =  (int*) malloc((m - l) * sizeof(int));
	int* right = (int*) malloc((r - m) * sizeof(int));
	for (int i = l; i < m; ++i)
		left[i - l] = *(v + i);
	for (int i = m; i < r; ++i)
		right[i - m] = *(v + i);

	int* result = merge(left, right, m - l, r - m);
	for (int i = l; i < r; ++i)
		*(v + i) = *(result + i - l);

	free(result);
	free(left);
	free(right);
}

int main()
{
	int n;
	cin >> n;

	int* v = (int*) malloc(n * sizeof(int));
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		v[i] = temp;
	}

	mergeSort(0, n, v);

	cout << inverseCount;

	return 0;
}
