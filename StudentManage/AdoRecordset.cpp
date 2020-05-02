// AdoRecordset.cpp: implementation of the CAdoRecordset class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StudentManage.h"
#include "AdoRecordset.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdoRecordset::CAdoRecordset()
{

}

CAdoRecordset::~CAdoRecordset()
{

}

BOOL CAdoRecordset::OpenSql(CString strSql,OperatorDB *pDB)
{
     // 创建记录集对象
	HRESULT nRet = m_pSet.CreateInstance(__uuidof(Recordset));
	if(FAILED(nRet))
	{
		return FALSE;
	}
	// 调用Open函数
	nRet = m_pSet->Open(_variant_t(strSql),(IDispatch*)pDB->m_pConnection,adOpenForwardOnly,adLockOptimistic,adCmdText);
    if(FAILED(nRet))
	{
        return FALSE;
	}
	return TRUE;
}
long CAdoRecordset::GetFieldCount()
{
     return  m_pSet->Fields->GetCount();
}
void CAdoRecordset::GetFiledName(long nIndex,CString & strName)
{
     strName = (char *)m_pSet->Fields->GetItem(nIndex)->GetName();
}

void CAdoRecordset::GetFileValue(long nIndex,CString & strValue)
{
    _variant_t varValue = m_pSet->Fields->GetItem(nIndex)->GetValue();
	if(varValue.vt == VT_NULL)
	{
		strValue = "";
	}
	else
	{
		strValue = (char*)(_bstr_t)varValue;
	}
}
void CAdoRecordset::MoveFirst()
{
    m_pSet->MoveFirst();
}
void CAdoRecordset::MoveLast()
{
    m_pSet->MoveLast();
}
void CAdoRecordset::MovePrevious()
{
    m_pSet->MovePrevious();
}
void CAdoRecordset::MoveNext()
{
    m_pSet->MoveNext();
}
BOOL CAdoRecordset::IsBOF()
{
    return m_pSet->BOF;
}
BOOL CAdoRecordset::IsEOF()
{
    return m_pSet->adoEOF;
}