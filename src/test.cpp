#include "../include/test.hpp"

Test::Test()
{
    key = 0;
}

Test::Test(int i)
{
    key = i;
}

bool operator>(const Test &klasa1, const Test &klasa2)
{
    return klasa1.key > klasa2.key;
}

bool operator<(const Test &klasa1, const Test &klasa2)
{
    return klasa1.key < klasa2.key;
}

bool operator==(const Test &klasa1, const Test &klasa2)
{
    return klasa1.key == klasa2.key;
}

std::ostream &operator<<(std::ostream &os, const Test klasa1)
{
    os << klasa1.key;
    return os;
}