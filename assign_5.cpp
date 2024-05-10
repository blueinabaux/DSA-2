#include <iostream>
#include <string>
using namespace std;

class node{

    int key;
    string value;
    node *next;

    public:
        node(int k, string data){
            key = k;
            value = data;
            next = NULL;
        }

    friend class HashMap;
};

class HashMap{
    
    node *arr[10];

    public:
        HashMap(){
            for(int i=0;i<10;i++){
                arr[i] = NULL;
            }
        }

        void insert(int k, string data){

            int k1 = (3*k + 5) % 10;
            node *temp = arr[k1];

            if(arr[k1] == NULL){
                arr[k1] = new node(k, data);
                return;
            }
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new node(k, data);
        }

        void deleteKey(int key){

            int k = (3*key + 5) % 10; 
            node *temp = arr[k];

            if(temp->key == key){
                arr[k] = temp->next;
                delete temp;
                return;
            }

            while(temp->next->key != key){
                temp = temp->next;
            }
            node *delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode; 
        }

        void search(int key){

            int k = (3*key + 5) % 10;
            node *temp = arr[k];

            while(temp != NULL && temp->key != key){
                temp = temp->next;
            }
            if(temp == NULL){
                cout<<"KEY NOT PRESENT !"<<endl;
            }
            else{
                cout<<"ELEMENT FOUND: "<<endl;
                cout<<temp->key<<" -> "<<temp->value<<endl;
            }
        }

        void print(){

            for(int i=0;i<10;i++){
                node *temp = arr[i];
                cout<<i<<" -> "<<" ";
                while(temp != NULL){
                    cout<<temp->key<<" "<<temp->value<<" "<<" -> ";
                    temp = temp->next;
                }
                cout<<endl;
            }
        }
};

int main(){

    HashMap h;
    int ch,k;
    string val;

    cout<<"1. Insert data\n2. Delete data\n3. Find key\n4. Display"<<endl;
    while(ch!=5){
        cout<<"Enter your Choice: ";
        cin>>ch;

        switch(ch){
            case 1:{
                cout<<"Enter Key: ";
                cin>>k;
                cout<<"Enter Value: ";
                cin>>val;
                h.insert(k, val);
                break;
            }
            case 2:{
                cout<<"Enter Key to be DELETED: ";
                cin>>k;
                h.deleteKey(k);
                h.print();
                break;
            }
            case 3:{
                cout<<"Enter Key to be SEARCHED: ";
                cin>>k;
                h.search(k);
                h.print();
                break;
            }
            case 4:{
                h.print();
            }
            case 5:{
                break;
            }
            default:
                break;
        }
    }

    return 0;
}