#include "Data.h"
#include "Stack.h"

// Vector

/* References: 
https://opendsa-server.cs.vt.edu/ODSA/Books/Everything/html/ListADT.html

https://yung-web.github.io/home/courses/datastructure.html

*/
// Vector or List  data structure implementation, uses stack architecture
class Vector {
    public:
        //insert Data object at index X
        void insert(Data d, int idx){

        }

        Data remove(int idx){

        }
        void clear(){

        }
        int length(){
            int i = 0;
            
        }
        void append(Data d){
            s.stack_push(d);
        }

    private:
        Stack s;
        int max = __INT_MAX__;

};