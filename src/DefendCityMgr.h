#ifndef _DEFENDCITYMGR_H
#define _DEFENDCITYMGR_H

#include "Chat.h"
#include "Config.h"
#include "Player.h"
#include "ScriptMgr.h"

class DefendCityMgr
{
public:
    static DefendCityMgr* instance();

    bool DefendCityEnabled;
    bool Announce;

    void LoadConfig(/*bool reload*/);
};

#define sDefendCityMgr DefendCityMgr::instance()

#endif //_DEFENDCITYMGR_H
