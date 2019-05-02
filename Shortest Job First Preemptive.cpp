#include <iostream>

using namespace std;

struct sjf{
    int pid,a,b,b1,co;
};

int smallest(struct sjf* sjf, int s, int n){
    int pos=-1,small=100;
    for(int i=0;i<n;i++){
        if(sjf[i].a<=s && sjf[i].b<small && sjf[i].co==0){
            small=sjf[i].b;
            pos=i;
        }
    }
    return pos;
}

int main()
{
    int n,maxi=-1;
    cin>>n;
    struct sjf sjf[n];
    int aat[n],tat[n],ar[n],wt[n];
    for(int i=0;i<n;i++){
        cin>>sjf[i].pid>>sjf[i].a>>sjf[i].b;
        ar[i]=sjf[i].a;
        if(sjf[i].a>maxi){
            maxi=sjf[i].a;
        }
        sjf[i].b1=sjf[i].b;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ar[i]>ar[j]){
                int t = ar[i];
                ar[i] = ar[j];
                ar[j] = t;
            }
        }
    }
    for(int i=0;i<n;i++){
        aat[i]=0;
        sjf[i].co=0;
    }
    int c=0,s=0,k=0;
    for(int i=0;i<maxi;i++){
        int small = smallest(sjf,i,n);
        s+=1;
        aat[small]+=s;
        sjf[small].b-=1;
        if(sjf[small].b==0){
            sjf[small].co=-1;
            c++;
        }
    }
    int small;
    la:
    if(c==n){
        goto t;
    }
    small = smallest(sjf,s,n);
    s+=sjf[small].b;
    sjf[small].b=0;
    aat[small]=s;
    sjf[small].co=-1;
    c++;
    cout<<c<<"\n";
    if(c==n){
        goto t;
    }
        goto la;
    t:
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<aat[i]<<" ";
    }
    cout<<"\nTurn Around Time : ";
    for(int i=0;i<n;i++){
        cout<<aat[i]-sjf[i].b1<<" ";
    }
    cout<<"\nWaiting Time : ";
    for(int i=0;i<n;i++){
        cout<<aat[i]-sjf[i].b1-sjf[i].a<<" ";
    }
    return 0;
}
