#include <iostream>
using namespace std;
#include <string>
#include "admin.h"
#include "book.h"
#include "faculty.h"
#include "librarian.h"
#include "student.h"
#include "person.h"
#include <fstream>
#pragma once

class Library{
    private:
        Book *lib_book[1000];
        Student *student[1000];
        Faculty *faculty[1000];
        Admin *admin[1000];
        Librarian *librarian[1000];
        int count_student, count_book, count_faculty, count_admin, count_librarian;

    public:
        Library(){
            count_student = 0; 
            count_book = 0;
            count_faculty = 0;
            count_admin = 0;
            count_librarian = 0;
            for(int i=0; i<1000; i++){
                student[i] = nullptr;
                faculty[i] = nullptr;
                admin[i] = nullptr;
                librarian[i] = nullptr;
                lib_book[i] = nullptr;
            }
        }

        void loadFilePerson(){
            Student *student_ptr;
            Faculty *faculty_ptr;
            Admin *admin_ptr;
            Librarian *librarian_ptr;

            string line;
            int id;
            int index;
            ifstream infile;
            infile.open("users.txt");
            while(infile>>line){
                if (line == "admin"){
                    Admin *admin_ptr = new Admin;
                    infile>>line;
                    cout<<endl;
                    admin_ptr -> setFirstName(line);
                    infile>>line;
                    cout<<endl;
                    admin_ptr -> setLastName(line);
                    infile>>line;
                    admin_ptr -> setDob(line);
                    infile>>line;
                    admin_ptr -> setUsername(line);
                    infile>>line;
                    admin_ptr -> setPassword(line);
                    cout<<endl;
                    infile>>id;
                    admin_ptr -> setID(id);
                    admin[count_admin] = admin_ptr;
                    count_admin++;
                }

                else if(line == "student"){
                    Student *student_ptr = new Student;
                    infile>>line;
                    student_ptr -> setFirstName(line);
                    infile>>line;
                    student_ptr -> setLastName(line);
                    infile>>line;
                    student_ptr -> setDob(line);
                    infile>>line;
                    student_ptr -> setUsername(line);
                    infile>>line;
                    student_ptr -> setPassword(line);
                    infile>>id;
                    student_ptr -> setID(id);
                    infile>>id;
                    student_ptr -> setNumBook(id);
                    for(int i=0; i < student_ptr -> getNumBook(); i++){
                        infile>>index;
                        for(int j=0; j<count_book; j++){
                            if (lib_book[j]->getIndex() == index){
                                student_ptr->getBookList()[i] = lib_book[j];
                            }
                        }
                    }
                    count_student++;
                }

                else if(line == "faculty"){
                    Faculty *faculty_ptr = new Faculty;
                    infile>>line;
                    faculty_ptr -> setFirstName(line);
                    infile>>line;
                    faculty_ptr -> setLastName(line);
                    infile>>line;
                    faculty_ptr -> setDob(line);
                    infile>>line;
                    faculty_ptr -> setUsername(line);
                    infile>>line;
                    faculty_ptr -> setPassword(line);
                    infile>>id;
                    faculty_ptr -> setID(id);

                    for(int i=0; i < faculty_ptr -> getNumBook(); i++){
                        infile>>index;
                        for(int j=0; j<count_book; j++){
                            if (lib_book[j]->getIndex() == index){
                                faculty_ptr->getBookList()[i] = lib_book[j];
                            }
                        }
                    }
                    count_faculty++;
                }
                
                else if(line == "librarian"){
                    Librarian *librarian_ptr = new Librarian;
                    infile>>line;
                    librarian_ptr -> setFirstName(line);
                    infile>>line;
                    librarian_ptr -> setLastName(line);
                    infile>>line;
                    librarian_ptr -> setDob(line);
                    infile>>line;
                    librarian_ptr -> setUsername(line);
                    infile>>line;
                    librarian_ptr -> setPassword(line);
                    infile>>id;
                    librarian_ptr -> setID(id);
                    count_librarian++;
                }
            }
        }

        void loadFileBook(){
            Book *lib_book_ptr;
            string line;
            int index;
            double charge;
            ifstream infile;
            infile.open("books.txt");
            while(infile>>index){
                Book *lib_book_ptr = new Book;
                lib_book_ptr -> setIndex(index);
                getline(infile, line);
                lib_book_ptr -> setTitle(line);
                getline(infile, line);
                lib_book_ptr -> setAuthor(line);
                getline(infile, line);
                lib_book_ptr -> setPublisher(line);
                infile>>index;
                lib_book_ptr -> setYear(index);
                getline(infile, line);
                lib_book_ptr -> setBorrower(line);
                infile>>index;
                lib_book_ptr -> setExpiredDate(index);
                infile>>charge;
                lib_book_ptr -> setCharge(charge);
                lib_book[count_book] = lib_book_ptr;
                count_book++;
            }
        }

        void addStudent(){
            if (count_student == 1000){
                cout<<"Full! Cannot add more students."<<endl;
            }
            string line;
            int id;
            Student *student_ptr = new Student;
            cout<<"Enter as the following: first name, last name, date of birth, username, password, id"<<endl;
            cin>>line;
            student_ptr -> setFirstName(line);
            cin>>line;
            student_ptr -> setLastName(line);
            cin>>line;
            student_ptr -> setDob(line);
            cin>>line;
            student_ptr -> setUsername(line);
            cin>>line;
            student_ptr -> setPassword(line);
            cin>>id;
            student_ptr -> setID(id);
            student[count_student] = student_ptr;
            count_student ++;
        };

        void removeStudent(){
            if (count_student == 0){
                cout<<"No student to remove"<<endl;
            }
            int id;
            cout<<"Enter the id of the student you want to remove"<<endl;
            cin>>id;
            for(int i=0; i< count_student; i++){
                if (student[i] == nullptr)
                    continue;
                if (student[i]->getId() == id){
                    delete student[i];
                    student[i] = nullptr;
                    for(int j=i; j<count_student; j++){
                        student[j] = student[j+1];
                    }
                    count_student --;
                }
            }
        }

        void addFaculty(){
            if (count_faculty == 1000){
                cout<<"Full! Cannot add more faculty."<<endl;
            }
            string line;
            int id;
            Faculty *faculty_ptr = new Faculty;
            cout<<"Enter as the following: first name, last name, date of birth, username, password, id"<<endl;
            cin>>line;
            faculty_ptr -> setFirstName(line);
            cin>>line;
            faculty_ptr -> setLastName(line);
            cin>>line;
            faculty_ptr -> setDob(line);
            cin>>line;
            faculty_ptr -> setUsername(line);
            cin>>line;
            faculty_ptr -> setPassword(line);
            cin>>id;
            faculty_ptr -> setID(id);
            faculty[count_faculty] = faculty_ptr;
            count_faculty ++;
        }

        void removeFaculty(){
            if (count_faculty == 0){
                cout<<"No faculty to remove"<<endl;
            }
            int id;
            cout<<"Enter the id of the student you want to remove"<<endl;
            cin>>id;
            for(int i=0; i< count_faculty; i++){
                if (faculty[i] == nullptr)
                    continue;
                if (faculty[i]->getId() == id){
                    delete faculty[i];
                    faculty[i] = nullptr;
                    for(int j=i; j<count_faculty; j++){
                        faculty[j] = faculty[j+1];
                    }
                    count_faculty --;
                }
            }
        }

        void addLibrarian(){
            if (count_librarian == 1000){
                cout<<"Full! Cannot add more librarians."<<endl;
            }
            string line;
            int id;
            Librarian *librarian_ptr = new Librarian;
            cout<<"Enter as the following: first name, last name, date of birth, username, password, id"<<endl;
            cin>>line;
            librarian_ptr -> setFirstName(line);
            cin>>line;
            librarian_ptr -> setLastName(line);
            cin>>line;
            librarian_ptr -> setDob(line);
            cin>>line;
            librarian_ptr -> setUsername(line);
            cin>>line;
            librarian_ptr -> setPassword(line);
            cin>>id;
            librarian_ptr -> setID(id);
            librarian[count_librarian] = librarian_ptr;
            count_librarian ++;
        }

        void removeLibrarian(){
            if (count_librarian == 0){
                cout<<"No librarian to remove"<<endl;
            }
            int id;
            cout<<"Enter the id of the student you want to remove"<<endl;
            cin>>id;
            for(int i=0; i< count_librarian; i++){
                if (librarian[i] == nullptr)
                    continue;
                if (librarian[i]->getId() == id){
                    delete librarian[i];
                    librarian[i] = nullptr;
                    for(int j=i; j<count_librarian; j++){
                        librarian[j] = librarian[j+1];
                    }
                    count_librarian --;
                }
            }
        }

        void addBook(){
            if (count_book == 1000){
                cout<<"Full! Cannot add more books."<<endl;
            }
            string line;
            int index;
            double charge;
            Book *book_ptr = new Book;
            cout<<"Enter as the following: index, title, author, publisher, year, borrower, expired_date, charge"<<endl;
            cin>>index;
            book_ptr -> setIndex(index);
            cin>>line;
            book_ptr -> setTitle(line);
            cin>>line;
            book_ptr -> setAuthor(line);
            cin>>line;
            book_ptr -> setPublisher(line);
            cin>>index;
            book_ptr -> setYear(index);
            cin>>line;
            book_ptr -> setBorrower(line);
            cin>>index;
            book_ptr -> setExpiredDate(index);
            cin>>charge;
            book_ptr -> setCharge(charge);
            lib_book[count_book] = book_ptr;
            count_book ++;
        }

        void removeBook(){
            if (count_book == 0){
                cout<<"No books to remove"<<endl;
            }
            int index;
            cout<<"Enter the index of the book you want to remove"<<endl;
            cin>>index;
            for(int i=0; i< count_book; i++){
                if (lib_book[i] == nullptr)
                    continue;
                if (lib_book[i]->getIndex() == index){
                    delete lib_book[i];
                    lib_book[i] = nullptr;
                    for(int j=i; j<count_book; j++){
                        lib_book[j] = lib_book[j+1];
                    }
                    count_book --;
                }
            }
        }

        void viewBorrowedBookStudent(){
            for(int i=0; i < count_student; i++){
                if (student[i] -> getLateFee() > 0){
                    student[i] -> printInfo();
                    student[i] -> printBorrowedBook();
                    cout<<endl;
                }
            }
        }

         void viewBorrowedBookFaculty(){
            for(int i=0; i < count_faculty; i++){
                if (faculty[i] -> getLateFee() > 0){
                    faculty[i] -> printInfo();
                    faculty[i] -> printBorrowedBook();
                    cout<<endl;
                }
            }
        }

        void viewAllLibrarian(){
            for(int i=0; i<count_librarian; i++){
                librarian[i] -> printInfo();
                cout<<endl;
            }
        }

        void viewAllLibraryBook(){
            for(int i=0; i < count_book; i++){
                lib_book[count_book] -> printInfo();
                cout<<endl;
            }
        }
};
