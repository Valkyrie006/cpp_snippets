// This is method 1 - Pascal triangle method
// nCr is C[n][r]


const int maxncr = 31;
long long C[maxncr + 1][maxncr + 1];
void init_ncr(){
	C[0][0] = 1;
	for (int n = 1; n <= maxncr; ++n) {
		C[n][0] = C[n][n] = 1;
		for (int k = 1; k < n; ++k)
			C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
	}
}





//  This is method2, use it when N is greater and we take mod of values

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
