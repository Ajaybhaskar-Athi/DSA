// You have given a 2-dimensional array ‘ARR’ with ‘N’ rows and ‘M’ columns in which each element contains only two values,i.e., 0 and 1. Your task is to convert the given matrix into the Good matrix in which if an element is 0, you need to set all elements values present in its entire row and column to 0.

// For example:


// Explain
// Consider ARR = [[1 , 0 , 1] ,
//                 [1 , 1 , 1] , 
//                 [1 , 1 , 1]], 
// the Good matrix after updating the given matrix as described in the question is  
//                 [[0 , 0 , 0] , 
//                  [1 , 0 , 1] , 
//                  [1 , 0 , 1]]. 
// Since ARR[0][1] is 0, we need to set all element’s values present in 0-th row and 1-th column to 0.
// Note :

// You do not need to print the matrix. Just change in the given input.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :

// Explain
// 1 <= T <= 20
// 1 <= N <= 300
// 1 <= M <= 300

// ARR[i][j] can only contain two values, i.e, 0 and 1.    

//  Where 'T' denotes the number of test cases, 'N' and 'M' denotes the number of rows and the number of columns in the array ‘ARR’ respectively, and 'ARR[i][j]' denotes the ’j-th’ element of  'i-th' row of the array 'ARR'. 

// Time Limit: 1sec
// Sample Input 1 :

// Explain
// 2
// 2 2 
// 0 1 
// 1 1
// 3 3
// 1 1 0
// 1 1 1 
// 1 1 1
// Sample Output 1 :

// Explain
// 0 0
// 0 1
// 0 0 0
// 1 1 0
// 1 1 0
// Explanation of sample input 1:

// Explain
// For the first test case, 
// The Good matrix after updating the given matrix as described in the question is  
//                     [[0 , 0] , 
//                      [0 , 1]]. 
// Since ARR[0][0] is 0, we need to set all elements value present in 0-th row and 0-th column to 0.

// For the second test case,
// The Good matrix after updating the given matrix as described in the question is  
//                     [[0 , 0 , 0] , 
//                      [1 , 1 , 0] , 
//                      [1 , 1 , 0]]. 
// Since ARR[0][2] is 0, we need to set all elements value present in 0-th row and 2-th column to 0.
// Sample Input 2 :

// Explain
// 2
// 4 4 
// 1 1 1 1   
// 0 1 1 1
// 1 1 1 1
// 0 1 1 1
// 3 3
// 0 1 1
// 0 1 1 
// 1 1 1
// Sample Output 2 :

// Explain
// 0 1 1 1
// 0 0 0 0
// 0 1 1 1
// 0 0 0 0
// 0 0 0
// 0 0 0
// 0 1 1


// method 1
vector<vector<int>> findGoodMatrix(vector<vector<int>>&arr){
    int rs=arr.size();//row size
    int cs=arr[0].size();//col size
    for(int i=0;i<rs;i++){
    for(int j=0;j<cs;j++){
        if(arr[i][j]==0){
3.
            for(int k=0;k<arr.size();k++){
                if(arr[i][k]!=0)arr[i][k]=-1;
                // we r making all row to -1 except the element which is 0.since in future while
                // we r iterating through that elemment we need to amke that positon row and col also to -1;
            }
            for(int x=0;x<cs;x++){
                if(arr[k][j]!=0)arr[k][j]=-1;
            }
        }

    }
    }
//we mmarked to all elemtns to -1 so chaage that to 0;

for(int i=0;i<rs;i++){
    for(int j=0;j<cs;j++){
        if(arr[i][j]==-1)arr[i][j]=0;
    }
}
return arr;

}

//method 2 
//both r having same tc but this method uses extra space also


vector<vector<int>> findGoodMatrix(vector<vector<int>>&arr){
    int rs=arr.size();
    int cs=arr[0].size();
    vector<bool> zeroRows(rs,false);
    vector<bool>zeroCols(cs,false);
    for(int i=0;i<rs;i++){
        for(int j=0;j<cs;j++){
            if(arr[i][j]==0){
                zeroRows[i]=true;
                zeroCols[j]=true;
            }
        }
    }
    for(int i=0;i<rs;i++){
        if(zeroRows[i]){
            for(int j=0;j<cs;j++){
                arr[i][j]=0;
            }
        }
    }
    for(int j=0;j<cs;j++){
        if(zeroCols[j]){
            for(int i=0;i<rs;i++){
                arr[i][j]=0;
            }
        }
    }
    return arr;

}