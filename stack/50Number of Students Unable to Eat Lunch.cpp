The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.

 

Example 1:

Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
Output: 0 
Explanation:
- Front student leaves the top sandwich and returns to the end of the line making students = [1,0,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,0,1,1].
- Front student takes the top sandwich and leaves the line making students = [0,1,1] and sandwiches = [1,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [1,1,0].
- Front student takes the top sandwich and leaves the line making students = [1,0] and sandwiches = [0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,1].
- Front student takes the top sandwich and leaves the line making students = [1] and sandwiches = [1].
- Front student takes the top sandwich and leaves the line making students = [] and sandwiches = [].
Hence all students are able to eat.
Example 2:

Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
Output: 3
 

Constraints:

1 <= students.length, sandwiches.length <= 100
students.length == sandwiches.length
sandwiches[i] is 0 or 1.
students[i] is 0 or 1.  



class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        stack<int>s;
        for(int i=sandwiches.size()-1;i>=0;i--){
            s.push(sandwiches[i]);
        }
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }

        int c=0;bool flag=true;

        while(!q.empty() ){
            if(c==q.size())return q.size();
        if(q.front()==s.top()){
            s.pop();
            q.pop();
            c=0;
        }
        else {
            q.push(q.front());
            q.pop();
            c++;
        }
        
        }
        return q.size();

    }
};




tc=O(N) but sc=O(N);

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
     int squareStud=0,circleStud=0;
     for(int ele:students){
        if(ele==1) squareStud++;
        else circleStud++;
     }
     for(int i:sandwiches){
        if(i==1){
            if(squareStud>0)squareStud--;
            else break;
        }
        if(i==0){
            if(circleStud>0)circleStud--;
            else break;
        }
     }
     return squareStud+circleStud;

    }
};


tc=O(n) abd sc=o(1)

