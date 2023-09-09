#custom queue implementation for AlgoXplorer 
#include <iostream> 
#include <vector>
#include <cstdarg>
#include <algorithm>


class cQueue{
public:
    cQueue(int capacity) : capacity(capacity), queueVector(capacity){};
    void push(std::vector<int> values) {
        for (const int& value : values) {
            if (queueVector.size() < capacity) {
                queueVector.insert(queueVector.begin(), value);
            } else {
                queueVector.pop_back();
                queueVector.insert(queueVector.begin(), value);
                break;
            }
        }
    }
    bool isEmpty(){
        return queueVector.empty();
    }
    
    bool isFull(){
        return queueVector.size() == capacity;
    }

    int top(){
        if(!isEmpty()){
            return queueVector[capacity-1];
        }
        else{
            return 0;
        }
        
    }
 
    void pop(){
        if(!isEmpty()){
            queueVector.pop_back();
        }
        
    }
    void popEnd(){
        if(!isEmpty()){
            queueVector.erase(queueVector.begin());
        }
        
    }
    void reverseQueue(){
        std::reverse(queueVector.begin(), queueVector.end());
    }
    void clearQueue(){
        queueVector.clear();
    }
    void inOrderPrint(){
        for (int i = 0; i < capacity; i++){
            std::cout<< queueVector[i];
        }
    }
    void reversePrint(){
        for (int i = capacity - 1; i >= 0; i--){
            std::cout << queueVector[i];
        }
    }

private:
    int capacity;
    std::vector<int> queueVector;
    
};
