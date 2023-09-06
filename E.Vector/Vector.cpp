#include <iostream>
#include"ArrList.cpp"
using namespace std;
int main()
{
	ArrList<int>arr;
	arr.append(1);
	arr.append(2);
	arr.append(3);
	arr.dispaly();
	cout << "\n";
	arr.deleteAt(0);
	arr.insertAt(1, 20);
	arr.dispaly();
}
