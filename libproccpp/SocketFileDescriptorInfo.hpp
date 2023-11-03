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
    SocketFileDescriptorInfo(struct socket_fdinfo aSocketInfo);
private:
    struct socket_fdinfo _socketInfo;
};

} // namespace libproccpp

#endif /* SocketFileDescriptorInfo_hpp */
