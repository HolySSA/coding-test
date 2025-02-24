#include <iostream>
#include <stack>
using namespace std;

int n;
string str;
double alphabet[26];
stack<double> s;

int main() {
	cin >> n >> str;
	for (int i = 0; i < n; i++) {
            cin >> alphabet[i];
	}

	for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            if (ch >= 'A' && ch <= 'Z')
                s.push(alphabet[ch - 'A']);
            else {
                double num2 = s.top();
                s.pop();
                double num1 = s.top();
                s.pop();

                double tmp;
                if (ch == '+')
                    tmp = num1 + num2;
                else if (ch == '-')
                    tmp = num1 - num2;
                else if (ch == '*')
                    tmp = num1 * num2;
                else if (ch == '/')
                    tmp = num1 / num2;
                
                s.push(tmp);
            }
        }

        cout.precision(2);
        cout << fixed << s.top();
        return 0;
}
