// There are n 1-indexed robots, each having a position on a line, health, and movement direction.
// You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] 
// is either 'L' for left or 'R' for right). All integers in positions are unique.
// All robots start moving on the line simultaneously at the same speed in their given directions. 
// If two robots ever share the same position while moving, they will collide.
// If two robots collide, the robot with lower health is removed from the line, and the health of the 
// other robot decreases by one. The surviving robot continues in the same direction it was going. 
// If both robots have the same health, they are both removed from the line.
// Your task is to determine the health of the robots that survive the collisions, 
// in the same order that the robots were given, i.e. final heath of robot 1 (if survived), 
// final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.
// Return an array containing the health of the remaining robots (in the order they were 
// given in the input), after no further collisions can occur.

// Note: The positions may be unsorted.

Example 1:
Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
Output: [2,17,9,15,10]
Explanation: No collision occurs in this example, since all robots are moving in the same direction. 
So, the health of the robots in order from the first robot is returned, [2, 17, 9, 15, 10].

x----------------------------------------------------------x-----------------x-------------------------------------------x
  
class Solution {
public:
    using int2=pair<int, int>;// (position, idx)
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string& directions) {
        const int n=positions.size();
        vector<int2> robot(n);
        for(int i=0; i<n; i++)// 0-indexed is fine
            robot[i]={positions[i], i};
        sort(robot.begin(), robot.end());

        int stack[n], top=-1;
        for(auto& [_, i]: robot){
            if (directions[i]=='R') stack[++top]=i;
            else{
                while(top!=-1 && healths[i]>0){
                    int j=stack[top];
                    int x=healths[j]-healths[i];
                    if (x>0) healths[j]--, healths[i]=0;
                    else if (x<0) healths[j]=0, healths[i]--, top--;
                    else healths[i]=healths[j]=0, top--;
                }
            }
        }
        vector<int> ans;
        for(int x: healths)
            if (x>0) ans.push_back(x);
        return ans;
    }
};
