#include <iostream>

using namespace std;

struct car{
    int time, in;
    car(int x, int y)
    {
        time = x;
        in = y;
    }
};

int main()
{
    int c, n, t, m, arriveTime;
    string side;
    stack<car> LEFT, RIGHT;
    
    cin >> c;
    while ( c-- )
    {
        int currTime = 0, isLeft = 1, carsOnFerry = 0;
        cin >> n >> t >> m;
        for( int i = 0; i < m; i++ )
        {
            cin >> arriveTime >> side;
            if ( side == "left" )
                LEFT.push(car(arriveTime, i));
            else RIGHT.push(car(arriveTime, i));
        }
        int res[10000];
        while ( !L.empty() || !R.empty )
        {
            if ( isLeft )
            {
                while( carsOnFerry < n && !LEFT.empty() && LEFT.front().time <= currTime)
                {
                    carsOnFerry++;
                    res[LEFT.front().in] = currTime + time; 
                    LEFT.pop();
                }
                if ( carsOnFerry ) // there is at least 1 car on the ferry, goto either
                { 
                    currTime += t;
                    isLeft = 1 - isLeft;
                    continue;
                }
                // if no car on ferry
                if ( RIGHT.empty() || ( !LEFT.empty() && LEFT.front().time <= RIGHT.front().time ) ) //if (no car on right bank OR car coming up on left)
                {
                    currTime = LEFT.front().time;// wait for a car on the left
                    while ( carsOnFerry < n && !LEFT.empty() && LEFT.front().time <= currTime )
                    {
                        carsOnFerry++; 
                        res[LEFT.front().in] = currTime + t; 
                        LEFT.pop();
                    }
                    currTime += t;
                } 
                else 
                {
                    if ( !RIGHT.empty() || LEFT.empty() && LEFT.front().t > RIGHT.front().t ) 
                        currTime = max(RIGHT.front().time, currTime) + t;//max tricky
                    else
                        currTime += t; //
                }
            }
        }
    }
}
