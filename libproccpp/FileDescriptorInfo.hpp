//
//  FileDescriptorInfo.hpp
//  testlibproccpp
//
//  Created by Danil Korotenko on 11/3/23.
//

#ifndef FileDescriptorInfo_hpp
#define FileDescriptorInfo_hpp

#include <stdio.h>
#include <memory>
#include <libproc.h>

namespace libproccpp
{

class FileDescriptorInfo
{
public:
    typedef std::shared_ptr<FileDescriptorInfo> PtrT;

    enum class FileDescriptorType
    {
        ATALK =     PROX_FDTYPE_ATALK       // 0
        , VNODE =   PROX_FDTYPE_VNODE       // 1
        , SOCKET =  PROX_FDTYPE_SOCKET      // 2
        , PSHM =    PROX_FDTYPE_PSHM        // 3
        , PSEM =    PROX_FDTYPE_PSEM        // 4
        , KQUEUE =  PROX_FDTYPE_KQUEUE      // 5
        , PIPE =    PROX_FDTYPE_PIPE        // 6
        , FSEVENTS = PROX_FDTYPE_FSEVENTS   // 7
        , NETPOLICY = PROX_FDTYPE_NETPOLICY // 9
        , CHANNEL = PROX_FDTYPE_CHANNEL     // 10
        , NEXUS =   PROX_FDTYPE_NEXUS       // 11
    };


    FileDescriptorInfo(struct proc_fdinfo aFdInfo);

    FileDescriptorType getType();
    bool isSocket();

private:
    struct proc_fdinfo _fdInfo;
};

} // namespace libproccpp

#endif /* FileDescriptorInfo_hpp */
