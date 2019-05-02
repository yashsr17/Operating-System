#include <iostream>

using namespace std;

struct sjf{
    int pid,a,b,co;
};

int smallest(struct sjf* sjf, int s, int n){
    int pos=-1,small=100;
    for(int i=0;i<n;i++){
        int x=sjf[i].co;
        if(sjf[i].a<=s && sjf[i].b<=small && sjf[i].co==0){
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
    lab:
    for(int i=0;i<5;i++){
        if(ar[k]==sjf[i].a && sjf[i].a<=ar[k] && sjf[i].co==0){
            s+=sjf[i].b;
            aat[i]=s;
            sjf[i].co=-1;
            c++;
            k++;
            if(aat[i]>=maxi){
                break;
            }else{
                la:
                int small=smallest(sjf,s,n);
                s+=sjf[small].b;
                aat[small]=s;
                sjf[small].co=-1;
                c++;
                k++;
                if(s<maxi){
                    goto la;
                }
                break;
            }
            goto lab;
        }
    }
    lab3:
    int mini=1000,pos=-1;
    for(int i=0;i<n;i++){
        if(sjf[i].b<mini && sjf[i].co==0){
            mini=sjf[i].b;
            pos=i;
        }
    }
    s+=sjf[pos].b;
    aat[pos]=s;
    sjf[pos].co=-1;
    c++;
    if(c==n){
        goto lab2;
    }
    goto lab3;
    lab2:
    int tats=0,wts=0;
    for(int i=0;i<n;i++){
        tat[i]=aat[i]-sjf[i].a;
        tats+=tat[i];
        wt[i]=tat[i]-sjf[i].b;
        wts+=wt[i];
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<aat[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<tat[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<tat[i]-sjf[i].b<<" ";
    }
    cout<<"\nTurn Around Time - "<<tats/n<<"\nWaiting Time - "<<wts/n;
    return 0;
}
