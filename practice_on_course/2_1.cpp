#include<iostream>
#include<vector>
std::tuple<std::string, std::string, std::string> getClassInfo() {
    std::string className = "CS106L";
    std::string location = "online";
    std::string language = "C++";
    return {className, location, language};
}
int main() {
    auto [className, location, language] = getClassInfo();
    std::cout << "Join us " << location << " for " << className << " to learn " << language << "!" << std::endl;
    return 0;
}