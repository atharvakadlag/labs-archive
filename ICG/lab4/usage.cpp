#include "draw_line.hpp"
#include "bits/stdc++.h"
using namespace std;

int main()
{
	vector<pair<int, int>> line_points = BLD(-20,10,-30,18);

	for (auto e : line_points)
	{
		cout << "x: " << e.first << "y: " << e.second << "\n";
	}
// 560 360
// 460 533
// 260 533
// 160 360
// 259 186
// 459 186
}