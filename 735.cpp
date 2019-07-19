#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool check(int a)
{
    if ( (0 <= a && a <= 20) || a == 50 )
        return true;
    else if ( 20 <= a && a <= 40 && a % 2 == 0 )
        return true;
    else if ( 20 <= a && a <= 60 && a % 3 == 0 )
        return true;
    return false;
}

vector<int> caseResult, potentialCombo;
vector<vector<int>> results;

int main(){
	int score, permutations = 0;
    set<vector<int>> combos;

	while ( cin >> score && score > 0 )
    {
        if ( score > 180 )
            goto label;
        for( int j = 0; j <= 60; j++ )
        {
            for( int k = 0; k <= 60; k++ )
            {
                for( int l = 0; l <= 60; l++ )
                {
                    if ( j + k + l == score && check(j) && check(k) && check(l) )
                    {
                        potentialCombo.push_back(j);
                        potentialCombo.push_back(k);
                        potentialCombo.push_back(l);
                        sort(potentialCombo.begin(), potentialCombo.end());
                        combos.insert(potentialCombo);
                        potentialCombo.clear();
                        permutations++;
                        break;
                    }
                }
            }
        }
        label:
            caseResult.push_back(score);
            caseResult.push_back(combos.size());
            caseResult.push_back(permutations);
            results.push_back(caseResult);
            caseResult.clear();
            combos.clear();
            permutations = 0;
    }

    for( int i = 0; i < results.size(); i++ )
    {
        if ( results[i][1] == 0 )
            cout << "THE SCORE OF " << results[i][0]
            << " CANNOT BE MADE WITH THREE DARTS." << '\n';
        else
        {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << results[i][0] << " IS "
            << results[i][1] << "." << '\n';
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << results[i][0] << " IS "
            << results[i][2] << "." << '\n';
        }
        for( int j = 0; j < 70; j++ )
            cout << "*";
        cout << '\n';
    }
    cout << "END OF OUTPUT\n";
	return 0;
}
