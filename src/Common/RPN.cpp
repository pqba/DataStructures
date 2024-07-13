/* References:
https://en.wikipedia.org/wiki/Reverse_Polish_notation
https://www-stone.ch.cam.ac.uk/documentation/rrf/rpn.html

Algorithm is to place numbers on stack until operator encountered, then apply operator. Ultimately should be algebraically reducible.
*/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "../../include/Structures/Data.h"
#include "../../include/Structures/Stack.h"

void doRPN();

class RPN {
   private:
    Stack notator;
    int result;
    std::string inputEquation;

   public:
    // Member initializer list
    RPN(std::string s) : notator(makeNotator()) {
        parseEq(s);
        notator.stack_name_output();
        result = atoi(notator.stack_peek().getName().c_str());
        inputEquation = s;
    }
    ~RPN() {
    }

    Stack makeNotator() {
        return Stack(1);
    }
    // Return integer math evaluation using two numbers and operator. Throws error for unrecognized operators.
    int operate(char op, int a, int b) {
        if (op == '+') {
            return a + b;
        } else if (op == '-') {
            return a - b;
        } else if (op == '*') {
            return a * b;
        } else if (op == '/') {
            return a / b;
        } else {
            throw std::invalid_argument("Not a valid operator");
        }
    }
    bool isOp(std::string s) {
        return (s == "+" || s == "-" || s == "*" || s == "/");
    }
    // Outputs algebraic interpretation of equation, converts postfix to infix
    std::string describeAlgebraic(std::string eq) {
        Stack algebraic(1);
        std::stringstream ss(eq);
        while (ss.good()) {
            std::string expr;
            getline(ss, expr, ' ');
            if (isANumber(expr)) {
                algebraic.stack_push(Data(1, 1, expr));
            } else if (isOp(expr)) {
                std::string first = algebraic.stack_peek().getName();
                algebraic.stack_pop();
                std::string second = algebraic.stack_peek().getName();
                algebraic.stack_pop();
                std::string combined = "(" + second + " " + expr + " " + first + ")";
                algebraic.stack_push(Data(1, 1, combined));
            } else {
                throw std::invalid_argument("Cannot parse to algebraic, incorrect RPN notation.");
            }
        }
        return algebraic.stack_peek().getName();
    }
    /*
    Parses input, initializes notator Stack
    */
    void parseEq(std::string eq) {
        std::stringstream ss(eq);
        int basicId = 0;
        while (ss.good()) {
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
    void translateReversePolish() {
        Data component = notator.stack_peek();
        std::string value = component.getName();
        //  std::cout << notator.stack_name_output() << std::endl;
        if (!isANumber(value)) {
            // eval operator
            std::string op_represent = notator.stack_pop().getName();
            char op = evalOperator(op_represent);
            // Eventually use own Vector implementation
            std::vector<int> orands;
            // only twice, binary operators.
            for (int i = 0; i < 2; i++) {
                if (notator.isEmpty()) {
                    throw std::invalid_argument("Invalid RPN. Empty.");
                }
                std::string N = notator.stack_pop().getName();
                if (isANumber(N)) {
                    int num = atoi(N.c_str());
                    orands.insert(orands.begin(), num);
                    //   std::cout << num << "\t";
                } else {
                    std::cout << "\nERROR!" << std::endl;
                    throw std::invalid_argument("Invalid RPN. Not a number.");
                }
            }
            int total;
            // Apply operator to top 2 in list (only binary operations supported)
            for (int i = 0; i < (int)orands.size() - 1; i++) {
                int calc = operate(op, orands[i], orands[i + 1]);
                // printf("%d %c %d = %d ", orands[i], op, orands[i + 1], calc);
                orands[i + 1] = calc;
                total = orands[i + 1];
            }
            notator.stack_push(Data(0, 0, std::to_string(total)));
        }
    }

    // Returns the char version of s operator, if not recognized throws error.
    char evalOperator(std::string s) {
        if (s.length() != 1) {
            throw std::invalid_argument("Not a recognized operator.");
        }

        if (s == "+") {
            return '+';
        } else if (s == "-") {
            return '-';
        } else if (s == "*") {
            return '*';
        } else if (s == "/") {
            return '/';
        } else {
            throw std::invalid_argument("Not a recognized 1 char operator.");
        }
    }

    bool isANumber(std::string s) {
        bool isNumerical = true;
        for (int i = 0; i < (int)s.length(); i++) {
            if (!isdigit(s[i])) {
                isNumerical = false;
                break;
            }
        }
        return isNumerical;
    }
    int getResult() {
        return result;
    }
    std::string getInputEquation() {
        return inputEquation;
    }
};
