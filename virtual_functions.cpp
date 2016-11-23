#include <bits/stdc++.h>
using namespace std;


class A{
public:
    virtual void f(){
        cout<<"Class A\n";
    }
};

class B:public A{
public:/*
    virtual void f(){
        cout<<"Class B\n";
    }*/
};

class C:public B{
public:
    virtual void f(){
        cout<<"Class C\n";
    }
};


int main()
{
    A *a = new A(),*b=new B(),*c=new C();
    a->f();b->f();c->f();
    return 0;
}
