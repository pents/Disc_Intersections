#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <iterator>

using namespace std;

int a[] = {1,5,2,1,4,0};

int solution(vector<int> &A)
{

		vector <int> start(A.size());
		vector <int> end(A.size());
		vector < pair <int, int> > same;
		int collisions = 0;
		for (int i = 0; i < (int)A.size(); i++)
		{
			 start[i] = i - A[i];
			 end[i] =  i + A[i];
			// start.push_back(i - A[i]);
			// end.push_back(i + A[i]);
		}
		for (int i = 0; i < (int)A.size(); i++)
		{
			for (int j = 0; j < (int)end.size(); j++)
			{
				pair<int, int> p = make_pair(i, j);
				if (i == j || find(same.begin(), same.end(), p)!=same.end()) continue;
				if ((start[j] <= end[i] && j > i) || (start[j] >= end[i] && j < i))
				{
					collisions ++;
					same.push_back(make_pair(j,i));
				}
			}
			if (collisions > 10E6) return -1;
		}

		return collisions;
}


int _tmain(int argc, _TCHAR* argv[])
{
	vector <int> A(6);    // A(N)
	for (int i = 0; i < 6; i++) A[i] = a[i];
	cout << "Result = " << solution(A) << endl;

	system("pause");
	return 0;
}
