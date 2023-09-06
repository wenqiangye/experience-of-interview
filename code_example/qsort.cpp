#include <bits/stdc++.h>

using namespace std;

vector<int>a;
int n;

int Pati(vector<int> &num, int l,int r) {
    if(l+1>=r) {
        return l;
    }
    int ls = l, rs = r;
    int key = num[ls];
    while(ls<rs) {
        while (ls<rs&&num[rs]>=key)
        {
            --rs;
        }
        num[ls] = num[rs];
        while (ls<rs&&num[ls]<key)
        {
            ++ls;
        }
        num[rs]=num[ls];
    }
    num[ls] = key;
    return ls;
}

void qusort(vector<int> &a,int l,int r) {
    if(l>r) return;
    int mid = Pati(a,l,r);
    qusort(a,l,mid-1);
    qusort(a,mid+1,r);
}

void quick_sort(vector<int> &a,int l,int r) {
    if(l>r) {
        return;
    }
    int ls = l,rs = r,key = a[ls];
    while (ls<rs)
    {
        while (ls<rs&&a[rs]>=key)
        {
            rs--;
        }
        a[ls]=a[rs];
        while (ls<rs&&a[ls]<key)
        {
            ls++;
        }
        a[rs]=a[ls];
    }
    a[ls]=key;
    quick_sort(a,l,ls-1);
    quick_sort(a,ls+1,r);
    
}
int main()
{
     a.push_back(1);
     a.push_back(-1);
     a.push_back(299);
     a.push_back(3);
     a.push_back(2);
     a.push_back(9);
     a.push_back(8);
     a.push_back(7);
     a.push_back(9);
    //  qusort(a,0,a.size()-1);
    quick_sort(a,0,a.size()-1);
     for(int i=0;i<a.size();++i) {
        cout<<a[i]<<' ';
     }
     cout<<endl;
    return 0;
}