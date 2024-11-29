#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this-> data = data;
        left = NULL;
        right = NULL;
    }
};
// LEFT OR RIGHT TRAVERSE
// AGAR DONO NULL HO TO PRINT
// WARNA JAHAPE MILEGA USIPE DHOKO
void lastNodePrint(Node* node){
    if(node->left == NULL && node->right == NULL){
        cout << node->data << " ";
        return;
    }
    if(node->left){
        lastNodePrint(node->left);
    }
    if(node->right){
        lastNodePrint(node->right);
    }
}

int levelMeasure(Node* node){
    if(node == NULL){
        return 0;
    }
    int l = levelMeasure(node->left);
    int r = levelMeasure(node->right);
    return max(l,r)+1;
}

bool identical(Node* node1,Node* node2){
    if(node1 == NULL && node2 == NULL){
        return true;
    }
    if(node1 == NULL || node2 == NULL){
        return false;
    }
    if(node1->data != node2->data){
        return false;
    }
    if(identical(node1->left,node2->left) == false){
        return false;
    }
    if(identical(node1->right,node2->right) == false){
        return false;
    }
    return true;
}

int main(){
    Node* head1 = new Node(10);
    head1->left = new Node(20);
    head1->right = new Node(30);
    head1->left->left = new Node(40);
    head1->left->right = new Node(50);
    head1->left->right->left = new Node(90);
    head1->right->left = new Node(60);
    head1->right->left->right = new Node(80);

    Node* head2 = new Node(10);
    head2->left = new Node(20);
    head2->right = new Node(30);
    head2->left->left = new Node(40);
    head2->left->right = new Node(50);
    head2->left->right->left = new Node(90);
    head2->right->left = new Node(60);
    head2->right->left->right = new Node(80);
    // lastNodePrint(head1);
    // int llength,rlength,len = 0;

    // cout << levelMeasure(head1);
    cout << identical(head1,head2);
    return 0;
}