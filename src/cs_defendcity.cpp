#include "ScriptMgr.h"

using namespace Acore::ChatCommands;

class defendcity_commandscript : public CommandScript
{
public:
    defendcity_commandscript() : CommandScript("defendcity_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable commandTable =
                {
                        { "defend",      HandleDefendCommand,           SEC_PLAYER,    Console::Yes }
                };

        return commandTable;
    }

    static bool HandleDefendCommand(ChatHandler* handler)
    {
        WorldSession* session = handler->GetSession();

        return true;
    }

};

void AddSC_defendcity_commandscript()
{
    new defendcity_commandscript();
}
