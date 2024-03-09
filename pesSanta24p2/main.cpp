#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 200200;
const int K = 32;

struct Item {
	ll a, b;

	Item() : a(), b() {}
	
	void scan() {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		a = x + 1;
		b = x + y + 1;
	}

	bool operator < (const Item &I) const {
		return (I.a - 1) * b < (a - 1) * I.b;
	}
};
vector<Item> items;
ll dp[K];
ll T;
vector<ll> z;
int n;

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &T);
	for (int i = 0; i < n; i++) {
		Item I;
		I.scan();
		if (I.a == 1) {
			z.push_back(I.b);
		} else {
			items.push_back(I);
		}
	}
	sort(items.begin(), items.end());
	sort(z.begin(), z.end());

	dp[0] = 0;
	for (int i = 1; i < K; i++)
		dp[i] = T + 1;
	for (Item I : items) {
		for (int i = K - 2; i >= 0; i--) {
			if (dp[i] > T) continue;
			dp[i + 1] = min(dp[i + 1], I.a * dp[i] + I.b);
		}
	}
	int ans = 0;
	for (int t = 0; t < K; t++) {
		if (dp[t] > T) continue;
		ll w = dp[t];
		int res = t;
		for (ll x : z) {
			if (w + x > T) break;
			w += x;
			res++;
		}
		ans = max(ans, res);
	}
	printf("%d\n", ans);

	return 0;
}
