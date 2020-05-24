#include <bits/stdc++.h>

// ---------------------------template starts here-------------------------- 

#define int long long int
#define pb push_back
#define MAX LLONG_MAX
#define endl "\n"
#define precise std::cout << std::fixed;std::cout << std::setprecision(6); 
#define zerobits(x) __builtin_ctzll(z)
#define print(v) for(int x : v) cout << x << endl;
#define F first
#define S second  
#define mp make_pair
#define MIN LLONG_MIN
#define MOD 1000000007
#define FO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

set <int> s;
bool ar[100001];
vector <pair <int, int> > factors;

void seive() {
    ar[0] = ar[1] = true;

    for(int p=2; p*p<=100001; p++) {
        if(ar[p] == false) {
            for(int i=p*p;i<=100001;i+=p)
                ar[i] = true ;
        }
    }

    for(int p=2;p<=100001;p++) {
        if(ar[p] == false)
            s.insert(p);
    }
}

bool is_palindrome(string str) {
    int len = str.length();
    for(int i=0;i<=len/2;i++) {
        if(str[i] != str[len-1-i])
            return false;
    }
    return true;
}

int binexpo(int x, int y, int p) {    
    int res = 1;     // Initialize result  
    x = x % p; // Update x if it is more than or  
                // equal to p  

    while (y > 0)  {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;
}

bool is_prime(int n) {
    if(n < 2)
        return false;
    if(n == 2 || n == 3)
        return true;
    for(int i=2;i*i<=n;i++) {
        if(n%i == 0)
            return false;
    }
    return true;
}

bool sortbydec(const pair <int, int> &a, const pair <int, int> &b) {
    return (a.first > b.first);
}

void primeFactors(int n) {  
    // Print the number of 2s that divide n
    if(n%2 == 0) {  
        int count = 0;
        while (n % 2 == 0) {  
            count++;  
            n = n/2;  
        }
        factors.pb(mp(2, count));  
    }
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2) {  
        // While i divides n, print i and divide n
        if(n%i == 0) {  
            int count = 0;
            while (n % i == 0) {  
                count++;  
                n = n/i;  
            }
            factors.pb(mp(i, count));
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        factors.pb(mp(n, 1));  
}

int lcm(int a, int b) {
    return (a*b)/(__gcd(a, b));
}

// number of power of v in n!
int get(int n, int v) {
    
    int cur = v,res = 0;
    
    while (cur <= n) {
        res += n / cur;
        if (cur > n / v)
            break;
        cur *= v;
    }
    
    return res;
}

// --------------------------template ends here------------------------------

vector <int> adj[100005];
int vis[100005] = {0};
int col[100005] = {0};

bool dfs(int v, int c) {

    vis[v] = 1;
    col[v] = c;

    for(int child : adj[v]) {
        
        if(vis[child] == 0) {
            if(dfs(child, c^1) == false)
                return false;
        }
        else {
            if(col[child] == col[v]) 
                return false;
        }
    }

    return true;

}
void solve() {
    
    int t;
    // cin >> t;
    t = 1;

    while(t--) {
        
        int n, m;
        cin >> n >> m;

        // n = number of nodes
        // m = number of edges

        while(m--) {

            int x, y;
            cin >> x >> y;

            // undirected graph
            adj[x].pb(y);
            adj[y].pb(x);
        
        }    

        int flag = 0;
        
        for(int i=1;i<=n;i++) {
            if(dfs(i, 0) == false) {
                flag = 1;
                break;
            }
        }

        if(flag)
            cout << "Failed Bipartite Test" << endl;
        else
            cout << "Passed Bipartite Test" << endl;

    }    

    return;    
}

int32_t main() {
    
    FO;
    
    auto start = std::chrono::high_resolution_clock::now();

    solve();
    
    auto finish = std::chrono::high_resolution_clock::now();  
    std::chrono::duration<double> elapsed = finish - start;
    cerr << "Elapsed time: " << elapsed.count() << " s\n";

}