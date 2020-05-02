// OperatorDB.h: interface for the OperatorDB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPERATORDB_H__49376314_2674_4D6C_BC5B_3EBE15D0B7B7__INCLUDED_)
#define AFX_OPERATORDB_H__49376314_2674_4D6C_BC5B_3EBE15D0B7B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include <afxdb.h>
#include "stdAfx.h"
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF")


class OperatorDB  
{
public:
	OperatorDB();
	virtual ~OperatorDB();

public:	
	int OpenDataSource();
	void CloseDataSource();
	void AddData(CString pName,int pAge,CString pstrClass,CString pstrAddress);
	void Delete(CString pName,int pAge,CString pstrClass,CString pstrAddress);
	void UpdateData(CString pName,int pAge,CString pstrClass,CString pstrAddress);
	void HandOperator(CString pSql);


    _ConnectionPtr m_pConnection;
};



#endif // !defined(AFX_OPERATORDB_H__49376314_2674_4D6C_BC5B_3EBE15D0B7B7__INCLUDED_)
