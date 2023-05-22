#include <bits/stdc++.h>
using namespace std;


class Node{

public :
    int key;
    Node* left;
    Node* right;

};


class BST{

private:
    Node* root;

    Node* getNewNode(int data){
        Node* temp=new Node;

        temp->key=data;
        temp->left=nullptr;
        temp->right=nullptr;

        return temp;
    }

    void clear(Node* t){
        if (t==nullptr){
            return;
        }
        clear(t->left);
        clear(t->right);
        delete t;

    }

    Node* getMin(Node *t){
        if (t->left != nullptr){
            return getMin(t->left);
        }
        else{
            return t;
        }
    }
    Node* getMax(Node *t){
        if (t->right!=nullptr) return getMax(t->right);
        else return t;
    }
    


   
public:

    BST(){
        root=nullptr;
    }
    ~BST(){
        clear(root);
    }
    
    //Insert
    void Insert(int data){
       
        if (root==nullptr){
            root=getNewNode(data);
            return ;
        }
       

        Node* current=root;
        Node* parent;
        while(current!=nullptr){
            parent=current;
            if (data < current->key){
                current=current->left;
            }
            else{
                current=current->right;
            }
        }

        Node* child=getNewNode(data);
        if (data < parent->key){
            parent->left=child;
        }
        else{
            parent->right=child;
        }

    }

    //Find()
    bool Find(int data){
        if (root==nullptr){
            return false ;
        }
        Node* current=root;
        while (current!=nullptr){
            if (data < current->key){
                current=current->left;
            }
            else if (data > current->key){
                current=current->right;
            }
            else{
                return true;
            }
        }
        return false;
    }

    //Delete()
    void Delete(int data){
        if (!Find(data)){
            cout << "missing that data\n";
            return;
        }
        if (root==nullptr){
            cout <<"Tree is empty\n";
            return ;
        }
        if (root->left==nullptr && root->right==nullptr){
            delete root;
            root=nullptr;

            cout << "Root got deleted\n";
            return;
        }
        Node* current =root;
        Node* parent =root;
        Node* prev;
        while(current!=nullptr){
            prev=parent;
            parent=current;
            if (data < current->key){
                current=current->left;
            }
            else if (data > current->key){
                current=current->right;
            }
            else{
                break;
            }
        }
        if (parent->left==nullptr && parent->right==nullptr){
            if (parent->key < prev->key){
                prev->left=nullptr;
            }
            else prev->right=nullptr;

            delete parent;
            print(4);
        }
        else {
            cout << "Invalid Operation\n";
        }
    }

    

    void currentState(Node* t){
        if(root ==nullptr){
            return;
        } 
        cout << t->key << "";
        if (t->left!=nullptr && t->right==nullptr){
            cout << "(";
            currentState(t->left);
            cout <<")()";

        }
        else if (t->left!=nullptr){
            cout << "(";
            currentState(t->left);
            cout <<")";
        }
        
     
        
        if (t->right!=nullptr && t->left==nullptr){
            cout <<"()(";
            currentState(t->right);
            cout <<")";

        }
        else if (t->right!=nullptr){
            cout <<"(";
            currentState(t->right);
            cout <<")";
    
        }
    }


    //preorder
    void preOrder(Node* t){
        if (root==nullptr){
            cout <<"Tree is empty, so no pre order traversal ";
            return;
        }
        cout << t->key << " ";
       
        if (t->left!=nullptr){
            preOrder(t->left);
        }
        if (t->right!=nullptr){
            preOrder(t->right);
        }
    }
    //inorder
    void inOrder(Node* t){
        if(root ==nullptr){
            cout <<"Tree is empty, so no in order traversal ";
            return;
        } 
       
        if (t->left!=nullptr){
            inOrder(t->left);
        }
        cout << t->key << " ";

        if (t->right!=nullptr){
            inOrder(t->right);
        }     
    }
    //postorder
    void postOrder(Node* t){
        if(root ==nullptr){
            cout <<"Tree is empty, so no post order traversal ";
            return;
        } 
    
        if (t->left!=nullptr){
            postOrder(t->left);
        }
        
        if (t->right!=nullptr){
            postOrder(t->right);
    
        }
        cout << t->key << " ";
    }
    // height 

    int Height(Node* t){
        if (t==nullptr) return -1;
        else {
            return max(Height(t->left),Height(t->right))+1;
        }
    }

    void Height(){
        cout << "height is  "<< Height(root) << endl;
    }

    // Depth
    int Depth(int data){
        if (root==nullptr) return -1;
        
        Node *temp=root;
        int d=0;
        while (temp!=nullptr){
            if (data < temp->key){
                temp=temp->left;
                d++;
            }
            else if (data >  temp->key){
                temp=temp->right;
                d++;
            }
            else {
                return d;
            }
        }
        return -1;

    }
    //total nodes
    int totalNodes(Node *root){
        if(root==nullptr) return 0;
        return 1+totalNodes(root->left) +totalNodes(root->right);
    }
    int totalNodes(){
        return totalNodes(root);
    }

    void print(int i){
        if (i==1){
            inOrder(root);
        }
        else if (i==2){
            preOrder(root);
        }
        else if (i==3){
            postOrder(root);
        }
        else if (i==4){
            currentState(root);
        }
        cout << "\n";
    }
 
    void getMin(){
        cout << getMin(root)->key << endl;
    }
    void getMax(){
        cout << getMax(root)->key << endl;
    }

    
};
