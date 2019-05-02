#include <iostream>

using namespace std;

void callp(int pg[],int s){
    for(int i=0;i<s;i++){
        cout<<pg[i]<<" ";
    }
    cout<<"\n";
}
void calll(int pg[],int s){
    for(int i=0;i<s;i++){
        cout<<pg[i]<<" ";
    }
    cout<<"\n";
}
int check(int e, int pg[], int s){
    for(int i=0;i<s;i++){
        if(e==pg[i]){
            return 1;
        }
    }
    return 0;
}
int main()
{
    int ar[15]={7,0,1,2,0,3,0,4,2,3,0,3,1,2,0},f=0,h=0,pg[3],lu[3];
    for(int i=0;i<15;i++){
        cout<<ar[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<15;i++){
        if(i<3){
            pg[i]=ar[i];
            lu[i]=ar[i];
            callp(pg,i+1);
            //calll(lu,i+1);
            f++;
        }else{
            if(check(ar[i],pg,3)){
                h++;
                callp(pg,3);
                int pos=-1;
                for(int j=0;j<3;j++){
                    if(ar[i]==lu[j]){
                        pos=j;
                        break;
                    }
                }
                for(int j=pos;j<2;j++){
                    lu[j]=lu[j+1];
                    //cout<<lu[j]<<" ";
                }
                lu[2]=ar[i];
                //cout<<ar[i]<<"FOUND\t";
                //calll(lu,3);
            }else{
                int pos=-1;
                for(int j=0;j<3;j++){
                    if(lu[0]==pg[j]){
                        pos=j;
                        break;
                    }
                }
                pg[pos]=ar[i];
                callp(pg,3);
                for(int j=1;j<3;j++){
                    lu[j-1]=lu[j];
                }
                lu[2]=ar[i];
                //calll(lu,3);
                f++;
            }
        }
    }
    cout<<"FAULT = "<<f<<"\nHIT = "<<h;
    return 0;
}
