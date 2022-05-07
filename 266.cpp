#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct C {
	int start;
	int end;
};

int main()
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	int n;
	in >> n;
	vector <C> v(n);
	vector <int> t(1440);
	for (int i = 0; i < n; i++) {
		int q, w, e, r;
		in >> q >> w >> e >> r;
		v[i].start = q * 60 + w;
		v[i].end = e * 60 + r;
		if (v[i].start < v[i].end) {
			for (int j = v[i].start; j < v[i].end; j++)
				t[j]++;
		}
		else {
			for (int j = v[i].start; j < 1440; j++)
				t[j]++;
			for (int j = 0; j < v[i].end; j++)
				t[j]++;
		}
	}

	int res = 0;
	for (auto i : t)
		if (i == n)
			res++;
	out << res;

}
