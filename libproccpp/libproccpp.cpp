//
//  libproccpp.cpp
//  testlibproccpp
//
//  Created by Danil Korotenko on 11/3/23.
//

#include "libproccpp.hpp"
#include <libproc.h>

namespace libproccpp
{

std::vector<ProcessInfo::PtrT> getAllProcesses()
{
    std::vector<ProcessInfo::PtrT> result;

    int pid_count = proc_listallpids(NULL, 0);
    if (pid_count > 0)
    {
        pid_t *pids = (pid_t *)malloc(sizeof(pid_t) * pid_count);
        if (pids)
        {
            pid_count = proc_listallpids(pids, sizeof(pid_t) * pid_count);
            if (pid_count > 0)
            {
                for (int i = 0; i < pid_count; i++)
                {
                    result.push_back(ProcessInfo::PtrT(new ProcessInfo(pids[i])));
                }
            }
            free(pids);
        }
    }

    return result;
}

} // namespace libproccpp
