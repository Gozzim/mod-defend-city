#ifndef _DEFENDCITYMGR_H
#define _DEFENDCITYMGR_H

#include "Chat.h"
#include "Config.h"
#include "Player.h"
#include "ScriptMgr.h"

struct DefendCityData
{
    bool underAttack;
    uint32 underAttackTime;
    std::vector<uint32> defenseGroupIDs;
    uint32 defensePhaseID;
};

class DefendCityMgr
{
public:
    static DefendCityMgr* instance();

    bool DefendCityEnabled;
    bool Announce;
    bool TeleportEnabled
    bool TeleportPromptEnabled;
    bool PhasingEnabled;

    void LoadConfig(/*bool reload*/);

    bool isUnderAttack(uint32 defendCityID) const;

private:
    typedef std::map<uint32, DefendCityData> DefendCityMap;
    DefendCityMap defendCityMap;
};

#define sDefendCityMgr DefendCityMgr::instance()

#endif //_DEFENDCITYMGR_H
