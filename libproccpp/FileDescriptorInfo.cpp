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

FileDescriptorInfo::FileDescriptorInfo(struct proc_fdinfo aFdInfo)
    : _fdInfo(aFdInfo)
{

}

} // namespace libproccpp
