#include "plugin.h"
#include <stdlib.h>
#include <tchar.h>

static bool cbCommand(int argc, char* argv[])
{
    char command[256];
    char condition[] = "!mod.base([csp])";
    char remove_bp[] = "bpc";

    if(argc < 2)
    {
      _plugin_logputs("Usage: heapbp apiName\n");
      return false;
    }

    memset(command, 0, 256);
    sprintf_s(command, "%s %s", "bp", argv[1]);

    if(!DbgCmdExecDirect(command))
    {
        _plugin_logputs("Failed to set the BP\n");
        return false;
    }

    memset(command, 0, 256);
    sprintf_s(command, "%s %s,  %s", "bpcnd", argv[1], condition);

    if(!DbgCmdExecDirect(command))
    {
        _plugin_logputs("Failed to set Bp condition\n");
        //remove the bp
        memset(command, 0, 256);
        sprintf_s(command, "%s %s", remove_bp, argv[1]);
        DbgCmdExecDirect(command);       
        return false;
    }
    
    return true; //Return false to indicate the command failed.
}

//Initialize your plugin data here.
bool pluginInit(PLUG_INITSTRUCT* initStruct)
{
    if(!_plugin_registercommand(pluginHandle, "heapbp", cbCommand, false))
        _plugin_logputs("[" PLUGIN_NAME "] Error registering the \"" PLUGIN_NAME "\" command!");
    return true; //Return false to cancel loading the plugin.
}

//Deinitialize your plugin data here (clearing menus optional).
bool pluginStop()
{
    return true;
}

//Do GUI/Menu related things here.
void pluginSetup()
{
}
