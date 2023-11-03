//
//  libproccpp.hpp
//  testlibproccpp
//
//  Created by Danil Korotenko on 11/3/23.
//

#ifndef libproccpp_hpp
#define libproccpp_hpp

#include <stdio.h>
#include <vector>
#include "ProcessInfo.hpp"

namespace libproccpp
{

std::vector<ProcessInfo::PtrT> getAllProcesses();


}

#endif /* libproccpp_hpp */
