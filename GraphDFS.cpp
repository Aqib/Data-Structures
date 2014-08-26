#include <iostream>
#include <stdio.h>
using namespace std;
class node{
public:
node* next;
int value;
node(int a) {value=a; next=NULL;}
node() {value=-1; next=NULL;}

};

class graph{
public:
int V;
node** arr;
node** end;
int* color;
int* d;

graph(int a) {V=a; d=new int(a); color=new int(a); arr=new node*[a]; end=new node*[a];

for(int i=0;i<a;i++) {arr[i]=new node(i); end[i]=arr[i];}

}
void decolor() {for(int i=0;i<V;i++) color[i]=0;}

void connect(int x,int y);
void dfs(int);
void bfs(int);

};

void graph::connect(int x,int y)
{
   if(x==y) return;
    end[x]->next=new node(y);
    end[x]=end[x]->next;
    end[y]->next=new node(x);
    end[y]=end[y]->next;


}

void graph::dfs(int a)
{
   printf(" %d",a);
    node* current=arr[a]->next;
    color[a]=1;
 while(current!=NULL)
    {
    //   cout<<"here once"<<endl;
        if(color[current->value]==0) { dfs(current->value);}
        current=current->next;

    }




}



int main()
{
graph g(4);
g.decolor();
    g.connect(0, 1);
    g.connect(0, 2);
    g.connect(1, 2);
    g.connect(2, 0);
    g.connect(2, 3);
    g.connect(3, 3);
/*
for(int i=0;i<4;i++)
{
    node* current=g.arr[i];
    while(current!=NULL) {printf("%d ",current->value); current=current->next; }
    printf("\n");

}*/

   cout << "Following is Depth First Traversal (starting from vertex 2) \n";
  g.dfs(2);
    g.decolor();




}
