// OperatorDB.cpp: implementation of the OperatorDB class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StudentManage.h"
#include "OperatorDB.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OperatorDB::OperatorDB()
{

}

OperatorDB::~OperatorDB()
{

}

int OperatorDB::OpenDataSource()
{
    HRESULT hr = 0;
	CString strSourceName = "Provider=OraOLEDB.Oracle.1;Password=c123456;PersistSecurity Info=True;User ID=TEST;Data \
		Source=ORCL_127.0.0.1";
	hr = m_pConnection.CreateInstance("ADODB.Connection");
	if(SUCCEEDED(hr))
	{
		_bstr_t strConnect = _bstr_t(strSourceName);
		m_pConnection->ConnectionTimeout =30;
		// 连接数据库
		hr = m_pConnection->Open(((_bstr_t)strSourceName),"","",adModeUnknown);
		return 1;
	 }
	return 0;
}

void OperatorDB::CloseDataSource()
{
	if(m_pConnection->State)
	{
		m_pConnection->Close();
	}
}

void OperatorDB::AddData(CString pName,int pAge,CString pstrClass,CString pstrAddress)
{
     /*CString f_str;
	 f_str.Format("insert into Student(SName,Age,SClass,SAddress,) values('%s',%d,'%s','%s')",pName,pAge,pstrClass,pstrAddress);
	 db.ExecuteSQL(f_str);*/
}

void OperatorDB::Delete(CString pName,int pAge,CString pstrClass,CString pstrAddress)
{
	/*CString f_str;
	f_str.Format("Delete  from Student where SName = pName");
	db.ExecuteSQL(f_str);*/
}

void OperatorDB::UpdateData(CString pName,int pAge,CString pstrClass,CString pstrAddress)
{
    
}

void OperatorDB::HandOperator(CString pSql)
{
     m_pConnection->Execute((_bstr_t)(pSql),NULL,adCmdText);
}
