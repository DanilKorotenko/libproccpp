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

    std::cout << "PID" << "\t\t"
        << "kind" << "\t"
        << "state" << "\t"
        << "localPort" << "\t"
        << "foreignPort" << "\t"
        << std::endl;

    for (libproccpp::ProcessInfo::PtrT procInfo: allPids)
    {
        std::vector<libproccpp::FileDescriptorInfo::PtrT> fileDescriptors = procInfo->getAllFileDescriptors();
        for (libproccpp::FileDescriptorInfo::PtrT fileDescriptorInfo: fileDescriptors)
        {
            libproccpp::SocketFileDescriptorInfo::PtrT socketInfo = fileDescriptorInfo->getSocketInfo();
            if (socketInfo)
            {
                libproccpp::TCPSocketInfo::PtrT tcpInfo = socketInfo->getTCPSocketInfo();
                if (tcpInfo)
                {
                    std::cout << procInfo->getPid() << "\t"
                        << "tcp" << "\t\t"
                        << tcpInfo->getStateString() << "\t"
                        << tcpInfo->getLocalPort() << "\t"
                        << tcpInfo->getForeignPort() << "\t"
                        << std::endl;

                }

            }
        }
    }

    return 0;
}
