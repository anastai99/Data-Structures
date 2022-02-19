#include "avl.h"
#include <iostream>
#include <queue>


using namespace std;

void AVL::rotateLeft(Node *& node) {
    Node *tmp = node->right;
    node->right = tmp->left;
    tmp->left = node; 
    node = tmp;
    return;
}

void AVL::rotateRight(Node *& node) {
    Node *tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    node = tmp;
    return;
}

void AVL::rotateLeftRight(Node *& node) {
    rotateLeft(node->left);
    rotateRight(node);
    return;
}

void AVL::rotateRightLeft(Node *& node) {
    rotateRight(node->right);
    rotateLeft(node);
    return;
}

int getHeight(Node *node) {
    return node == nullptr ? -1 : node->height;
}

int computeHeight(Node *root){

if(root == nullptr){
    return -1;
} else {
    int hLeft = computeHeight(root->left);
    int hRight = computeHeight(root->right);
    return std::max(hLeft,hRight) + 1;
}

}

void balance(AVL * avl, int balance, Node * n, int v){
    //n is the node prior to the node we want to balance at and 
    //v is the value of the node we want to balance
    
}

void insert_helper(Node * root, const int &v, queue<Node *> * q){
    if (v < root->val){
        //q->push('L');
        if(root->left == nullptr){
            Node *m = new Node(v);
            root->left = m;
            root->height += 1;
            q->push(root);
            cout << "root->val2:" << root->val << endl;
            //return q;
        } else{
            insert_helper(root->left, v, q);
            cout << "root of " << root->val << "was added to the q on left" << endl;
            q->push(root);
        }

    } else if (v > root->val){
        //q->push('R');
        if(root->right == nullptr){
            Node *m = new Node(v);
            root->right = m;
            root->height += 1;
            q->push(root);
            cout << "(root->right)->val3:" << (root->right)->val << endl;
            //return q;
        } else{
            insert_helper(root->right, v, q);
            cout << "root of " << root->val << "was added to the q on right" << endl;
            q->push(root);
        }

     } else if(v == root->val){
        return;
     }

}

void AVL::insert(const int &v) {
    // your code
    // <50 lines of code should be OK

    //normal BST insertion
    queue<Node *> AVL_; 
    if(getHeight(root) == -1){
        root = new Node(v);
        cout << "root->val1:" << root->val << endl;
        return;  //for first new elements
    } else{ 
        insert_helper(root, v, &AVL_);
        cout << "AVL size():" << AVL_.size() << endl;
    }

    Node * current_node;
    Node * parent;
    while(!AVL_.empty()){
        current_node = AVL_.front();
        AVL_.pop();
        if (!AVL_.empty()){
            parent = AVL_.front();
        }
        //checking if balance and if not then balance it
        int balance = computeHeight(current_node->left) - computeHeight(current_node->right);
        cout << "balance = "<< balance << "at node: "  << current_node->val << endl;
        
        //left-left case
        if(balance > 1 && v < (current_node->left)->val){
            if (current_node == root){
                rotateRight(root);
            }
            else if (current_node-> val < parent->val){
                rotateRight(parent->left);
            }
            else{
                rotateRight(parent->right);
            }
            cout << "B1" << endl;
            return;
        }

        //right-right case
        else if(balance < -1 && v > (current_node->right)->val){
            if (current_node == root){
                rotateLeft(root);
            }
            else if (current_node-> val < parent->val){
                rotateLeft(parent->left);
            }
            else{
                rotateLeft(parent->right);
            }
            cout << "B2" << endl;
            return;
        }

        //left-right case
        else if(balance > 1 && v > (current_node->left)->val){
            if (current_node == root){
                rotateLeftRight(root);
            }
            else if (current_node-> val < parent->val){
                rotateLeftRight(parent->left);
            }
            else{
                rotateLeftRight(parent->right);
            }
            cout << "B3" << endl;
            return;
        }

        //right-left case
        else if(balance < -1 && v < (current_node->right)->val){
            if (current_node == root){
                rotateRightLeft(root);
            }
            else if (current_node-> val < parent->val){
                rotateRightLeft(parent->left);
            }
            else{
                rotateRightLeft(parent->right);
            }
            cout << "B4" << endl;
            return;
        }

    }

}

void printBT(const string& prefix, const Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        cout << prefix;

        cout << (isLeft ? "├──" : "└──" );

        int balance = getHeight(node->left) - getHeight(node->right);
        // print the value of the node
        cout << " " << node->val << "," << node->height << "," << balance << endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const Node* node)
{
    printBT("", node, false);    
}

// int main(){

//     AVL a;
//     a.insert(1);
//     printBT(a.root);
//     a.insert(2);
//     printBT(a.root);
//     a.insert(3);
//     printBT(a.root);
//     a.insert(5);
//     printBT(a.root);
//     a.insert(200);
//     printBT(a.root);
//     a.insert(20);
//     printBT(a.root);

//     return 0;
// }
