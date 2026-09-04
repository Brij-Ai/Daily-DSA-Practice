#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        queue<int> sen, direIndx, redIndx;

        for (int i = 0; i < senate.size(); i++)
        {
            sen.push(i);
            if (senate[i] == 'D')
                direIndx.push(i);
            else
                redIndx.push(i);
        }

        while (sen.size() > 1)
        {
            // Skippin Vote all ready canceled his right by another
            if (senate[sen.front()] == 'X')
            {
                sen.pop();
            }
            // Checking for Radiant
            else if (senate[sen.front()] == 'R')
            {
                // Check for victory Radiant
                if (direIndx.empty())
                    return "Radiant";
                else
                { // Take rights of next D
                    senate[direIndx.front()] = 'X';
                    direIndx.pop();
                    // Next of R
                    sen.push(sen.front());
                    sen.pop();
                    // next of R
                    redIndx.push(redIndx.front());
                    redIndx.pop();
                }
            }
            // Checking for Dire
            else
            { // senate[senIndx.front()] == 'D'
                // Check for victory of Dire
                if (redIndx.empty())
                    return "Dire";
                else
                { // Take rights of next R
                    senate[redIndx.front()] = 'X';
                    redIndx.pop();
                    sen.push(sen.front());
                    sen.pop();
                    direIndx.push(direIndx.front());
                    direIndx.pop();
                }
            }
        }
        if (senate[sen.front()] == 'D')
            return "Dire";
        return "Radiant";
    }
};