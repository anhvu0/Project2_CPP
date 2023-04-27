#include <iostream>
using namespace std;
#include <string>
#include "person.h"
#include "book.h"
#pragma once

class Student : public Person{
    private:
        Book *booklist[10]; // an array of maximum 10 books that have attributes of Book class (10 is the maximum number of book students can borrow)
        double late_fee; //late fee of the student
        int count;
        int numbook; //the number of books students already borrowed
    public:

        ////Default constructor to initiate a students without any book and late fee
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

        //create a function to add a book into student's booklist.
        void setBookList(int num, Book* book_){
            *booklist[num]= *book_;
        }

        int getNumBook(){
            return numbook;
        }

        //create a pointer of Book class type to get a whole array of books student borrowed. That’s why we use double pointer to return a pointer to a whole array.
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