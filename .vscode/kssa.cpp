#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1e9
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define fl for (int i = 0; i < n; i++)
typedef vector<int> vll;
typedef pair<int, int> pll;
typedef vector<pll> vpll;
#define print(a)          \
	for (auto x : a)      \
		cout << x << " "; \
	cout << endl // vector print
#define print1(a)    \
	for (auto x : a) \
	cout << x.F << " " << x.S << endl // maps or pairs
#define print2(a, x, y)         \
	for (int i = x; i < y; i++) \
		cout << a[i] << " ";    \
	cout << endl
class ST{
	vector<int>seg,lazy;
public:
	ST(int n){
		seg.resize(4*n);
		lazy.resize(4*n);
	}
public:
	void build(int ind,int low,int high,int arr[]){
		if(low==high){
			seg[ind]=arr[low];
			return ;
		}
		int mid=(low+high)>>1;
		build(2*ind+1,low,mid,arr);
		build(2*ind+2,mid+1,high,arr);
		seg[ind]=seg[2*ind+1]+seg[2*ind+2];

	}
public:
	void update(int ind,int low,int high,int l,int r,int val){
		//update the previous remaingn updates
		// and propagate downwards
		if(lazy[ind]!=0){
			seg[ind]+=(high-low+1)*lazy[ind];
			// propogate the lazy update downwards
			//for the reamingin nodes ot get updates
			if(low!=high){
				lazy[2*ind+1]+=lazy[ind];
				lazy[2*ind+2]+=lazy[ind];
			}
			lazy[ind]=0;
		}
		// no overlap
		// we dont do anything and return 
		if(high<l or r<low){
			return;
		}
		// complete overlap 
		if(low>=l and high<=r ){
			seg[ind]+=(high-low+1)*val;
			if(low!=high){
				lazy[2*ind+1]+=val;
				lazy[2*ind+2]+=val;
			}
			return;
		}
		// patially overlap
		int mid=(low+high)>>1;
		update(2*ind+1,low,mid,l,r,val);
		update(2*ind+2,mid+1,high,l,r,val);
		seg[ind]=seg[2*ind+1]+seg[2*ind+2];
	}
public:
	int query(int ind,int low,int high,int l ,int r){
		// update of any updates are remaining
		// as the node will stay fresh and updated
		if(lazy[ind]!=0){
			seg[ind]+=(high-low+1)*lazy[ind];
			// propogate the lazy update downwards
			//for the reamingin nodes ot get updates
			if(low!=high){
				lazy[2*ind+1]+=lazy[ind];
				lazy[2*ind+2]+=lazy[ind];
			}
			lazy[ind]=0;
		}


		// no overlap return 0
		if(high<l or r<low){
			return 0;
		}

		// complete overlap
		if(low>=l and high<=r) return seg[ind];
		int mid=(low+high)>>1;
		int left=query(2*ind+1,low,mid,l,r);
		int right=query(2*ind+1,mid+1,high,l,r);
		return left+right;
	}


};
bool isPerfectSquare(int x)
{
	if (x >= 0)
	{
		int sr = sqrt(x);
		return (sr * sr == x);
	}
	return false;
}
// int x=1e9+7;
int binExp(int a, int b)
{
	int ans = 1;
	while (b > 0)
	{
		if (b & 1)
		{
			ans = (ans * a);
		}
		a = (a * a);
		b = b >> 1;
	}
	return ans;
}
const int N = 1e5 + 10;
int bit[N];
// fenwick tree
void update(int i, int x)
{
	for (; i < N; i += (i & -i))
		bit[i] += x;
}

// int sum(int i)
// {
// 	int ans = 0;
// 	for (; i > 0; i -= (i & -i))
// 		ans += bit[i];
// 	return ans;
// }



bool static sortbysec(const pair<int, int> &a,
					  const pair<int, int> &b)
{
	return (a.second > b.second);
}


int N1=10000005;
vector<int>siv(N1+1,1);
void sieve(){
	
	for(int i=2;i<=N1;i++){
		if(siv[i]==1){
			
			siv[i]=i;
			for(int j=i*i;j<=N1;j+=i){
				if(siv[j]==1){
					siv[j]=i;
				}
			}
		}
	}
}

vll factoristion(int n){
	vll fact;

	while(n>1){
		
		int x=siv[n];
		while(n%x==0){
			n/=x;
		}
		fact.pb(x);
	}
	return fact;
	
}
bool dfs(int node,int par,vector<int>&vis,vector<set<int>>&g){
	bool flag=1;
	vis[node]=1;
	for(auto it :g[node]){
		if(!vis[it]){
			flag=flag&dfs(it,node,vis,g);
		}
		else if(it!=par){
			flag=0;
		}

	}
	return flag;
}


void solve()
{
	
	int n;
	cin>>n;
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<n;i++){
		cnt+=(s[i]==')');
	}
	if(cnt!=n-cnt){
		cout<<-1<<endl;
		return;
	}
	stack<pair<char,int>>st;
	int color=1;
	vll v(n,0);
	if(s[0]=='('){
		st.push({'(',0});
		v[0]=1;
		for(int i=1;i<n;i++){
			if(st.empty()==true){
				if(s[i]=='('){
					st.push({'(',i});
					
				}
			}
			else{
				if(st.top().first=='(' and s[i]==')'){
					v[i]=1;
					v[st.top().second]=1;
					st.pop();
				}
				else{
					st.push({s[i],i});
				
				}
			}
		}
	}
	else{
		st.push({')',0});
		v[0]=1;
		for(int i=1;i<n;i++){
			if(st.empty()==true){
				if(s[i]==')'){
					st.push({')',i});
					
				}
			}
			else{
				if(st.top().first==')' and s[i]=='('){
					v[i]=1;
					v[st.top().second]=1;
					st.pop();
				}
				else{
					st.push({s[i],i});
				
				}
			}
		}
	}
	int ans=1;
   cnt=0;
	for(auto &it:v){
		if(it==1){
			cnt++;
		}
	}
	if(cnt==0 or cnt==n){
		for(auto &it:v){
			it=1;
		}
	}
	else{
		ans++;
		for(auto &it:v){
			if(it==0){
				it=2;
			}
		}
	}
	cout<<ans<<endl;
	
	print(v);
	

}








int32_t main()
{
 	
	
	
	int t;
	t=1;
	cin>>t;
	while (t--)
	{
		solve();
	}

	return 0;
}