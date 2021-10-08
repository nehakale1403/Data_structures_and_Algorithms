#include <bits/stdc++.h>
using namespace std;

class medianFinder{
    public:
        priority_queue<int> maxheap;
        priority_queue<int, vector<int>, greater<int>> minheap;

        medianFinder(){

        }

        void addNum(int num){
            int lsize = maxheap.size();
            int rsize = minheap.size();

            if(lsize == 0){
                maxheap.push(num);
            }else if(lsize == rsize){
                if(num < minheap.top()){
                    maxheap.push(num);
                }else{
                    int temp = maxheap.top();
                    maxheap.pop();
                    maxheap.push(temp);
                    minheap.push(num);
                }
            }else{
                if(minheap.size() == 0){
                    if(minheap.size() == 0){
                        if(num > maxheap.top())
                            minheap.push(num);
                        else{
                            int temp = maxheap.top();
                            maxheap.pop();
                            maxheap.push(num);
                            minheap.push(temp);
                        }
                    }
                }else if(num >= minheap.top()){
                    minheap.push(num);
                }else{
                    if(num <maxheap.top()){
                        int temp = maxheap.top();
                        maxheap.pop();
                        maxheap.push(num);
                        minheap.push(temp);
                    }else{
                        minheap.push(num);
                    }
                }
            }
        }

        double findmedian(){
            int lsize = maxheap.size();
            int rsize = minheap.size();

            if((lsize + rsize)%2 == 1){
                return maxheap.top();
            }else{
                return (double(maxheap.top()) + double(minheap.top()))/2;
            }
        }
};
 

int main(){
    int n;
    cin>>n;

    int arr[n];

    medianFinder ob;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        ob.addNum(arr[i]);
        cout<<ob.findmedian();
    }
} 


//method 2

// #include <bits/stdc++.h>
// using namespace std;


// class Solution
// {
//     public:
//     //Function to insert heap.
//     priority_queue<double> s;
//         priority_queue<double, vector<double>, greater<double>> g;

        
//     void insertHeap(int &x)
//     {
//         if(s.empty() || x<s.top())
//        {
//            s.push(x);
//        }
//        else
//        {
//            g.push(x);
//        }
       
//       if(s.size()>1+g.size())
//        {
//            g.push(s.top());
//            s.pop();
//        }
//        else
//        {
//            if(g.size()>1+s.size())
//            {
//                s.push(g.top());
//                g.pop();
//            }
//        }
//     }
    
//     //Function to balance heaps.
//     void balanceHeaps()
//     {
//         if(s.size()>1+g.size())
//        {
//            g.push(s.top());
//            s.pop();
//        }
//        else
//        {
//            if(g.size()>1+s.size())
//            {
//                s.push(g.top());
//                g.pop();
//            }
//        }
//     }
    
//     //Function to return Median.
//     double getMedian()
//     {
//        double med;
//        if(s.size()==g.size())
//        {
//            med=(s.top()+g.top())/2.0;
//        }
//        else
//        {
//            if(s.size()>g.size())
//            {
//                med=s.top();
//            }
//            else
//            {
//                med=g.top();
//            }
//        }
       
//        return med;
//     }
// };


// // { Driver Code Starts.

// int main()
// {
//     int n, x;
//     int t;
//     cin>>t;
//     while(t--)
//     {
//     	Solution ob;
//     	cin >> n;
//     	for(int i = 1;i<= n; ++i)
//     	{
//     		cin >> x;
//     		ob.insertHeap(x);
//     	    cout << floor(ob.getMedian()) << endl;
//     	}
//     }
// 	return 0;
// } 