#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

// It is a bad practice to use global variabble in Software Engineering
// But it is ok for competitve programming
int N, target;
double dist[20][20], memo[ 1 << 16];    // 1 << 16 = 2^16

double matching(int bitmask) {
    // DP staate = bitmask
    // We initialize memo with -1
    if(memo[bitmask] > -0.5) {  // This state has been computed before
        return memo[bitmask];   // Just look at the memo table
    }
    if(bitmask == target) { // All stidents are already matched , the cost is 0
        return memo[bitmask] = 0;
    }

    double ans = 2000000000000000000.0;
    int p1,p2;
    for(p1=0; p1 < 2*N; p1++) {
        if(!(bitmask & (1 << p1)))  // Find the first bit that is off
            break;
    for(p2 = p1 + 1; p2 < 2*N; p2++) {
        if(!(bitmask & (1 << p2)))  // Check the first off bit
            // Pick the minimum
            ans = min(ans, dist[p1][p2] + matching(bitmask | (1 << p1) | (1 << p2)));
    }
    return memo[bitmask] = ans; // Store results in memo table and return
    }
}

// Driver program
auto main() -> int {
    int i,j, caseNo = 1, x[20], y[20];
    // redirect file to stdin
    // freopen("10011.txt", 'r', stdin)
    while(scanf("%d", &N), N) {
        for(i = 0; i< 2*N; i++)
            scanf("%*s, %d, %d", &x[i], &y[i]); // Skip names %*s does same
        for(i=0; i< 2*N; i++)
            for(j=i+1; j< 2*N; j++)
                dist[i][j] = dist[j][i] = hypot(x[i] - x[j], y[i] - y[j]);
        // usee DP to solve min weighted perfect matching on small general graph
        for(i =0; i< (1 << 16); i++)
            memo[i] = -1;
        target = (1 << (2 * N)) - 1;
        printf("Case %d: %.2lf\n", caseNo++, matching(0));
    }
    return 0;
}
