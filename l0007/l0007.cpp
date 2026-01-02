// Given a signed 32-bit integer x, return x with its digits reversed.
// If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

// Assume the environment does not allow you to store 64 - bit integers(signed or unsigned).
//
// Example 1:
//
//      Input: x = 123
//      Output : 321
// 
// Example 2 :
//
//      Input : x = -123
//      Output : -321
// 
// Example 3 :
//
//      Input : x = 120
//      Output : 21
// 
// Constraints:
//      -2^31 <= x <= 2^31 - 1

#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

class Solution {
public:
	int reverse(int x) {		
		int ans = 0;

		// This check is too clow
		//if ((numeric_limits<int>::max() <= x) || (numeric_limits<int>::min() >= x)) {
		//	return 0;
		//}

		while (x != 0) {
			
			if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
				return 0;
			}
			
			ans = ans * 10 + x % 10;
			x = x / 10;				
		}

		return ans;
	}
};

int main()
{
	Solution sol;
	int X;

	X = 123;
	cout << X << ": " << sol.reverse(X) << endl;
	X = -123;
	cout << X << ": " << sol.reverse(X) << endl;
	X = 120;
	cout << X << ": " << sol.reverse(X) << endl;

	X = 1534236469;
	cout << X << ": " << sol.reverse(X) << endl;
	X = -2147483412;
	cout << X << ": " << sol.reverse(X) << endl;
}