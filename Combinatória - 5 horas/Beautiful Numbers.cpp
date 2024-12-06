// https://codeforces.com/problemset/problem/300/C

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;
const int MAX = 1e7;
int fatorial[MAX];
void pre_calc_fatorial(int N){
  fatorial[0] = 1;
  for(int i=1; i <= N; i++){
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

signed main(){
  int a,b,n; cin >> a >> b >> n;
  int ca = n, cb=0;
  int val = a*n, teste, denominator1, denominator2, l;
  bool check;
  pre_calc_fatorial(n);
  int res=0;
  for(int i=0; i<=n; i++){
      check = true;
      teste = val;
      while(teste>0){
          if(teste%10!=a && teste%10!=b){
              check = false;
              break;
          }
          teste = teste/10;
      }
      if(check){
          denominator1 = fatorial[ca];
          denominator2 = fatorial[cb];
          l = (fatorial[n]*modular_inverse(denominator1))%MOD;
          l = (l*modular_inverse(denominator2))%MOD;
          res+=l;
          res=res%MOD;
      }
      val-=a;
      val+=b;
      ca--;
      cb++;
  }
  cout << res << endl;
}