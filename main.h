#include <iostream>
using namespace std;

//задаем неизменяемые значения размеру поля и количеству лис.
const int field_size = 10;
const int count_fox = 8;

class Hunter_foxes {
private:
    int field[field_size][field_size];
    int foxesFound;
public:
    Hunter_foxes();
    void play();
};
