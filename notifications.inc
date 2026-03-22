#if defined _TD_ADS_INCLUDED
    #endinput
#endif
#define _TD_ADS_INCLUDED

// CONFIG
#define MAX_ADS 50
#define MAX_AD_TEXT 144

// Variables
new TDAds_Texts[MAX_ADS][MAX_AD_TEXT];
new TDAds_Time[MAX_ADS];
new TDAds_Count;

new PlayerText:TDAds_Draw[MAX_PLAYERS];
new TDAds_Index[MAX_PLAYERS];
new TDAds_Timer[MAX_PLAYERS];

// Forward
forward TDAds_Next(playerid);

//init
stock TDAds_Init()
{
    TDAds_Count = 0;
    return 1;
}

//add
stock TDAds_Add(const text[], time)
{
    if(TDAds_Count >= MAX_ADS) return -1;

    format(TDAds_Texts[TDAds_Count], MAX_AD_TEXT, "%s", text);
    TDAds_Time[TDAds_Count] = time;

    TDAds_Count++;
    return TDAds_Count - 1;
}

//show
stock TDAds_Show(playerid)
{
    TDAds_Index[playerid] = 0;

    TDAds_Draw[playerid] = CreatePlayerTextDraw(playerid, 320.0, 400.0, "");
    PlayerTextDrawAlignment(playerid, TDAds_Draw[playerid], 2);
    PlayerTextDrawBackgroundColor(playerid, TDAds_Draw[playerid], 255);
    PlayerTextDrawFont(playerid, TDAds_Draw[playerid], 1);
    PlayerTextDrawLetterSize(playerid, TDAds_Draw[playerid], 0.3, 1.2);
    PlayerTextDrawColor(playerid, TDAds_Draw[playerid], -1);
    PlayerTextDrawSetOutline(playerid, TDAds_Draw[playerid], 1);

    TDAds_Next(playerid);
    return 1;
}

//next
public TDAds_Next(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
    if(TDAds_Count == 0) return 0;

    new index = TDAds_Index[playerid];

    PlayerTextDrawSetString(playerid, TDAds_Draw[playerid], TDAds_Texts[index]);
    PlayerTextDrawShow(playerid, TDAds_Draw[playerid]);

    TDAds_Timer[playerid] = SetTimerEx("TDAds_Next", TDAds_Time[index], false, "i", playerid);

    TDAds_Index[playerid]++;
    if(TDAds_Index[playerid] >= TDAds_Count)
        TDAds_Index[playerid] = 0;

    return 1;
}
//stop
stock TDAds_Stop(playerid)
{
    KillTimer(TDAds_Timer[playerid]);
    PlayerTextDrawHide(playerid, TDAds_Draw[playerid]);
    return 1;
}