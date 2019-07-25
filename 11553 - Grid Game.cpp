/*
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<int> oneResult, num;
    vector<vector<int>> caseResult;
    vector<vector<vector<int>>> results;

    while ( cin >> n && n != 0 )
    {
        num.push_back(n);
        for( int fghij = 1234; fghij < 98765 / n; fghij++ )
        {
            int abcde = fghij * n;
            int tmp, used = (fghij < 10000);
            tmp = abcde;
            while (tmp)
            {
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            tmp = fghij;
            while (tmp)
            {
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            if ( used == ( 1 << 10 ) - 1 )
            {
                oneResult.push_back(abcde);
                oneResult.push_back(fghij);
                caseResult.push_back(oneResult);
                oneResult.clear();
            }
        }
        results.push_back(caseResult);
        caseResult.clear();
    }

    for( int i = 0; i < results.size(); i++ )
    {
        if ( results[i].size() == 0 )
            cout << "There are no solutions for " << num[i] << ".";
        else
        {
            for( int j = 0; j < results[i].size(); j++  )
            {
                printf("%0.5d / %0.5d = %d", results[i][j][0], results[i][j][1], num[i]);
                if ( j < results[i].size() - 1 )
                    cout << '\n';
            }
        }
        if ( i < results.size() - 1 )
            cout << "\n\n";
    }
    return 0;
}
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, num = 0;
    vector<int> oneResult;
    vector<vector<int>> caseResult;
    vector<vector<vector<int>>> results;

    while ( cin >> n && n != 0 )
    {
        for( int fghij = 1234; fghij < 98765 / n; fghij++ )
        {
            int abcde = fghij * n;
            int tmp, used = (fghij < 10000);
            tmp = abcde;
            while (tmp)
            {
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            tmp = fghij;
            while (tmp)
            {
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            if ( used == ( 1 << 10 ) - 1 )
            {
                num++;
                printf("%0.5d / %0.5d = %d\n", fghij, abcde, n);
            }
        }
        if ( num == 0 )
            cout << "There are no solutions for " << n << ".\n";
        num = 0;
        cout << endl;
    }

    return 0;
}
