#include <iostream>
using namespace std;

    bool isArrSorted(int arr[],int  n){
        if(n==1){
            return true;
        }

        bool restArr = isArrSorted(arr+1, n-1);

        return arr[0]<arr[1] && restArr;


    }

    int firstOcurr(int arr[], int n, int index, int key){

            if(index==n){
                return -1;
            }


        if(arr[index]==key){
            return index;
        }
        return firstOcurr(arr, n, index+1, key);
    }


    int lastOccur(int arr[], int n, int index,  int key){

            if(index==n){
                return -1;
            }
            

            int  inRestArr = lastOccur(arr, n, index+1, key);

            if(inRestArr!=-1){
                return inRestArr;
            }

            if(arr[index]==key){
                return index;
            }

            return -1;
    }


    void reverseStr(string s){
        if(s.length()==0){
            return;
        }

        string restStr = s.substr(1);
        reverseStr(restStr);
        cout<<s[0];
        
    }

    void replacePi(string s){




        if(s[0]=='p' && s[1]=='i'){
            cout<<"3.14";
            replacePi(s.substr(2));

        }
        else{
            cout<<s[0];
            replacePi(s.substr(1));
        }
    }


    void towerOfHanoi(int n, char src, char dest, char helper){
            if(n==0){
                return;
            }


        towerOfHanoi(n-1, src, helper, dest);
        cout<<"Move from "<<src<<" to "<<dest<<endl;
        towerOfHanoi(n-1, helper, dest, src);
    }

    string removeDuplicates(string s){
        if(s.length()==0){
            return "";
        }

        char ch = s[0];
        string restSstr = removeDuplicates(s.substr(1));
        if(ch==restSstr[0]){
            return restSstr;
        }
        return s[0] + restSstr;
    }

    string shiftXtoEnd(string s){

        if(s.length()==0){
            return "";
        }

        char ch = s[0];
        string restStr = shiftXtoEnd( s.substr(1));

        if(ch=='x'){
            return restStr+ch;

        }
        return ch+restStr;
    }

    void subsequence(string s, string ans){
            if(s.length()==0){
                cout<<ans<<endl;
                return;
            }

        char ch = s[0];
        string reststr = s.substr(1);
        subsequence(reststr,ans) ;    //either ch is not in ans
        subsequence(reststr, ans+ch); //or it is in

    }

    void subseqAscii(string s, string ans){
            if(s.length()==0){
                cout<<ans<<endl;
                return;
            }



        char ch  = s[0];
        int code = ch;
        string restStr = s.substr(1);

        subseqAscii(restStr, ans);
        subseqAscii(restStr, ans+ch);
        subseqAscii(restStr, ans+to_string(code));

    }
    

    string keypadArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};  //GLOBAL

    void keyPad(string s, string ans){
        if(s.length()==0){
            cout<<ans<<endl;
            return;
        }


        char ch =s[0];
        string keyCode = keypadArr[ch-'0'];   //"abc" for ch='2'
        string restStr = s.substr(1);

        for(int i=0; i<keyCode.length(); i++){

            keyPad(restStr, ans+keyCode[i]);
   }
}

    void strPermutation(string s, string ans){
        if(s.length()==0){
            cout<<ans<<endl;
            return ;
        }
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            string restStr  = s.substr(0, i) + s.substr(i+1);
            strPermutation(restStr, ans+ch);
        }
    }

    int countPath(int start, int end){
        if(start==end){
            return 1;
        }
        if(start> end){
            return 0;
        }

        int count=0;

        for(int i=1; i<=6; i++){
            count+=countPath(start+i, end);

        }
        return count;
    }


    // int countPathMaze(int n, int i, int j){

    //     if(i==n-1 && j==n-1){
    //         return 1;
    //     }
    //     if(i>=n || i>= n){
    //         return 0;
    //     }

    //     return countPathMaze(n, i+1, j) + countPathMaze(n, i, j+1);

    // }


    int tilingWays(int n){


        if(n==1){
            return 1;
        }

        if(n==0){
            return 0;
        }


        return tilingWays(n-1) + tilingWays(n-2);
    }


    int friendsPairing(int n){
        if(n==0 || n==1 || n==2){
            return n;
        }

        return friendsPairing(n-1) + friendsPairing(n-2)*(n-1);  //for the pairing case we have (n-1) option to choose to pair with
    }

    int knapSack(int values[], int wt[], int n, int W){

            if(n==0 || W==0){
                return 0;
            }

            if(wt[n-1]>W){
               return  knapSack(values, wt, n-1, W);
            }

        return max(knapSack(values, wt, n-1, W-wt[n-1]) + values[n-1], knapSack(values, wt, n-1, W));
    }

    int kickStart(int* arr, int n, int B){
    
    if(n==0 || B==0){
        return 0;
    }
    
    if(arr[n-1]>B){
        return kickStart(arr, n-1, B);
    }
    return max(kickStart(arr, n-1, B-arr[n-1])+1, kickStart(arr, n-1, B)); 
    
}














int main(){

//     int arr1[] = {1,2,33,44,55, 55};
//     int arr2[] = {3,5,4,33,2};

//     cout<<isArrSorted(arr1, 5)<<endl;
//     cout<<isArrSorted(arr2, 5)<<endl;
//     cout<<firstOcurr(arr1, 6, 0, 55);
//     cout<<endl;
//     cout<<lastOccur(arr1, 6, 0, 55);

//     cout<<endl;

//     reverseStr("BINOD");
//  cout<<endl;

//         replacePi("pippp3pifsfdp3pi");
//          cout<<endl;

//          towerOfHanoi(3, 'A', 'C', 'B');
//          cout<<removeDuplicates("aaaaabbbddd");
//          cout<<endl;
//          cout<<shiftXtoEnd("afsxxkjfslxs");
//          subsequence("abc","");
//               subseqAscii("AB","");

//               keyPad("23", "");
//               strPermutation("ABC","");
//               cout<<countPath(0, 3)<<endl;
              //cout<<countPathMaze(3, 0, 0)<<endl;

            //   cout<<tilingWays(4);
            //   cout<<endl;
            //   cout<<friendsPairing(4);

            //   int wt[] = {10, 20, 30};
            //   int values[] = {100, 50, 150};
            //   int W=50;
            //   cout<<endl;
            //   cout<<knapSack(values, wt, 3, W)<<endl;


    int T;
    cin>>T;
    
    for(int i=0; i<T; i++){
        int n;
        int B;
        cin>>n;
        cin>>B;
        
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        cout<<"case #"<<i+1<<": "<<kickStart(arr, n, B)<<endl;
    }
    




    return 0;
}