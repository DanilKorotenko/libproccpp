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

TCPSocketInfo::PtrT SocketFileDescriptorInfo::getTCPSocketInfo()
{
    if (!this->isTCP())
    {
        return nullptr;
    }

    TCPSocketInfo::PtrT result = TCPSocketInfo::PtrT(new TCPSocketInfo(_socketInfo.psi.soi_proto.pri_tcp));
    return result;
}

} // namespace libproccpp
