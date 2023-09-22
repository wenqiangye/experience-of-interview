#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
class A {
public:
    int x;
    int y;
    A(){}
    ~A(){
        cout<<"析构 A"<<endl;
    }
};

class Node {
public:
    weak_ptr<Node> pre;
    weak_ptr<Node> next;
    int val;
    Node(int x) {
        val=x;
    }
    ~Node(){
        cout<<"析构"<<endl;
    }
};
int main()
{
    shared_ptr<A> p;
    shared_ptr<A> q(new A());
    cout<<p.use_count()<<' '<<q.use_count()<<endl;
    p = q;
    cout<<p.use_count()<<' '<<q.use_count()<<endl;

    A* tmp = new A();
    p.reset(tmp);
    cout<<p.use_count()<<' '<<q.use_count()<<endl;

    shared_ptr<A> p1(p);
    p1.swap(q);
    cout<<p1.use_count()<<' '<<p.use_count()<<' '<<q.use_count()<<endl;
    // unique_ptr<A> up(new A());
    
    shared_ptr<Node> head (new Node(5));
    head->pre = head;
    head->next = head;
    shared_ptr<Node> temp(new Node(4));
    head->next = temp;
    temp->pre = head;
    temp->next = head;
    head->pre = temp;
    cout<<head.use_count()<<' '<<temp.use_count()<<endl;
    head = temp;
    cout<<head.use_count()<<' '<<temp.use_count()<<endl;
    // weak_ptr<Node> A;
=======
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

>>>>>>> 0bcbc6ebd392212eb6ea06f7c66e92093b589e1a
    return 0;
}