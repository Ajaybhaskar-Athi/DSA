// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     map<int,int>mp;
//     vector<int>v={1,2,1,2,1,1,1,5};
//     for(int ele:v){
      
//       auto it=mp.find(ele);
//       if(it==mp.end()){
//         mp.insert({ele,1});
//       }
//       else{
//         it->second++;
//       }
//     }
//     for(auto it:mp){
//         if(it.second>v.size()/2){
//         cout<<it.first<<" "<<it.second<<endl;
//     }
//     }


// }


// #include<bits/stdc++.h>
// using namespace std;
// class llist{
//   public:
//   int data;
//   llist*next;
//   llist(int data){
//     this->data=data;
//     next=NULL;
//   }
// };
// llist*make(llist*head,int data){
//   llist*nn=new llist(data);
//     if(head==NULL){
//     head=nn;
//     }
//     else{
//       llist*temp=head;
//       while(temp->next!=NULL){
//         temp=temp->next;
//       }
//       temp->next=nn;
//     }
//     return head;


// }
// void print(llist*head){
//   llist*temp=head;
//   while(temp!=NULL){
//     cout<<temp->data;
//     if(temp->next!=NULL)cout<<"->";
//     temp=temp->next;
//   }
// }
// int main(){
//   int n;
//   cin>>n;
//   llist*head=NULL;
//   for(int i=0;i<n;i++){
//     int data;
//     cin>>data;
//   head=make(head,data);
//   }
//   print(head);
// }

// #include<bits/stdc++.h>
// using namespace std;
// class llist{
//   public:
//   int data;
//   llist*next;
//   llist(int val):data(val),next(NULL){}

// };
// llist*make(llist*head){
//   int n;cin>>n;
//   int i=0;
//       llist*temp=NULL;
//   while(i<n){
//     int d;cin>>d;
//     llist*nn=new llist(d);

//     if(head==NULL){
//       head=temp=nn;
//       i++;
//     }
//     else{
//     temp->next=nn;
//     temp=nn;
//     i++;
//     }
//   }
//   return head;
// }
// void print(llist*head){
//   llist*temp=head;
//   while(temp!=NULL){
//     cout<<temp->data;
//     if(temp->next!=NULL)cout<<"->";
//     temp=temp->next;
//   }

// }
// llist*insert_end(llist*head,int data){
//   llist*nn=new llist(data);
//   if(head==NULL)return nn;
//   llist*temp=head;
//   while(temp->next!=NULL)temp=temp->next;
//   temp->next=nn;
//   return head;
// }
// llist*insert_start(llist*head,int data){
//   llist*nn=new llist(data);
//   if(head==NULL)return nn;
//   nn->next=head;
//   head=nn;
//   return head;
// }
// llist*insert(llist*head,int pos,int data){
//   llist*temp=head;
//   llist*nn=new llist(data);
//   if(pos==1){
//     head=insert_start(head,data);
//     return head;
//   }
//   pos--;
//   while(pos>1){
//     temp=temp->next;
//     pos--;
//   }
//   llist*temp2=temp->next;
//   temp->next=nn;
//   nn->next=temp2;
//   return head;


// }
// llist*del_pos(llist*head,int pos){
//   if(pos==1)return head->next;
//   llist*temp=head;
//   pos--;
//   while(pos>1){
//     temp=temp->next;
//     pos--;
//   }
//   temp->next=temp->next->next;
//   return head;
// }
// llist*del_entire(llist*head,int data){
//   llist*temp=head;
//   while(temp!=NULL){
//     temp=temp->next;
//     delete head;
//     head=temp;
//   }
//   return head;
// }
// llist*insert_hai(llist*h1,llist*h2,int p1,int p2){
//   llist*temp=h1;
//   p1--;
//   while(p1>1){
//     temp=temp->next;
//     p1--;
//   }

//  llist*temp2=temp->next;
//  int d=p2-p1;
//  while(d>0){
//   temp2=temp2->next;
//   d--;
//  }
//  temp->next=h2;
//  llist*temp3=h2;
//  while(temp3->next!=NULL)temp3=temp3->next;
//  temp3->next=temp2;
//  return h1;



// }
// llist*prac(llist*h1,llist*h2,int p1,int p2){
//   int c=p2-p1;
//   llist*temp=h1;
//   p1--;
//   while(p1>1){
//     temp=temp->next;
//   p1--;
//   }
//   llist*temp2=temp->next;
//   for(int i=0;i<c;i++){
//     temp2=temp2->next;
//   }
//   llist*temp3=h2;
//   while(temp3->next!=NULL)temp3=temp3->next;
// temp->next=h2;
// temp3->next=temp2->next;
// return h1;

// }
// int main(){
//   list<int>l1={1,2,3,4};
//   list<int>l2={5,6,7,8};
//   llist*h1=NULL;
//   llist*h2=NULL;

// h1=make(h1);
// h2=make(h2);
// print(h1);
// cout<<endl;
// print(h2);
// cout<<endl;
//  h1=prac(h1,h2,3,5);

//  print(h1);
//   // llist*head=NULL;
//   // head=make(head);
//   //   print(head);
//   //   cout<<endl;
//   // head=del_pos(head,5);
//   // print(head);

// }

#include<bits/stdc++.h>
using namespace std;


    int helper(int idx1,int idx2,string s1,string s2){
        if(idx1<0 || idx2<0)return 0;
        if(s1[idx1]==s2[idx2])return 1+helper(idx1-1,idx2-1,s1,s2);
        else{
            return 0+max(helper(idx1-1,idx2,s1,s2), helper(idx1,idx2-1,s1,s2));
        }

    }
    int helper(string s1,string s2){
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int i=1;i<=s1.size();i++){

            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        // return helper(n1-1,n2-1,s1,s2);
        return helper(s1,s2);
    }


    int main(){
        cout<<longestCommonSubsequence("Ajay","Vijay");
    }