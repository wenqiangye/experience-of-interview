#include <bits/stdc++.h>

using namespace std;

class Merge {
private:

public:
    vector<int>a,b;
    int n;
    int InvNum=0;//逆序对数量
    Merge() {}
    ~Merge() {}

    void guiMerge(vector<int> &a, vector<int> &b, int l, int mid, int r) {
        int i = l, j = mid+1;
        for(int k=l;k<=r;k++) {
            if(j>r||i<=mid&&a[i]<=a[j]) b[k] = a[i++];
            else b[k]=a[j++],InvNum += mid-i+1;
        }
        for(int k=l;k<=r;k++) a[k]=b[k];
    }
    void guiSort(vector<int> &a, vector<int> &b, int l, int r) {
        if(l<r) {
            int mid = (l+r)>>1;
            guiSort(a,b,l,mid);
            guiSort(a,b,mid+1,r);
            guiMerge(a,b,l,mid,r);
        }
    }

    void setnums(vector<int> &tmp) {
        for(auto x:tmp) a.push_back(x);
        b.resize(a.size());
    }
};

int main() 
{   
    vector<int> a = {10,9,8,7,6,5,4,3,2,1};
    Merge* m = new Merge();
    m->setnums(a);
    m->guiSort(m->a,m->b,0,m->a.size());
    cout<<"逆序对： "<<m->InvNum<<endl;
    for(auto &x : m->a) {
        cout<<x<<' ';
    }
    cout<<endl;
    return 0;
}

