#ifndef MEM_DYNAMIC_OPERATE_HEADER_
#define MEM_DYNAMIC_OPERATE_HEADER_

#include "helper/tstring.h"
#include <Windows.h>

/** 
 * @param strProcName [in] ������
 * @param offset [in] Ҫ�滻���ڴ��ַ����ڽ�����ʼ��ַ��ƫ����
 * @param content [in] Ҫ�滻������
 * @param nsize [in] Ҫ�滻���ֽ���
 * @ret �ɹ�����0
 * ���ӿ��޸Ľ��̵��ڴ�ֵ�����滻���ǽ�������ִ�еĴ�������ɵ�����ȷ��
 * �滻ǰ����Ӧλ�õ����ݲ���Ӱ��ǰ�����ε�����ִ�С�Be Carefully!
 */
int mdo_modify_memory(const tstring& strProcName, unsigned long offset,
    const byte* content, size_t nsize);

#endif //MEM_DYNAMIC_OPERATE_HEADER_
