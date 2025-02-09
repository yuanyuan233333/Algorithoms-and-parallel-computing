//
// Created by Federica Filippini on 09/12/2020.
//

#include "callcenter.h"

void CallCenter::RegisterTaxi (const std::string& license_id)
{
    Taxi new_taxi(license_id);
    taxis.insert(std::pair<std::string, Taxi>(license_id, new_taxi));
}
