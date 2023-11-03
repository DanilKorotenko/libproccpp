//
//  TCPSocketInfo.hpp
//  testlibproccpp
//
//  Created by Danil Korotenko on 11/3/23.
//

#ifndef TCPSocketInfo_hpp
#define TCPSocketInfo_hpp

#include <stdio.h>
#include <memory>
#include <string>
#include <libproc.h>

namespace libproccpp
{

class TCPSocketInfo
{
public:
    typedef std::shared_ptr<TCPSocketInfo> PtrT;

    enum class TCPSocketState
    {
        CLOSED =        TSI_S_CLOSED            // 0       /* closed */
        , LISTEN =        TSI_S_LISTEN            // 1       /* listening for connection */
        , SYN_SENT =      TSI_S_SYN_SENT          // 2       /* active, have sent syn */
        , SYN_RECEIVED =  TSI_S_SYN_RECEIVED      // 3       /* have send and received syn */
        , ESTABLISHED =   TSI_S_ESTABLISHED       // 4       /* established */
        , _CLOSE_WAIT =   TSI_S__CLOSE_WAIT       // 5       /* rcvd fin, waiting for close */
        , FIN_WAIT_1 =    TSI_S_FIN_WAIT_1        // 6       /* have closed, sent fin */
        , CLOSING =       TSI_S_CLOSING           // 7       /* closed xchd FIN; await FIN ACK */
        , LAST_ACK =      TSI_S_LAST_ACK          // 8       /* had fin and close; await FIN ACK */
        , FIN_WAIT_2 =    TSI_S_FIN_WAIT_2        // 9       /* have closed, fin is acked */
        , TIME_WAIT =     TSI_S_TIME_WAIT         // 10      /* in 2*msl quiet wait after close */
        , RESERVED =      TSI_S_RESERVED          // 11      /* pseudo state: reserved */
    };

    enum class TCPSocketType
    {
        IPv4 = 0
        , IPv6
    };

    TCPSocketInfo(struct tcp_sockinfo aTcpInfo);

    TCPSocketType getType();
    bool isIPv4();

    TCPSocketState getState();
    std::string getStateString();

    int getLocalPort();
    int getForeignPort();

private:
    struct tcp_sockinfo _tcpInfo;
};

} // namespace libproccpp

#endif /* TCPSocketInfo_hpp */
