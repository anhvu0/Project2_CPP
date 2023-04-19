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
        Person *user_ptr;
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
            if (!infile.is_open()){
                cout<<"Cannot open file user.";
            }
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
                    infile.ignore();
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
                        getline(infile, line);
                        for(int j=0; j<count_book; j++){
                            if (lib_book[j]->getIndex() == index){
                                student_ptr->getBookList()[i] = lib_book[j];
                            }
                        }
                        infile.ignore();
                    }
                    student[count_student]=student_ptr;
                    count_student++;
                    infile.ignore();
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
                    faculty[count_faculty]=faculty_ptr;
                    count_faculty++;
                    infile.ignore();
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
                    librarian[count_librarian]= librarian_ptr;
                    count_librarian++;
                    infile.ignore();
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
             if (!infile.is_open()){
                cout<<"Cannot open file book.";
            }
            while(infile>>index){
                infile.ignore();
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
                infile>>index;
                lib_book_ptr -> setBorrowerId(index);
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
        }

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
            cout<<"Enter the id of the librarian you want to remove"<<endl;
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
            cin>>index;
            book_ptr -> setBorrowerId(index);
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
                lib_book[i] -> printInfo();
                cout<<endl;
            }
        }


        void getLateFee(int borrower_id_){
            string current_date;
            cout<<"Enter the current date. MMDDYYYY without symbol."<<endl;
            cin>>current_date;
            for(int i=0; i<1000; i++){
                if(student[i]->getId() == borrower_id_){
                    student[i]->setLateFee(5);
                }
                else if (faculty[i]->getId() == borrower_id_){
                    faculty[i]->setLateFee(5);
                }
            }

        }

        void viewBorrower(){
            int index;
            int borrower_id;
            cout<<"Enter the index of the book"<<endl;
            cin>>index;
            for(int i=0; i<count_book; i++){
                if(lib_book[i]->getIndex() == index){
                    borrower_id = lib_book[i]->getBorrowerId();
                    if(borrower_id != 0){
                        getLateFee(borrower_id);
                    }
                }
            }
        }

        void login(){
            string role;
            string username;
            string password;
            cout<<"Enter your role: "<<endl;
            while(cin>>role){
                cout<<"Enter username: "<<endl;
                cin>>username;
                cout<<"Enter password: "<<endl;
                cin>>password;
                if(role == "Admin"){
                    for(int i=0; i<count_admin; i++){
                        if (admin[i]->getUsername() == username && admin[i]->getPassword() == password){
                            cout<<"Admin login successfully!"<<endl;
                            user_ptr=admin[i];
                            break;
                        }
                        else{
                        cout<<"Wrong username or password. Enter role, username, and password again."<<endl;
                        cout<<"Enter your role: "<<endl;
                        }
                    }
                }
                else if(role == "Librarian"){
                    for(int i=0; i<count_librarian; i++){
                        if (librarian[i]->getUsername() == username && librarian[i]->getPassword() == password){
                            cout<<"Librarian login successfully!"<<endl;
                            user_ptr = librarian[i];
                            break;
                        }   
                        else{
                            cout<<"Wrong username or password. Enter role, username, and password again."<<endl;
                            cout<<"Enter your role: "<<endl;

                        }
                    }
                }
                else if(role == "Faculty"){
                    for(int i=0; i<count_faculty; i++){
                        if (faculty[i]->getUsername() == username && faculty[i]->getPassword() == password){
                            cout<<"Faculty login successfully!"<<endl;
                            user_ptr = faculty[i];
                            break;
                        }
                        else{
                            cout<<"Wrong username or password. Enter role, username, and password again."<<endl;
                            cout<<"Enter your role: "<<endl;

                        }
                    }
                }
                else if(role == "Student"){
                    for(int i=0; i<count_librarian; i++){
                        if (student[i]->getUsername() == username && student[i]->getPassword() == password){
                            cout<<"Student login successfully!"<<endl;
                            user_ptr = student[i];
                            break;
                        }
                        else{
                            cout<<"Wrong username or password. Enter role, username, and password again."<<endl;
                            cout<<"Enter your role: "<<endl;

                        }
                    }
                }
            }
        }

        void interaction(){
            int choice;
            if(user_ptr->getType() == "Admin"){
                cout<<"Entering number for each options"<<endl;
                cout<<"1: Add librarian"<<endl;
                cout<<"2: Remove librarian"<<endl;
                cout<<"0: Exit"<<endl;
                while(cin>>choice){
                    if(choice == 1){
                        addLibrarian();
                    }
                    else if (choice == 2){
                        removeLibrarian();
                    }
                    else if (choice == 0){
                        break;
                    }
                }
            }

            else if(user_ptr->getType() == "Librarian"){
                cout<<"Entering number for each options"<<endl;
                cout<<"1: Add new student"<<endl;
                cout<<"2: Delete student"<<endl;
                cout<<"3: Add new faculty"<<endl;
                cout<<"4: Delete faculty"<<endl;
                cout<<"5: Add new book to the library"<<endl;
                cout<<"6: Remove a book from the library"<<endl;
                cout<<"7: Check id of the borrower of a specific book"<<endl;
                cout<<"8: Check return due date of a specific book"<<endl;
                cout<<"0: Exit."<<endl;
                while (cin >> choice){
                    if (choice == 1){
                        addStudent();
                    }
                    else if(choice == 2){
                        removeStudent();
                    }
                    else if(choice == 3){
                        addFaculty();
                    }
                    else if (choice == 4){
                        removeFaculty();
                    }
                    else if (choice == 5){
                        addBook();
                    }
                    else if (choice == 6){
                        removeBook();
                    }
                    else if (choice == 7){
                        viewBorrower();
                    }
                    else if (choice == 8){
                        int book_index;
                        cout<<"Enter index of the book you want to check: "<<endl;
                        cin>>book_index;
                        for(int i=0; i<count_book; i++){
                            cout<<lib_book[i]->getExpired()<<endl;
                        }
                    }
                    else if (choice == 0){
                        break;
                    }
                }
            }

            else if(user_ptr->getType() == "Student" || user_ptr->getType() == "Faculty"){
                cout<<"Entering number for each options"<<endl;
                cout<<"1: Check all available book"<<endl;
                cout<<"2: Check availability of a specific book"<<endl;
                cout<<"3: Borrow a book"<<endl;
                cout<<"4: Return a book"<<endl;
                cout<<"0: Exit."<<endl;
                while (cin >> choice){
                    if (choice == 1){
                        for(int i=0; i<count_book; i++){
                            cout<<lib_book[i]->getTitle()<<" | index: "<<lib_book[i]->getIndex()<<endl;
                        };
                    }
                    else if(choice == 2){
                        cout<<"Enter the name of the book"<<endl;
                        string name;
                        int count_available=0;
                        int array[1000];
                        cin>>name;
                        for(int i=0; i<count_book; i++){
                            if(lib_book[i]->getTitle() == name && lib_book[i]->getBorrowerId() == 0){
                                array[i] = lib_book[i]->getIndex();
                                count_available++;
                            }
                        }
                        cout<<"There are "<<count_available<<" copies available and there index numbers are: "<<endl;
                        for(int i=0; i<count_available;i++){
                            cout<<array[i]<<endl;
                        }
                    }
                    else if(choice == 3){
                        int index_num;
                        Book* book_ptr;
                        if(user_ptr -> getType() == "Student"){
                            if(user_ptr->getNumBook() == 10){
                                cout<<"Cannot borrow more book";
                            }
                            else if (user_ptr -> getNumBook() < 10){
                                cout<<"Enter the index of the book you want to borrow: "<<endl;
                                cin>>index_num;
                                for(int i=0; i<count_book; i++){
                                    if (lib_book[i]->getIndex() == index_num){
                                        book_ptr = lib_book[i];
                                    }
                                }
                                user_ptr -> getBookList()[user_ptr->getNumBook()] = book_ptr;
                                for(int i=0; i<count_book; i++){
                                    if (lib_book[i] == book_ptr){
                                        for(int j=i; j<count_book-1; j++){
                                            delete lib_book[j];
                                            lib_book[j]=nullptr;
                                            lib_book[j] = lib_book[j+1];
                                        }
                                    }
                                }
                                count_book --;
                            }
                        }
                        else if(user_ptr -> getType() == "Faculty"){
                            if(user_ptr->getNumBook() == 15){
                                cout<<"Cannot borrow more book";
                            }
                            else if (user_ptr -> getNumBook() < 15){
                                cout<<"Enter the index of the book you want to borrow: "<<endl;
                                cin>>index_num;
                                for(int i=0; i<count_book; i++){
                                    if (lib_book[i]->getIndex() == index_num){
                                        book_ptr = lib_book[i];
                                    }
                                }
                                user_ptr -> getBookList()[user_ptr->getNumBook()] = book_ptr;
                                for(int i=0; i<count_book; i++){
                                    if (lib_book[i] == book_ptr){
                                        for(int j=i; j<count_book-1; j++){
                                            delete lib_book[j];
                                            lib_book[j]=nullptr;
                                            lib_book[j] = lib_book[j+1];
                                        }
                                    }
                                }
                                count_book--;
                            }
                        }
                    }
                    else if (choice == 4){
                        int index_num;
                        int current_date;
                            if(user_ptr->getNumBook() == 0){
                                cout<<"You have no books to return";
                            }
                            else if (user_ptr -> getNumBook() > 0){
                                cout<<"Enter the current date as MMDDYYYY without symbols."<<endl;
                                cin>>current_date;
                                cout<<"Enter the index of the book you want to return: "<<endl;
                                cin>>index_num;
                                for(int i=0; i < user_ptr -> getNumBook(); i++){
                                    if (user_ptr->getBookList()[i]->getIndex() == index_num){
                                        lib_book[count_book] = user_ptr->getBookList()[i];
                                        count_book++;
                                        user_ptr->setNumBook(user_ptr->getNumBook()-1);
                                        if(lib_book[count_book]->getExpired()-current_date < 0){
                                            user_ptr -> setLateFee(user_ptr->getLateFee()-5);
                                        }
                                    }
                                }
                            }

                    }
                    else if (choice == 0){
                        break;
                    }
                }
            }
        }
};
