#include "DefendCityMgr.h"

class DefendCity_Config : public WorldScript
{
public: DefendCity_Config() : WorldScript("DefendCity_Config") { };

    void OnAfterConfigLoad(bool reload) override
    {
        sDefendCityMgr->LoadConfig(/*reload*/);
    }
};

class DefendCity_Player : public PlayerScript
{
public:
    DefendCity_Player() : PlayerScript("DefendCity_Player") { }

    void OnLogin(Player* player)
    {
        if (sGlobalChatMgr->GlobalChatEnabled)
        {
            if (sGlobalChatMgr->Announce)
            {
                ChatHandler(player->GetSession()).PSendSysMessage("This server is running the |cff4CFF00GlobalChat|r module. Use |cff4CFF00.help global|r to find out how to use it.");
            }
        }
    }

    void OnPlayerUpdateArea(Player* player, uint32 oldArea, uint32 newArea)
    {
        // if enters area around thrall, ask to join group
        if (player->GetTeamId() != TEAM_HORDE || newArea != 1637 || !sDefendCityMgr->isUnderAttack(player->GetAreaId()))
        {
            return;
        }

        // TODO
    }

};

void AddSC_DefendCity()
{
    new DefendCity_Config();
    new DefendCity_Player();
}
