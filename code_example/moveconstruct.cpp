#include <bits/stdc++.h>

using namespace std;

class Person
{
public:
string* name;
public:
Person(){

}
Person(string _name) {
    this->name = new string(_name);
    // this->name=&_name;
    cout<<"init"<<endl;
    cout<<this->name<<endl;
}
Person(Person &p){
    this->name = new string(*p.name);
    cout<<"kaobei"<<endl;
}
Person(Person &&p):name(p.name) {
    cout<<p.name<<endl;
    p.name = nullptr;
    cout<<"move"<<endl;
}

~Person() {

    cout<<"desconstrut"<<endl;
    delete (name);
}

};
int main()
{
    Person p = Person("yesky");  

    Person p1 = Person(p);
    p.~Person();
    cout<<"---"<<endl;
    cout<<p1.name<<endl;
    // cout<<p.name<<endl;
    Person tmp  = Person("jzf");
    // Person p2 = Person(Person("jzf"));
    Person p2 = Person(tmp);
    cout<<p2.name<<endl;
    cout<<"---"<<endl;
    return 0;
}