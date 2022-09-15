#include<bits/stdc++.h>

using namespace std;
// segmenty tree build
void build(int ind,int low,int high,int seg[],int arr[]){
      if(low==high){
        seg[ind]=arr[low];
        return ;
      }
     // int mid=(low+high)/2;
     int  mid=(low+high)>>1;
      build(2*ind+1,low,mid,seg,arr);
      build(2*ind+2,mid+1,high,seg,arr);

      seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}
// Building query

int Query(int ind,int low,int high,int l,int r,int seg[]){
 // No overlapping
     if(r<low||high<l) return INT_MAX;
     // complete overlap
     if(low>=l  && high<=r) return seg[ind];
     // partially overlap
     int mid=(low+high)/2;
     int left=Query(2*ind+1,low,mid,l,r,seg);
     int right=Query(2*ind+2,mid+1,high,l,r,seg);
     return min(left,right);

}
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int seg[4*n];
    build(0,0,n-1,seg,arr);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<Query(0,0,n-1,l,r,seg)<<endl;
    }

}
int main(){
    solve();
    return 0;
}
