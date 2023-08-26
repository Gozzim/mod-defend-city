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