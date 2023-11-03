//
//  FileDescriptorInfo.hpp
//  testlibproccpp
//
//  Created by Danil Korotenko on 11/3/23.
//

#ifndef FileDescriptorInfo_hpp
#define FileDescriptorInfo_hpp

#include <stdio.h>
#include <memory>
#include <libproc.h>

namespace libproccpp
{

class FileDescriptorInfo
{
public:
    typedef std::shared_ptr<FileDescriptorInfo> PtrT;

    FileDescriptorInfo(struct proc_fdinfo aFdInfo);

private:
    struct proc_fdinfo _fdInfo;
};

} // namespace libproccpp

#endif /* FileDescriptorInfo_hpp */
