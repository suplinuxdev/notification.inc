Example for use:

#include <notifications.inc>

public OnGameModeInit()
{
    TDAds_Init();

    TDAds_Add("Bienvenido al servidor!", 5000);
    TDAds_Add("Usa /ayuda para ver comandos", 5000);
    TDAds_Add("Visita nuestra web!", 5000);
}

public OnPlayerConnect(playerid)
{
    TDAds_Show(playerid);
    return 1;
}
