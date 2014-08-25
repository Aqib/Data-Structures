#include <iostream>
#include <stdio.h>
using namespace std;

class node{
    public:
node* next[27];
int value;
node() {for(int i=0;i<27;i++) next[i]=NULL;}
node(int a) {value=a; for(int i=0;i<27;i++) next[i]=NULL; }

};

class suffixtree{
public:
node* root;
suffixtree() {root=new node();}
void insert(int,int,string,node*);
//suffixtree(string);
void find(int,int,string,node*);



};

void suffixtree::insert(int i, int y, string c,node* p)
{
 if(i>y) {p->next[26]=new node(-1); return; }
 //int l=c.size();
 int k=int(c[i])-97;
 if(p->next[k]!=NULL) {p=p->next[k]; insert(i+1,y,c,p);}
  else {//p->next[k]=new node();
  while(i<=y){
      k=int(c[i])-97;
  p->next[k]=new node(i);
  p=p->next[k];
  i++;

  }
 p->next[26]=new node(-1);

}


}

void suffixtree::find(int i,int y,string c,node* p)
{
    if(i>y) {printf("Found at %d\n",p->value-c.size()+2);      }
   int k=int(c[i])-97;
   if(p->next[k]==NULL) {printf("\nNot present");}
   else {p=p->next[k]; find(i+1,y,c,p); }




}



//suffixtree::suffixtree(string c)



int main()
{

    string c;
    cin>>c;
    int l=c.size();
    suffixtree mytree;
    for(int i=0;i<l;i++) {mytree.insert(i,l-1,c,mytree.root); }
    string b;

    cin>>c;
    mytree.find(0,c.size()-1,c,mytree.root);



}
