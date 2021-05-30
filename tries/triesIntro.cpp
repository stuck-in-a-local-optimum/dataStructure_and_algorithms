#include <iostream>
using namespace std;


class Trie{
    public:
        class Node{
            public:
                bool end;
                Node* next[26];

                Node(){
                    end = false;
                        for(int i=0; i<26; i++){
                            next[i] = NULL;
                        }
                }
        };

        Node* trie;
         Trie(){
             trie = new Node();
         }


         void insert(string word){
             int i=0;
             Node it = trie;

             while( i< word.size()){
                 if( it-> next[word[i] - 'a'] == NULL){  //if node not exist in trie then create that node
                        it->next[word[i]-'a'] = new Node();
                 it = it->next[word[i] - 'a'];
                 i++:
                 }
                 it->end =true;  //this indicates that a word is ending here
             }
         }


         bool search( string word){
             int i=0;
             Node* it = trie;

             while( i < word.size()){
                 if( it-> next[word[i] - 'a'] == NULL){
                     return false;
                 }
                  it = it-> next[word[i] - 'a'];
                  it++;
             }


             return it->end;   //if it so far has an end then it means word exists

                 
}
};






int main(){

    Trie *myTrie = new Trie();
    vector<string> words = {"ayush", "daasi"};

        for( auto w : words){
                myTrie-> insert(w);
            
        }

        if(myTrie ->search("madhav")){
            cout<<"Madhav found\n";
        }
        else{
            cout<<"Madhav no found\n";
        }



    return 0;
}