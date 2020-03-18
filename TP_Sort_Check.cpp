#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int search(int num,int arr[],int SIZE)
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		if(arr[i]==num)
			break;
	}
	return i;
}

int main()
{
	ifstream in("TP_Sort_0516046.txt"),data("sample data.txt");
	if(!in.is_open()||!data.is_open())
	{
		cout << "File Missing" << endl;
		return 0;
	}
	int SIZE,tmp,t,times=0;
	while(data >> SIZE)
	{
		times++;
		cout << times << "." ;
		int arr[SIZE];
		bool flag=1;
		for(int i=0;i<SIZE;i++)
		{
			data >> tmp;
			in >> arr[i];
		}
		data >> t;
		for(int i=0;i<t;i++)
		{
			int a,b;
			char c;
			data >> a >> c >> b;
			if(search(b,arr,SIZE)>search(a,arr,SIZE))
			{
				if(flag)
					cout << "Wrong" << endl;
				flag=0;
				cout << "  " << a << " " << c << " " << b << endl;
			}
		}
		if(flag)
			cout << "Correct" << endl;
	}

}