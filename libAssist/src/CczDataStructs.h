#pragma once

#ifndef CCZ_ASSIST_DATASTRUCTURE_INCLUDE_H
#define CCZ_ASSIST_DATASTRUCTURE_INCLUDE_H

#include <WinBase.h>

enum ItemProperty{
    // Nm_: Normal Sp_: Special
    Nm_Sword = 0, Sp_Sword, Nm_Spear, Sp_Spear, Nm_Arrow, Sp_Arrow, Nm_Stick, Sp_Stick, Nm_Stone, 
    Sp_Stone, Nm_Fan, Sp_Fan, Nm_Bao, Sp_Bao, Nm_Armor, Sp_Armor, Nm_Suit, Sp_Suit, 
    
    Ef_RenewHP, Ef_RenewMP, Ef_Wakeup, Ef_GetExp, Ef_WeaponExp,
    Ef_ClothExp, Ef_Atk, Ef_Vgr, Ef_Def, Ef_Erupt, Ef_Luck, Ef_GainHP, Ef_GainMP,
    Ef_GainExp, Ef_AddMv, Ef_Assault, Ef_Adverse, Ef_Confus, Ef_Poison, Ef_Paralysis,
    Ef_NoMagic, Ef_AddHtRt, Ef_StrikeBk, Ef_CritHit, Ef_FarAtk, Ef_PenetrateAtk, 
    Ef_NoAntiAtk, Ef_HouseAtk, Ef_GoOnAtk, Ef_AddFireMagic, Ef_AddWindMagic,
    Ef_SavMP, Ef_Summon, Ef_MagicSimu, Ef_AddMagicRt, Ef_RaiseAtkDef, Ef_RaisMagicDef,
    Ef_RaisAllDef, Ef_IgnorFarAtk, Ef_IgnorCritAtk, Ef_Ignor2ndAtk, Ef_LessMagicHurt,
    Ef_MPasHP, Ef_LeesFarAtk, Ef_AutoUseFrt,
    Use_4HP, Use_4MP, Use_4Confus, Use_4Poison, Use_4Paralysis, Use_4Magic, Use_4AllBad,
    Use_UpFourc, Use_UpSpirit, Use_UpLeadCap, Use_UpAgileCap, Use_UpMorale, 
    Use_UpLv, Use_UpArmLv
};

const std::wstring kItemProperName[] ={
    L"��ͨ��",
    L"���⽣",
    L"��ͨǹ",
    L"����ǹ",
    L"��ͨ��",
    L"���⹭",
    L"��ͨ��",
    L"�����",
    L"��ͨͶʯ��",
    L"����Ͷʯ��",
    L"��ͨ��",
    L"������",
    L"��ͨ����",
    L"���ⱦ��",
    L"��ͨ����",
    L"��������",
    L"��ͨ�·�",
    L"�����·�",
    L"ÿ�غϻָ�HP(�ٷ���)",
    L"ÿ�غϻָ�MP(�ٷ���)",
    L"ÿ�غϻָ�״̬",
    L"ÿ�غϻ��Exp(����)",
    L"ÿ�غϻ������Exp(����)",
    L"ÿ�غϻ�õ���Exp(����)",
    L"����������(����)",
    L"����������(����)",
    L"����������(����)",
    L"����������(����)",
    L"��������(����)",
    L"����HP����(����)",
    L"����MP����(����)",
    L"�������Exp(ʮ����)",
    L"�����ƶ���(����)",
    L"ͻ���ƶ�",
    L"��·�ƶ�",
    L"���ҹ���",
    L"�ж�����",
    L"��Թ���",
    L"��ɱ����",
    L"������������(�ٷ���)",
    L"�����󷴻�",
    L"����һ������",
    L"Զ���빥��(û���)",
    L"��͸Ч��",
    L"�޷�������",
    L"������(�ٷ���)",
    L"��������",
    L"�����������(�ٷ���)",
    L"�����������(�ٷ���)",
    L"��ԼMP(�ٷ���)",
    L"�ٻ�����",
    L"����ģ��",
    L"������������(�ٷ���)",
    L"������������(�ٷ���)",
    L"�������Է���(�ٷ���)",
    L"����ȫ����",
    L"����Զ�̹���",
    L"��ֹ����һ��",
    L"��ֹ���ι���",
    L"�����������(�ٷ���)",
    L"mp��������",
    L"����Զ��������(�ٷ���)",
    L"�Զ�ʹ�õ���",
    L"��ȡHP(����)",
    L"��ȡMP(����)",
    L"���ƻ���",
    L"�����ж�",
    L"�������",
    L"���ƽ���",
    L"����һ���쳣",
    L"��������(����)",
    L"��������(����)",
    L"ͳ˧����(����)",
    L"��������(����)",
    L"ʿ������(����)",
    L"�ȼ�����",
    L"��������",
    L"(��)"
};

#pragma pack(1)

#define NAME_COPY_LEN 0x11

typedef struct _MapPos
{
    byte byX;
    byte byY;
}MapPos, *PMapPos;

typedef struct _FiveDimBY
{
    byte byAtk;
    byte byDef;
    byte byPow;
    byte byDex;
    byte byCrt;
}FiveDimBY, *PFiveDimBY;

typedef struct _FiveDimWD
{
    WORD wAtk;
    WORD wDef;
    WORD wPow;
    WORD wDex;
    WORD wCrt;
}FiveDimWD, *PFiveDimWD;

enum EArmyFlg{EPlyFlg=0, EFrdFlg, EEmyFlg};

typedef struct _TroopStatus
{
    WORD wNameIdx;
    WORD wNonuse;
    byte byStageIdx;
    byte byArmyFlg;//0:player, 1:friend, 2:enemy
    MapPos mapPos;
    byte byAIStageIdx;
    MapPos mapAIPos;
    byte byAlwaysFF;
    byte byLifeCode;//2:alive, 3:dead
    byte byPicCode;//0~6
    byte byAICode;//0~7, 7:player
    byte byDirection;
    DWORD dwHP;
    DWORD dwMP;
    FiveDimBY status;
    byte byMov;
    char szRest[6];
} TroopStatus, *PTroopStatus;

typedef struct _ItemInfo
{
    byte byIdx;
    byte byLv;
    byte byExp;
}ItemInfo, *PItemInfo;

typedef struct _BaseData
{
    WORD wCodeIdx;//from 0x1000
    WORD wClothIdx;
    WORD wPicIdx;
    WORD wNonuse;
    char szName[9];
    FiveDimWD fdDW;
    byte bySzEnd;
    DWORD dwHP;
    byte byMP;
    FiveDimBY base;
    byte byUnknown;
    byte byFightCount;
    byte byWinCount;
    byte byRetreatCount;
    byte byArmyFlg;//0:player, FF:enemy
    ItemInfo infoSelf;
    ItemInfo infoWeapon;
    ItemInfo infoArmour;
    ItemInfo infoAssist;
    char szRest[NAME_COPY_LEN];
}BaseData, *PBaseData;

typedef struct _ItemDetail
{
    char szName[17];
    union{
        byte byType;     // ��߱�ʾ����
        byte byAstSpEff; // ������ʾ����Ч��
    };
    byte byPrice;//0xFF means not-for-sale
    byte byIcon;
    byte bySpEffect;
    union{
        byte byLvOne;     // ��߱�ʾһ����ʼֵ
        byte byAstSpValue;// ������ʾ����Ч��ֵ
    };
    byte bySpValue;
    union{
        byte byLvInc;     // ��߱�ʾ�����ɳ�ֵ
        byte byAstFitArmy;// ������ʾ���ñ���
    };
    bool bIsSpItem;//01:yes
} ItemDetail, *PItemDetail;


typedef struct _JobData
{
    byte byMov;
    byte byAtkAear;
    FiveDimBY fdBY;//CBASX+
    byte byHP;
    byte byMP;
    bool aIsSuit[18];
}JobData, PJobData;

#pragma pack()

#endif // CCZ_ASSIST_DATASTRUCTURE_INCLUDE_H
