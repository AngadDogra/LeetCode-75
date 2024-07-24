int memo[101][101];

int getRoutes(int y, int x, int m, int n)
{
    if (y == m || x == n)
        return 0;
    if (y == m - 1 && x == n - 1)
        return 1;
    
    if (memo[y][x] != -1)
        return memo[y][x];

    int right = getRoutes(y, x + 1, m, n);
    int down = getRoutes(y + 1, x, m, n);
    memo[y][x] = right + down;
    return memo[y][x];
}

int uniquePaths(int m, int n){
    memset(memo, -1, sizeof(memo));
    return getRoutes(0, 0, m, n);
}