#include <iostream>
#include<queue>
using namespace std;

class node
{
    int data;
    node *lc, *rc;

    public:
        node()
        {
            data = 0;
            lc = NULL;
            rc = NULL;
        }
        friend class stack;
        friend class BinaryTree;
};

class stack
{
    node *s[20];
    int top;

    public:
        stack()
        {
            top = -1;
        }

        void push(node *val)
        {
            s[++top] = val;
        }

        void pop()
        {
            top--;
        }
        node *gettop()
        {
            return s[top];
        }
        bool isEmpty()
        {
            if (top == -1)
                return true;
            else
                return false;
        }
};

class BinaryTree
{
    node *root;

    node *createR()
    {
        node *temp = new node();
        char ch;

        cout<<"Enter Data "<<endl;
        cin>>temp->data;

        cout<<"Want to add its right child?(Y/N)"<<endl;
        cin>>ch;
        if(ch == 'Y')
            temp->rc=createR();

        cout<<"Want to add its left child?(Y/N)"<<endl;
        cin>>ch;
        if(ch == 'Y')
            temp->lc=createR();

        return temp;
    }
    
    void inorder(node *T)
    {
        if(T==NULL)
            return;
        inorder(T->lc);
        cout<<T->data<<" ";
        inorder(T->rc);
    }
    void preorder(node *T)
    {
        if(T==NULL)
            return;
        cout<<T->data<<" ";
        preorder(T->lc);
        preorder(T->rc);
    }
    void postorder(node *T)
    {
        if(T==NULL)
            return;
        postorder(T->lc);
        postorder(T->rc);
        cout<<T->data<<" ";
    }
    void inorderNR(node *T)
    {
        stack s;
        while(1)
        {
            while(T!=NULL)
            {
                s.push(T);
                T=T->lc;
            }
            if(s.isEmpty())
                return;
            T = s.gettop();
            s.pop();
            cout<<T->data<<" ";
            T=T->rc;
        }
    }

    void inorderNRD(node *T)
    {
        stack s;
        while(1)
        {
            while(T!=NULL)
            {
                s.push(T);
                T=T->rc;
            }
            if(s.isEmpty())
                return;
            T = s.gettop();
            s.pop();
            cout<<T->data<<" ";
            T=T->lc;
        }
    }
    void preorderNR(node *T)
    {
        stack s;
        while(1)
        {
            while(T!=NULL)
            {
                s.push(T);
                cout<<T->data<<" ";
                T=T->lc;
            }
            if(s.isEmpty())
                return;
            T = s.gettop();
            s.pop();
            T=T->rc;
        }
    }
    void postorderNR(node *T)
    {
        stack s,s1;
        s.push(T);
        while(!s.isEmpty())
        {
            T = s.gettop();
            s.pop();
            s1.push(T);
            if(T->lc!=NULL)
                s.push(T->lc);
            if (T->rc!=NULL)
                s.push(T->rc);
        }
        while(!s1.isEmpty())
        {
            T = s1.gettop();
            s1.pop();
            cout<<T->data<<" ";
        }
    }
    void s(node *T)
    {
        node *temp;
        if(T==NULL) return;
        s(T->lc);
        s(T->rc);
        temp = T->lc;
        T->lc = T->rc;
        T->rc = temp; 
    }
    int h(node *T)
    {
         if (T == NULL)
            return 0;
        int leftHeight = h(T->lc);
        int rightHeight = h(T->rc);
        return max(leftHeight, rightHeight) + 1;
    }
    
    int leaf(node *T)
    {
        if(T==NULL) 
            return 0;
        if(T->lc == NULL && T->rc == NULL) 
            return 1;
        else 
            return leaf(T->lc)+leaf(T->rc);
    }
    int internalNode(node *T)
    {
        if(T==NULL || T->lc == NULL && T->rc == NULL)
            return 0;
        return 1 + internalNode(T->lc) + internalNode(T->rc);
    }
    void dt(node *T)
    {
        if(T==NULL) return;
        dt(T->lc);
        dt(T->rc);
        cout<<"Deleting Node "<<T->data<<endl;
        delete T;
    }
    void levelOrder() {
        if (root == nullptr)
            return;

        queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            node* front = q.front();
            q.pop();
            cout << front->data << " ";
            if (front->lc != nullptr)
                q.push(front->lc);
            if (front->rc != nullptr)
                q.push(front->rc);
        }
        cout << endl;
    }
    
    public:
    
    BinaryTree()
    {
        root=NULL;
    }

    
    void cR()
    {
        root=createR();
    }
    
    void traversal()
		{
			cout<<"Inorder traversal : "<<endl;
			inorder(root);
			cout<<"\nPreorder traversal : "<<endl;
			preorder(root);
			cout<<"\nPostorder traversal : "<<endl;
			postorder(root);
			cout<<"\nNon Recur Inorder traversal"<<endl;
			inorderNR(root);
            cout<<"\nNon Recur Inorder traversal DESCENDING"<<endl;
			inorderNRD(root);
			cout<<"\nNon Recur Preorder traversal"<<endl;
			preorderNR(root);
			cout<<"\nNon Recur Postorder traversal"<<endl;
			postorderNR(root);
            cout<<"\nlevel wise traversal"<<endl;
			levelOrder();
		}
    
    void swap()
    {
        s(root);
        inorder(root);
        cout<<endl;
    }
    

    void height()
    {
        cout<<"Height is "<<h(root)<<endl;
    }
  
    
    void number()
    {
        cout<<"No. of leaf: "<<leaf(root)<<endl;
        cout<<"No. of internal node: "<<internalNode(root)<<endl;
    }
   
    void deleteAll()
    {
        dt(root);
    }
};

int main(){
    BinaryTree t,t1;
    t.cR();
    t.traversal();
    t.swap();
    t.height();
    t.number();
    t.deleteAll();
    return 0;
}
