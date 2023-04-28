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
        Book *lib_book[1000]; //existing book in the library
        Student *student[1000]; //existing students in the system
        Faculty *faculty[1000]; //existing faculty in the system
        Admin *admin[1000]; //existing admin in the system
        Librarian *librarian[1000]; //existing librarian in the system
        Person *user_ptr; //a pointer point to a user to manipulate that user

        // Student *student_ptr;
        // Faculty *faculty_ptr;
        // Admin *admin_ptr;
        // Librarian *librarian_ptr;

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
            user_ptr = nullptr;
        }

        //This function will read the users.txt file to count the number of people of each role and create objects for them. Then their objects will be saved into an appropriate array of each role above.
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
                    infile.ignore();
                    for(int i=0; i < student_ptr -> getNumBook(); i++){
                        getline(infile, line);
                        infile>>index;
                        for(int j=0; j<count_book; j++){ //Do a for loop to search for the book in the library
                            if (lib_book[j]->getTitle() == line && lib_book[j]->getIndex() == index){ //If the book's title exists in the library's system
                                student_ptr->setBookList(i, lib_book[j]); //This student has a book borrowed from the library
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

                    infile>>id;
                    faculty_ptr -> setNumBook(id);
                    infile.ignore();
                    for(int i=0; i < faculty_ptr -> getNumBook(); i++){
                        getline(infile, line);
                        infile>>index;
                        for(int j=0; j<count_book; j++){ //Do a for loop to search for the book in the library
                            if (lib_book[j]->getTitle() == line && lib_book[j]->getIndex() == index){ //If the book's title exists in the library's system
                                faculty_ptr->setBookList(i, lib_book[j]); //This student has a book borrowed from the library
                            }
                        }
                        infile.ignore();
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
            infile.close();
        }

        //Work the same way as above function. It read the books.txt file then count number of books, create objects for them and save those object into the book array.
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
                infile.ignore();
                getline(infile, line);
                lib_book_ptr -> setAuthor(line);
                infile.ignore();
                getline(infile, line);
                lib_book_ptr -> setPublisher(line);
                infile>>index;
                lib_book_ptr -> setYear(index);
                infile.ignore();
                getline(infile, line);
                lib_book_ptr -> setBorrower(line);
                infile>>index;
                lib_book_ptr -> setExpiredDate(index);
                infile>>charge;
                lib_book_ptr -> setCharge(charge);
                lib_book[count_book] = lib_book_ptr;
                count_book++;
            }
            infile.close();
        }

        void addStudent(){
            if (count_student == 1000){
                cout<<"Full! Cannot add more students."<<endl;
            }
            string line;
            int id;
            Student *student_ptr = new Student;
            cout<<"Enter as the following: first name, last name, date of birth, username, password, id, and number of books borrow(set 0 for new account)"<<endl;
            cout<<"Enter 'Exit' to exit"<<endl;
            cin>>line;
            if(line == "Exit" || line == "exit"){
                interaction();
            }
            // outfile<<line<<endl;
            student_ptr -> setFirstName(line);
            cin>>line;
            // outfile<<line<<endl;
            student_ptr -> setLastName(line);
            cin>>line;
            // outfile<<line<<endl;
            student_ptr -> setDob(line);
            cin>>line;
            // outfile<<line<<endl;
            student_ptr -> setUsername(line);
            cin>>line;
            // outfile<<line<<endl;
            student_ptr -> setPassword(line);
            cin>>id;
            // outfile<<id<<endl;
            student_ptr -> setID(id);
            cin>>id;
            // outfile<<id<<endl;
            student_ptr -> setNumBook(id);
            student[count_student] = student_ptr;
            count_student ++;
            cout<<"Student added successfully"<<endl;
        }

        void removeStudent(){
            if (count_student == 0){
                cout<<"No student to remove"<<endl;
            }
            int id;
            cout<<"Enter the id of the student you want to remove or enter '0' to return"<<endl;
            cin>>id;
            if(id == 0){
                interaction();
            }
            for(int i=0; i< count_student; i++){
                // if (student[i] == nullptr)
                //     continue;
                if (student[i]->getId() == id){
                    delete student[i];
                    student[i] = nullptr;
                    for(int j=i; j<count_student; j++){
                        student[j] = student[j+1];
                    }
                    count_student --;
                    cout<<"Student removed successfully"<<endl;
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
            cout<<"Enter as the following: first name, last name, date of birth, username, password, id, and number of books borrow(set 0 for new account)"<<endl;
            cout<<"Enter 'Exit' to exit"<<endl;
            cin>>line;
            if(line == "Exit" || line == "exit"){
               interaction();
            }
            // outfile<<line<<endl;
            faculty_ptr -> setFirstName(line);
            cin>>line;
            // outfile<<line<<endl;
            faculty_ptr -> setLastName(line);
            cin>>line;
            // outfile<<line<<endl;
            faculty_ptr -> setDob(line);
            cin>>line;
            // outfile<<line<<endl;
            faculty_ptr -> setUsername(line);
            cin>>line;
            // outfile<<line<<endl;
            faculty_ptr -> setPassword(line);
            cin>>id;
            // outfile<<id<<endl;
            faculty_ptr -> setID(id);
            cin>>id;
            // outfile<<id<<endl;
            faculty_ptr -> setNumBook(id);
            faculty[count_faculty] = faculty_ptr;
            count_faculty ++;
            cout<<"Faculty added successfully"<<endl;
        }

        void removeFaculty(){
            if (count_faculty == 0){
                cout<<"No faculty to remove"<<endl;
            }
            int id;
            cout<<"Enter the id of the student you want to remove or enter '0' to return"<<endl;
            cin>>id;
            if(id == 0){
                interaction();
            }
            for(int i=0; i< count_faculty; i++){
                // if (faculty[i] == nullptr)
                //     continue;
                if (faculty[i]->getId() == id){
                    delete faculty[i];
                    faculty[i] = nullptr;
                    for(int j=i; j<count_faculty; j++){
                        faculty[j] = faculty[j+1];
                    }
                    count_faculty --;
                    cout<<"Faculty removed successfully"<<endl;
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
            cout<<"To exit, enter 'Exit'"<<endl;
            cin>>line;
            if(line == "Exit" || line == "exit"){
                interaction();
            }
            else {
            // outfile<<line<<endl;
                librarian_ptr -> setFirstName(line);
                cin>>line;
                // outfile<<line<<endl;
                librarian_ptr -> setLastName(line);
                cin>>line;
                // outfile<<line<<endl;
                librarian_ptr -> setDob(line);
                cin>>line;
                // outfile<<line<<endl;
                librarian_ptr -> setUsername(line);
                cin>>line;
                // outfile<<line<<endl;
                librarian_ptr -> setPassword(line);
                cin>>id;
                // outfile<<id<<endl;
                librarian_ptr -> setID(id);
                librarian[count_librarian] = librarian_ptr;
                count_librarian ++;
                cout<<"Librarian added successfully"<<endl;
            }
        }

        void writeFile(){
            ofstream outfile;
            outfile.open("users.txt");
            for(int i=0; i<count_admin; i++){
                outfile<<admin[i]->getType()<<endl;
                outfile<<admin[i]->getFirstName()<<endl;
                outfile<<admin[i]->getLastName()<<endl;
                outfile<<admin[i]->getDob()<<endl;
                outfile<<admin[i]->getUsername()<<endl;
                outfile<<admin[i]->getPassword()<<endl;
                outfile<<admin[i]->getId()<<endl;
                outfile<<endl;
            }

            for(int i=0; i<count_librarian; i++){
                outfile<<librarian[i]->getType()<<endl;
                outfile<<librarian[i]->getFirstName()<<endl;
                outfile<<librarian[i]->getLastName()<<endl;
                outfile<<librarian[i]->getDob()<<endl;
                outfile<<librarian[i]->getUsername()<<endl;
                outfile<<librarian[i]->getPassword()<<endl;
                outfile<<librarian[i]->getId()<<endl;
                outfile<<endl;
            }
            for(int i=0; i<count_student; i++){
                outfile<<student[i]->getType()<<endl;
                outfile<<student[i]->getFirstName()<<endl;
                outfile<<student[i]->getLastName()<<endl;
                outfile<<student[i]->getDob()<<endl;
                outfile<<student[i]->getUsername()<<endl;
                outfile<<student[i]->getPassword()<<endl;
                outfile<<student[i]->getId()<<endl;
                outfile<<student[i]->getNumBook()<<endl;
                for(int j=0; j<student[i]->getNumBook(); j++){
                    outfile<<student[i]->getBookTitle(j)<<endl;
                }
                outfile<<endl;
            }
            for(int i=0; i<count_faculty; i++){
                outfile<<faculty[i]->getType()<<endl;
                outfile<<faculty[i]->getFirstName()<<endl;
                outfile<<faculty[i]->getLastName()<<endl;
                outfile<<faculty[i]->getDob()<<endl;
                outfile<<faculty[i]->getUsername()<<endl;
                outfile<<faculty[i]->getPassword()<<endl;
                outfile<<faculty[i]->getId()<<endl;
                outfile<<faculty[i]->getNumBook()<<endl;
                for(int j=0; j<faculty[i]->getNumBook(); j++){
                    outfile<<faculty[i]->getBookTitle(j)<<endl;
                }
                outfile<<endl;
            }
            outfile.close();
        }

        //Don't know how to remove from the files yet.
        // Can try seperating the write into txt file part and write a whole file again every time an object is deleted from array
        void removeLibrarian(){
            if (count_librarian == 0){
                cout<<"No librarian to remove"<<endl;
            }
            int id;
            cout<<"Enter the id of the librarian you want to remove or enter '0' to go back"<<endl;
            cin>>id;
            if(id == 0){
                interaction();
            }
            else{
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
                        cout<<"librarian removed successfully"<<endl;
                    }
                }
            }
        }

        void writeBook(){
            ofstream outfile;
            outfile.open("books.txt");
            for(int i=0; i<count_book; i++){
                outfile<<lib_book[i]->getIndex()<<endl;
                outfile<<lib_book[i]->getTitle()<<endl;
                outfile<<lib_book[i]->getAuthor()<<endl;
                outfile<<lib_book[i]->getPublisher()<<endl;
                outfile<<lib_book[i]->getYear()<<endl;
                outfile<<lib_book[i]->getBorrower()<<endl;
                outfile<<lib_book[i]->getExpired()<<endl;
                outfile<<lib_book[i]->getCharge()<<endl;
                outfile<<endl;
            }
            outfile.close();
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
            cout<<"To exit, enter '0' in the index"<<endl;
            cin>>index;
            if(index == 0){
                exit(0);
            }
            else{
                book_ptr -> setIndex(index);
                cin.ignore();
                getline(cin, line);
                book_ptr -> setTitle(line);
                cin.ignore();
                getline(cin, line);
                book_ptr -> setAuthor(line);
                cin.ignore();
                getline(cin, line);
                book_ptr -> setPublisher(line);
                cin>>index;
                book_ptr -> setYear(index);
                cin.ignore();
                getline(cin, line);
                book_ptr -> setBorrower(line);
                cin>>index;
                book_ptr -> setExpiredDate(index);
                cin>>charge;
                book_ptr -> setCharge(charge);
                lib_book[count_book] = book_ptr;
                count_book ++;
                cout<<"Book added successfully"<<endl;
            }
        }

        void removeBook(){
            if (count_book == 0){
                cout<<"No books to remove"<<endl;
            }
            int index;
            cout<<"Enter the index of the book you want to remove or enter '0' to go back"<<endl;
            cin>>index;
            if(index == 0){
                interaction();
            }
            else{
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
                        cout<<"Book removed successfully"<<endl;
                    }
                }
            }
        }

        void viewBorrowedBookStudent(){
            for(int i=0; i < count_student; i++){
                if (student[i] -> getNumBook() > 0){
                    student[i] -> printInfo();
                    student[i] -> printBorrowedBook();
                    cout<<endl;
                }
            }
        }

         void viewBorrowedBookFaculty(){
            for(int i=0; i < count_faculty; i++){
                if (faculty[i] -> getNumBook() > 0){
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
            int current_date;
            cout<<"Enter the current date. MMDDYYYY without symbol."<<endl;
            cin>>current_date;
            for(int i=0; i<1000; i++){
                if(student[i]->getId() == borrower_id_){
                    for(int j=0; j<count_book; j++){
                        if(lib_book[j]->getExpired() > current_date && lib_book[j]->getCharge()==5){
                            cout<<"The book is overdue and charge is applied."<<endl;
                            student[i]->setLateFee(student[i]->getLateFee()+5);
                        }
                    }
                }
                else if (faculty[i]->getId() == borrower_id_){
                    for(int j=0; j<count_book; j++){
                        if(lib_book[j]->getExpired() > current_date && lib_book[j]->getCharge()==5){
                            cout<<"The book is overdue and charge is applied."<<endl;
                            faculty[i]->setLateFee(faculty[i]->getLateFee()+5);
                        }
                    }
                }
            }

        }

        void viewBorrower(){
            int index;
            string borrower_name;
            cout<<"Enter the index of the book"<<endl;
            cin>>index;
            for(int i=0; i<count_book; i++){
                if(lib_book[i]->getIndex() == index){
                    borrower_name = lib_book[i]->getBorrower();
                    cout<<"The name of the borrower is: "<<borrower_name<<endl;
                }
                else if (i == count_book){
                    cout<<"This book does not have any borrower"<<endl;
                }
            }
        }

        void login(){
            string role;
            string username;
            string password;
            bool found=false;
            // user_ptr = nullptr;
            cout<<"Enter your role (Capitalize the first letter): "<<endl;
            cin>>role;
            cout<<"Enter username: "<<endl;
            cin>>username;
            cout<<"Enter password: "<<endl;
            cin>>password;
            if(role == "Admin"){
                for(int i=0; i<count_admin; i++){
                    if (admin[i]->getUsername() == username && admin[i]->getPassword() == password){
                        cout<<"Admin login successfully!"<<endl;
                        user_ptr=admin[i];
                        found = true;
                        break;
                    }
                }
            }

            else if(role == "Librarian"){
                for(int i=0; i<count_librarian; i++){
                    if (librarian[i]->getUsername() == username && librarian[i]->getPassword() == password){
                        cout<<"Librarian login successfully!"<<endl;
                        user_ptr = librarian[i];
                        found = true;
                        break;
                    }   
                    // else{
                    //     cout<<"Login failed. Enter role, username, and password again."<<endl;
                    //     cout<<"Enter your role: "<<endl;
                    //}

                }
            }

            else if(role == "Faculty"){
                for(int i=0; i<count_faculty; i++){
                    if (faculty[i]->getUsername() == username && faculty[i]->getPassword() == password){
                        cout<<"Faculty login successfully!"<<endl;
                        user_ptr = faculty[i];
                        found = true;
                        break;
                    }
                    // else{
                    //     cout<<"Login failed. Enter role, username, and password again."<<endl;
                    //     cout<<"Enter your role: "<<endl;
                    //}

                }
            }

            else if(role == "Student"){
                for(int i=0; i<count_student; i++){
                    if (student[i]->getUsername() == username && student[i]->getPassword() == password){
                        cout<<"Student login successfully!"<<endl;
                        user_ptr = student[i];
                        found = true;
                        break;
                    }        
                    // else{
                    //     cout<<"Login failed. Enter role, username, and password again."<<endl;
                    //     cout<<"Enter your role: "<<endl;
                    //     break;
                    // }
                }
            }

            else if (role == "Exit"){
                exit(0);
            }

            if (found==false){
                cout<<"Login failed. Enter role, username, and password again or enter 'exit' to exit."<<endl;
                login();
            }
        }

        void interaction(){
            int choice;
            if(user_ptr->getType() == "Admin"){
                cout<<"Entering number for each options"<<endl;
                cout<<"1: Add librarian"<<endl;
                cout<<"2: Remove librarian"<<endl;
                cout<<"0: Exit"<<endl;
                cin>>choice;
                    if(choice == 1){
                        addLibrarian();
                    }
                    else if (choice == 2){
                        removeLibrarian();
                    }
                    else if (choice == 0){
                        writeFile();
                        exit(0);
                    }
                    interaction();
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
                cin >> choice;
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
                    writeBook();
                    writeFile();
                    exit(0);
                }
                interaction();
            }

            else if(user_ptr->getType() == "Student" || user_ptr->getType() == "Faculty"){
                cout<<"Entering number for each options"<<endl;
                cout<<"1: Check all available book"<<endl;
                cout<<"2: Check availability of a specific book"<<endl;
                cout<<"3: Borrow a book"<<endl;
                cout<<"4: Return a book"<<endl;
                cout<<"0: Exit."<<endl;
                cin >> choice;
                if (choice == 1){
                    for(int i=0; i<count_book; i++){
                        cout<<lib_book[i]->getTitle()<<" | index: "<<lib_book[i]->getIndex()<<endl;
                    };
                    cout<<endl;
                }
                else if(choice == 2){
                    cout<<"Enter the name of the book: "<<endl;
                    string name;
                    int count_available=0;
                    int array[1000];
                    cin.ignore();
                    getline(cin, name);
                    for(int i=0; i< count_book; i++){
                        if(lib_book[i]->getTitle() == name && lib_book[i]->getBorrower() == "none"){
                            array[count_available] = lib_book[i]->getIndex();
                            count_available++;
                        }
                        // for(int j=0; j<count_available; j++){
                        //     if(lib_book[i]->getTitle() == name && lib_book[i]->getBorrowerId() == 0){
                        //         array[j] = lib_book[j]->getIndex();
                        //     }
                        // }
                    }
                    cout<<"There are "<<count_available<<" copies available and their index numbers are: "<<endl;
                    for(int j=0; j<count_available;j++){
                        cout<<array[j]<<endl;
                    }
                    cout<<endl;
                }

                else if(choice == 3){
                    int index_num;
                    Book* book_ptr;
                    int current_date;
                    if(user_ptr -> getType() == "Student"){
                        if(user_ptr->getNumBook() >= 10){
                            cout<<"Cannot borrow more book";
                        }
                        else if (user_ptr -> getNumBook() < 10){
                            cout<<"Enter the index of the book you want to borrow: "<<endl;
                            cin>>index_num;

                            //Dont't know what to do yet about the date
                            // cout<<"Enter current date as MMDDYYYY"<<endl;
                            // cin>>current_date;

                            for(int i=0; i<count_book; i++){
                                if (lib_book[i]->getIndex() == index_num){
                                    book_ptr = lib_book[i];
                                    lib_book[i]->setBorrower(user_ptr->getFirstName()+' '+user_ptr->getLastName());
                                }
                            }
                            user_ptr -> setBookList(user_ptr->getNumBook(), book_ptr);
                            cout<<"Book borrowed successfully"<<endl;

                            //Dont't know what to do yet about the date
                            // cout<<"The expiration date will be"<<current_date+300000<<endl;
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
                            user_ptr -> setBookList(user_ptr->getNumBook(), book_ptr);                                // for(int i=0; i<count_book; i++){
                            //     if (lib_book[i] == book_ptr){
                            //         for(int j=i; j<count_book-1; j++){
                            //             delete lib_book[j];
                            //             lib_book[j]=nullptr;
                            //             lib_book[j] = lib_book[j+1];
                            //         }
                            //     }
                            // }
                            // count_book--;
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
                                    user_ptr->setNumBook(user_ptr->getNumBook()-1);
                                    if(user_ptr->getBookList()[i]->getExpired()>current_date /*&& user_ptr->getBookList()[i]->getCharge()==5*/){
                                        user_ptr -> setLateFee(user_ptr->getLateFee()-5);
                                        for(int i=0; i<count_book; i++){
                                            if (lib_book[i]->getIndex() == index_num){
                                                lib_book[i]->setBorrower("none");
                                                lib_book[i]->setExpiredDate(0);
                                                // lib_book[i]->setCharge(0);
                                            }
                                        }
                                    }
                                }
                            }
                        }

                }
                else if (choice == 0){
                    exit(0);
                }
                interaction();
            }
        }

};
