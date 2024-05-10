#include <iostream>
#include <string>
using namespace std;

class Entry{

    public:
        string name;
        long long phoneNumber;

        Entry(){
            name = "";
            phoneNumber = -1;
        }

        Entry(string n, long long p){
            name = n;
            phoneNumber = p;
        }
};

class hashTable{

    Entry arr[10]; // Hash Table
    int size = 10;

    public:
        hashTable(){
            for(int i=0;i<10;i++){
                arr[i] = Entry();
            }
        }

        void insertWithoutRepl(string name, long long phoneNumber){
            
            int hkey = int(phoneNumber % size);

            if(arr[hkey].phoneNumber == -1){
                arr[hkey] = Entry(name, phoneNumber);
            }
            else{
                while(arr[hkey].phoneNumber != -1){
                    hkey = (hkey + 1) % size;
                }
                arr[hkey] = Entry(name, phoneNumber);
            }
        }

        void insertWithRepl(string name, long long phoneNumber){
            
            int hkey = int(phoneNumber % 10);

            if(arr[hkey].phoneNumber == -1){
                arr[hkey] = Entry(name, phoneNumber);
            }
            else{
                if((arr[hkey].phoneNumber % size) == hkey){
                    while(arr[hkey].phoneNumber != -1){
                        hkey = (hkey + 1) % size;
                    }
                    arr[hkey] = Entry(name, phoneNumber);
                }
                else{
                    Entry temp = arr[hkey];
                    arr[hkey] = Entry(name,phoneNumber);
                    while(arr[hkey].phoneNumber != -1){
                        hkey = (hkey + 1) % size;
                    }
                    arr[hkey] = temp;
                }
            }
        }

        void deleteWithRepl(long long phoneNumber){

            int hkey = int(phoneNumber % 10);

            if(arr[hkey].phoneNumber == phoneNumber){
                arr[hkey] = Entry();
                return;
            }
            else{
                while(arr[hkey].phoneNumber != phoneNumber){
                    hkey = (hkey + 1) % size;
                }
                if(arr[hkey].phoneNumber == phoneNumber){
                    arr[hkey] = Entry();
                }

            }
        }

        void search(long long phoneNumber){
            int comp = 1;
            int index = int(phoneNumber % 10);
            int temp = index;

            while(arr[index].phoneNumber != phoneNumber){
                comp++;
                if(index != 9){
                    index += 1;
                }
                else{
                    index = 0;
                }

                if(index == temp){
                    cout<<"\nELEMENT NOT FOUND !"<<endl;
                    return;
                }
            }

            if(arr[index].phoneNumber == phoneNumber){
                cout<<"NAME: "<<arr[index].name<<endl;
                cout<<"PHONE NUMBER: "<<arr[index].phoneNumber<<endl;
            }
            else{
                cout<<"\nELEMENT NOT FOUND !"<<endl;
            }
            cout<<"COMPARISONS: "<<comp<<endl;
        }

        void display() {
            cout << "Index  " << "Name" << "    " << "Phone Number" << endl;
            for (int i = 0; i < size; i++) {
                cout << i << "      " << arr[i].name << "    " << arr[i].phoneNumber << endl;
            }
        }
};


int main(){

    hashTable h1, h2;
    int flag = 0;

    cout << "1. Insert with replacement" << endl;
    cout << "2. Insert without replacement" << endl;
    cout << "3. Delete with replacement" << endl;
    cout << "4. Comparisons " << endl;
    cout << "5. Exit" << endl;
    cout << "You are allowed to enter up to 10 values" << endl;

    int ch;
    while(ch!=5){
        cout<<"Enter your choice: ";
        cin>>ch;

        switch(ch){
            case 1: {
                int x;
                long long y;
                string name;
                cout<<"Enter no. of Elements: ";
                cin>>x;
                for(int i=0;i<x;i++){
                    cout<<"Name: ";
                    cin>>name;
                    cout<<"Phone No.: ";
                    cin>>y;
                    h1.insertWithRepl(name,y);
                }
                cout<<"With Replacement: "<<endl;
                h1.display();
                cout<<endl;
                flag = 0;
                break;
            }

            case 2: {
                int x;
                long long y;
                string name;
                cout<<"Enter no. of Elements: ";
                cin>>x;
                for(int i=0;i<x;i++){
                    cout<<"Name: ";
                    cin>>name;
                    cout<<"Phone No.: ";
                    cin>>y;
                    h2.insertWithoutRepl(name,y);
                }
                cout<<"Without Replacement: "<<endl;
                h2.display();
                cout<<endl;
                flag = 1;
                break;
            }

            case 3: {
                long long x;
                cout<<"Enter the phn. no. to delete with replacement: ";
                cin>>x;
                h1.deleteWithRepl(x);
                cout<<"After Deletion: "<<endl;
                h1.display();
                cout<<endl;
                break;
            }

            case 4: {
                long long d;
                cout<<"Enter the Phone no. to be SEARCHED: ";
                cin>>d;
                if(flag==0){
                    h1.search(d);
                }
                else if(flag == 1){
                    h2.search(d);
                }
                else {
                    cout<<"Phone no. not inserted"<<endl;
                }
                break;
            }

            case 5:
                cout<<"PROGRAM TERMINATED"<<endl;
                break;

            default:
                cout<<"INVALID CHOICE !"<<endl;
        }
    }

    return 0;
}