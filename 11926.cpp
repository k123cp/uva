#include <iostream>
#include <bitset>
#include <cstring>

using namespace std;

bool active[1000000];

int main()
{
    int n, m, x, y, c;

    while ( cin >> n >> m && (n != 0 || m != 0) )
    {
        int flag = 0;
        memset(active, 0, sizeof(active));
        for( int i = 0; i < n; i++ )
        {
            if ( flag )
                break;
            cin >> x >> y;
            for( int j = x; j < y; j++ )
            {
                if ( active[j] )
                {
                    flag = 1;
                    break;
                }
                active[j] = true;
            }
        }
        for( int i = 0; i < m; i++ )
        {
            if ( flag )
                break;
            cin >> x >> y >> c;
            for( int j = x; j < y && j < 1000000; j++ )
            {
                if ( active[j] )
                {
                    flag = 1;
                    break;
                }
                active[j] = true;
                x += c, y += c;
                if (flag)
                    break;
            }
        }
        puts(flag ? "CONFLICT" : "NO CONFLICT");
    }
    return 0;
}
/*
#include <stdio.h>
#include <string.h>

bool active[1000000];
int main() {
    int n, m, i, j, k, x, y, c;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if (!n && !m)
            break;
        int flag = 0;
        memset(active, 0, sizeof(active));
        for( i = 0; i < n; i++ )
        {
            scanf("%d %d", &x ,&y);
            if (!flag)
            {
                for( j = x; j < y; j++ )
                {
                    if (active[j])
                    {
                        flag = 1;
                        break;
                    }
                    active[j] = true;
                }
            }
        }
        for( i = 0; i < m; i++ )
        {
            scanf("%d %d %d", &x ,&y, &c);
            if (!flag)
            {
                for( k = 0; x < 1000000; k++ )
                {
                    for( j = x; j < y && j < 1000000; j++ )
                    {
                        if (active[j])
                        {
                            flag = 1;
                            break;
                        }
                        active[j] = true;
                    }
                    x += c, y += c;
                    if (flag)
                        break;
                }
            }
        }
        puts(flag ? "CONFLICT" : "NO CONFLICT");
    }
    return 0;
}
*/
