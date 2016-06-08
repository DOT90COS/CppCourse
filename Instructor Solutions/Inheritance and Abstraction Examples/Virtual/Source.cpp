#include <iostream>

class Base {
    int x_ = 0;
public:
    void foo() { std::cout << "Base::foo\n"; }
    virtual void bar() { std::cout << "Base::bar\n"; }
};

class foobar : public Base
{
    double y_ = 1.2;
public:
    void foo() { std::cout << "foobar::foo\n"; }
    void bar() override { std::cout << "foobar::bar\n"; }
    void baseFoo() { Base::foo(); }
    void baseBar() { Base::bar(); }
};

class baz : public foobar
{
public: 
    void bar() { std::cout << "bar::bar\n"; }
};

void fun(const Base& base)
{

}

int main()
{
    baz z;
    foobar a = z;
    Base b = a;
    Base& c = a;
    foobar& e = a;
    Base* x = new foobar;
    Base* d = &a;
    

    a.foo(); //foobar::foo
    b.foo(); //Base::foo
    c.foo(); //Base::foo
    d->foo(); //Base::foo
    a.bar(); //foobar::bar
    z.bar(); //baz::bar
    b.bar(); //Base::bar
    c.bar(); //foobar::bar
    d->bar(); //foobar::bar
    a.baseBar(); //Base::bar

    return 0;
}