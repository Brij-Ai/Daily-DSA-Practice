#include <queue>
using namespace std;
class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        // A good question
        queue<int> studentQue;
        for (int x : students)
            studentQue.push(x);
        int n = students.size();
        int counter = 0; // for the avoiding infinite loop;
        int i = 0;       // iterating over sandwiches stack
        while (!studentQue.empty() and counter != studentQue.size())
        {
            if (studentQue.front() == sandwiches[i])
            {
                i++;
                studentQue.pop();
                counter = 0;
            }
            else
            {
                // does not like the sandwiche shape by the student
                // Go back the end of queue
                int go_End = studentQue.front();
                studentQue.pop(); // remove from front and go back the end
                studentQue.push(go_End);
                counter++; // for preventing the infinte loop
            }
        }
        return studentQue.size();
    }
};