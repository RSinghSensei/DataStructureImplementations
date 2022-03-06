#include <iostream>
#include <vector>

// Quick Sort Implementation

int pivotPoint(std::vector<int>& v1, unsigned int l, unsigned int pivot)
{
	int lesserBarrier = l - 1;
	for (int i = l; i < pivot; i++)
	{
		if (v1[i] <= v1[pivot])
		{
			lesserBarrier+= 1;
			std::cout << "swap" << std::endl;
			std::swap(v1[lesserBarrier], v1[i]);
			std::cout << "swap" << std::endl;

		}
	}

	std::swap(v1[lesserBarrier + 1], v1[pivot]);
	return lesserBarrier + 1;
}

void quickSort(std::vector<int>& v1, unsigned int l, unsigned int r)
{
	if (l < r)
	{
		int pivot = pivotPoint(v1, l, r);
		quickSort(v1, l, pivot - 1);
		quickSort(v1, pivot + 1, r);
	}

}

int main()
{
	std::vector<int>v1{ 16, 32, 1, 12, 94, 325, 3, 13, 25, 29, 1593, 235 };
	quickSort(v1, 0, v1.size() - 1);
	for (auto x : v1) { std::cout << x << std::endl; }

	return 0;
}