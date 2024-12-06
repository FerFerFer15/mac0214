// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, k;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) {
      cin >> a[i];
  }
  
  sort(a.begin(),a.end());
  
  cin >> k;
  
  while(k--) {
      int l, r; cin >> l >> r;
      
      int left = 0, right = n-1;
      int res1, res2;
    
      while(left <= right){
        int mid = (left+right)/2;
    
        if(l <= a[mid]){
          right = mid-1;
        }
    
        if(l > a[mid]){
          left = mid+1;
        }
      }
      
      res1 = left;
      
      left = 0; right = n-1;
    
      while(left <= right){
        int mid = (left+right)/2;
    
        if(r < a[mid]){
          right = mid-1;
        }
    
        if(r >= a[mid]){
          left = mid+1;
        }
      }
      
      res2 = right;
      
      cout << res2 - res1 + 1 << ' ';
  }
  cout << '\n';
}