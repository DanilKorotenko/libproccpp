//
//  SocketFileDescriptorInfo.cpp
//  testlibproccpp
//
//  Created by Danil Korotenko on 11/3/23.
//

#include "SocketFileDescriptorInfo.hpp"

namespace libproccpp
{

SocketFileDescriptorInfo::SocketFileDescriptorInfo(struct socket_fdinfo aSocketInfo)
    : _socketInfo(aSocketInfo)
{

}

} // namespace libproccpp
