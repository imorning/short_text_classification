///////////////////////////////////////////////////////////////////////////
//
// libkafka - C/C++ client for Apache Kafka v0.8+
//
// David Tompkins -- 8/8/2013
// tompkins@adobe_dot_com
//
///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2013 Adobe Systems Incorporated. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
///////////////////////////////////////////////////////////////////////////

#ifndef FETCHPARTITION_H
#define FETCHPARTITION_H

#include <string>
#include "../Debug.h"
#include "../Packet.h"
#include "../WireFormatter.h"
#include "../PacketWriter.h"

namespace LibKafka {

class FetchPartition : public WireFormatter, public PacketWriter
{
  public:

    int partition;
    long int fetchOffset;
    int maxBytes;

    FetchPartition(Packet *packet);
    FetchPartition(int partition, long int fetchOffset, int maxBytes);
    ~FetchPartition();

    unsigned char* toWireFormat(bool updatePacketSize = true);
    int getWireFormatSize(bool includePacketSize = false);
};

std::ostream& operator<< (std::ostream& os, const FetchPartition& fp);
inline bool operator==(const FetchPartition& lhs, const FetchPartition& rhs) { return ((lhs.partition==rhs.partition)&&(lhs.fetchOffset==rhs.fetchOffset)&&(lhs.maxBytes==rhs.maxBytes)); }
inline bool operator!=(const FetchPartition& lhs, const FetchPartition& rhs) { return !operator==(lhs,rhs); }

}; // namespace LibKafka

#endif /* FETCHPARTITION_H */
