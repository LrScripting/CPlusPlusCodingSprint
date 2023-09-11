#include <iostream>
#include <vector>
#include <algorithm>

struct node {
    int value;
    node* next;
    node* prev;
};


class dLinkedList{
public:
    dLinkedList(node*& head) : head(head), tail(head){}; 

    void addItem(int value) {
        node* newNode = new node;
        newNode->value = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        tail->next = nullptr;

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            if (head->next == nullptr) { // Update the next pointer of the head node
                head->next = newNode;
            }
        }
    }
    node* getHead(){
        return head;
    }
    void removeItem(int& value){
        if(!head){
            return;
        }
        if(head->value == value){
            if(head->next){
                head = head->next;
                head->prev = nullptr;
            }else{
                head = nullptr;
                return;
            }
        }


        node* current = head;
        node* target = nullptr;
        while(current->next && current->next->value!= value){
            current = current->next;

        }
        if(!current->next){
            return;
        }
        else{
            target = current->next;
            if(target->next){
                current->next = target->next;
                target->prev = current;
                
            }
            else{
                current->next = nullptr;
            }
            delete target;
        }
    
    }
    void display() {
        if (head) {
            node* current = head;
            while (current) {
                std::cout << current->value << "\n";
                current = current->next;
            }
        } else {
            std::cout << "empty list" << std::endl;
        }
    }
    int getLength(){
        int counter = 0;
        if(head){
            node* current = head;
            while(current){
                counter++;
                current = current->next;
            }
            return counter;

        }else{
            return counter;
        }
    }
    std::vector<int> getPosition(int value){
        int counter = 1;
        if(head){
            node* current = head;
            while(current->value != value){
                counter++;
                current= current->next;
            }
            return std::vector<int> {value, counter};
        }
        else{
            return std::vector<int> {0,0};
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
        tail = nullptr;
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
    node* tail;
};

int main(void) {
    node* kek = new node;
    kek->next = nullptr;
    kek->prev = nullptr;
    kek->value = 5;
    dLinkedList ll(kek);
    
    int item2 = 10;
    int item3 = 20;
    int item4 = 1;
    int item5 = 2;
    ll.addItem(item3);
    ll.addItem(item2);
    ll.addItem(item5);
    ll.addItem(item4);
    ll.sortList();
    ll.display();
 
    



}
