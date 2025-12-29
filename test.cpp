#include <iostream>

struct Test
{
    int num;
};

int* createTest(int num)
{
    Test *test = (Test*)malloc(sizeof(Test));

    test->num = num;

    std::cout << "Addres of Test ptr: "<<&(test->num) << std::endl;

    return &(test->num);
}

int* normalTest(int num)
{
    int _num = num;

    int* address = &_num;

    return address;
}

int main()
{
    int* Address = createTest(10);

    free(Address);

    std::cout << "Address: " << Address << " | Value: " << *Address << std::endl;

    int* normalAddress = normalTest(10);
    
    std::cout << "Address: " << normalAddress << " | Value: " << *normalAddress << std::endl;

    return 0;
}   