/* References: https://en.wikipedia.org/wiki/Reverse_Polish_notation
https://www-stone.ch.cam.ac.uk/documentation/rrf/rpn.html

Algorithm is to place numbers on stack until operator encountered, then apply operator. Ultimately should be algebraically reducible.
*/
#include <iostream>
#include <stdexcept>
#include "../Stack.h"
#include "../Data.h"
#include <string>
#include <sstream>
#include <vector>

class RPN {
    private:
        Stack  notator;
        int result;
    public:
    // Member initializer list
        RPN(std::string s): notator(makeNotator()){
            parseEq(s);
            notator.stack_print();
        }
        ~RPN(){
        }

        Stack makeNotator(){
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
        void describeAlgebraic(std::string eq) {
        }
        /*
        Parses input, initializes notator Stack 
        */
        void parseEq(std::string eq){
            std::stringstream ss (eq);
            while(ss.good()){
                // problem may lie here...
                // https://stackoverflow.com/questions/15449544/stdstring-c-str-returning-a-weird-characters
                std::string expr;
                getline(ss,expr,' ');
                Data d(0,0,expr.c_str());
printf("expr: %s (length: %zu)\t", expr.c_str(), expr.length(), d.getName());
                notator.stack_push(d);
               translateReversePolish();
            }  
        }
        /*
        From current notator state, checks if there is an operator to be evaulated. 
        If there is, it will pop off all elements from stack to evalaute, then push the result.
        */ 
        void translateReversePolish(){
            Data component = notator.stack_peek();
            std::string value = component.getName();
            std::cout << "Notator head: " << notator.size() << " Component:" << value << std::endl;
            if(!isANumber(value)){
                //eval operator
                std::string op_represent = notator.stack_pop().getName();
                char op = evalOperator(op_represent);
                // Eventually use own Vector implementation
                std::vector<int> orands;
                while(!notator.isEmpty()){
                    std::cout << "head: " << notator.size() << std::endl;
                    std::string N = notator.stack_pop().getName();
                    if(isANumber(N)){
                        orands.push_back(atoi(N.c_str()));
                    }
                }
                for(int i : orands){
                    std::cout << i << "\t";
                }
                std::cout << std::endl;

                int total; //Continously apply operator through operands list.
                for(int i = 0; i < orands.size() -1; i++){
                    int calc =  operate(op,orands[i],orands[i+1]);
                    orands[i+1] = calc;
                    total = orands[i+1]; 
                }
                printf("Total:%d Op:%s \n",total,op);
                notator.stack_push(Data(0,0,std::to_string(total).c_str()));
            }
            
        }
        // Returns the char version of s operator, if not recognized throws error.
        char evalOperator(std::string s){
            if(s.length() != 1){
                throw std::invalid_argument("Not a recognized operator.");
            }
    
            if(s == "+"){
                    return '+';
            }
            else if(s == "-"){
                    return '-';
            }
            else if (s == "*"){
                return '*';
            }
            else if( s == "/"){
                return '/';
            }
            else {
                throw std::invalid_argument("Not a recognized 1 char operator.");
                }

        }

        bool isANumber(std::string s){
            bool isNumerical = true;
            for(int i = 0; i < s.length(); i++){
                if(!isdigit(s[i])){
                    isNumerical = false;
                }
            }
            std::cout << "s: " << s << " result: " << isNumerical << std::endl;
            return isNumerical;
        }
        int getResult(){
            return result;
        }

};

int main()
{

    // Test stack
    RPN b("3 5 + 7 2 - *");
    std::cout << "Initialized b. B is: " << b.getResult() << " " << std::endl;
    return 0;
}