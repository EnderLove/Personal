#include <iostream>

class Son;  // forward declaration

class Father
{
public:
    Son* mySon;  // pointer to child
    int fValue = 10;

    Father();   // constructor
    ~Father();  // destructor to manually delete child
};

class Son
{
public:
    Father* parent;   // pointer to father

    Son(Father* p = nullptr)
        : parent(p)
    {}
};

Father::Father()
{
    mySon = new Son(this);   // create child
}

Father::~Father()
{
    delete mySon;            // manually free child
}

int main()
{
    Father* f = new Father();

    std::cout << f->fValue << std::endl;

    delete f;   // this will delete the child too

    return 0;
}
