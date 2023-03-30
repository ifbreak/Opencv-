#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N = 2e5 +10;
int n, c, b, mid;
int a[N];
int ans = 0;

bool check(int b)
{
	int l=1, r=n;
	while(l<r)
	{
		mid = (l+r)/2;
		if(a[mid]>=b)
		{
			r = mid;
		}else {
			l = mid + 1;
		}
	}
	if(a[l]==b)
	{
		while(a[l]==b)
		{
			l++;
			ans++;
		}
		return true;
	}else return false;
}
void solve()
{
	cin >> n >> c;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++)
	{
		b = a[i]+c;
		if(b>a[n])
		{
			cout << ans;
			break;
		}else {
			check(b);
		}
	}
}
signed main()
{
	solve();
	return 0;
}