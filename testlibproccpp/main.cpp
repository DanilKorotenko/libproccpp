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

    std::vector<libproccpp::ProcessInfo::PtrT> allPids = libproccpp::getAllProcesses();

    std::cout << "Processes count: " << allPids.size() << std::endl;

    for (libproccpp::ProcessInfo::PtrT procInfo: allPids)
    {
        std::cout << "Process: " << procInfo->getPid() << std::endl;

    }

    return 0;
}
