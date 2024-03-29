#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int row[8], TC, a, b, lineCounter;

bool place(int r, int c)
{
    for(int prev = 0; prev < c; prev++) //check previously placed queens
        if ( row[prev] == r || abs(row[prev]-r) == abs(prev-c) )
            return false; //share same row or diagonal
    return true;
}

void backtrack(int c) //try placing a queen on col c
{
    if ( c == 8 ) //candidate sol,
    {             //has placed queens on all 8 rows
        printf("%2d      %d", ++lineCounter, row[0] + 1);       //
        for( int j = 1; j < 8; j++ ) printf(" %d", row[j] + 1); //print
        printf("\n");                                           //
    }
    for( int r = 0; r < 8; r++ ) //try all possible row
    {
        if ( r >= b && row[b] != a ) break; //if (a, b) does not have queen
        if ( place(r, c) ) //if can place a queen at this col and row
        {
            row[c] = r; backtrack(c + 1);   //put this queen here and recurse
        }
    }
}

int main()
{
    scanf("%d", &TC);
    while (TC--)
    {
        scanf("%d %d", &a, &b); a--; b--;
        memset(row, 0, sizeof row); lineCounter = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(0);
        if (TC) printf("\n");
    }
    return 0;
}

