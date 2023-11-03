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


//int TCPSocketInfo::getPort()
//{
//    return _tcpInfo;
//}


} // namespace libproccpp
