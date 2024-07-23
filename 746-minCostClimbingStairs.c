// Dynamic Programming baby

int min(int a, int b)
{
	if ( a > b)
		return b ;
	else
		return a ;
}

int minCostClimbingStairs (int* cost, int costSize)
{
	int* dp = (int *) malloc (costSize * sizeof(int)) ;
	dp[0] = cost[0] ;
	dp[1] = cost[1] ;

	for (int i = 2 ; i < costSize ; i++ )
	{
		dp[i] = min(dp[i-1], dp[i-2]) + cost[i] ;
	}
	int result = min (dp[costSize - 1], dp[costSize - 2]) ;
	free(dp) ;
	return result ;
}

int main()
{
	// include testcases if you want to run
}
