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
const static int kArmyTypeNum = 27;
const static int kFarAttackRangeNum = 16;
const static int kMultiAttkRangeNum = 7;
const static int kSummonNum = 4;

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
    L"ÿ�غϻָ�HP",
    L"ÿ�غϻָ�MP",
    L"ÿ�غϻָ�״̬",
    L"ÿ�غϻ��Exp",
    L"ÿ�غϻ������Exp",
    L"ÿ�غϻ�û���Exp",
    L"����������",
    L"����������",
    L"����������",
    L"����������",
    L"��������",
    L"����HP����",
    L"����MP����",
    L"�������Exp",
    L"�����ƶ���",
    L"ͻ���ƶ�",
    L"��·�ƶ�",
    L"���ҹ���",
    L"�ж�����",
    L"��Թ���",
    L"��ɱ����",
    L"������������",
    L"�����󷴻�",
    L"����һ������",
    L"Զ�๥��",
    L"��͸����",
    L"�޷�������",
    L"������",
    L"��������",
    L"�����������",
    L"�����������",
    L"��ԼMP",
    L"�ٻ�����",
    L"����ģ��",
    L"������������",
    L"������������",
    L"�������Է���",
    L"����ȫ����",
    L"����Զ�̹���",
    L"��ֹ����һ��",
    L"��ֹ���ι���",
    L"��������˺�",
    L"MP��������",
    L"����Զ���˺�",
    L"�Զ�ʹ�õ���",
    L"����HP",
    L"����MP",
    L"���ƻ���",
    L"�����ж�",
    L"�������",
    L"���ƽ���",
    L"����һ���쳣",
    L"��������",
    L"��������",
    L"ͳ˧����",
    L"��������",
    L"ʿ������",
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
    L"����",
    L"û���",
    L"�ڳ�",
    L"���ڳ�",
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

const std::wstring  kArmyFitAll = L"ȫ������";

const std::wstring kArmyNamesDesc[] = {
    L"Ⱥ��",
    L"����",
    L"���",
    L"���",
    L"�����",
    L"�ڳ�",
    L"������",
    L"����",
    L"��ʿ",
    L"��ˮʿ",
    L"��ʿ",
    L"�����ı",
    L"����",
    L"�������",
    L"�ƽ��",
    L"����",
    L"ѵ��ʦ",
    L"ѵ��ʦ",
    L"����",
    L"����ʿ",
    L"����",
    L"��ض�",
    L"���ݶ�",
    L"ľ��",
    L"��ż",
    L"�ʵ�",
    L"����"
};

const std::wstring kSummonDescpt[] = {
    L"����",
    L"��ȸ",
    L"����",
    L"�׻�"
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
    union{
        byte bySpEffect;
        byte byAst21ph;   // �������������壬��ΪFF
    };
    union{
        byte byLvOne;     // ��߱�ʾһ����ʼֵ
        byte byAstSpValue;// ������ʾ����Ч��ֵ
    };
    union{
        byte bySpValue;
        byte byAst23ph;   // �������������壬��Ϊ00
    };
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
    Item_Normal,    // ��ͨ���
    Item_Special,   // �������
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
    ClsItemDetail()
    {

    }

    ClsItemDetail(const ItemDetail& idtl)
    {
        setItemDetail(idtl);
    }

    ~ClsItemDetail()
    {

    }

    ItemDetail getItemDetailPure()
    {
        if (m_iType == Item_Unknown)
        {
            if ( m_byType >= Nm_Sword && m_byType <= Sp_Suit)
            {
                m_iType = (m_byType % 2 == 0) ? Item_Normal : Item_Special; 
            }
            else
            {
                if (m_bySpEffect >= Ef_RenewHP && m_bySpEffect <= Ef_AutoUseFrt)
                {
                    m_iType = Item_Assist;
                }
                else if (m_bySpEffect >= Use_4HP && m_bySpEffect <= Use_UpArmLv)
                {
                    m_iType = Item_Use;
                }
            }
        }
        ItemDetail rtIdtl = {0};
        memcpy(rtIdtl.szName, m_szName, 17);
        rtIdtl.byIcon = m_byIcon;
        rtIdtl.byPrice = m_byPrice;
        rtIdtl.bIsSpItem = m_bIsSpecial;
        if (m_iType == Item_Normal || m_iType == Item_Special)
        {
            rtIdtl.byType = m_byType;
            rtIdtl.bySpEffect = m_bySpEffect;
            rtIdtl.bySpValue = m_bySpValue;
            rtIdtl.byLvOne = m_byLvOne;
            rtIdtl.byLvInc = m_byLvInc;
        }
        else
        {
            rtIdtl.byAstSpEff = m_bySpEffect;
            rtIdtl.byAstSpValue = m_bySpValue;
            rtIdtl.byAstFitArmy = m_byLvInc;
            rtIdtl.byAst21ph = 0xFF;
            rtIdtl.byAst23ph = 0x00;
        }
        return rtIdtl;
    }

    void setItemDetail(ItemDetail idtl)
    {
        m_bIsSpecial = idtl.bIsSpItem;
        m_byIcon = idtl.byIcon;
        m_byPrice = idtl.byPrice;
        memcpy(m_szName, idtl.szName, 17);

        byte tp = idtl.byType;
        if ( tp >= Nm_Sword && tp <= Sp_Suit)
        {
            m_iType = (idtl.byType % 2 == 0) ? Item_Normal : Item_Special;
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

        if (m_iType == Item_Normal || m_iType == Item_Special)
        {
            m_byType = idtl.byType;
            m_bySpEffect = idtl.bySpEffect;
            m_bySpValue = idtl.bySpValue;
            m_byLvOne = idtl.byLvOne;
            m_byLvInc = idtl.byLvInc;
        }
        else if (m_iType == Item_Use || m_iType == Item_Assist)
        {
            m_byType = 0;
            m_byLvOne = 0;
            m_bySpEffect = idtl.byAstSpEff;
            m_bySpValue = idtl.byAstSpValue;
            m_byLvInc = idtl.byAstFitArmy;
        }
    }

    void changeToGeneric(byte tp)
    {
        assert( Nm_Sword <= tp && tp <= Sp_Suit);
        setItemTypeValue(tp);
    }

    void changeToAssist()
    {
        if (m_bySpEffect >= Ef_RenewHP && m_bySpEffect <= Ef_AutoUseFrt)
        {
            m_iType = Item_Assist;
        }
        else if (m_bySpEffect >= Use_4HP && m_bySpEffect <= Use_UpArmLv)
        {
            m_iType = Item_Use;
        }
    }

    void setItemTypeValue(byte val)
    {
        // ��߲ŵ��øýӿڣ�������ñ�Ľӿ�
        assert (val >= Nm_Sword && val <= Sp_Suit );
        m_byType = val;
        m_iType = (val % 2 == 0) ? Item_Normal : Item_Special;;
    }

    void removeSpcialEff()
    {
        m_bySpEffect = -1;
        m_bySpValue = 0;
    }

    void setItemSpEffct(byte sp)
    {
        assert (m_iType != Item_Unknown);
        if (sp >= Ef_RenewHP && sp <= Use_UpArmLv)
        {
            m_bySpEffect = sp;
        }
        else
        {
            m_bySpEffect = -1;
        }
    }

    void setItemSpecialEffValue(byte spval)
    {
        assert(m_iType != Item_Unknown);
        m_bySpValue = spval;
    }

    void setItemPrice(byte prc) { m_byPrice = prc; }
    void setItemOriginVal(byte val) { m_byLvOne = val; }
    void setIsSpecialItem(bool isp) { m_bIsSpecial = isp; }
    void setIconPicId(byte icid){ m_byIcon = icid; }
    void setLvDeltaVal(byte val){ m_byLvInc = val; }
    void setFitArmyType(byte val){ setLvDeltaVal(val); }
    const char* getItemName() { return m_szName; }
    byte getItemIcon() { return m_byIcon; }
    byte getItemPrice() { return m_byPrice; }
    byte getItemSpecial() { return m_bySpEffect; }
    byte getItemSpecialValue() { return m_bySpValue; }
    byte getItemType() { return m_byType; }
    byte getItemOriginVal() { return m_byLvOne; }
    byte getItemLvDelta() { return m_byLvInc; }
    byte getAssistFitArmy() { return m_byLvInc; }

    bool isNormalItem(){ return m_iType == Item_Normal; }
    bool isSpecialItem() {return m_iType == Item_Special; }
    bool isAssistItem() { return m_iType == Item_Assist; }
    bool isAstUseItem() { return m_iType == Item_Use; }

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
    char    m_szName[17];
    byte    m_byType;
    byte    m_byPrice;
    byte    m_byIcon;
    byte    m_bySpEffect;
    byte    m_bySpValue;
    byte    m_byLvOne;
    byte    m_byLvInc;      // �����ɳ�ֵ��������ʾ�ʺϱ���
    bool    m_bIsSpecial;
    CczItemType m_iType;
};

#endif // CCZ_ASSIST_DATASTRUCTURE_INCLUDE_H
