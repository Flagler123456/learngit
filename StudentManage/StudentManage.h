// StudentManage.h : main header file for the STUDENTMANAGE application
//

#if !defined(AFX_STUDENTMANAGE_H__901499C4_EC1C_4DC1_AACC_081FF8F1C135__INCLUDED_)
#define AFX_STUDENTMANAGE_H__901499C4_EC1C_4DC1_AACC_081FF8F1C135__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "OperatorDB.h"

/////////////////////////////////////////////////////////////////////////////
// CStudentManageApp:
// See StudentManage.cpp for the implementation of this class
//

class CStudentManageApp : public CWinApp
{
public:
	CStudentManageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentManageApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL InitApplication();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStudentManageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	OperatorDB m_operator;
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTMANAGE_H__901499C4_EC1C_4DC1_AACC_081FF8F1C135__INCLUDED_)
