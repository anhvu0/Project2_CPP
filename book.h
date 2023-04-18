#include <iostream>
#include <string>
using namespace std;
#pragma once

class Book{
    private:
        int index;
        string title;
        string author;
        string publisher;
        int year;
        string borrower;
        int expired_date;
        double charge;

    public:
        Book(){
            index=0;
            title = "";
            publisher = "";
            year = 0;
            borrower = "";
            expired_date = 0;
            charge = 0;
        };
        
        void setIndex(int index_){
            index = index_;
        }

        void setTitle(string title_){
            title = title_;
        }

        void setAuthor(string author_){
            author = author_;
        }

        void setPublisher(string publisher_){
            publisher = publisher_;
        }

        void setYear(int year_){
            year = year_;
        }

        void setBorrower(string borrower_){
            borrower = borrower_;
        }

        void setExpiredDate(int expired_){
            expired_date = expired_;
        }

        void setCharge(double charge_){
            charge = charge_;
        }

        int getIndex(){
            return index;
        }

        string getBorrower(){
            return borrower;
        }

        double getCharge(){
            return charge;
        }

        int getExpired(){
            return expired_date;
        }

        string getTitle(){
            return title;
        }

        void printInfo(){
            cout<<"Index: " << index <<endl;
            cout<<"Title: "<< title << endl;
            cout<<"Author: "<< author <<endl;
            cout<<"Publisher: " << publisher <<endl;
            cout<<"Year: "<<year<<endl;
            cout<<"Borrower: "<<borrower << endl;
            cout<<"Expired Date: "<<expired_date<<endl;
            cout<<"Charge: "<<charge<<endl;
        }
};