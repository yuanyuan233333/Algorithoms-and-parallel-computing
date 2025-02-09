//
// Created by Federica Filippini on 09/12/2020.
//

#ifndef TAXICALLCENTER_INITIAL_CALLCENTER_H
#define TAXICALLCENTER_INITIAL_CALLCENTER_H

#include <unordered_map>
/* YOUR CODE GOES HERE */

#include "date.h"
#include "place.h"
#include "taxi.h"

class CallCenter
{
private:
    /* YOUR CODE GOES HERE */ available_taxis;

    /* YOUR CODE GOES HERE */ station_available_taxis;

    std::unordered_map<std::string, Taxi> taxis;

    const Place station = Place(0.0, 0.0);

public:
    void RegisterTaxi (const std::string& license_id);

    Taxi Call (const Place& source, const Place& destination);

    Taxi CallAtRailStation (const Place& Destination);

    Taxi CallToRailStation (const Place& Source);

    void Arrived (const std::string& license_id);
};

#endif //TAXICALLCENTER_INITIAL_CALLCENTER_H
