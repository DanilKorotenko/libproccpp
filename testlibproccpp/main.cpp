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
        std::vector<libproccpp::FileDescriptorInfo::PtrT> fileDescriptors = procInfo->getAllFileDescriptors();
        for (libproccpp::FileDescriptorInfo::PtrT fileDescriptorInfo: fileDescriptors)
        {
            libproccpp::SocketFileDescriptorInfo::PtrT socketInfo = fileDescriptorInfo->getSocketInfo();
            if (socketInfo)
            {
                std::cout << procInfo->getPid() << "\t" << "socket" << std::endl;

            }
        }
    }

    return 0;
}
