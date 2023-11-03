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

SocketFileDescriptorInfo::SocketInfoKind SocketFileDescriptorInfo::getKind()
{
    return static_cast<SocketInfoKind>(_socketInfo.psi.soi_kind);
}

bool SocketFileDescriptorInfo::isTCP()
{
    return this->getKind() == SocketInfoKind::TCP;
}

} // namespace libproccpp
