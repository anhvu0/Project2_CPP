#include <iostream>
#include <string>
#include "library.h"
using namespace std;

int main(){
    Library library;
    library.loadFilePerson();
    library.loadFileBook();
    // library.viewAllLibraryBook();
    // library.viewAllLibrarian();
    library.login();
    library.interaction();

    return 0;
}