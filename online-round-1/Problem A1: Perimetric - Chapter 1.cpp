// first second push_back unordered return continue break vector visited check flag bool while iterator begin end lower_bound upper_bound temp true false ll_MAX ll_MIN insert erase clear pop push compare ll64_MAX ll64_MIN  reverse replace stringstream string::npos length substr front priority_queue

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#endif

#define endl '\n'
#define ll long long
#define rint register int
#define minpq priority_queue <int, vector<int>, greater<int> >
#define maxpq  priority_queue <int>

#define re register
#define pb(x) push_back(x);
#define ce(x) cout << x << '\n';

using db = long double;
using pll = pair < ll, ll >;
#define scan(a, n) 		for(int i = 0; i < n; i++)cin >> a[i];

#define rep(i,x,n,inc) for(i=x ; i<n ; i+=inc)
#define repr(i,x,n,inc) for( i=x ; i>n ; i+=inc)
#define all(a)      (a).begin(),(a).end()
#define unique_sort(x) sort(all(x)), x.resize(distance(x.begin(), unique(all(x))))

#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define hell 1000000007
#define infl LLONG_MAX

#define conutBits(n)	__builtin_popcount(n)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Fill(s,v) memset(s,v,sizeof(s))
#define cout_p(x, p) cout << fixed << setprecision((p)) << x << endl     //print with precision

#define tc(tt) \
    ll tt;    \
    cin >> tt; \
    for (ll _tt = 1; _tt <= tt; _tt++) // testcase 

int32_t main() {
	ios::sync_with_stdio(0); 		cin.tie(0); cout.tie(0);

	ll t, i, x, j, y, w,	z, k, n;
	tc(tt) {
		cout << "Case #" << _tt << ": ";
		z = 1;

		cin >> n >> k >> w;
		std::vector<ll> l, h, p;
		rep(i, 0, k, 1)	{
			cin >> x;
			l.push_back(x);
		}

		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		rep(i, k, n, 1) {
			x = (a * l[i - 2] + b * l[i - 1] + c) % d + 1;
			l.push_back(x);
		}


		rep(i, 0, k, 1)	{
			cin >> x;
			h.push_back(x);
		}

		cin >> a >> b >> c >> d;
		rep(i, k, n, 1) {
			x = (a * h[i - 2] + b * h[i - 1] + c) % d + 1;
			h.push_back(x);
		}

		x = 2 * (w + h[0]);
		p.push_back(x);

		set<ll> mx_end, mx_height;
		mx_end.insert(l[0] + w);
		mx_height.insert(h[0]);

		map<ll, ll> height, end;
		i = 0;
		end[l[i] + w] = i;
		height[h[i]] = i;


		rep(i, 1, n, 1) {
			ll y = 2 * (w + h[i]);
			// ll l[i] = l[i];
			ll sub = 0;
			// debug(y, mx_end);
			while (mx_end.size() and (*mx_end.begin()) < l[i]) {
				ll temp = *mx_end.begin();
				mx_end.erase(temp);
				mx_height.erase(h[end[temp]]);
			}

			if (mx_end.size()) {
				y -= 2 * (min(l[i] + w, *mx_end.rbegin()) - l[i]);
				y -= 2 * min(h[i], *mx_height.rbegin());
			}

			mx_end.insert(l[i] + w);
			mx_height.insert(h[i]);

			end[l[i] + w] = i;
			height[h[i]] = i;

			x += y ;
			// x -= sub;
			p.push_back(x % hell);
		}

		// if (_tt == 5) {
		// 	// debug(l, h);
		// 	debug(p);
		// }

		z = 1;
		for (auto zx : p)	{
			z = (z * ( zx % hell)) % hell;
		}


		// debug(z);

		ce(z);
	}
}

/*

Case #1: 120
Case #2: 200
Case #3: 9144576
Case #4: 803986060
Case #5: 271473330

[x_cor, y_cor] = [{0,2,4,5,9,12}, {0,4,3,6,3,2}]
[x_cor, y_cor] = [{0,9,14,15,19,23,27,31,35,39,43}, {0,12,7,16,31,30,27,16,17,2,15}]
*/

