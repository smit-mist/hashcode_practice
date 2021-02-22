//Classic
//g++ -std=c++17 -O2 -Wall a.cpp -o test
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define pi pair<int,int>
#define vp vector<pi>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define For(i,a,b) for(ll i=a;i<b;i++)
#define endl "\n"
#define debug2(x,y) cout<<"AA Baju Smit----> "<<#x<<" -> "<<x<<" | "<<#y<<" -> "<<y<<endl;
#define debug(x) cout<<"AA Baju Smit------> "<<#x<<" -> "<<x<<endl
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define mint map<int,int>
#define mod 1000000007
#define ciN cin
#define tu(a,s) get<a>(s)
#define tin tuple<ll,ll,ll>
#define ter(x,y,z) ((x)?y:z)
////////////////////////////////////////////////////////////////
struct collection {
	int b, sign, scan;
	vi v;
	vi ha;
};
ld getrank(ld scor, ld ratio, ld sign) {
	ld here = scor / (sign * ratio);
	return here;
}
struct output {
	int id;
	vi v;
};
void jabru() {
	int books, lib, d; cin >> books >> lib >> d;
	map<int, int>score;
	for (int i = 0; i < books; i++) {
		int x; cin >> x;
		score[i] = x;
	}
	vector<collection>stor;
	vector<pair<long double, int>>lis;
	for (int i = 0; i < lib; i++) {
		collection curr;
		cin >> curr.b >> curr.sign >> curr.scan;
		vp v;
		ld scor = 0, ratio = curr.scan, sign = curr.sign;
		for (int j = 0; j < curr.b; j++) {
			int x; cin >> x;
			v.pb(mp(score[x], x));
			scor += (long double)score[x];
		}
		ld index = getrank(scor, ratio, sign);
		//	debug2(index, i);
		sort(rall(v));
		for (int j = 0; j < curr.b; j++) {
			curr.v.pb(v[j].S);
			curr.ha.pb(v[j].F);
		}
		stor.pb(curr);
		lis.pb(mp(index, i));
	}
	sort(rall(lis));
	vector<output>ans;
	vector<bool>vis(books, 0);
	int done = 0;
	for (int i = 0; i < lib; i++) {
		int ind = lis[i].S;
		output curr;
		curr.id = ind;
		done += stor[ind].sign;
		int oo = done;
		int scanned = 0;
		for (int j = 0; j < stor[ind].b; j++) {
			if (!vis[stor[ind].v[j]]) {
				if (scanned == 0 && oo + 1 < d) {
					curr.v.pb(stor[ind].v[j]);
					vis[stor[ind].v[j]] = 1;
					oo++;
					scanned++;
					if (scanned == stor[ind].scan) {
						scanned = 0;
					}
				}
				else {
					curr.v.pb(stor[ind].v[j]);
					vis[stor[ind].v[j]] = 1;
					scanned++;
					if (scanned == stor[ind].scan) {
						scanned = 0;
					}
				}


			}
		}
		if (oo < d) {
			ans.pb(curr);
		}

	}
	ll sss = 0;
//	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		//	cout << ans[i].id << " " << ans[i].v.size() << endl;
		for (int j = 0; j < ans[i].v.size(); j++) {
			//	cout << ans[i].v[j] << " ";
			sss += score[ans[i].v[j]];
		}
		//	cout << endl;
	}
	cout << sss << endl;



}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("b.txt", "r", stdin);
	freopen("ssout.txt", "w", stdout);
	ll t;
	t = 1;
//	cin >> t;
	while (t--) {
		jabru();
	}

	return 0;




}