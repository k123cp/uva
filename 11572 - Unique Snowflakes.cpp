#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

#define maxn (int)(1e9)+1

int t, n, x, ans, cnt, block;
map<int, int> lastseen; //keep track of the index of the last occurence of each flake
//cnt: the number of uniqur snowflakes seen so far
//block: index of the last snowflake that wasn't unique
int main() {
    cin >> t;
    while (t--) 
    {
        cin >> n;
        lastseen.clear();
        ans = 0, cnt = 0, block = 0;
        for( int i = 1; i <= n; i++ ) 
        {
            cin >> x;
            int lx = lastseen[x]; 1 2 3 2 1
            if ( lx != 0 ) //if a snowflake that is not unique is found
            {
                block = max(block, lx); //updates block to the most recent collision
                cnt = i - block - 1; //resets cnt to the number of snowflakes between
                                     //the most recent conflict and the current index
            }
            cnt++;
            lastseen[x] = i;//last occurence of snowflake x
            ans = max(ans, cnt);
        }
        cout << ans << '\n';
    }
}
