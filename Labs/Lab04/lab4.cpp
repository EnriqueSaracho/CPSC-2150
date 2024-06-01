#include <iostream>
#include <string>
#include <stack>
#include <queue>

std::string in2prefix(std::string exp);
std::string pre2infix(std::string exp);
std::string post2infix(std::string exp);

int main()
{
    std::string infixExp = "( ( x % d) + (Y - c))";
    std::string prefixExp = "*+A Bt";
    std::string postfixExp = "x d % Y c - +";

    std::cout << "in2prefix:" << std::endl;
    std::cout << in2prefix(infixExp) << std::endl;

    std::cout << "pre2infix:" << std::endl;
    std::cout << pre2infix(prefixExp) << std::endl;

    std::cout << "post2infix:" << std::endl;
    std::cout << post2infix(postfixExp) << std::endl;
}

std::string post2infix(std::string exp)
{
    std::string output;
    std::stack<std::string> operands;
    std::string s;

    for (char &c : exp)
    {
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        {
            std::string op2 = operands.top();
            operands.pop();
            std::string op1 = operands.top();
            operands.pop();

            std::string s = "(";
            s.append(op1);
            s.push_back(c);
            s.append(op2);
            s.push_back(')');
            operands.push(s);
        }
        else if ((c > 64 && c < 91) || (c > 96 && c < 123)) // if it's a letter
        {
            std::string s(1, c);
            operands.push(s);
        }
        else
        {
            continue;
        }
    }
    output = operands.top();

    return output;
}

std::string pre2infix(std::string exp)
{
    std::string output;
    std::stack<char> operators;
    std::queue<char> operands;

    for (char &c : exp)
    {

        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        {
            operators.push(c);
            output.push_back('(');
        }
        else if ((c > 64 && c < 91) || (c > 96 && c < 123)) // if it's a letter
        {
            operands.push(c);
        }
        else
        {
            continue;
        }

        if (operands.size() > 1)
        {
            output.push_back(operands.front());
            operands.pop();
            output.push_back(operators.top());
            operators.pop();
            output.push_back(operands.front());
            operands.pop();
            output.push_back(')');
        }
    }
    if (!operands.empty())
    {
        output.push_back(operators.top());
        operators.pop();
        output.push_back(operands.front());
        operators.pop();
        output.push_back(')');
    }

    return output;
}

std::string in2prefix(std::string exp)
{
    std::string output;
    std::stack<char> operators;
    std::queue<char> operands;

    for (char &c : exp)
    {
        if (c == '(')
        {
            operators.push(c);
        }
        else if (c == ')')
        {
            if (operands.size() < 2)
            {
                std::string temp = output;
                output = operators.top();
                operators.pop();
                output.append(temp);
                if (!operands.empty())
                {
                    output.push_back(operands.front());
                    operands.pop();
                }
                operators.pop();
            }
            else
            {
                output.push_back(operators.top());
                operators.pop();
                output.push_back(operands.front());
                operands.pop();
                output.push_back(operands.front());
                operands.pop();
                operators.pop();
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        {
            operators.push(c);
        }
        else if ((c > 64 && c < 91) || (c > 96 && c < 123)) // if it's a letter
        {
            operands.push(c);
        }
        else
        {
            continue;
        }
    }

    return output;
}