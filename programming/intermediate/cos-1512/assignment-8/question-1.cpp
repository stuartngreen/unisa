#include <iostream>
using namespace std;

//------------------------------------------
class A
{
private:
    int x;
protected:
    //int getX();
public:
    int getX();
    void setX();
};

int A::getX()
{
    return x;
}

void A::setX()
{
    x = 10;
}

//----------------------------------------------
class B
{
private:
    int y;
protected:
    A objA;
    int getY();
public:
    void setY();
};

void B::setY()
{
    y = 24;
    int a = objA.getX();
}

//----------------------------------------------
class C: public A
{
protected:
    int z;
public:
    int getZ();
    void setZ();
};

int C::getZ()
{
    return z;
}

void C::setZ()
{
    z = 65;
}

int main ()
{
    C objC;
    objC.setZ();
    cout << objC.getZ() << endl;

    return 0;
}
