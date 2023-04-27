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

        // Default constructor inherited from class Person’s default constructor
        Librarian() : Person(){};

        //Destructor to delete the librarian object
        ~Librarian(){
            cout<<"Librarian deleted.";
        }

        //getType function override the class Person’s getType to return the role “Librarian”
        string getType(){
            return "Librarian";
        }
};