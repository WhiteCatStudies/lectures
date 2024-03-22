#include <iostream>
#include <string>

#include "young.h"

int main() {
    Person* person = new Young("Wasia");
    person->say();
    delete person;

    getchar();
    
}
