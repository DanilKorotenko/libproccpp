//
//  FileDescriptorInfo.cpp
//  testlibproccpp
//
//  Created by Danil Korotenko on 11/3/23.
//

#include "FileDescriptorInfo.hpp"
#include <libproc.h>

namespace libproccpp
{

FileDescriptorInfo::FileDescriptorInfo(struct proc_fdinfo aFdInfo, pid_t aParentPid)
    : _fdInfo(aFdInfo)
    , _parentPid(aParentPid)
{

}

FileDescriptorInfo::FileDescriptorType FileDescriptorInfo::getType()
{
    return static_cast<FileDescriptorInfo::FileDescriptorType>(_fdInfo.proc_fdtype);
}

bool FileDescriptorInfo::isSocket()
{
    return this->getType() == FileDescriptorInfo::FileDescriptorType::SOCKET;
}

SocketFileDescriptorInfo::PtrT FileDescriptorInfo::getSocketInfo()
{
    if (!this->isSocket())
    {
        return nullptr;
    }

    struct socket_fdinfo sinfo;

    // returns the number of bytes of data returned in the provided buffer;
    //               -1 if an error was encountered
    int res = proc_pidfdinfo(_parentPid, _fdInfo.proc_fd, PROC_PIDFDSOCKETINFO, &sinfo,
        sizeof(struct socket_fdinfo));

    if (res <= 0)
    {
        /* process may have exited or socket may have
        * been released. */
        return nullptr;
    }

    SocketFileDescriptorInfo::PtrT result = SocketFileDescriptorInfo::PtrT(new SocketFileDescriptorInfo(sinfo));

    return result;
}

} // namespace libproccpp
