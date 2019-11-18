#include <bits/stdc++.h>
using namespace std;

unordered_set<int> frame;//global set for frame

void pageFaults(int page,int capacity){
   //if frame is not full
    if(frame.size() < capacity){
        //new page is inserted 
        if(frame.find(page) == frame.end()){
            frame.insert(page);
            cout<<"page misses"<<endl;
            cout<<page<<" is in frame"<<endl;
        }
        //page is already in frame
        else{
            cout<<"page hits"<<endl;
        }
    }
    //frame is full so now replacment starts
    else{
        cout<<"frame is full so now randomly replacing ";
        
        if(frame.find(page) == frame.end()){
            srand(time(0));
            int r = rand()%capacity;
            
            cout<<r<<"th element"<<endl;
            auto i = frame.begin();
            for(int j = 0;j < r; j++)
                i++;
            
            cout<<"page misses"<<endl;
            cout<<page<<" is in frame"<<endl;
            frame.erase(i);
            frame.insert(i,page);
            
        }
        else{
            cout<<" but page hits"<<endl;
        }
    }
}
int main(){
    int capacity;
    cout<<"enter capacity of frame"<<endl;
    cin>>capacity;
    int n;
    cout<<"enter number of pages you want to enter"<<endl;
    cin>>n;
    
    for(int i =0;i<n;i++){
        int page;
        cout<<"enter page no."<<endl;
        cin>>page;
        
        pageFaults(page,capacity);
    }
    return 0;
}
