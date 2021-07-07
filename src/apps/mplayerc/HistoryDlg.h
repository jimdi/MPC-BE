/*
 * (C) 2021 see Authors.txt
 *
 * This file is part of MPC-BE.
 *
 * MPC-BE is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * MPC-BE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include <afxcmn.h>
#include <afxwin.h>
#include <ResizableLib/ResizableDialog.h>

// CHistoryDlg dialog

class CHistoryDlg : public CResizableDialog
{
	//DECLARE_DYNAMIC(CHistoryDlg)

public:
	enum {
		COL_PATH = 0,
		COL_TITLE,
		COL_POS,
		COL_COUNT
	};

	CHistoryDlg(CWnd* pParent = nullptr);
	virtual ~CHistoryDlg();

	enum { IDD = IDD_HISTORY };
	CListCtrl m_list;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();

	void SetupList();

	DECLARE_MESSAGE_MAP()
public:
};
