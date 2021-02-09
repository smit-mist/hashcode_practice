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
int n, Ttwo, Tthree, Tfour;

vp pizza;
vector<bool>used;
map<int, set<string>> ind;
vector<vi>ans;
map<string, vi> ele;

/////////////////////

pair<set<string>, int> get_index(set<string>status) {
	vi has(n + 1);
	set<string>curr = status;
	for (int j = 1; j <= n; j++) {
		has[j] = ind[j].size();
	}
	for (auto x : status) {
		string mate = x;
		for (int k = 0; k < ele[mate].size(); k++) {
			has[ele[mate][k]]--;
		}
	}
	ll mx = 0;
	int element_index = -1;
	for (int j = 1; j <= n; j++) {
		if (!used[j]) {
			if (mx <= has[j]) {
				mx = has[j];
				element_index = j;
			}
		}
	}
	for (auto x : ind[element_index]) {
		curr.insert(x);
	}
	return mp(curr, element_index);

}
void jabru() {
	cin >> n >> Ttwo >> Tthree >> Tfour;
	pizza = vector<pair<int, int>>(n, mp(0, 0));
	used = vector<bool>(n + 1, false);
	//debug(n);
	for (int i = 0; i < n; i++) {

		cin >> pizza[i].F;

		pizza[i].S = i + 1;
//		debug(pizza[i].S);
		for (int j = 0; j < pizza[i].F; j++) {
			string s; cin >> s;
			ele[s].pb(i + 1);
			ind[i + 1].insert(s);
		}
	}

	sort(rall(pizza));
	int current = 0;
	int unused = n;
	//O(M*(ingredients)*(same ingredients))
	while (Ttwo > 0 || Tthree > 0 || Tfour > 0 && unused > 0) {
		bool can = 0;

		while (used[current + 1]) {
			current++;
		}
		vi curr = {};
		//	debug(current);
		if (unused > 0) {
			int here = pizza[current].S;
			used[here] = 1;
			int first = here, second = -1, third = -1, fourth = -1;
			int team2 = 0, team3 = 0, team4 = 0;
			if (unused > 1) {
				auto fo = get_index(ind[here]);
				team2 = fo.F.size();
				used[fo.S] = 1;
				second = fo.S;
				if (unused > 2) {
					auto to = get_index(fo.F);
					team3 = to.F.size();
					used[to.S] = 1;
					third = to.S;
					if (unused > 3) {
						//	debug("IM HERE");
						auto eo = get_index(to.F);
						//	debug2(eo.F.size(), eo.S);
						//	if (eo.S != -1) {
						team4 = eo.F.size();
						used[eo.S] = 1;
						fourth = eo.S;
						//}

					}
				}
			}
			else
				break;
			//	debug(first); debug(second); debug(third); debug(fourth); debug("---------");
			if (unused >= 4) {
				if (team2 == team3 && team3 == team4 && Ttwo > 0) {
					if (third != -1)
						used[third] = 0;
					if (fourth != -1)
						used[fourth] = 0;
					curr = {first, second};
					unused -= 2;
					Ttwo--;
				}
				else if (team3 == team4 && Tthree > 0) {
					if (fourth != -1)
						used[fourth] = 0;
					unused -= 3;
					Tthree--;
					curr = {first, second, third};
				}
				else if (Tfour > 0) {
					curr = {first, second, third, fourth};
					unused -= 4;
					Tfour--;
				}

			}
			else if (unused >= 3) {
				if (team3 <= team2 && Ttwo > 0) {
					used[third] = 0;
					curr = {first, second};
					unused -= 2;
					Ttwo--;
				}
				else if (Tthree > 0) {
					curr = {first, second, third};
					unused -= 3;
					Tthree--;
				}
			}

			else if (unused >= 2 && Ttwo > 0) {
				curr = {first, second};
				unused -= 2; Ttwo--;

			}
			else  {
				break;
				// no team can be served
			}



		}
		if (curr.size() != 0) {
			ans.pb(curr);
		}
		else {
			break;
		}
		current++;

	}
	cout << ans.size() << endl;
	for (auto x : ans) {
		cout << x.size() << " ";
		for (auto z : x) {
			cout << z - 1 << " ";
		}
		cout << endl;
	}
	/*



	Pizza   ----------
	vector<bool> used(n,0);
	vector<pair<int,int>>  (pizza ingre, index)     (sort descending)
	map<int,vector<string>>  (index wise, string)
	map<string,vector<int>>  (mushroom, 1 2 3 pizzza index)
	-----------------
	////////////////
	select -- //
	// i ,j ,k // true.....
	1 // done;
	get string of first ;
	vector<int> v(pizza);
	for every element // decrease the element in the map..  O(ingredients*10) /// 10^4..
	v maximum.. index 2nd pizza..    // 2 team ---- // O(M)
	current string...
							// 3 team ----

	*/




}


int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("fourth.txt", "w", stdout);
	ll t;
	t = 1;
//	debug("HELLO");
//	cin >> t;
	while (t--) {
		jabru();
	}

	return 0;




}