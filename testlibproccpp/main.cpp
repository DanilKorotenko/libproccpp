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

        std::vector<libproccpp::FileDescriptorInfo::PtrT> fileDescriptors = procInfo->getAllFileDescriptors();
        std::cout << "FileDescriptors: " << fileDescriptors.size() << std::endl;

        for (libproccpp::FileDescriptorInfo::PtrT fileDescriptorInfo: fileDescriptors)
        {
            std::cout << "FileDescriptor isSocket: " << (fileDescriptorInfo->isSocket() ? "true" : "false")
                << std::endl;

        }
    }

    return 0;
}
