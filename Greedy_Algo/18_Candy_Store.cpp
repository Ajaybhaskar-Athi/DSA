//18_Find the minimum and maximum amount to buy all N candies.cpp
//geek for geeks

#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
            
        int calc(int candies[],int N,int K){
              int x=0;
        int i=0,j=N-1;
        while(i<=j){
                x+=candies[i];
                j-=K;
                i++;
        }
        return x;
        }

    vector<int> candyStore(int candies[], int N, int K)
    {  
        // Write Your Code here
        sort(candies,candies+N);
        int mini=calc(candies,N,K);
        sort(candies,candies+N,greater<>());
        int maxi=calc(candies,N,K);
      
        
        
        return {mini,maxi};
    }

};



//METHOD 2 : instead of sorting in both ascendinga and descending . jsut sort one time and find both values



class Solution
{
public:
            
        
        int findMin(int candies[],int N,int K){
              int x=0;
        int i=0,j=N-1;
        while(i<=j){
                x+=candies[i];
                j-=K;
                i++;
        }
        return x;
        }
        
          int findMax(int candies[],int N,int K){
              int maxi=0;
        int i=0,j=N-1;
        while(j>=i){
                maxi+=candies[j];
                i+=K;
                j--;
        }
        return maxi;
        }


    vector<int> candyStore(int candies[], int N, int K)
    {  
        sort(candies,candies+N);
        int mini=findMin(candies,N,K);
        int maxi=findMax(candies,N,K);
      
        
        
        return {mini,maxi};
    }

};
