#include "Data.h"

Data::Data(){
    setData();
}
Data::Data(unsigned int i, float f, char * N){
    setData(i,f,N);
}

void Data::setData(){
    description.ID_NUMBER = 0;
    description.constant = 0;
    description.name = nullptr;
}

void Data::setData(unsigned int i, float f, char * N){
    description.ID_NUMBER = i;
    description.constant = f;
    description.name = N;
}
// Access entire relevant struct
internal Data::getData(){
    return description;
}

// Access members of struct
unsigned int Data::getID(){
    return description.ID_NUMBER;
}
float Data::getConstant(){
    return description.constant;
}
const char * Data::getName(){
    return description.name;
}
