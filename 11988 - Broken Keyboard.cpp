#include <iostream>
#include <list>

using namespace std;

#define maxn 1000005

string s;
list<char> chars;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while ( cin >> s )
    {
        chars.clear();
        list<char> :: iterator it = chars.begin();
        for( char c : s )
        {
            if ( c == '[' ) it = chars.begin();
            else if ( c == ']') it = chars.end();
            else chars.insert(it, c);
        }

        for ( auto v : chars )
            cout << v;
        cout << '\n';
    }
    return 0;
}

