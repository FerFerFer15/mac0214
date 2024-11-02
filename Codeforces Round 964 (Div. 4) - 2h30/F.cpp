#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9+7;
const int MAX = 2e5+100;
vector<int> fatorial(MAX);

void fast_fat() {
    fatorial[0] = 1;
    for(int i=1; i<MAX; i++) {
        fatorial[i] = (fatorial[i-1]*i)%MOD;
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

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fast_fat();
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n);

        for(int i=0; i<n; i++) {
            cin >> a[i];
        }

        sort(a.begin(),a.end());

        int res = 0;
        int add;
        for(int i = k/2; i<n-(k/2); i++) {
            if(a[i]==1) {
                add = comb(i,k/2);
                add = (add * comb(n-1-i,k/2))%MOD;
                res = (res + add)%MOD;
            }
        }

        cout << res << '\n';
    }
}