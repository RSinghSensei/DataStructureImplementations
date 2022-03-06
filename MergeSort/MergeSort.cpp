#include <iostream>
#include <vector>

// Merge Sort Implementation

void merge(std::vector<int>& v1, unsigned int l, unsigned int mid, unsigned int r)
{
	std::vector<int>leftTemp;
	unsigned int leftElements = mid - l + 1;
	for (unsigned int i = 0; i < leftElements; i++)
	{
		leftTemp.push_back(v1[l + i]);
	}
	std::vector<int>rightTemp;
	unsigned int rightElements = r - mid;
	for (unsigned int i = 0; i < rightElements; i++)
	{
		rightTemp.push_back(v1[i + mid + 1]);
	}
	unsigned int leftPtr = 0, rightPtr = 0;

	while(leftPtr < leftTemp.size() && rightPtr < rightTemp.size())
	{
		if (leftTemp[leftPtr] <= rightTemp[rightPtr])
		{
			v1[l] = leftTemp[leftPtr];
			leftPtr += 1;
		}
		else
		{
			v1[l] = rightTemp[rightPtr];
			rightPtr += 1;
		}

		l += 1;
	}

	while(leftPtr < leftTemp.size())
	{
		v1[l] = leftTemp[leftPtr];
		leftPtr += 1;
		l += 1;
	}
	while(rightPtr < rightTemp.size())
	{
		v1[l] = rightTemp[rightPtr];
		rightPtr += 1;
		l += 1;
	}

}

void mergeSort(std::vector<int>& v1, unsigned int l, unsigned int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		mergeSort(v1, l, mid);
		mergeSort(v1, mid + 1, r);
		merge(v1, l, mid, r);
	}
}

int main()
{
	std::vector<int>v1{ 16, 32, 1, 12, 94, 325, 3, 13, 25, 29, 1593, 235 };
	mergeSort(v1, 0, v1.size() - 1);
	for (auto x : v1) { std::cout << x << std::endl; }

	return 0;
}