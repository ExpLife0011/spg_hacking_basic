// ����libMemDO����ؽӿ�
#include <tchar.h>
#include "../../libMemDO/src/MemDO.h"

int main()
{
    HMODULE hMemDO = LoadLibrary(TEXT("libMemDO.dll"));
    if (hMemDO == NULL)
    {
        return 1;
    }
    typedef int(*mdo_Mod_MemProc)(const tstring&, unsigned long, byte*, size_t);
    mdo_Mod_MemProc mdo_mod_mem = (mdo_Mod_MemProc)GetProcAddress(hMemDO, "mdo_modify_memory");
    if (mdo_mod_mem != NULL)
    {
        byte bnop[] = {0x90, 0x90}; // ֲ���ս��ʬ�� ��ȡ����ֵ�Ĵ���λ���滻��nop
        // 0x01baa4 ��ֲ���ս��ʬ�пۼ�����ֵ��λ�á�
        mdo_mod_mem(tstring(_T("PlantsVsZombies.exe")), 0x01baa4, bnop, 2);
    }
    FreeLibrary(hMemDO);
    return 0;
}
