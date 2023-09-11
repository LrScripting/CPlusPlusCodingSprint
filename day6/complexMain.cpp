//main file for my complex visualizer, cli tool 
#include "../include/complex.h"
#include "../include/drawingfunctions.h"
#include <raylib.h>
#include <string>

#include <iostream>
#include <cstdlib>
#include <vector>
#include "complex.h"



std::vector<int> cordTranslator(std::vector<int> kek){
    return {kek[0]*30, kek[1]*30};
}

void drawCNumber(int r, int i, int screenWidth, int screenHeight){

    std::vector<int> cordinates = cordTranslator({r, i});
    
    DrawCircle(screenWidth/2+cordinates[0], screenHeight/2-cordinates[0], 10, RED);
}




int main(int argc, char* argv[]){
    if (argc != 6) {
        std::cout << "Usage: " << argv[0] << " <operation> <real> <imaginary> <initial_real> <initial_imaginary>" << std::endl;
        return 1;
    }
    std::string operation = argv[1];
    int real = std::atoi(argv[2]);
    int imaginary = std::atoi(argv[3]);
    int initialReal = std::atoi(argv[4]);
    int initialImaginary = std::atoi(argv[5]);

    int screenWidth = 2000;
    int screenHeight = 2000;

    InitWindow(screenWidth, screenHeight, "Complex Plane");
    
    

    std::vector<int> kek = {initialReal, initialImaginary};
    Complex<int> C(kek);
    if (operation == "add") {
        C.addition(real, imaginary);
    } else if (operation == "subtract") {
        C.subtraction(real, imaginary);
    } else {
        std::cout << "Invalid operation. Use 'add' or 'subtract'." << std::endl;
        return 1;
    }
    std::vector<int> cordinates = C.getValue();
    

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(GRAY);
        drawCNumber(cordinates[0], cordinates[1], screenWidth, screenHeight);
        
        graphBackground(screenWidth, screenHeight);
        
    
        EndDrawing();
    }
    return 0;
}
