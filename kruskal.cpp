#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
const int maximum=1000001;
class unionfind
{
public:
	int parent[maximum],size[maximum];
	unionfind(int node )
	{
		for (int k = 0; k < node; ++k)
		{
			size[k]=1;
			parent[k]=k;
		}
	}
	int find_root(int x )
	{
		while(x!=parent[x])
		{
			parent[x]=parent[parent[x]];
			x=parent[x];
		}
		return x;
	}
	int check_same_root(int u,int v)
	{
		return find_root(u)==find_root(v);
	}
	void do_union(int a , int b)
	{
		int m=find_root(a);
		int n=find_root(b);
		if(size[m]>size[n])
		{
			parent[n]=m;
			size[m]=+size[n];
		}
		else 
		{
			parent[m]=n;
			size[n]=+size[m];
		}
	}
};
vector< pair<float, pair<int, int> > > graph;
int nodes;
int edges;
float cost;
int save_v[maximum],save_u[maximum],tempo;
float save_w[maximum];
void kruskal_algorithm()
{
	unionfind arr(nodes);
	int u,v;
	tempo=0;
	for (int i = 0; i<edges; ++i)
	{
		u=graph[i].second.first;
		v=graph[i].second.second;
		if(!arr.check_same_root(u,v))
		{
			arr.do_union(u,v);
			save_w[tempo]=graph[i].first;
			save_v[tempo]=v;
			save_u[tempo]=u;
			tempo++;
			cost=cost+graph[i].first;
		}
	}
}
float store_w[maximum];
int store_u[maximum],store_v[maximum];

int main()
{
	int u,v;
	cin>>nodes;
	float w;
	edges=0;
	while((scanf("%d",&u)!=EOF)&&(scanf("%d",&v)!=EOF)&&scanf("%f",&w)!=EOF)
	{
		store_v[edges]=v;
		store_u[edges]=u;
		store_w[edges]=w;
		edges++;
		
	}
	graph.resize(edges);
	for (int i = 0; i < edges; ++i)
	{
		graph[i].first=store_w[i];
		graph[i].second.first=store_u[i];
		graph[i].second.second=store_v[i];
	}
	sort(graph.begin(), graph.end());	
	cost = 0;
	kruskal_algorithm();
	printf("%.2f\n",cost);
	for (int l = 0; l < tempo; ++l)
	{
		if(save_u[l]>save_v[l]){
			cout<<save_v[l]<<" ";
			cout<<save_u[l]<<" ";
		}
		else{
			cout<<save_u[l]<<" ";
			cout<<save_v[l]<<" ";
		}
		printf("%.2f\n",save_w[l]);
	}
	return 0;
}