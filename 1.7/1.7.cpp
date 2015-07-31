#include <iostream>

using namespace std;

void setColRow(int **arr, int m, int n)
{
	bool *rows = new bool[m];
	bool *cols = new bool[n];

	memset(rows, 0, sizeof(bool)*m);
	memset(cols, 0, sizeof(bool)*n);

	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
		{
			if(arr[i][j] == 0) {
				rows[i] = true;
				cols[i] = true;
			}
		}

	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
		{
			if(rows[i] || cols[j])
				arr[i][j] = 0;
		}
}

int main()
{
	const int m = 3;
	const int n = 3;

	int **arr = new int*[m];
	for(int i=0; i<m; i++)
		arr[i] = new int[n];

	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			arr[i][j] = m * i + j + 1;
	arr[1][1] = 0;
	arr[2][2] = 0;

	//int arr[m][n] = {	{1, 2, 3},
	//					{4, 0, 6},
	//					{7, 8, 0}
	//				};

	cout << "---" << endl;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			cout << arr[i][j];
		cout << endl;
	}

	setColRow(arr, m, n);

	cout << "---" << endl;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			cout << arr[i][j];
		cout << endl;
	}

	return 0;
}