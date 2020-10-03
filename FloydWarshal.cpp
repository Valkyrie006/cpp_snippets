//Floyd-Warshal algorithm is an all-pairs shortest path algorithm using dynamic programming.
//Time Complexity - O(n^3)
const int maxN = 1e3+5;
long long d[maxN][maxN];

void FloydWarshal()
{
	//If graph d is given in matrix form where d[i][i] = 0
	//and rest uninitialized are INT_MAX
	for(long long k = 1; k <= n; k++)
	{
		for(long long i = 1; i <= n; i++)
		{
			for(long long j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
		}
	}
}
	
