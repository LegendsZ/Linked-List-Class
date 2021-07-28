#include <iostream>
#include "L_list.h"

struct person { //for testing
    const char* name;
    int age;
    person(const char* nameG, int ageG) : name(nameG), age(ageG) { }
};

int main()
{
    L_list list;
    person one("One", 1);
    person two("Two", 2);
    person three("Three", 3);

    list.addNodeByPtr(&one);
    list.addNodeByPtr(&two);
    list.addNodeByPtr(&three);

    list.delNodeByPtr(&two);
    list.addNodeByIndex(1, &two);

    person** retList = (person**)list.retSubStringPtrsAsPtr(0, list.retManualNodeCount());

    for (int i = 0; i < list.retNodeCount(); i++) {
        std::cout << "INDEX: " << i << ": NAME: '" << retList[i]->name << "' | AGE: " << retList[i]->age << "!\n";
    }

    std::cout << "\nAddress of 0th index object stored: 0x" << list.retPtrByIndex(0) << "\n";


    system("pause");
}