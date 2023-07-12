#include <iostream>
#include <stack>
#include <string>
#include <windows.h>

using namespace std;

namespace ns1//
{
    bool isMatchingPair(char opening, char closing)
    {
        return (opening == '(' && closing == ')') || (opening == '[' && closing == ']') || (opening == '{' && closing == '}');
    }

    bool isBalanced(const string& expression)
    {
        stack<char> brackets;

        for (char bracket : expression)
        {
            if (bracket == '(' || bracket == '[' || bracket == '{')
            {
                brackets.push(bracket);
            }
            else if (bracket == ')' || bracket == ']' || bracket == '}')
            {
                if (brackets.empty() || !isMatchingPair(brackets.top(), bracket))
                {
                    return false;
                }
                brackets.pop();
            }
        }

        return brackets.empty();
    }
}
using namespace ns1;//

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string expression;
    cout << "Введіть рядок з дужками: ";
    getline(cin, expression);

    if (isBalanced(expression))
    {
        cout << "Рядок містить коректне розташування дужок." << endl;
    }
    else
    {
        cout << "Рядок містить некоректне розташування дужок." << endl;
    }

    return 0;
}