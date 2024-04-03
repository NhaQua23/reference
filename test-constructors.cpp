#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;

    void init(int _x, int _y) {
        x = _x; y = _y;
    }

    Point()  {
        cerr << "Point() " << this << "\n";
    }
    Point(int _x, int _y)  {
        cerr << "Point(int, int) " << this << "\n";
        init(_x, _y);
    }
    Point(Point& p) {
        cerr << "Point(Point&) " << this << "\n";
        init(p.x, p.y);
    }
    Point(const Point& p) {
        cerr << "Point(const Point&) " << this << "\n";
        init(p.x, p.y);
    }
    void operator=(const Point& p){
        cerr << "void const operator= " << this << "\n";
        init(p.x, p.y);
    }
    Point& operator=(Point& p){
        cerr << "operator= " << this << "\n";
        init(p.x, p.y);
    }
    ~Point() {
        cerr << "~Point " << this << "\n";
    }
};

void f(Point p) {
    cerr << "End f. Should see Point(const Point&) called before and ~Point() called after this line\n";
}

void g(Point& p) {
    cerr << "g'p's address " << &p << "\n";
    cerr << "End g. Should see no constructor or destructor called around this line\n";
}

Point* foo() {
    Point* pp;
    cerr << "\nCreating a point with params. Point(int, int)  should be called after this\n";
    pp = new Point(1,2);
    return pp;
}

int main () {
    cerr << "Creating p0. Point() should be called after this\n";
    Point p0;

    cerr << "\ncalling f (pass by value)\n";
    f(p0);
    cerr << "\ncalling g (pass by reference). address of g'p should be " << &p0 << ", same as p1's\n";
    g(p0);

    const Point* ptr = foo();
    cerr << "\nfoo ended. " << ptr << " is in heap memory and has not been destroyed yet \n";

    cerr << "\np0 = p1\n";
    p0 = (*ptr);

    cerr << "\nnow " << ptr << " is destroyed \n";
    delete ptr;

    cerr << "\nEnd main. Should see destructors for p0 and p1 automatically called after this line\n";
    return 0;
}
