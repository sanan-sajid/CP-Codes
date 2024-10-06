// Q = 1, 2, 3, 4, 5, 6 , 7, 8 
 
 
// K = 3
 
// Q = 3, 2, 1, 6, 5, 4 , 8, 7 

void helper(queue<int>&q,int k){
    if(k==0){
        return;
    }
    int ele=q.front();
    q.pop();
    helper(q,k-1);
    q.push(ele);
}
void rec(queue<int>&q,int k){
        int n=q.size();
        int i=0;
        while(i<n){
            
        }
}


