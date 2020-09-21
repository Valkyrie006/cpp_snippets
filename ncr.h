// Create a global class object to use ......
// Eg ->  NCR ncr(max_size_of_n);
//	  ncr.get(n,r)  // this gets the value of nCr

class NCR{
	public:
		//Variables
		int N;
		vector<int> fact;
		
		// Constructor
		NCR(int x){
			N = x;
			fact.resize(N+1);
			fact[0] = 1;
			rep(i,1,N) fact[i] = 1LL*fact[i-1]*i%MOD;
		}
		
		// Methods
		int get(int n,int r){
			return 1LL * fact[n] * inverse(fact[r]) % MOD * inverse(fact[n - r]) % MOD;
		}
	private:
		const int MOD = 1e9+7;
		int euclid(int a, int b, int& x, int& y) {
		    if (b == 0) {
		        x = 1;
		        y = 0;
		        return a;
		    }
		    int x1, y1;
		    int d = euclid(b, a % b, x1, y1);
		    x = y1;
		    y = x1 - y1 * (a / b);
		    return d;
		}
		long long binexp(long long a, long long b) {
		    a %= MOD;
		    long long res = 1;
		    while (b > 0) {
		        if (b & 1)
		            res = res * a % MOD;
		        a = a * a % MOD;
		        b >>= 1;
		    }
		    return res;
		}
		int inverse(int a){
			if(MOD == (int)1e9+7) return binexp(a,MOD-2);
			int x,y;
			euclid(a,MOD,x,y);
			if(x<0) x = MOD + x;
			return x;
		}
};
