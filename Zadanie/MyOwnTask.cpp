#include <iostream>
#include "Person.h"
/*
napisz klase opisującą osobę oraz kod testujący.
dodać 5 pól opisowych (musi być rok urodzenia).
*/

int main()
{
    Date date;
    date.year = 2004;
    date.month = 10;
    date.day = 24;

    Person person1("Judy", "Howdy");
    //person1.ShowPersonInfo();

    Person person2("Grzegorz", "Brzeczyszczykiewicz", date);
    //person2.ShowPersonInfo();

    Person person3("Ola", "Brzeczyszczykiewicz", date, 150);
    person3.ShowPersonInfo();
    person3.Majority();
}
