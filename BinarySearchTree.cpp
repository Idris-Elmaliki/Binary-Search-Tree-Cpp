#include <iostream>

template<class T>
class Node {
public: 
    T data; 
    Node<T>* left; 
    Node<T>* right; 

    Node(const T& data) 
    : data(data){
        left = nullptr; 
        right = nullptr; 
    }
};

template<class T>
class BinarySearchTree {
    Node<T>* root; 

public:
    BinarySearchTree() { 
        root = nullptr; 
    }

    bool insert(const int &data) {
        Node<T>* newNode = new Node<T>(data); 

        if(root == nullptr) {
            root = newNode; 
            return true; 
        }
        
        Node<T>* temp = root; 

        while(true) {
            if(newNode->data == temp->data)
                return false; 
            
            if(newNode->data < temp->data) {
                if(temp->left == nullptr) {
                    temp->left = newNode; 
                    break; 
                }
                temp = temp->left;  
            }
            else {
                if(temp->right == nullptr) {
                    temp->right = newNode; 
                    break; 
                }
            
                temp = temp->right;
            }
        }
    
        return true; 
    }

    bool Contains(const int &data) {
        Node<T>* temp = root; 

        while(temp != nullptr) {
            if(data < temp->data) {
                temp = temp->left; 
            }
            else if(data > temp->data) {
                temp = temp->right; 
            }
            else {
                return true; 
            }
        }

        return false; 
    }
};