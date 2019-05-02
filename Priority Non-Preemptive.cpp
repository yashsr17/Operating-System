#include <iostream>

using namespace std;

struct prio{
    int pid,ati,bti,pri,co;
};

int check(struct prio* p,int s,int n){
    int maxi=-1,pos=-1;
    for(int i=0;i<n;i++){
        if(p[i].pri>maxi && p[i].co==0 && p[i].ati<=s){
            pos=i;
            maxi=p[i].pri;
        }
    }
    return pos;
}

int main()
{
    int n;
    cin>>n;
    struct prio prior[n];
    int ati[n],atim[n],tat[n],wat[n];
    for(int i=0;i<n;i++){
        cin>>prior[i].pid>>prior[i].ati>>prior[i].bti>>prior[i].pri;
        ati[i]=prior[i].ati;
        prior[i].co=0;
    }
    int c=0,k=0,s=0,pos=-1;
    lab:
    if(c==n){
        goto fin;
    }
    pos=check(prior,s,n);
    cout<<pos<<"\n";
    s+=prior[pos].bti;
    prior[pos].co=-1;
    atim[pos]=s;
    tat[pos]=atim[pos]-prior[pos].ati;
    wat[pos]=tat[pos]-prior[pos].bti;
    c++;
    goto lab;
    fin:
    for(int i=0;i<n;i++){
        cout<<tat[i]<<" "<<wat[i]<<"\n";
    }
    return 0;
}
