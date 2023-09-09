#custom Queue implementation for AlgoXplorer tool 
#include <iostream>
#include <vector>
#include <algorithm>


struct node{
    int value;
    node* next;
};

class sLinkedList{
public:
    sLinkedList(node* head) : head(head){};

    void addItem(int &value){
        node* newNode = new node;
        newNode-> value = value;
        newNode-> next = nullptr;
        if(!head){
            head = newNode;
        }
        else{
            node* current = head;
            while(current->next){
                current = current->next;
            }
            current->next = newNode;
        }

    }

    void removeItem(int& value){
        node* temp = head;
        while(temp->next){
            if(temp->next->value == value){
                node* targetNode = temp->next;
                temp->next = temp->next->next;
                delete targetNode;
                break;
            }

            temp = temp->next;
        }
    }

    std::vector<int> getItemAndPos(int &value){
        node* temp = head;
        int counter = 1;
        if(head->value == value){
            return std::vector<int> {value, counter};
        }
        while(temp->next){
            counter++;
            if(temp->next->value == value){
                
                return std::vector<int> {temp->next->value, counter};
            }
            temp = temp->next;
        }
    }

    int getLength(){
        if(head){
            int counter = 1;
            node* temp = head;
            while(temp->next){
                counter++;
                temp = temp->next;
            }
            return counter;
        }
        else{
            return 0;
        }

    }
    void clearList() {
        node* current = head;
        while (current) {
            node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr; 
    }
    void reverseList() {
        node* prev = nullptr;
        node* current = head;
        node* nextNode = nullptr;

        while (current) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
    }
    void concat(node* seconHead){
        node *temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = seconHead;

    }

    void sortList() {
        std::vector<int> tempList;
        node* temp = head;

        if (!temp) {
            return;
        }

        while (temp) {
            tempList.push_back(temp->value);
            node* target = temp;
            temp = temp->next;
            delete target;
        }

        std::sort(tempList.begin(), tempList.end());

   
        for (int i = 0; i < tempList.size(); i++) {
            node* newNode = new node;
            newNode->value = tempList[i];
            newNode->next = nullptr;

            if (i == 0) {
                head = newNode;
                temp = head;
            } else {
                temp->next = newNode;
                temp = temp->next;
            }
        }
    }

private: 
    node* head;
};
