﻿/*
Copyright © 2017-2019, orcaer@yeah.net  All rights reserved.

Author: orcaer@yeah.net

Last modified: 2019-10-24

Description: https://github.com/wlgq2/uv-cpp
*/

#ifndef UV_LIST_BUFFER_HPP
#define UV_LIST_BUFFER_HPP


#include <list>

#include "PacketBuffer.hpp"


//ListBuffer
//---------------------------------------
//  Null  |  Packet   |  Packet   |  Null 
//---------------------------------------
//        ↑                      ↑
//   read position           write position

//not thread safe.

namespace uv
{

class ListBuffer : public PacketBuffer
{
public:
    ListBuffer();
    ~ListBuffer();
 
    int append(const char* data, uint64_t size);
    int readBufferN(std::string& data, uint64_t N);
    uint64_t readSize();
    int clearBufferN(uint64_t N);
    int clear();

private:
    std::list<uint8_t> buffer_;

};

}

#endif // AGILNET_NET_BUFFER
