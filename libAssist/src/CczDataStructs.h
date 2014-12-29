#pragma once

#ifndef CCZ_ASSIST_DATASTRUCTURE_INCLUDE_H
#define CCZ_ASSIST_DATASTRUCTURE_INCLUDE_H

#include <WinBase.h>
#include <assert.h>

enum ItemProperty{
    // Nm_: Normal Sp_: Special
    Nm_Sword = 0, Sp_Sword, Nm_Spear, Sp_Spear, Nm_Arrow, Sp_Arrow, Nm_Stick, Sp_Stick, Nm_Stone, 
    Sp_Stone, Nm_Fan, Sp_Fan, Nm_Bao, Sp_Bao, Nm_Armor, Sp_Armor, Nm_Suit, Sp_Suit, 
    
    Ef_RenewHP, Ef_RenewMP, Ef_Wakeup, Ef_GetExp, Ef_WeaponExp,
    Ef_ClothExp, Ef_Atk, Ef_Vgr, Ef_Def, Ef_Erupt, Ef_Luck, Ef_GainHP, Ef_GainMP,
    Ef_GainExp, Ef_AddMv, Ef_Assault, Ef_Adverse, Ef_Confus, Ef_Poison, Ef_Paralysis,
    Ef_NoMagic, Ef_AddHtRt, Ef_StrikeBk, Ef_CritHit, Ef_FarAtk, Ef_MultiAtk, 
    Ef_NoAntiAtk, Ef_HouseAtk, Ef_GoOnAtk, Ef_AddFireMagic, Ef_AddWindMagic,
    Ef_SavMP, Ef_Summon, Ef_MagicSimu, Ef_AddMagicRt, Ef_RaiseAtkDef, Ef_RaisMagicDef,
    Ef_RaisAllDef, Ef_IgnorFarAtk, Ef_IgnorCritAtk, Ef_Ignor2ndAtk, Ef_LessMagicHurt,
    Ef_MPasHP, Ef_LeesFarAtk, Ef_AutoUseFrt,
    Use_4HP, Use_4MP, Use_4Confus, Use_4Poison, Use_4Paralysis, Use_4Magic, Use_4AllBad,
    Use_UpFourc, Use_UpSpirit, Use_UpLeadCap, Use_UpAgileCap, Use_UpMorale, 
    Use_UpLv, Use_UpArmLv
};

const static int kItemNmTypeNum = 18;
const static int kItemSpTypeNum = 45;
const static int kItemUseTypeNum = 14;
const static std::wstring kItemProperUnknown = L"��";

const static unsigned long kItemsOffset = 0xA1140;
const static int kItemsNum = 104;

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
};

const std::wstring kFarawayAttackDescpt[] =
{
    L"�����",
    L"����",
    L"����",
    L"���",
    L"�����",
    L"����"
    L"û���",
    L"�ڳ�",
    L"���ڳ�"
    L"�����",
    L"ȫ��",
    L"��",
    L"���+���",
    L"���+�����",
    L"С����",
    L"�󷽿�"
};
const std::wstring kMutiAttackDescpt[] =
{
    L"����",
    L"ʮ��",
    L"�Ź�",
    L"û���",
    L"��͸2��",
    L"��͸6��",
    L"Ƭ��" // ��� + �����
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

enum CczItemType{
    Item_Unknown,
    Item_Generic,   // ���
    Item_Assist,    // ����
    Item_Use        // ����Ʒ
};

enum CczValidSpEffVal{
    Valid_NoValid,
    Valid_Rate,
    Valid_10BaseRate,  // 10�ı������ϵ����� 1.5������ֵΪ15
    Valid_Integer,
    Valid_Enums
};

class ClsItemDetail{
public:
    ClsItemDetail(const ItemDetail& idtl)
        : m_itmDetail(idtl)
    {
        byte tp = idtl.byType;
        if ( tp >= Nm_Sword && tp <= Sp_Suit)
        {
            m_iType = Item_Generic;
        }
        else
        {
            tp = idtl.byAstSpEff;
            if (tp >= Ef_RenewHP && tp <= Ef_AutoUseFrt)
            {
                m_iType = Item_Assist;
            }
            else if (tp >= Use_4HP && tp <= Use_UpArmLv)
            {
                m_iType = Item_Use;
            }
        }
    }

    ~ClsItemDetail()
    {

    }

    void setItemTypeValue(byte val)
    {
        // ��߲ŵ��øýӿڣ�������ñ�Ľӿ�
        assert (val >= Nm_Sword && val <= Sp_Suit );
        m_itmDetail.byType = val;
        m_iType = Item_Generic;
    }

    void setItemSpEffct(byte sp)
    {
        assert (sp >= Ef_RenewHP && sp <= Use_UpArmLv);
        assert (m_iType != Item_Unknown);
        if (m_iType == Item_Generic)
        {
            m_itmDetail.bySpEffect = sp;
        }
        else
        {
            m_itmDetail.byAstSpEff = sp;
        }
    }

    void setItemSpecialEffValue(byte spval)
    {
        assert(m_iType != Item_Unknown);
        if (m_iType == Item_Generic)
        {
            m_itmDetail.bySpValue = spval;
        }
        else
        {
            m_itmDetail.byAstSpValue = spval;
        }
    }

    void setItemPrice(byte prc)
    {
        m_itmDetail.byPrice = prc;
    }

    void setItemOriginVal(byte val)
    {
        assert(m_iType == Item_Generic);
        m_itmDetail.byLvOne = val;
    }

    void setIsSpecialItem(bool isp)
    {
        m_itmDetail.bIsSpItem = isp;
    }

    void setIconPicId(byte icid)
    {
        m_itmDetail.byIcon = icid;
    }

    void setLvDeltaVal(bool val)
    {
        assert(m_iType == Item_Generic);
        m_itmDetail.byLvInc = val;
    }

public:
    static CczValidSpEffVal valueTypeOfSpEffect(byte spEff)
    {
        switch (spEff)
        {
        case Ef_GainExp:
            return Valid_10BaseRate;

        case Ef_Wakeup: case Ef_Assault:   case Ef_Adverse: 
        case Ef_Confus: case Ef_Poison:    case Ef_Paralysis:
        case Ef_NoMagic:case Ef_GoOnAtk:   case Ef_MagicSimu:
        case Ef_MPasHP: case Ef_NoAntiAtk: case Ef_IgnorFarAtk:
        case Ef_CritHit:case Ef_StrikeBk:  case Ef_IgnorCritAtk:
        case Ef_Ignor2ndAtk:
        case Use_4Confus: case Use_4Poison: case Use_4Paralysis:
        case Use_4Magic:  case Use_4AllBad: 
        case Ef_AutoUseFrt: case Use_UpLv: case Use_UpArmLv:
            return Valid_NoValid;

        case Ef_GetExp: case Ef_WeaponExp: case Ef_ClothExp:
        case Ef_Atk:    case Ef_Vgr:       case Ef_Def:
        case Ef_Erupt:  case Ef_Luck:      case Ef_GainHP:
        case Ef_GainMP: case Ef_AddMv: 
        case Use_4HP:       case Use_4MP:      case Use_UpFourc:
        case Use_UpSpirit:  case Use_UpLeadCap:case Use_UpAgileCap:
        case Use_UpMorale:
            return Valid_Integer;

        case Ef_RenewHP: case Ef_RenewMP:     case Ef_AddHtRt:
        case Ef_HouseAtk:case Ef_AddFireMagic:case Ef_AddWindMagic:
        case Ef_SavMP:   case Ef_AddMagicRt:  case Ef_RaiseAtkDef:
        case Ef_RaisMagicDef:
        case Ef_RaisAllDef:   case Ef_LessMagicHurt: case Ef_LeesFarAtk:
            return Valid_Rate;

        case Ef_FarAtk:  case Ef_MultiAtk: 
        case Ef_Summon:
            return Valid_Enums;
        }
    }

    static byte getValidSpValue(byte spEff, byte val)
    {
        CczValidSpEffVal cvlid = valueTypeOfSpEffect(spEff);
        switch (cvlid)
        {
        case Valid_Rate:
            return (0 <= val && val <= 100) ? val : 100;
        case Valid_Enums:
            {
                if (spEff == Ef_Summon)
                {
                    return (64 <= val && val <= 67) ? val : 64;
                }
                if (spEff == Ef_FarAtk)
                {
                    return (val >= 16) ? 11 : val;
                }
                if (spEff == Ef_MultiAtk)
                {
                    return (val > 6) ? 0 : val;
                }
            }
        case Valid_10BaseRate:
        case Valid_NoValid:
        case Valid_Integer:
            return val;
        }
    }

private:
    ItemDetail   m_itmDetail;
    CczItemType  m_iType;
};

#endif // CCZ_ASSIST_DATASTRUCTURE_INCLUDE_H
