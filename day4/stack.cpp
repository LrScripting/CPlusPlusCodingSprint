# custom stack implementation for AlgoXplorer tool 
#include <iostream> 
#include <vector>
#include <cstdarg>
#include <cmath>

class cStack {
    
public:

    cStack(int capacity) : capacity(capacity), stackVector(capacity){}

    void push(const std::vector<int>& values) {
        for (const int& value : values) {
            if (stackVector.size() < capacity) {
                stackVector.insert(stackVector.begin(), value);
            } else {
                // Handle the case of stack overflow (you can throw an exception or take appropriate action)
                break;
            }
        }
    }

    void resizePush(const std::vector<int>& values) {
        for (const int& value : values) {
            if (stackVector.size() < capacity) {
                stackVector.resize(capacity + static_cast<int>(std::round(capacity / 3.0)));
            } 
                // Handle the case of stack overflow (you can throw an exception or take appropriate action)
            stackVector.insert(stackVector.begin(), value); 
            
        }
    }


    void pop(){
        stackVector.erase(stackVector.begin());
    }

    int top(){
        if(!isEmpty){
            return stackVector.front();
        }
        
    }

    bool isfull(){
        stackVector.size() == capacity;
    }

    bool isEmpty(){
        return stackVector.empty();
    }

    void clear(){
        stackVector.clear();
    }


    void reverseStack(){
        std::vector<int> newVector(capacity);
        for (int i = 0; i < capacity; i++){
            newVector.insert(newVector.begin(), stackVector[i]);
            
        }
        
        stackVector = newVector;
    }

private:
    int capacity;
    std::vector<int> stackVector;
    
};
