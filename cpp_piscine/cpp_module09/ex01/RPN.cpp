#include "RPN.hpp"

RPN::RPN()
{
    
}

RPN::RPN(RPN &target)
{
    (void)target;
}

RPN& RPN::operator=(RPN &target)
{
    (void)target;
    return (*this);
}

RPN::~RPN()
{
    
}

void RPN::calculation(std::string input)
{
    std::stack<int> number;
    for (long unsigned int i = 0; i < input.length(); i++)
    {
        if (input.at(i) == '+')
        {
            if (number.size() < 2)
            {
                std::cout <<"Syntaxe error "<< std::endl;
                return ;
            }
            int a = number.top();
            number.pop(); 
            int b = number.top();
            number.pop();
            number.push(a + b);
        }
        else if (input.at(i) == '-')
        {
            if (number.size() < 2)
            {
                std::cout <<"Syntaxe error  "<< std::endl;
                return ;
            }
            int a = number.top();
            number.pop(); 
            int b = number.top();
            number.pop();
            number.push(b - a);
        }
        else if (input.at(i) == '/')
        {
            if (number.size() < 2)
            {
                std::cout <<"Syntaxe error  "<< std::endl;
                return ;
            }
            int a = number.top();
            number.pop(); 
            int b = number.top();
            number.pop();
            if (b == 0 || a == 0)
            {
                std::cout << "Error division with 0 is impossible" << std::endl;
                return ;
            }
            number.push(b / a);
        }
        else if(input.at(i) == '*')
        {
            if (number.size() < 2)
            {
                std::cout <<"Syntaxe error "<< std::endl;
                return ;
            }
            int a = number.top();
            number.pop(); 
            int b = number.top();
            number.pop();
            number.push(a * b);
        }
        else if (input.at(i) >= '0' && input.at(i) <= '9')
            number.push(static_cast<int>(input.at(i)) - 48);
        else if (input.at(i) != ' ')
        {
            std::cout << "Error forbidden caracter" << std::endl;
            return ;
        }
    }
    if (number.size() != 1)
        std::cout << "Wrong number of argument" << std::endl;
    else
    {
        int result = number.top();
        std::cout << "Result = " << result << std::endl;
        number.pop();
    }
}
