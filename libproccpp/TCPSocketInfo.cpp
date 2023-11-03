//
//  TCPSocketInfo.cpp
//  testlibproccpp
//
//  Created by Danil Korotenko on 11/3/23.
//

#include "TCPSocketInfo.hpp"

namespace libproccpp
{

TCPSocketInfo::TCPSocketInfo(struct tcp_sockinfo aTcpInfo)
    : _tcpInfo(aTcpInfo)
{

}

TCPSocketInfo::TCPSocketType TCPSocketInfo::getType()
{
    if (_tcpInfo.tcpsi_ini.insi_vflag == INI_IPV4)
    {
        return TCPSocketType::IPv4;
    }
    return TCPSocketType::IPv6;
}

bool TCPSocketInfo::isIPv4()
{
    return this->getType() == TCPSocketType::IPv4;
}

TCPSocketInfo::TCPSocketState TCPSocketInfo::getState()
{
    return static_cast<TCPSocketState>(_tcpInfo.tcpsi_state);
}

std::string TCPSocketInfo::getStateString()
{
    switch (this->getState())
    {
        case TCPSocketState::CLOSED:        { return "CLOSED"; }
        case TCPSocketState::LISTEN:        { return "LISTEN"; }
        case TCPSocketState::SYN_SENT:      { return "SYN_SENT"; }
        case TCPSocketState::SYN_RECEIVED:  { return "SYN_RECEIVED"; }
        case TCPSocketState::ESTABLISHED:   { return "ESTABLISHED"; }
        case TCPSocketState::_CLOSE_WAIT:   { return "_CLOSE_WAIT"; }
        case TCPSocketState::FIN_WAIT_1:    { return "FIN_WAIT_1"; }
        case TCPSocketState::CLOSING:       { return "CLOSING"; }
        case TCPSocketState::LAST_ACK:      { return "LAST_ACK"; }
        case TCPSocketState::FIN_WAIT_2:    { return "FIN_WAIT_2"; }
        case TCPSocketState::TIME_WAIT:     { return "TIME_WAIT"; }
        case TCPSocketState::RESERVED:      { return "RESERVED"; }
    }
    return "";
}


int TCPSocketInfo::getLocalPort()
{
    return (int)ntohs(_tcpInfo.tcpsi_ini.insi_lport);
}

int TCPSocketInfo::getForeignPort()
{
    return (int)ntohs(_tcpInfo.tcpsi_ini.insi_fport);
}


} // namespace libproccpp
