//
// Copyright (C) 2013 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


#include "inet/physicallayer/wireless/generic/GenericReceiver.h"

#include "inet/physicallayer/wireless/common/contract/packetlevel/SignalTag_m.h"
#include "inet/physicallayer/wireless/common/radio/packetlevel/ListeningDecision.h"
#include "inet/physicallayer/wireless/common/radio/packetlevel/ReceptionDecision.h"
#include "inet/physicallayer/wireless/common/analogmodel/unitdisk/UnitDiskNoise.h"
#include "inet/physicallayer/wireless/common/analogmodel/unitdisk/UnitDiskReceptionAnalogModel.h"

namespace inet {
namespace physicallayer {

Define_Module(GenericReceiver);

void GenericReceiver::initialize(int stage)
{
    ReceiverBase::initialize(stage);
    if (stage == INITSTAGE_LOCAL)
        ignoreInterference = par("ignoreInterference");
}

std::ostream& GenericReceiver::printToStream(std::ostream& stream, int level, int evFlags) const
{
    stream << "GenericReceiver";
    if (level <= PRINT_LEVEL_INFO)
        stream << (ignoreInterference ? ", ignoring interference" : ", considering interference");
    return stream;
}

bool GenericReceiver::computeIsReceptionPossible(const IListening *listening, const IReception *reception, IRadioSignal::SignalPart part) const
{
    return getAnalogModel()->computeIsReceptionPossible(listening, reception, part);
}

bool GenericReceiver::computeIsReceptionSuccessful(const IListening *listening, const IReception *reception, IRadioSignal::SignalPart part, const IInterference *interference, const ISnir *snir) const
{
    return getAnalogModel()->computeIsReceptionPossible(listening, reception, part, interference, snir);
}

const IListening *GenericReceiver::createListening(const IRadio *radio, const simtime_t startTime, const simtime_t endTime, const Coord& startPosition, const Coord& endPosition) const
{
    return getAnalogModel()->createListening(radio, startTime, endTime, startPosition, endPosition);
}

const IListeningDecision *GenericReceiver::computeListeningDecision(const IListening *listening, const IInterference *interference) const
{
    return getAnalogModel()->computeListeningDecision(listening, interference);
}


} // namespace physicallayer
} // namespace inet
