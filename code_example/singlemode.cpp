#include <bits/stdc++.h>

using namespace std;

class SingleIns
{
public:
//获取单例实例对象
    static SingleIns* getSingIns() 
    {
        if(singleins==nullptr) {
            std::unique_lock<std::mutex> lock(m_mutex);
            if(singleins==nullptr) {
                volatile auto temp = new (std::nothrow) SingleIns();
                singleins = temp;
            }
        }
        return singleins;
    }
    //释放
    static void delIns() 
    {
        std::unique_lock<mutex> lock(m_mutex);
        if(singleins) {
            delete singleins;
            singleins = nullptr;
        }
    }
private:
//唯一单例实例对象指针
    static SingleIns* singleins;
    static std::mutex m_mutex;
    //构造，拷贝等函数私有
    SingleIns() {}
    ~SingleIns() {}
    SingleIns(const SingleIns &singleins){

    }

};

SingleIns* SingleIns::singleins = nullptr;
std::mutex SingleIns::m_mutex;

class SingleIns2
{
public:
    static SingleIns2& getSingIns() 
    {
        static SingleIns2 singleins2;
        return singleins2;
    }
    static void delIns() 
    {
        
    }
private:
    
    SingleIns2() {}
    ~SingleIns2() {}
    SingleIns2(const SingleIns2 &singleins2) = delete;
    const SingleIns2 &operator = (const SingleIns2 &single) = delete;
};
int main()
{

    return 0;
}