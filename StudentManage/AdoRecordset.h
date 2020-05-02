// AdoRecordset.h: interface for the CAdoRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADORECORDSET_H__14916345_4DBB_4EDA_93A8_9CAC0EA6B45C__INCLUDED_)
#define AFX_ADORECORDSET_H__14916345_4DBB_4EDA_93A8_9CAC0EA6B45C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OperatorDB.h"

class CAdoRecordset  
{
public:
	CAdoRecordset();
	virtual ~CAdoRecordset();
	BOOL OpenSql(CString strSql,OperatorDB *pDB);
	long GetFieldCount();
	void GetFiledName(long nIndex,CString & strName);
	void GetFileValue(long nIndex,CString & strValue);
	void MoveFirst();
	void MoveLast();
	void MovePrevious();
	void MoveNext();
	BOOL IsBOF();
	BOOL IsEOF();

public:
	_RecordsetPtr m_pSet;

};

#endif // !defined(AFX_ADORECORDSET_H__14916345_4DBB_4EDA_93A8_9CAC0EA6B45C__INCLUDED_)
