#include <iostream>
#include <string>
using namespace std;
#pragma once
#include "book.h"

class Person{
    protected:
        string first_name; //Store first name
        string last_name; //Store last name
        int id; //Store the person’s id
        string dob; //Store the date of birth
        string username; //Store the username
        string password; //Store the password

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

        //Pure virtual function to get the role of each person
        virtual string getType() = 0;

        //Set the first name of the person
        void setFirstName(string firstname){
            first_name = firstname;
        }

        // Set the last name of the person
        void setLastName(string lastname){
            last_name = lastname;
        }

        // Set the username of the person
        void setUsername(string username_){
            username = username_;
        }

        // Set the password of the person
        void setPassword(string password_){
            password = password_;
        }

        //Set the date of birth
        void setDob(string dob_){
            dob = dob_;
        }

        //Set ID
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

        //Virtual function so other role can overload to get the number of books they already borrowed
        virtual int getNumBook(){};

        //Virtual function to get the list of the book each person borrow
        virtual Book** getBookList(){};

        //Virtual function to set the number of book each person borrow
        virtual void setNumBook(int num){};

        //Virtual function to set each person’s late fee if they have one
        virtual void setLateFee(double fee){};

        //Virtual function to return each person’s late fee if they have one
        virtual double getLateFee(){};

        //Print basics information of a person including first, last name, date of birth, username, password, id
        void printInfo(){
            cout<<"First Name: "<<first_name<<endl;
            cout<<"Last Name: "<<last_name<<endl;
            cout<<"Date of Birth: "<<dob<<endl;
            cout<<"Username: "<<username<<endl;
            cout<<"Password: "<<password<<endl;
            cout<<"id: "<<id<<endl;
        }

};