#include <iostream>
#include <string>
using namespace std;


int main (){

    //ways to declare string
    // string str;
    // cin>>str;

    // cout<<str<<endl;


    //2 way


    // string str2 = "ApniKaksha";
    // cout<<str2;

    // string str3;
    // getline(cin, str3);

    // cout<<str3<<endl;

    //FUCTIONS OF STRING

    string s1 = "fam";
    string s2 = "ily";

    s1.append(s2);

    cout<<s1<<endl;

    s1.clear();
    cout<<"after clear"<<endl;

    cout<<s1.empty()<<endl;
    cout<<s1<<endl;

        string s3 = "nincompoop";

        s3.erase(3, 2);
        cout<<s3<<endl;

        s3.insert(2, "lol");
        cout<<s3<<endl;

        cout<<s3.size()<<endl;  // length() also works


            string subStr = s3.substr(6, 4);

            cout<<subStr<<endl;


            //string to integer
            string num = "786";

            int x = stoi(num);
            string s4;

            cout<<to_string(x)+"2"<<endl;

            s4 = "alfsjdflsdfas";

            sort(s4.begin(), s4.end());

            cout<<s4<<endl;

            vector<int> v2 (3, 50);   //v2 = {50 50 50}

            

            



    return 0;
}