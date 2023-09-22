#include <bits/stdc++.h>

using namespace std;

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
    return 0;
}