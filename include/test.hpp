#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

class Test
{
public:
    Test();
    Test(int i);
    friend bool operator>(const Test &klasa1, const Test &klasa2);
    friend bool operator<(const Test &klasa1, const Test &klasa2);
    friend bool operator==(const Test &klasa1, const Test &klasa2);
    friend std::ostream &operator<<(std::ostream &os, const Test klasa1);
    int key;
};

#endif