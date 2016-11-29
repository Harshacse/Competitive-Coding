#include <iostream>
#include <string>
#define mod 1000000007
using namespace std;
typedef long long int ll;
 
ll modpow(ll a,ll b){
	ll ans = 1;
	a = a%mod;
	while(b > 0){
		if(b&1) ans = (ans*a)%mod;
		b=b>>1;
		a = (a * a)%mod;	
	}
	return ans;
}
 
int main() {
	bool seti;
	int t;
	ll count;
	string a,b;
	cin >> t;
	while(t--){
		count = 0;
		seti = true;
		cin >> a >> b;
		for(int i = 0; i < a.size()-1 && seti; i++){
			if(a[i] == '1' && b[i] == '1') count++;
			else{
				if(i+3 < a.size()){ 
					if(a[i] == '2' && b[i] == '2'){
						if(a[i+1] != '2' || b[i+1] != '2' || a[i+2] != '1' || b[i+2] != '1') {
							seti = false;
							cout<<"here\n";
						}
						else{
							count += 3;
							i += 2;	
						}
					}
					else {
						if(a[i+1] == '2' && b[i+1] == '2'){
							if((a[i+2]-'0')*(b[i+2] - '0') == 2 && i+4 < a.size()){
								if((a[i+3]-'0')*(b[i+3] - '0') == 4){
									cout<<"heresfj\n";
									seti = false;
								}
								else{
									if(a[i+3] == '1' && b[i+3] == '1') count++;
									i += 2;
								}
							}
							else{

								cout<<i<<"hegewhre\n";
								seti = false;
							}
							count++;
						}
						else if(a[i+1] == '1' && b[i+1] == '1'){
							cout<<"herewqvgfj\n";
							seti = false;
						}
						else{
							if(a[i+2] == '2' && b[i+2] == '2'){
								cout<<"whwjehere\n";
								seti = false;
							}
							else{
								if(a[i+2] == '1' && b[i+2] == '1') count++;
								i++;
							}
						}
					}
				}
				else{
					cout<<"wqjkwhere\n";
					seti = false;
				}
			}
		}
		if(seti) cout << modpow(2,count+1) << endl;
		else cout << 0 << endl; 
	}
	return 0;
} 
