// first second push_back unordered return continue break vector visited check flag bool while iterator begin end lower_bound upper_bound temp true false ll_MAX ll_MIN insert erase clear pop push compare ll64_MAX ll64_MIN  reverse replace stringstream string::npos length substr front priority_queue

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#define io() 42
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
// #define infl LLONG_MAX
const ll hell = 10000000000000007;

#define conutBits(n)	__builtin_popcount(n)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Fill(s,v) memset(s,v,sizeof(s))
#define cout_p(x, p) cout << fixed << setprecision((p)) << x << endl     //print with precision

#define tc(tt) \
    ll tt;    \
    cin >> tt; \
    for (ll _tt = 0; _tt < tt; _tt++) // testcase 

int32_t main() {
	ios::sync_with_stdio(0); 		cin.tie(0); cout.tie(0);
	// io();

	ll t, i, x, j, y, 	z, k, n;
	tc(tt) {
		cout << "Case #" << _tt + 1 << ": ";
		ll n, m;
		cin >> n >> k;
		long long * a = new long long[n];
		long long * dp = new long long[n];
		scan(a, n);

		multiset<ll> s;
		dp[n - 1] = 0;
		s.insert(0);

		rep(i, 0, n, 1) {
			if (a[i] == 0)	a[i] = hell;
		}

		// a[0] = 0;

		repr(i, n - 2, -1, -1) {
			if (i + k < n - 1) {
				s.erase(s.find(dp[i + k + 1]));
			}

			ll x = *s.begin();
			if (x != hell and a[i] != hell)
				dp[i] = a[i] +	x;
			else dp[i] = hell;

			s.insert(dp[i]);
		}


		z = hell + 10;
		rep(i, 0, min(n, k + 1), 1)	z = min(z, dp[i]);

		if (z >= hell)	z = -1;
		cout << z << "\n";
	}
}
