//
//  SocketFileDescriptorInfo.hpp
//  testlibproccpp
//
//  Created by Danil Korotenko on 11/3/23.
//

#ifndef SocketFileDescriptorInfo_hpp
#define SocketFileDescriptorInfo_hpp

#include <stdio.h>
#include <memory>
#include <libproc.h>

namespace libproccpp
{

class SocketFileDescriptorInfo
{
public:
    typedef std::shared_ptr<SocketFileDescriptorInfo> PtrT;

    enum class SocketInfoKind
    {
        GENERIC =   SOCKINFO_GENERIC        // = 0,
        , IN =      SOCKINFO_IN             // = 1,
        , TCP =     SOCKINFO_TCP            // = 2,
        , UN =      SOCKINFO_UN             // = 3,
        , NDRV =    SOCKINFO_NDRV           // = 4,
        , KERN_EVENT = SOCKINFO_KERN_EVENT     // = 5,
        , KERN_CTL = SOCKINFO_KERN_CTL       // = 6,
        , VSOCK = SOCKINFO_VSOCK          // = 7,
    };

    SocketFileDescriptorInfo(struct socket_fdinfo aSocketInfo);

    SocketInfoKind getKind();

    bool isTCP();

private:
    struct socket_fdinfo _socketInfo;
};

} // namespace libproccpp

#endif /* SocketFileDescriptorInfo_hpp */
