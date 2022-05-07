#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int f(int a, int b) {
	if (a % b == 0)
		return b;
	if (b % a == 0)
		return a;
	if (a > b)
		return f(a % b, b);
	return f(a, b % a);
}

int main()
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	int n;
	in >> n;
	map <float, string> m;
	map <float, string> ::iterator it;
	for (int i = 2; i <= n; i++) 
		for (int j = 1; j < i; j++) {
			int a = f(i, j);
			if (a == 1) {
				float i2 = i;
				float q = j / i2;
				string z = to_string(i);
				string x = to_string(j);
				m.insert(make_pair(q,x+"/"+z));
			}
		}

	for(it=m.begin(); it != m.end(); it++)
		out << it->second << endl;

}
