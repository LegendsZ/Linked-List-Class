#include <iostream>
#include "L_list.h"

struct person { //for testing
    const char* name;
    int age;
    person(const char* nameG, int ageG) : name(nameG), age(ageG) { }
};

struct student : person {
    int id;
    student(const char* nameG, int ageG, int idG) : person(nameG, ageG), id(idG) {}
};

int main()
{
    L_list list;
    person one("One", 1);
    person two("Two", 2);
    person three("Three", 3);
    student four("Four", 4, 123);

    list.addNodeByPtr(&one);
    list.addNodeByPtr(&two);
    list.addNodeByPtr(&three);

    list.delNodeByPtr(&two);
    list.addNodeByIndex(1, &two);

    list.addNodeByIndex(list.retNodeCount(), &four);

    person** retList = (person**)list.retSubStringPtrsAsPtr(0, list.retManualNodeCount());

    for (int i = 0; i < list.retNodeCount(); i++) {
        std::cout << "INDEX: " << i << ": NAME: '" << retList[i]->name << "' | AGE: " << retList[i]->age << "!\n";
    }
    std::cout << "INDEX: " << "4" << ": NAME: '" << ((student*)retList[3])->name << "' | AGE: " << ((student*)retList[3])->age << " | ID: " << ((student*)retList[3])->id << "!\n";
    //std::cout << "INDEX: " << "4" << ": NAME: '" << retList[3]->name << "' | AGE: " << four.age << " | ID: " << four.id << "!\n";
    

    std::cout << "\nAddress of 0th index object stored: 0x" << list.retPtrByIndex(0) << "\n";


    system("pause");
}