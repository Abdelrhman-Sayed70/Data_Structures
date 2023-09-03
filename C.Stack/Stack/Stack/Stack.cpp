#include <iostream>
#include"StackArr.h"
using namespace std;
int main()
{
	StackArr st;
	st.push(1);
	st.push(2);
	st.push(3);

	while (!st.empty()) {
		cout << st.top() << "\n";
		st.pop();
	}
}