#include <iostream>
#include "Vecto.h"
using namespace std;
int main()
{
    Vector<int> a;
    a.push_back(5);
    a.push_front(4);
    a.push_front(3);
    a.push_back(6);
    a.display();
    a.find(1);
    a.find(6);

    return 0;
}