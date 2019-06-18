#include <iostream>
#include <string>
#include <sstream>
int main(){
    std::string myText("some-text-to-tokenize");
    std::istringstream iss(myText);
    std::string token;
    while (std::getline(iss, token, '-'))
    {
        std::cout << token << std::endl;
    }
    return 0;
}