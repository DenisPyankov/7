#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	int n;
	in >> n;
	float x = 100;
	for (int i = 0; i < n; i+=2) {
		float USD, EUR;
		in >> USD >> EUR;
		float newUSD, newEUR;
		in >> newUSD >> newEUR;
		x = max( x/USD*newUSD, x/EUR*newEUR);
	}
	out << x;
}
