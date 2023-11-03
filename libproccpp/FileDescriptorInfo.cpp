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

FileDescriptorInfo::FileDescriptorType FileDescriptorInfo::getType()
{
    return static_cast<FileDescriptorInfo::FileDescriptorType>(_fdInfo.proc_fdtype);
}

bool FileDescriptorInfo::isSocket()
{
    return this->getType() == FileDescriptorInfo::FileDescriptorType::SOCKET;
}

} // namespace libproccpp
