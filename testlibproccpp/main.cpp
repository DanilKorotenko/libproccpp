//
//  main.cpp
//  testlibproccpp
//
//  Created by Danil Korotenko on 11/3/23.
//

#include <iostream>

#include "../libproccpp/libproccpp.hpp"

int main(int argc, const char * argv[])
{
    std::cout << "Hello, libprccpp!" << std::endl;

    std::vector<pid_t> allPids = libproccpp::getAllPids();

    std::cout << "Processes count: " << allPids.size() << std::endl;


    return 0;
}
