#include <bits/stdc++.h>

using namespace std;

class Point{
public:
    int x;
    int y;
    Point() {}
    Point(const Point* point):x(point->x),y(point->y) {

    }
    ~Point() {
        cout<<"析构"<<endl;
    }
};

class base {
public:
    virtual void fun1() = 0;
};

class derive : public base{
public:
    virtual void fun1() {
        cout<<"实现"<<endl;
    }
};

void funtest(base& b){
    cout<<"Hello"<<endl;
}

class B {
    static int a;
public:
    int b;
    // B c;
    B* cc;
    // B& ccc;

    B() {
        a = 909;
        b = 0;
    }

    static int geta() {
        cout<<a<<endl;
        return a;
    }
};

int B::a = 10;
int main()
{
    // shared_ptr<Point> p1 = make_shared<Point>();
    // cout<<p1->x<<' '<<p1->y<<endl;
    // cout<<p1.get()<<endl;
    // Point* point1 = new Point();
    // p1 = make_shared<Point>(point1);
    // cout<<p1.get()<<endl;
    // cout<<p1.use_count()<<endl;
    // shared_ptr<Point> p2 = p1;
    // cout<<p1.use_count()<<' '<<p2.use_count()<<endl;
    
    // cout<<&p1<<endl;
    derive* d = new derive();
    derive b = derive();
    funtest(b);

    B bb = B();
    bb.geta();

    return 0;
}