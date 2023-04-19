#include <iostream>
using namespace std;
#include <string>
#include "person.h"
#include "book.h"
#pragma once

class Librarian : public Person{
    private:
        int count;
    public:
        Librarian() : Person(){};

        ~Librarian(){
            cout<<"Librarian deleted.";
        }

        string getType(){
            return "Librarian";
        }
};