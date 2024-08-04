You are given timings of n meetings in the form of (start[i], end[i]) where start[i] 
is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum 
number of meetings that can be accommodated in a single meeting room, when only one meeting can be 
held in the meeting room at a particular time. 
Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Examples :
Input: n = 6, start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)
  x-------------------------------------------------x-----------------------------x----------------------------------------------------x
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end());
        int c=1,d=v[0].first;
        for(int i=1;i<n;i++){
            if(v[i].second > d){
                d=v[i].first;
                c++;
            }
        }
        return c;
    }
};
