#include <iostream>
#include <string>
#include <random>
std::string generate(int length,bool includeSpecialChars,bool includeUpperCase,bool includeNums);
int main(int argc, const char * argv[]) {
    int length=12;
    bool includeSpecialChars=0,includeUpperCase=1,includeNumbers=1,set_up,again;

    do {
        std::cout << "Set up password generation? (1 - yes, 0 - no): ";
        std::cin >> set_up;
        if (set_up) {
            std::cout << "Enter the password length: ";
            std::cin >> length;

            std::cout << "Include special characters? (1 - yes, 0 - no): ";
            std::cin >> includeSpecialChars;

            std::cout << "Include Uppercase letters? (1 - yes, 0 - no): ";
            std::cin >> includeUpperCase;

            std::cout << "Include Numbers? (1 - yes, 0 - no): ";
            std::cin >> includeNumbers;
        }
        std::string password = generate(length, includeSpecialChars, includeUpperCase, includeNumbers);
        std::cout << "Generated password = " << password << std::endl;

        std::cout<<"Generate again? (1 - yes, 0 - no): ";
        std::cin>>again;

    }while(again);
    return 0;
}
std::string generate(int length,bool includeSpecialChars,bool includeUpperCase,bool includeNums){
    if(length<=0)
        return {};
    const std::string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    const std::string specialChars = "!@#$%^&*()_-";
    const std::string upperCaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string numbers = "0123456789";
    
    std::string allChars=lowercaseChars;
    if(includeSpecialChars)
        allChars+=specialChars;
    if(includeUpperCase)
        allChars+=upperCaseChars;
    if(includeNums)
        allChars+=numbers;
    
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0,allChars.size());

    std::string password;
    for(int i=0;i<length;++i)
    {
        int index=distribution(generator);
        password+=allChars[index];
    }
    return password;
}
