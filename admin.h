#include <iostream>
using namespace std;
#include <string>
#include "person.h"
#include "librarian.h"
#pragma once

class Admin : public Person{
    // private:
    //     Librarian* librarian[10];
    //     int count = 0;   
    public:
        // Admin(){
        //     for(int i=0; i<10; i++){
        //         librarian[i] == nullptr;
        //     }
        // }
        // Admin(string name_, string username_, string password_, string dob_, int id_){
        //     name = name_;
        //     username = username_;
        //     password = password_;
        //     dob = dob_;
        //     id = id_;
        // }

        Admin() : Person(){};
        string getType() override{
            return "Admin";
        }

        // bool addLibrarian(const Librarian & id_){
        //     if (count == 10){
        //         return false;
        //     }
        //     librarian[count] = new Librarian ((Librarian &) id_);
        //     count ++;
        //     return true;
        // }

        // bool removeLibrarian(const int & id_){
        //     if (count == 0){
        //         return false;
        //     }
        //     for(int i=0; i< count; i++){
        //         if (librarian[i] == nullptr)
        //             continue;
        //         if (librarian[i]->getId() == id_){
        //             delete librarian[i];
        //             librarian[i] = nullptr;
        //             for(int j=i; j<count; j++){
        //                 librarian[j] = librarian[j+1];
        //             }
        //             count --;
        //             return true;
        //         }
        //     }
        // }


};