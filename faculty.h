#include <iostream>
using namespace std;
#include <string>
#include "person.h"
#include "book.h"
#pragma once

class Faculty : public Person{
    private:
        Book *booklist[15];
        double late_fee;
        int numbook;
    public:
        Faculty() : Person(){
            for (int i=0; i < 15; i++){
                booklist[i]=nullptr;
            }
        }
        
        ~Faculty(){
            cout<<"User deleted.";
        }

        string getType(){
            return "Faculty";
        }

        void setLateFee(double fee_){
            late_fee += fee_;
        }

        void setNumBook(int num){
            numbook = num;
        }

        void setBookList(int num, Book* book_){
            *booklist[num]= *book_;
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

        string getBookTitle(int num){
            string arr = booklist[num]->getTitle();
            return arr;
        }

        // bool borrowBook(const Book & book_){
        //     if (count == 15){
        //         return false;
        //     }
        //     booklist[count] = new Book ((Book &) book_);
        //     count ++;
        //     return true;
        // }

        // bool returnBook(const int & index_){
        //     if (count == 0){
        //         return false;
        //     }
        //     for(int i=0; i< count; i++){
        //         if (booklist[i] == nullptr)
        //             continue;
        //         if (booklist[i]->getIndex() == index_){
        //             delete booklist[i];
        //             booklist[i] = nullptr;
        //             for(int j=i; j<count; j++){
        //                 booklist[j] = booklist[j+1];
        //             }
        //             count --;
        //             return true;
        //         }
        //     }
        // }   
};