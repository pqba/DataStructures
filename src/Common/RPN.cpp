/* References:
https://en.wikipedia.org/wiki/Reverse_Polish_notation
https://www-stone.ch.cam.ac.uk/documentation/rrf/rpn.html

Algorithm is to place numbers on stack until operator encountered, then apply operator. Ultimately should be algebraically reducible.
*/

#include <iostream>
#include <stdexcept>
#include "../../include/Structures/Stack.h"
#include "../../include/Structures/Data.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

void doRPN();

class RPN
{
private:
    Stack notator;
    int result;

public:
    // Member initializer list
    RPN(std::string s) : notator(makeNotator())
    {
        parseEq(s);
        notator.stack_name_output();
        result = atoi(notator.stack_peek().getName().c_str());
    }
    ~RPN()
    {
    }

    Stack makeNotator()
    {
        return Stack(1);
    }
    // Return integer math evaluation using two numbers and operator. Throws error for unrecognized operators.
    int operate(char op, int a, int b)
    {
        if (op == '+')
        {
            return a + b;
        }
        else if (op == '-')
        {
            return a - b;
        }
        else if (op == '*')
        {
            return a * b;
        }
        else if (op == '/')
        {
            return a / b;
        }
        else
        {
            throw std::invalid_argument("Not a valid operator");
        }
    }
    // To implement. Outputs algebraic interpretation of eq.
    void describeAlgebraic(std::string eq)
    {
        for(int i = 0; i < (int)eq.length();i++){
            std::cout << "unfinished" << std::endl;
            }
    }
    /*
    Parses input, initializes notator Stack
    */
    void parseEq(std::string eq)
    {
        std::stringstream ss(eq);
        int basicId = 0;
        while (ss.good())
        {
            std::string expr;
            getline(ss, expr, ' ');
            Data d(basicId, 1, expr);
            notator.stack_push(d);
            translateReversePolish();
            basicId++;
        }
    }
    /*
    From current notator state, checks if there is an operator to be evaulated.
    If there is, it will pop off all elements from stack to evalaute, then pushes the result onto notator.
    */
    void translateReversePolish()
    {
        Data component = notator.stack_peek();
        std::string value = component.getName();
        //  std::cout << notator.stack_name_output() << std::endl;
        if (!isANumber(value))
        {
            std::cout << "OPERATOR: " << value << "\t";
            // eval operator
            std::string op_represent = notator.stack_pop().getName();
            char op = evalOperator(op_represent);
            // Eventually use own Vector implementation
            std::vector<int> orands;
            // only twice, binary operators.
            for (int i = 0; i < 2; i++)
            {
                if (notator.isEmpty())
                {
                    throw std::invalid_argument("Invalid RPN. Empty.");
                }
                std::string N = notator.stack_pop().getName();
                if (isANumber(N))
                {
                    int num = atoi(N.c_str());
                    orands.insert(orands.begin(), num);
                    std::cout << num << "\t";
                }
                else
                {
                    std::cout << "\nERROR!" << std::endl;
                    throw std::invalid_argument("Invalid RPN. Not a number.");
                }
            }
            int total;
            // Apply operator to top 2 in list (only binary operations supported)
            for (int i = 0; i < (int)orands.size() - 1; i++)
            {
                int calc = operate(op, orands[i], orands[i + 1]);
                printf("%d %c %d = %d ", orands[i], op, orands[i + 1], calc);
                orands[i + 1] = calc;
                total = orands[i + 1];
            }
            notator.stack_push(Data(0, 0, std::to_string(total)));
            std::cout << std::endl;
        }
    }

    // Returns the char version of s operator, if not recognized throws error.
    char evalOperator(std::string s)
    {
        if (s.length() != 1)
        {
            throw std::invalid_argument("Not a recognized operator.");
        }

        if (s == "+")
        {
            return '+';
        }
        else if (s == "-")
        {
            return '-';
        }
        else if (s == "*")
        {
            return '*';
        }
        else if (s == "/")
        {
            return '/';
        }
        else
        {
            throw std::invalid_argument("Not a recognized 1 char operator.");
        }
    }

    bool isANumber(std::string s)
    {
        bool isNumerical = true;
        for (int i = 0; i < (int)s.length(); i++)
        {
            if (!isdigit(s[i]))
            {
                isNumerical = false;
            }
        }
        return isNumerical;
    }
    int getResult()
    {
        return result;
    }
};
