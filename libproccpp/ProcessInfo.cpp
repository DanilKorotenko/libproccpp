//
//  ProcInfo.cpp
//  testlibproccpp
//
//  Created by Danil Korotenko on 11/3/23.
//

#include "ProcessInfo.hpp"
#include <libproc.h>

namespace libproccpp
{

ProcessInfo::ProcessInfo(pid_t aPid)
    : _pid(aPid)
{

}

std::vector<FileDescriptorInfo::PtrT> ProcessInfo::getAllFileDescriptors()
{
    std::vector<FileDescriptorInfo::PtrT> result;
    /* fetch fd info for this pid */
    int fd_count = proc_pidinfo(_pid, PROC_PIDLISTFDS, 0, NULL, 0);
    if (fd_count > 0)
    {
        struct proc_fdinfo *fds = (struct proc_fdinfo *)malloc(PROC_PIDLISTFD_SIZE * fd_count);
        if (fds)
        {
            fd_count = proc_pidinfo(_pid, PROC_PIDLISTFDS, 0, fds, sizeof(fds[0]) * fd_count);
            if (fd_count > 0)
            {
                for (int i = 0; i <fd_count; i++)
                {
                    result.push_back(FileDescriptorInfo::PtrT(new FileDescriptorInfo(fds[i], getPid())));
                }
            }
            free(fds);
        }
    }
    return result;
}

pid_t ProcessInfo::getPid()
{
    return _pid;
}

} // namespace libproccpp
