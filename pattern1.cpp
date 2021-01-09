#include <iostream>
using namespace  std;


int main(){
int rows,cols;
cout<<"Enter total rows and columns"<<endl;

cin>>rows>>cols;

for(int row=1; row<=rows; row++){

    if(row==1 || row==rows){
        for(int col=1; col<=cols; col++){
            cout<<"*";
        
        }
        cout<<endl;
    }
    else
    {
            for(int col=1; col<=cols; col++){
                if(col==1 || col==cols){
            cout<<"*";
        
        }
        else{
            cout<<" ";

        }
        
    }
    cout<<endl;
    

}


}
    return 0;
}