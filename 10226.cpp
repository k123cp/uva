#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    int testcase;

    cin >> testcase;
    getchar();
	getchar();
    while ( testcase-- )
    {
        map<string, int> trees;
        string species;
        int totalTree = 0;
        while ( getline(cin, species) )
        {
            if ( species == "" )
                break;
            trees[species]++;
            totalTree++;
        }
        for( map<string, int>::iterator it = trees.begin(); it != trees.end(); it++ )
        {
            cout << it->first << " " << fixed << setprecision(4) << it->second*100.0/totalTree << endl;
        }
        if (testcase)
            puts("");
    }
    return 0;
}
