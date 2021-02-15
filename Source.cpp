#include<iostream>
#include <ctime>

using namespace std;
int n = 100000;

int* arrA= new int[n];
int* arrC=new int[n];
int* arr = new int[n];

void merge(int li, int di) {

	int aBeg = li, bBeg = ((li + di) / 2) + 1, cPlace = li;
	while (aBeg < ((li + di) / 2) + 1 && bBeg < di + 1)
	{

		if (arrA[aBeg] < arrA[bBeg])
		{
		
			arrC[cPlace] = arrA[aBeg];
			aBeg++;
		}
		else
		{
		
			arrC[cPlace] = arrA[bBeg];
			bBeg++;
		}
		cPlace++;
	}


	for (int i = aBeg; i < ((li + di) / 2) + 1; i++)
	{
		arrC[cPlace] = arrA[i];
		cPlace++;
	}

	for (int i = bBeg; i < di + 1; i++)
	{
		arrC[cPlace] = arrA[i];
		cPlace++;
	}
	
	for (int i = li; i < di + 1; i++) {

		arrA[i] = arrC[i];
	}
}
void mergeSort(int li, int di) {

	if (li < di) {
	
		mergeSort(li, (li + di) / 2);

		
		mergeSort(((li + di) / 2) + 1, di);

		
		merge(li, di);
	}
	

}
void QuickSort(int li, int di) {
	int j = li, k = di;
	if (li < di) {
		int Etalon = arr[(di + li) / 2];

		int temp;
		do
		{
			while (arr[j] < Etalon) j++;

			while (arr[k] > Etalon) k--;

			if (j <= k)
			{
				temp = arr[k];
				arr[k] = arr[j];
				arr[j] = temp;

				j++;
				k--;
			}
		} while (j <= k);


		QuickSort( li, k);

		QuickSort( j, di);
	}
}
void test(int num) {
	for (int i = 0; i < num; i++)
	{
		arrA[i] = rand()%100;
	}
	for (int j = 0; j < num; j++)
	{
		arr[j] = arrA[j];
	}


	clock_t c0, c1, c2, c3;

	c0 = clock();

	QuickSort(0, num-1);
	
	c1 = clock();
	float time1 = (float)(c1 - c0) / CLOCKS_PER_SEC;
	cout << " elements: " << num << " - time for Q SORT  " << (float)time1 << endl;

	c2 = clock();
	mergeSort(0, num-1);

	
    c3 = clock();
    float time2 = (float)(c3 - c2) / CLOCKS_PER_SEC;
    cout << " elements: " << num << " - time for MERGE SORT " << (float)time2 << endl;

}



int main() {
	test(n);
	delete[]arrA;
	delete[]arr;
	delete[]arrC;

	return 0;
}