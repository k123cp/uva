#include <iostream>
#include<cstdio>
#include <algorithm>
#include<map>

using namespace std;

int main()
{
    int n, subs[5];
    char buf[20];
    while ( cin >> n && n != 0 )
    {
        int subs[5];
        string str;
        map<string, int> record;
        while ( n-- )
        {
            cin >> subs[0] >> subs[1] >> subs[2] >> subs[3] >> subs[4];
            sort(subs, subs+5);
            sprintf(buf, "%d%d%d%d%d", subs[0], subs[1], subs[2], subs[3], subs[4]);
            str = buf;
            record[str]++;
        }
        int maximum = 0, maxNum = 0;
        for( map<string, int>::iterator it = record.begin(); it != record.end(); it++ )
        {
            if ( it->second > maximum )
                maximum = it->second, maxNum = 0;
            if ( it->second == maximum )
                maxNum += maximum;
        }
        cout << maxNum << endl;
    }
    return 0;
}
