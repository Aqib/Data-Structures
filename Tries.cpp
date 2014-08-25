#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class node {
public:
int value;
node* next[26];
int count;
node () {count=1; for(int i=0;i<26;i++) next[i]=NULL;}

};

class trie{
public:
node* root;
trie() {root=new node();}
void insert(string);
void find(string);
void remove(int,string,node*);




};



void trie::insert(string c)
{//cout<<"inserting"<<endl;
    int l=c.size();
    int i=0;
    node* current=root;
   // cout<<current->next[int(c[i])-97]<<endl;
    while(current->next[int(c[i])-97]!=NULL&&i<l)
    {//cout<<i<<endl;
        current=current->next[int(c[i])-97];
        current->count++;
            i++;

    }
//cout<<"here"<<endl;
 while(i<l)
 {
     current->next[int(c[i])-97]=new node();
     current=current->next[int(c[i])-97];
     i++;

 }





}


void trie::find (string c)
{
    //cout<<"finding"<<endl;

  node* current=root;
  int l=c.size();
  int i=0;
 while(current->next[int(c[i])-97]!=NULL&&i<l)
    {
     //   current->count++;
        current=current->next[int(c[i])-97];
            i++;

    }
    if(i==l) printf("PRESENT\n");
    else printf("NOT PRESENT\n");





}

void trie::remove(int i,string c,node* p)
{
    if(i==c.size()) return;
    if(p->next[int(c[i])-97]->count==1) {p->next[int(c[i])-97]=NULL; return; }
    else {p=p->next[int(c[i])-97]; p->count--; remove(i+1,c,p);}

}


int main()
{
   
    trie first;
    first.insert("understand");
    first.insert("under");
    first.remove(0,"under",first.root);
    first.find("understand");
   

}
