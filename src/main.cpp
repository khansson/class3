#include <iostream>

#include "SummingExamples.hpp"


int main(int argc, char** argv)
{

    int Size{2};

    if (argc > 1)
    {
        Size = std::atoi(argv[1]);
    }




    auto CStyleResult =     CStyle();
    auto CppStyleResult =     CppStyle();

    auto CStyleResult_VariableSize =     CStyle(Size);
    auto CppStyleResult_VariableSize =     CppStyle(Size);

    std::cout << "Results: " ;
    std::cout << CStyleResult << ", ";
    std::cout << CppStyleResult << ", ";
    std::cout << CStyleResult_VariableSize << ", ";
    std::cout << CppStyleResult_VariableSize << std::endl;




}