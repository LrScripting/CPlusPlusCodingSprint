

#include <iostream>

void fizzbuzz(int value){   
    if(value % 3 == 0 && value % 5 == 0){
        std::cout<<"fizzbuzz"<<"\n";
    }

    else if(value % 3 == 0){
        std::cout<<"fizz"<<"\n";
        }
    else if(value % 5 == 0){
        std::cout<<"buzz"<<"\n";
    }
};

int main(void){
    int fizz = 3;
    int buzz = 5;
    int fizzbuzzval = 15;
    fizzbuzz(fizz);
    fizzbuzz(buzz);
    fizzbuzz(fizzbuzzval);

    return 0;

}
