// CPP implementation of
// above algorithm
#include <bits/stdc++.h>
using namespace std;

int MaxSumDifference(int a[], int n)
{
	// final sequence stored in the vector
	vector<int> finalSequence;

	// sort the original array
	// so that we can retrieve
	// the large elements from
	// the end of array elements
	sort(a, a + n);

	// In this loop first we will insert
	// one smallest element not entered
	// till that time in final sequence
	// and then enter a highest element
	// (not entered till that time) in
	// final sequence so that we
	// have large difference value. This
	// process is repeated till all array
	// has completely entered in sequence.
	// Here, we have loop till n/2 because
	// we are inserting two elements at a
	// time in loop.
	for (int i = 0; i < n / 2; ++i) {
		finalSequence.push_back(a[i]);
		finalSequence.push_back(a[n - i - 1]);
	}

	// If there are odd elements, push the
	// middle element at the end.
	if (n % 2 != 0)
		finalSequence.push_back(a[n/2]);

	// variable to store the
	// maximum sum of absolute
	// difference
	int MaximumSum = 0;

	// In this loop absolute difference
	// of elements for the final sequence
	// is calculated.
	for(int ele:finalSequence)cout<<ele<<" ";
	cout<<endl;
	for (int i = 0; i < n - 1; ++i) {
		MaximumSum = MaximumSum + abs(finalSequence[i] - 
								finalSequence[i + 1]);
				cout<<MaximumSum<<" ";
	}cout<<endl;

	// absolute difference of last element
	// and 1st element
	MaximumSum = MaximumSum + abs(finalSequence[n - 1] -
									finalSequence[0]);

	// return the value
	return MaximumSum;
}

// Driver function
int main()
{
	int a[] = { 1, 2,3,4,5 };
	int n = sizeof(a) / sizeof(a[0]);

	cout << MaxSumDifference(a, n) << endl;
}
