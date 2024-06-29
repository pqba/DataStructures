#include "../../include/Structures/Data.h"
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>

Data::Data() : description{0,0,""}
{

}
Data::Data(int id, float c, std::string n) : description{ id, c, n } {
    
}
Data::~Data(){
    description.constant = 0.0;
    description.ID_NUMBER = 0;
    description.name = "";
}

// Checks if the constant, id, and name of Data objects are equal.
bool Data::operator==(const Data& other){
    return (abs(this->description.constant - other.description.constant) < TOLERANCE) &&
    this->description.ID_NUMBER == other.description.ID_NUMBER &&
    this->description.name == other.description.name;
}
// Data objects are larger if int ID is larger, float constant is larger, or name length is longer
bool Data::operator>(const Data& other){
    if(this->operator==(other)){
        return false;
    }
    return (this->getID() > other.getID()) ||
         (this->getID() == other.getID() && this->getConstant() > other.getConstant()) ||
         (this->getID() == other.getID() && this->getConstant() == other.getConstant() &&
          this->getName() > other.getName());
}
// Data objects are smaller if int ID is smaller, float constant is smaller, or name length is shorter
bool Data::operator<(const Data& other){
    if(this->operator==(other)){
        return false;
    }
    return !(this->operator>(other));
}
// Access entire relevant struct
internal Data::getData() const
{
    return this->description;
}

// Access ID of Data object.
int Data::getID() const
{
    return this->description.ID_NUMBER;
}
// Access constant of Data object.
float Data::getConstant() const
{
    return this->description.constant;
}
// Access name of Data object.
std::string Data::getName() const
{
    std::string res(description.name);
    return res;
}
// Mutate internals of Data object.
void Data::setData(internal i){
    this->description = i;
}
// // Mutate ID of Data object.
void Data::setID(int n){
    this->description.ID_NUMBER = n;
}
// Mutate constant of Data object.
void Data::setConstant(float ct) {
  this->description.constant = ct;
}
// Mutate name of Data object.
void  Data::setName(std::string nm){
    this->description.name = nm;
}

// Return ch array of id, constant, and name
const std::string Data::print() 
{
    std::string idStr = std::to_string(getID()) + "-";
    std::string constantStr =  std::to_string(getConstant()) + "-";
    std::string nameStr(getName());

    return idStr + constantStr + nameStr;
}
