#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, m, c, carLength, ferryLength;
    queue<int> carsLeft, carsRight;
    string side;
    cin >> c;
    while ( c-- )
    {
        int crossings = 0, isLeft = 1;
        cin >> l >> m;
        l *= 100;
        ferryLength = l;
        while ( m-- )
        {
            cin >> carLength >> side;
            if ( side == "left" )
                carsLeft.push(carLength);
            else carsRight.push(carLength);
        }

        while ( !carsLeft.empty() || !carsRight.empty() )
        {
            if ( isLeft )
            {
                while ( l >= carsLeft.front() && !carsLeft.empty() )
                {
                    l -= carsLeft.front();
                    carsLeft.pop();
                }
                isLeft = 0;
                l = ferryLength;
            }
            else
            {
                while ( l >= carsRight.front() || !carsRight.empty() )
                {
                    l -= carsRight.front();
                    carsRight.pop();
                }
                isLeft = 1;
                l = ferryLength;
            }
            crossings++;
        }
        cout << crossings << '\n';
        crossings = 0;
    }
    return 0;
}
