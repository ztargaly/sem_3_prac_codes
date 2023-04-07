#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#define pb push_back
using namespace std;
int N = 7;
int DP[100][100];
int b[100][100];
int nodes[] = {0, 1, 2, 3, 4, 5, 6, 7};
int freq[] = {0, 4, 2, 1, 3, 5, 2, 1};
int sums[10];
int P(int from, int to)
{
    return sums[to] - sums[from-1];
}
int rec(int from, int to)
{
    if(from > to) return 0;
    if(from == to) return freq[from];
    if(DP[from][to] != -1) return DP[from][to];

    int optimal = 1 << 29;
    for(int i = from; i <= to; ++i)
    {
        int current = rec(from, i-1) + rec(i+1, to) + P(from, to);
        if(current < optimal)
        {
            optimal = current;
            b[from][to] = i;
        }
    }
    DP[from][to] = optimal;
    return optimal;
}
void print(int from, int to)
{
    if(from == to) b[from][to] = from;
    if(b[from][to] == -1) return;
    cout<<"root between "<<from<<" and "<<to<<": "<<(char) (b[from][to] + 'A' -1)<<endl;
    print(from, b[from][to]-1);
    print(b[from][to] + 1, to);
}
int main()
{
    for(int i = 1; i <= N; ++i)
    {
        sums[i] = sums[i-1] + freq[i];
    }
    fill(&DP[0][0], &DP[0][0] + 100*100, -1);
    fill(&b[0][0], &b[0][0] + 100*100, -1);
    int res = rec(1, N);
    cout<<"Minimal value: "<<res<<endl;
    print(1, N);
    return 0;
}