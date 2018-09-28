#include <iostream>
#include <vector>
using namespace std;
struct T
{
	int a;
	string b;
	char c;
}temp;
vector <T> v;
int main() {
	temp.a = 1;
	temp.b = "adf";

	v.push_back(temp);
	temp.a = 2;
	temp.b = "fsd";
	v.push_back(temp);
}