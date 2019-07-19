/*#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
#include <algorithm>

using namespace std;

long long main()
{
    long long t, lines, value;
    vector<long long> grid;

    while ( t-- )
    {
        cin >> lines;
        for( long long i = 0; i < lines; i++ )
        {
            cin >> value;
            grid.push_back(value);
        }
    }
    return 0;
}
*/
#include <iostream>
#include <vector>

using namespace std;

vector<long long> results;
vector<long long> coefficients;

long long power(long long n, long long i)
{
    if ( i == 0 )
        return 1;
    if ( i == 1 )
        return n;
    if ( i % 2 == 0 )
        return power(n*n, i / 2);
    return n*power(n*n,(i-1)/2);
}

int main()
{
    long long caseResult = 0;
    long long T, highestPower, coef, d, orgD, k, n = 1;

    cin >> T;
    while ( T-- )
    {
        cin >> highestPower;
        for( long long i = 0; i <= highestPower; i++ )
        {
            cin >> coef;
            coefficients.push_back(coef);
        }
        cin >> d >> k;
        orgD = d;
        while ( k > d )
        {
            n++;
            k -= d;
            d += orgD;
        }
        for( long long i = 0; i <= highestPower; i++ )
        {
            caseResult += coefficients[i] * power(n, i);
        }
        coefficients.clear();
        results.push_back(caseResult);
        caseResult = 0;
        n = 1;
    }

    for( long long i = 0; i < results.size(); i++ )
    {
        cout << results[i];
        if ( i < results.size() - 1 )
            cout << '\n';
    }
    return 0;
}
