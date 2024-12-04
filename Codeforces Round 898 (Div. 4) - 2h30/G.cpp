#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;

	while(t--){
		string st; cin >> st;
		int tam = st.size();
		vector<char> s(tam);
		vector<char> s2(tam);

		for(int i=0; i<tam; i++){
			s[i] = st.at(i);
			s2[i] = st.at(i);
		}

		int res1 = 0;
		int res2 = 0;

		for(int i=0; i<tam-1; i++){
			if(s[i]=='B' and s[i+1]=='A') {
				s[i]='C'; s[i+1]='B';
				res1++;
			} else if(s[i]=='A' and s[i+1]=='B') {
				s[i]='B'; s[i+1]='C';
				res1++;
                if(i-1>=0 && s[i-1]=='A') {
                    int j = i-1;
                    while(j>=0 and s[j]=='A' and s[j+1]=='B') {
                        s[j] = 'B'; s[j+1] = 'C';
                        res1++;
                        j--;
                    }
                }
			}
		}

		for(int i=tam-2; i>=0; i--){
			if(s2[i]=='B' and s2[i+1]=='A') {
				s2[i]='C'; s2[i+1]='B';
				res2++;
                if(i+2<tam && s[i+2]=='A') {
                    int j = i+1;
                    while(j+1<tam and s2[j]=='B' and s2[j+1]=='A') {
                        s2[j] = 'C'; s2[j+1] = 'B';
                        res2++;
                        j++;
                    }
                }
			} else if(s2[i]=='A' and s2[i+1]=='B') {
				s2[i]='B'; s2[i+1]='C';
				res2++;
                
			}
		}

		cout << max(res1,res2) << '\n';
	}	
}
