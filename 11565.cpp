#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int T, a, b, c;
    cin >> T;
    while ( T-- )
    {
        cin >> a >> b >> c;
        for( int x = -sqrt(c); x < sqrt(c); x++ )
        {
            for( int y = -sqrt(c); y < sqrt(c); y++ )
            {
                for( int z = -sqrt(c); z < sqrt(c); z++ )
                {
                    if ( x + y + z == a && x*y*z == b && x*x + y*y + z*z == c )
                    {
                        if ( x != y && y != z && z != x)
                        {
                            cout << x << " " << y << " " << z << endl;
                            goto label;
                        }
                    }
                }
            }
        }
        cout << "No solution." << endl;
        label:
            continue;
    }
    return 0;
}
