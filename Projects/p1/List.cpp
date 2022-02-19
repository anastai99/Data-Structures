#include <iostream>

#include "List.h"

using std::cout;
using std::endl;


namespace ds {
    Node::Node(int v){
        val = v;
    }

    DoublyLinkedList::DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    DoublyLinkedList::DoublyLinkedList(int arr[], int size)  {
        // your code
        if (size == 0){
            head = nullptr;
            tail = nullptr;
            length = 0;
            return;
        }
        if (size == 1){
            head = new Node(arr[0]);
            head->next = nullptr;
            head->prev = nullptr;
            tail = head;
            length = 1;
            return;
        }
        length = size;
        head = new Node(arr[0]);
        head->prev = nullptr;
        Node *temp = head;

        for(int i = 1; i < size; i++){

           Node *node= new Node(arr[i]);
           node->prev = temp;
           temp->next = node;
           
        
            if (i == size-1){
                Node *node = new Node(arr[i]);
                node->prev = temp;
                temp->next = node;
                tail = node;
                tail->next = nullptr;
            }
            temp = node;           
        }

    }
    
    void DoublyLinkedList::Insert(int idx, int v) {
        if(idx > length || idx < 0){
            return; //returns without changing if idx > length or idx is negative
        }
        if(length==0){
            head = new Node(v);
            head->next = nullptr;
            head->prev = nullptr;
            tail = head;
            length = 1;
            return;
        }
        if (idx == 0){
            Node *node = new Node(v);
            node->next = head;
            head->prev = node;
            node->prev = nullptr;
            head = node;
            length = length + 1;
            return;
        }

        if (length == idx){
           Node *node = new Node(v);
           node->prev = tail;
           tail->next = node;
           tail = node;
           tail->next = nullptr;
           length = length +1;
           return;

       }

        Node *temp = head;
        int idex = 0;
        while(idex < length){

            if (idex == idx) {
                Node *node = new Node(v); //creates the new
                                          //node
                node->next = temp;
                node->prev = temp->prev;
                (temp->prev)->next = node;
                temp->prev = node;
                
                length = length + 1;
                return;
            }
            
            temp = temp->next;
            idex++;
        }
    }
    

    void DoublyLinkedList::Remove(int idx) {
        // Your code

        if(idx > length || idx < 0 || length == 0){
            return; 
        }

        if(length == 1){
            head = nullptr;
            tail = head;
            length = 0;
            return;
        }

        if (idx == 0){
            Node *node = head;
            head = head->next;
            head->prev = nullptr;
            length = length - 1;
            return;
        }

        if (idx == length-1){
            Node *node = tail;
            tail = tail->prev;
            tail->next = nullptr;
            length = length - 1;
            return;

        }

        Node *temp = head;
        int idex = 0;
        while(idex < length){
            if(idx == idex){
                Node *node = temp;
                (temp->next)->prev = temp->prev;
                (temp->prev)->next = temp->next;
                length = length - 1;
            }

            temp = temp->next;
            idex += 1;

        }
       
     


        return;
        
    }

    int DoublyLinkedList::Get(int idx) {
        // Your code

        if (idx >= length || idx < 0){
            return -1;
        }

        Node *temp = head;

        if (idx == 0){
           return temp->val;
        }


        int idex = 0;
        while(idex < length){
            temp = temp->next;
            idex++;
            if(idex == idx){
                return temp ->val;
            }    
              
        }
  


        return temp->val;
    }

    int DoublyLinkedList::Search(int v) {
        // Your code

        Node *temp = head;
        int idx = 0;
        while (temp->val != v ){
            idx = idx + 1;
            temp = temp->next;
            if (temp == nullptr ){
                return -1;
            }

        }
        return idx;
    }

    void DoublyLinkedList::ReverseList()  {
     
        // Your code
        
        if(length <= 1){
            return;
        }
        Node *temp;
        Node *temp1 = head;
        Node *temp2 =  head->next;
        Node *temp_h = head;
        head = tail;
        tail = temp_h;

        while(temp1 != NULL){
            temp = temp1 ->prev;
            temp1->prev = temp1->next;
            temp1->next = temp;
            
            if (temp2 != nullptr) {
            temp1 = temp2;
            temp2 = temp1->next;}
            else{temp1 = NULL;}

        }
        
        return;

    }

    void DoublyLinkedList::PrintList()  {
        // Your code
        Node *temp = head;
        while (temp != NULL ){
            if (temp == tail){
                cout << temp->val << endl;
                return;
            }
            cout << temp->val << " ";
            temp = temp->next;

        }
        
        return;
        
    }

    void DoublyLinkedList::MergeList(DoublyLinkedList *list)  {
        // Your code
        if (list->head == nullptr && list->tail == nullptr ){
            return;
        }


       

        Node *node = tail;
        (list->head)->prev = node;
        tail->next = list->head;
        tail = list->tail;
        length = list->length + length;



       
        

        
        return;
        
    }
}