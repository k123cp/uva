#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> row;
vector<vector<int>> grid;
vector<int> closestDists;

int main()
{
    int T, ia, minSteps = 1000000;
    char input;
    while ( cin >> T )
    {
        for( int i = 0; i < T; i++ )
        {
            for( int j = 0; j <= T; j++ )
            {
                scanf("%c", &input);
                if ( input - '0' != -38)
                {
                    ia = input - '0';
                    row.push_back(ia);
                }
            }
            grid.push_back(row);
            row.clear();
        }
        for( int i = 0; i < T; i++ )
        {
            for( int j = 0; j < T; j++ )
            {
                if ( grid[i][j] == 1 )
                {
                    for( int k = 0; k < T; k++ )
                    {
                        for( int l = 0; l < T; l++ )
                        {
                            if ( grid[k][l] == 3 )
                                if ( minSteps > abs(k - i) + abs(l - j) )
                                    minSteps = abs(k - i) + abs(l - j);
                        }
                    }
                    closestDists.push_back(minSteps);
                    minSteps = 1000000;
                }
            }
        }
        sort(closestDists.begin(), closestDists.end());
        cout << closestDists[closestDists.size() - 1] << endl;
        grid.clear();
        closestDists.clear();
        minSteps = 1000000;
    }
    return 0;
}
