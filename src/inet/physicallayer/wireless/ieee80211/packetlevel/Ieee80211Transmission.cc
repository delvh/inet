//
// Copyright (C) 2013 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


#include "inet/physicallayer/wireless/ieee80211/packetlevel/Ieee80211Transmission.h"

namespace inet {

namespace physicallayer {

Ieee80211Transmission::Ieee80211Transmission(const IRadio *transmitter, const Packet *packet, const simtime_t startTime, const simtime_t endTime, const simtime_t preambleDuration, const simtime_t headerDuration, const simtime_t dataDuration, const Coord startPosition, const Coord endPosition, const Quaternion startOrientation, const Quaternion endOrientation, b headerLength, b dataLength, const IModulation *modulation, const simtime_t symbolTime, Hz centerFrequency, Hz bandwidth, bps bitrate, double codeRate, W power, const IIeee80211Mode *mode, const Ieee80211Channel *channel) :
    FlatTransmissionBase(transmitter, packet, startTime, endTime, preambleDuration, headerDuration, dataDuration, startPosition, endPosition, startOrientation, endOrientation, headerLength, dataLength, bitrate, codeRate, modulation, symbolTime, centerFrequency, bandwidth),
    Ieee80211TransmissionBase(mode, channel)
{
}

std::ostream& Ieee80211Transmission::printToStream(std::ostream& stream, int level, int evFlags) const
{
    stream << "Ieee80211Transmission";
    Ieee80211TransmissionBase::printToStream(stream, level);
    return FlatTransmissionBase::printToStream(stream, level);
}

} // namespace physicallayer

} // namespace inet

