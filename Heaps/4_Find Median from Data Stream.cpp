#include<bits/stdc++.h>
using namespace std;



/*
    //tc =o(n log n) for finding meadina
    //o(1) for insertion

class MedianFinder {
public:
    vector<int>v;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        v.push_back(num);
    }
    
    double findMedian() {
        sort(v.begin(),v.end());
        int n=v.size();
        double med;
        if(n%2==0){
                med=(v[n/2-1]+v[n/2])/2.0;
        }else{
            med=v[n/2];
        }
        med=round(med*10)/10.0;
    return med;
    }
};
*/



/*
addNum(int a):  O(logn) 

findMedian(): O(1)
*/
class MedianFinder {
public:
    priority_queue<int>smaller_list;//max heap;
    priority_queue<int,vector<int>,greater<>> larger_list;//min heap;
    MedianFinder() {
        
    }
    
    void addNum(int a) {
       if(smaller_list.empty() || (!smaller_list.empty()&&a<=smaller_list.top())) smaller_list.push(a);
       else larger_list.push(a);

       //balance them;
       int ss=smaller_list.size(),ls=larger_list.size();
        if(ss>ls+1){
            larger_list.push(smaller_list.top());
            smaller_list.pop();
        }else if(ls>ss){
            smaller_list.push(larger_list.top());
            larger_list.pop();
        }


           }
    
    double findMedian() {
      if((smaller_list.size()+larger_list.size()) %2!=0)return smaller_list.top();
        else {
            return (smaller_list.top()+larger_list.top())/2.0;
        }
    }
};

