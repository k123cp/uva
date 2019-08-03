#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int numOfStacks = 1, j, c = 0;
    string in;
    vector<stack<char>> stacks;
    stack<char> indiStack;

    while ( cin >> in && in != "end" )
    {
        c++;
        indiStack.push(in[0]);
        stacks.push_back(indiStack);
        indiStack.pop();
        for( int i = 1; i < in.length(); i++ )
        {
            for( j = 0; j < numOfStacks; j++ )
            {
                if ( in[i] > stacks[j].top() ) continue;
                else
                {
                    stacks[j].push(in[i]);
                    break;
                }
            }
            if ( j >= numOfStacks )
            {
                indiStack.push(in[i]);
                stacks.push_back(indiStack);
                indiStack.pop();
                numOfStacks++;
            }
            j = 0;
        }
        cout << "Case " << c << ": " << numOfStacks << '\n';
        numOfStacks = 1;
        stacks.clear();
    }
    return 0;
}
