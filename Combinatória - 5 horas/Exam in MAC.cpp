// https://codeforces.com/problemset/problem/1935/D

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9+7;
const int MAX = 1e7;

int fatorial[MAX];

void pre_calc_fatorial(){
  fatorial[0] = 1;
  for(int i=1; i < MAX; i++){
    fatorial[i] = (fatorial[i-1] * i)%MOD;
  }
}

int exp(int a, int b){
	if(b == 0) return 1;
	int tmp = exp(a, b/2);
	tmp = (tmp * tmp)%MOD;
	if(b%2 == 1){
		tmp = (tmp * a)%MOD;
	}
	return tmp;
}

int modular_inverse(int a){
	return exp(a, MOD-2);
}

int comb(int n, int k){
  int numerator = fatorial[n];
  int denominator = (fatorial[k] * fatorial[n-k])%MOD;
	return (numerator * modular_inverse(denominator))%MOD;
}

signed main(){
    int t,n,c,a,b,par,impar; cin >> t;
    for(int i=0; i<t; i++){
        a=0; b=0; par=0; impar=0;
        cin >> n >> c;
        vector<int> s(n);
        for(int j=0; j<n; j++){
            cin >> s[j];
        }
        
        int total = ((c+2)*(c+1))/2;
        
        for(int j=0; j<n; j++){
            if(s[j]%2==0){
                a+=(s[j]+2)/2;
            } else {
                a+=(s[j]+1)/2;
            }
            b+=(c-s[j]+1);
            if(s[j]%2==0) par++;
            else impar++;
        }
        total-=(a+b-(((par*(par+1))/2)+(impar*(impar+1)/2)));
        
        cout << total << endl;
    }
    
}