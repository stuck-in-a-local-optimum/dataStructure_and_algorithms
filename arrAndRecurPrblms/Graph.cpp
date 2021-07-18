#include<iostream>
#include<unordered_map>
#include<list>
#include<cstring>
using namespace std;

class Graph{
	int V;
	unordered_map<string,list<pair<string,int> > > m;
public:
	Graph(int v){
		V = v;
	}

	void addEdge(string src,string dest,int wt,bool bidir=true){
		m[src].push_back(make_pair(dest,wt));
		if(bidir){
			m[dest].push_back(make_pair(src,wt));
		}
	}
	void print(){

		for(auto p:m){
			string src = p.first;
			auto cities = p.second;

			cout<<src<<"-->";
			for(auto city:cities){
				cout<<"("<<city.first<<","<<city.second<<")";
			}
			cout<<endl;
		}
	}
};




int main(){

	Graph g(5);
	g.addEdge("1","2",0);
	g.addEdge("2","3",0);
	g.addEdge("3","4",0);
	g.addEdge("4","5",0);
	g.addEdge("4","2",0);
	g.print();


	return 0;
}