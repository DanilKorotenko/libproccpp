//
//  ProcInfo.hpp
//  testlibproccpp
//
//  Created by Danil Korotenko on 11/3/23.
//

#ifndef ProcInfo_hpp
#define ProcInfo_hpp

#include <stdio.h>
#include <memory>
#include <vector>

#include "FileDescriptorInfo.hpp"

namespace libproccpp
{

class ProcessInfo
{
public:
    typedef std::shared_ptr<ProcessInfo> PtrT;

    ProcessInfo(pid_t aPid);

    std::vector<FileDescriptorInfo::PtrT> getAllFileDescriptors();

    pid_t getPid();

private:
    pid_t _pid;
};

} // namespace libproccpp

#endif /* ProcInfo_hpp */
