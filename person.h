#include <iostream>
#include <string>
using namespace std;
#pragma once
#include "book.h"

class Person{
    protected:
        string first_name;
        string last_name;
        int id;
        string dob;
        string username;
        string password;

    public:
        Person(){
            first_name = "";
            last_name = "";
            username = "";
            password = "";
            dob = "";
            id = 0000000;
        }

        Person(const string & first_name_, const string & last_name_,const string & username_, const string & password_, const string & dob_, int id_){
            first_name = first_name_;
            last_name = last_name_;
            username = username_;
            password = password_;
            dob = dob_;
            id = id_;
        }


        virtual string getType() = 0;

        void setFirstName(string firstname){
            first_name = firstname;
        }

        void setLastName(string lastname){
            last_name = lastname;
        }

        void setUsername(string username_){
            username = username_;
        }

        void setPassword(string password_){
            password = password_;
        }

        void setDob(string dob_){
            dob = dob_;
        }

        void setID(int id_){
            id = id_;
        }
        
        string getFirstName(){
            return first_name;
        }

        string getLastName(){
            return last_name;
        }
        
        int getId(){
            return id;
        }

        string getDob(){
            return dob;
        }

        string getUsername(){
            return username;
        }

        string getPassword(){
            return password;
        }

        virtual int getNumBook(){};

        virtual Book** getBookList(){};

        virtual void setNumBook(int num){};

        virtual void setLateFee(double fee){};

        virtual double getLateFee(){};


        void printInfo(){
            cout<<"First Name: "<<first_name<<endl;
            cout<<"Last Name: "<<last_name<<endl;
            cout<<"Date of Birth: "<<dob<<endl;
            cout<<"Username: "<<username<<endl;
            cout<<"Password: "<<password<<endl;
            cout<<"id: "<<id<<endl;
        }

};