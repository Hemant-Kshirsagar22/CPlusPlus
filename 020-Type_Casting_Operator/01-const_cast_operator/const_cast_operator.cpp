#include <iostream>
using namespace std;

class A {
    int i_;
public:
    A(int i) : i_(i) {}
    
    int get(void) const {
        return(i_);
    }
    
    void set(int j)
    {
        i_ = j;
    }
};

void print(char *str)
{
    cout << str;
}

int main(void)
{
    const char *c = "Sample Text\n";
    // print(c); // error: can't convert 'char *' to 'const char *'
    print(const_cast<char *>(c));
    
    const A a(1);
    a.get();
    
    // a.set(5) // error void A::set(int)' cannot convert 'this' pointer from 'const A' to 'A &'
    const_cast<A&>(a).set(5);
    // ((A &)a).set(5) c style type cast
    return(0);
}
