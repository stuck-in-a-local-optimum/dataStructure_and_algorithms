#include <iostream>

#include <vector>

using namespace std;


int main(){

        vector<int> v;

        v.push_back(1);
        v.push_back(2);
        v.push_back(3);

        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<endl;
        }

        cout<<endl;
        vector<int>::iterator it;

    cout<<endl;
        for(it = v.begin(); it!=v.end(); it++){
            cout<<*it<<endl;
        }

            cout<<endl;

        for(auto element : v){
            cout<<element<<endl;

        }


    return 0;
}