#include <iostream>
#include <set>

using namespace std;


int32_t main(){

    set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);


    for(auto i : s)
        cout<<i<<" ";

    cout<<"\n";

    cout<<s.size()<<"\n";

    s.erase(2);

    for(auto i : s)
        cout<<i<<" ";

    cout<<"\n";


    //MULTI-SET
    //it allows multiple instance of same number

    multiset<int> mSet;

    mSet.insert(1);
    mSet.insert(2);
    mSet.insert(3);
    mSet.insert(3);
    mSet.insert(3);
    mSet.insert(3);
    mSet.insert(3);

    for(auto i: mSet){
        cout<<i<<" ";
    }

    mSet.erase(mSet.find(3));  //it will delete first occurance of 3 only
    cout<<"\n";

     for(auto i: mSet){
        cout<<i<<" ";
    }

    cout<<"\n";

        mSet.erase(3);  //it will delete all occurance of 3

        for(auto i: mSet){
        cout<<i<<" ";
    }

    cout<<"\n";




    





    return 0;
}








//SETS
    //i) ORDERED SETS
