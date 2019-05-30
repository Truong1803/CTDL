#pragma one
#include <iostream>
using namespace std;
class Node{
public:
    int data[1000];
    Node  *next;
    Node(int data){
        this->data[0]=data;
        this->next=NULL;
    }
};
class Vector{
private:
    Node  *head;
    Node  *tail;
public:
    static int size_of;
    static int i;
    Vector(){
        this->head=NULL;
        this->tail=NULL;
    }
    void push_back(int val){
        if(size_of%1000==0){
            if(head==NULL){
                Node *temp=new Node(val);
                head=temp;
                tail=temp;
                size_of++;
                i++;
            }
            else {
                i=0;
                Node *temp=new Node(val);
                tail->next=temp;
                tail=tail->next;
                size_of++;
                i++;
            }
        }
        else{
            tail->data[i]=val;
            i++;
            size_of++; 
        }
    }

    int size(){
        return size_of;
    }
    bool empty(){
        if(size()==0)
            return true;
        return false;
    }
    void pop_back(){
        i--;
        size_of--;
    }
    void resize(int pos){
        int s=size_of;
        if(pos>s){
            for(int x=0;x<pos-s;x++)
                push_back(0);
        }
        else{
            Node*p=head;
            if(pos>=1000){
                for(int x=0;x<(pos/1000)-1;x++)
                    p=p->next;
                size_of=size_of-(pos/1000)*1000;
            }
            tail=p;
            p->next=NULL;
            for(int x=pos+1;x<size_of;x++)
                tail->data[x]=0;
            size_of=pos;
        }
    
    }
    int &operator [] (int val){
        Node *p=head;
        int s=1;
        for(int x=0;x<val/1000;x++){
            p=p->next;
            s++;
        }
        return p->data[val%(s*1000)];
    }
};
int Vector::size_of=0;
int Vector::i=0;