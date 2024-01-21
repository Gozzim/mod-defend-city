#include "DefendCityMgr.h"

DefendCityMgr* DefendCityMgr::instance()
{
    static WardenInjectMgr instance;
    return &instance;
}

void DefendCityMgr::LoadConfig(/*bool reload*/)
{
    DefendCityEnabled = sConfigMgr->GetOption<bool>("DefendCity.Enable", true);
    Announce = sConfigMgr->GetOption<bool>("DefendCity.Announce", true);
}

bool DefendCityMgr::isUnderAttack(uint32 defendCityID) const
{
    DefendCityMap::const_iterator itr = defendCityMap.find(defendCityID);
    if (itr != defendCityMap.end())
    {
        return itr->second.isUnderAttack();
    }

    return false;
}
