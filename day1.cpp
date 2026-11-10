
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiplyStrings(string& s1, string& s2) {

        bool negative = false;
        int i = 0, j = 0;

        if (s1[0] == '-') {
            negative = !negative;
            i = 1;
        }

        if (s2[0] == '-') {
            negative = !negative;
            j = 1;
        }

        while (i < s1.length() && s1[i] == '0')
            i++;

        while (j < s2.length() && s2[j] == '0')
            j++;

        if (i == s1.length() || j == s2.length())
            return "0";

        int n = s1.length() - i;
        int m = s2.length() - j;

        vector<int> result(n + m, 0);

        for (int a = s1.length() - 1; a >= i; a--) {
            for (int b = s2.length() - 1; b >= j; b--) {

                int p = (s1[a] - '0') * (s2[b] - '0');

                int sum = p + result[(a-i) + (b-j) + 1];

                result[(a-i) + (b-j) + 1] = sum % 10;

                result[(a-i) + (b-j)] += sum / 10;
            }
        }

        string ans = "";
        int k = 0;

        while (k < result.size() && result[k] == 0)
            k++;

        for (; k < result.size(); k++)
            ans += char(result[k] + '0');

        if (negative)
            ans = "-" + ans;

        return ans;
    }
};

int main() {
    Solution obj;

    string s1, s2;

    cout << "Enter first number: ";
    cin >> s1;

    cout << "Enter second number: ";
    cin >> s2;

    cout << "Product: " << obj.multiplyStrings(s1, s2);

    return 0;
}
