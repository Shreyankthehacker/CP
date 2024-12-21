// #include <bits/stdc++.h>
// using namespace std;
// int prefSum[1000001][31];
// int main()
// {
//    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif
//    int testcases;
//    cin>>testcases;
//    while(testcases--)
//    {
//        int n,q;
//        int i;
//        cin>>n;
//        for(i=0;i<=n;i++)
//          for(int j = 0;j<31;j++)
//            prefSum[i][j]=0;
//        for(i=1;i<=n;i++)
//        {
//          int a;
//          cin>>a;
//          int cnt = 0;
//          while(a>0)
//          {
//            prefSum[i][cnt]=a%2;
//            a/=2;
//            cnt++;
//          }
//        }
//        for(i=1;i<=n;i++)
//        {
//          for(int j=0;j<31;j++)
//            prefSum[i][j]+=prefSum[i-1][j];
//        }
//        cin>>q;
//        while(q--)
//        {
//          int l,r;
//          cin>>l>>r;
//          double total=(r-l+1.0)/(2);
//          long long x1 = 0,x2 = 0,x3 = 0;
//          for(i=0;i<31;i++)
//          {
//            int p = prefSum[r][i]-prefSum[l-1][i];
//            if(p<total)
//              x1+=(1LL<<i);
//            if(p!=(r-l+1))
//              x2+=(1LL<<i);
//            if(p)
//              x3+=(1LL<<i);
//          }
//          long long ans = x1+x2+x3;
//            cout<<testcases<<" "<<q<<" "<<ans<<endl;
//        }
//    }
// }


#include <bits/stdc++.h>
using namespace std;

#define int long long 
template<typename T> void maximize(T &res, const T &val) { if (res < val) res = val; }
template<typename T> void minimize(T &res, const T &val) { if (res > val) res = val; }

#define all(a) a.begin(), a.end()
#define full(dp) memset(dp, 0, sizeof(dp))
#define rall(a) a.rend(), a.rbegin()

const int mod = 1e9+7;



int prefix(int a[],int l,int r){
	return a[r]-a[l-1];
}
int prefix(vector<int>&a,int l,int r){
	return a[r]-a[l-1];
}


int modish(int a) {
    a %= mod;
    if (a < 0) a += mod;
    return a;
}

void ip(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
}
int power(int base, int exp, int mod) {
    int res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
inline int inv(int a) {
  a %= mod;
  if (a < 0) a += mod;
  int b = mod, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += mod;
  return u;
}

int xors(int a){
    int b[4]={a,1,a+1,0};
    return b[a%4];
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ip();
    
  int t;
  cin>>t;
  while(t--){
  	int n;
  	cin>>n;
  	vector<vector<int>>cnt(n+1,vector<int>(31,0));
  	for(int i = 1;i<=n;i++){
  		int x;
  		cin>>x;
  		int j = 0;
  		while(x){
  			cnt[i][j]=(x%2);
  			j++;
  			x/=2;
  		}
  	}
  	for(int i = 1;i<=n;i++){
  		for(int j= 0;j<31;j++){
  		cnt[i][j]+=cnt[i-1][j]; // prefixing all the index wise how many number of ones

  	}
		}
  // cnt[i][j] is just splitting the ith index number bitwise in the column in which we have jth index of that column


  int q;
  cin>>q;
  while(q--){
  	int l,r;
  	cin>>l>>r;
  	int x1=0,x2=0,x3=0;
  	for(int i = 0;i<31;i++){
  		int val = power(2,i,mod);
  		modish(val);
  		int ones = cnt[r][i]-cnt[l-1][i];// per index wise we travel here
  		if(2*ones< r - l + 1)x3 = modish(x3+val); 
  		if(ones!= r - l + 1)x2 = modish(x2+val); // for or
  		if(ones!=0)x1 = modish(x1+val);
  	
  	}
  

  cout<<modish(x1+x2+x3)<<endl;

  }




	}

}





// for every bit of the numbers
// ones be the total number of set bits of ith index of alll numbers from l to r 
// if ones<zero then set the ith bit of x to 1 else zero for XOR
// if all no have 1 at ith index then x can be set to 0 or else 1 for OR
// if all no have 0 then at ith index x can have zero else 1
