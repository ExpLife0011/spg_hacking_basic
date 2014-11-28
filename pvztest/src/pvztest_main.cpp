// ����libMemDO����ؽӿ�
#include <tchar.h>
#include "../../libMemDO/src/MemDO.h"
#include "helper/helper.h"
#include <iostream>

using std::cout;
using std::endl;
#pragma comment(lib, "WINMM")
int main()
{
//     HMODULE hMemDO = LoadLibrary(TEXT("libMemDO.dll"));
//     if (hMemDO == NULL)
//     {
//         return 1;
//     }
//     typedef int(*mdo_Mod_MemProc)(const tstring&, unsigned long, const byte*, size_t);
//     mdo_Mod_MemProc mdo_mod_mem = (mdo_Mod_MemProc)GetProcAddress(hMemDO, "mdo_modify_memory");
//     if (mdo_mod_mem != NULL)
//     {
//         byte bnop[] = {0x90, 0x90}; // ֲ���ս��ʬ�� ��ȡ����ֵ�Ĵ���λ���滻��nop
//         // 0x01baa4 ��ֲ���ս��ʬ�пۼ�����ֵ��λ�á�
//         mdo_mod_mem(tstring(_T("PlantsVsZombies.exe")), 0x01baa4, bnop, 2);
//     }
//     FreeLibrary(hMemDO);
//     DWORD dwCount = timeGetTime();
//     while (1)
//     {
//         DWORD curCount = timeGetTime();//GetTickCount();
//         printf("delta count %u\n", curCount - dwCount); 
//         dwCount = curCount;
//         Sleep(1000);
//     }
//     LARGE_INTEGER dwCount = {0};
//     QueryPerformanceCounter(&dwCount);
//     while (1)
//     {
//         LARGE_INTEGER curCount = {0};
//         QueryPerformanceCounter(&curCount);
//         printf("delta count %llu\n", curCount.QuadPart - dwCount.QuadPart); 
//         dwCount.QuadPart = curCount.QuadPart;
//         Sleep(1000);
//     }
    //timeGetTime();
    //LARGE_INTEGER li;
    //QueryPerformanceCounter(&li);
    char* buffer = "D:\\Git\\spghb\\output\\Debug\\libIPCO.dll";

    //����Ŀ����̣����򿪾��
    DWORD dwProcID = helper::process::get_process_by_name(TEXT("pvz.exe"));
    HANDLE hTarget = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcID);
    if (NULL == hTarget)
    {
        cout << "Can't Open target process!" << endl;
        return -1;
    }

    //��ȡLoadLibraryW��FreeLibrary�����������е���ڵ��ַ
    HMODULE hKernel32 = GetModuleHandle(_T("Kernel32"));
    LPTHREAD_START_ROUTINE pLoadLib = (LPTHREAD_START_ROUTINE)
        GetProcAddress(hKernel32, "LoadLibraryW");
    LPTHREAD_START_ROUTINE pFreeLib = (LPTHREAD_START_ROUTINE)
        GetProcAddress(hKernel32, "FreeLibrary");
    if (NULL == pLoadLib || NULL == pFreeLib)
    {
        cout << "Library procedure not found: " << GetLastError() << endl;
        CloseHandle(hTarget);
        return -1;
    }

    WCHAR szPath[MAX_PATH] = L"D:\\Git\\spghb\\output\\Debug\\libIPCO.dll";
//     MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, argv[2], -1,
//         szPath, sizeof(szPath) / sizeof(szPath[0]));

    //������������ΪLoadLibraryW�Ĳ�������ռ䣬��������ֵд��
    LPVOID lpMem = VirtualAllocEx(hTarget, NULL, sizeof(szPath),
        MEM_COMMIT, PAGE_READWRITE);
    if (NULL == lpMem)
    {
        cout << "Can't alloc memory block: " << GetLastError() << endl;
        CloseHandle(hTarget);
        return -1;
    }

    // ������ΪҪע���DLL���ļ�·��
    if (!WriteProcessMemory(hTarget, lpMem, (void*)szPath, sizeof(szPath), NULL))
    {
        cout << "Can't write parameter to memory: " << GetLastError() << endl;
        VirtualFreeEx(hTarget, lpMem, sizeof(szPath), MEM_RELEASE);
        CloseHandle(hTarget);
        return -1;
    }

    //�����ź�����DLL�������ͨ��ReleaseSemaphore��֪ͨ����������
    HANDLE hSema = CreateSemaphore(NULL, 0, 1, _T("Global\\InjHack"));

    //��DLLע����������
    HANDLE hThread = CreateRemoteThread(hTarget, NULL, 0, pLoadLib, lpMem, 0, NULL);

    //�ͷ����������ڵĲ����ڴ�
    VirtualFreeEx(hTarget, lpMem, sizeof(szPath), MEM_RELEASE);

    if (NULL == hThread)
    {
        cout << "Can't create remote thread: " << GetLastError() << endl;
        CloseHandle(hTarget);
        return -1;
    }

    //�ȴ�DLL�ź��������������˳�
    WaitForSingleObject(hThread, INFINITE);
    HANDLE hObj[2] = {hTarget, hSema};
    if (WAIT_OBJECT_0 == WaitForMultipleObjects(2, hObj, FALSE, INFINITE))
    {
        cout << "Target process exit." << endl;
        CloseHandle(hTarget);
        return 0;
    }
    CloseHandle(hSema);

    //�����߳��˳������ȡDLL��Module ID
    DWORD dwLibMod;
    if (!GetExitCodeThread(hThread, &dwLibMod))
    {
        cout << "Can't get return code of LoadLibrary: " << GetLastError() << endl;
        CloseHandle(hThread);
        CloseHandle(hTarget);
        return -1;
    }

    //�ر��߳̾��
    CloseHandle(hThread);

    //�ٴ�ע��FreeLibrary�������ͷ��������̼��ص�ע����DLL
    hThread = CreateRemoteThread(hTarget, NULL, 0, pFreeLib, (void*)dwLibMod, 0, NULL);
    if (NULL == hThread)
    {
        cout << "Can't call FreeLibrary: " << GetLastError() << endl;
        CloseHandle(hTarget);
        return -1;
    }
    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);

    CloseHandle(hTarget);

    getchar();

    return 0;
}
