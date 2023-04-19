#include <iostream>
using namespace std;
#include <string>
#include "person.h"
#include "book.h"
#pragma once

class Student : public Person{
    private:
        Book *booklist[10];
        double late_fee;
        int count;
        int numbook;
    public:
        Student(){
            for (int i=0; i < 10; i++){
                booklist[i]=nullptr;
            late_fee = 0;
            }
        }
        //Adding destructor
        ~Student(){
            cout<<"User deleted.";
        }

        //Get the type of user for later use
        string getType(){
            return "Student";
        }

        void setNumBook(int num){
            numbook = num;
        }

        void setLateFee(double fee_){
            late_fee += fee_;
        }

        int getNumBook(){
            return numbook;
        }

        Book** getBookList(){
            return booklist;
        }

        double getLateFee(){
            return late_fee;
        }

        void printBorrowedBook(){
            for(int i=0; i<numbook; i++){
                cout<<booklist[i]->getTitle()<<endl;
            }
        }

        //Add a function to add a book into the borrowing book array.
        // bool borrowBook(const Book & book_){
        //     if (count == 10){
        //         return false;
        //     }
        //     booklist[count] = new Book ((Book &) book_);
        //     count ++;
        //     return true;
        // }

        // //Create a function to remove a book from the borrowing array when the book is returned
        // bool returnBook(const int & index_, int return_date){
        //     if (count == 0){
        //         return false;
        //     }
        //     for(int i=0; i< count; i++){
        //         if (booklist[i] == nullptr)
        //             continue;
        //         if (booklist[i]->getIndex() == index_){
        //             if(booklist[i]->getExpired() - return_date < 0){
        //                 late_fee += 5;
        //             }
        //             delete booklist[i];
        //             booklist[i] = nullptr;

        //             //Move the position of the next item to the position of the current item to avoid having nullptr in the array
        //             for(int j=i; j<count; j++){
        //                 booklist[j] = booklist[j+1];
        //             }
        //             count --;
        //             return true;
        //         }
        //     }
        // }
};