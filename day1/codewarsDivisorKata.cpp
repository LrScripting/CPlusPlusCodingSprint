 int divisors(int &value){
          int counter = 0;
          for (int i = 1; i<value; i++){
                  if( value % i == 0){
                          counter++;
                          }
                  }
          return counter;}
  int main(){
          int lol = 20;
          int kek = divisors(lol);
          std::cout<<kek<<std::endl;
          return 0;
  }
