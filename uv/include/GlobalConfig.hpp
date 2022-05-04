/*
   Copyright © 2017-2019, orcaer@yeah.net  All rights reserved.

   Author: orcaer@yeah.net

   Last modified: 2019-10-25

   Description: https://github.com/wlgq2/uv-cpp
*/

#ifndef UV_GLOBAL_CONFIG_HPP
#define UV_GLOBAL_CONFIG_HPP

#include <string>
#include <functional>

namespace uv
{
class PacketBuffer;
class Packet;
typedef std::function<int(PacketBuffer*, std::string&)> ReadBufferStringFunc;
typedef std::function<int(PacketBuffer*, Packet&)> ReadBufferPacketFunc;
typedef std::function<int(PacketBuffer*, void*)> ReadBufferVoidFunc;

class GlobalConfig
{
public:
    enum BufferMode
    {
        NoBuffer,
        CycleBuffer,
        ListBuffer
    };
    static BufferMode BufferModeStatus;
    static uint64_t   CycleBufferSize;


    static ReadBufferStringFunc ReadBufferString;
    static ReadBufferPacketFunc ReadBufferPacket;
    static ReadBufferVoidFunc ReadBufferVoid;
};
}
#endif
