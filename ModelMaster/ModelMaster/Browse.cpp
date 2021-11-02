#include "stdafx.h"
#include "Browse.h"

//�����ȡ�ļ�·��
CString BrowseFile()
{
	// ���ù�����
	TCHAR szFilter[] = _T("ִ�г���(*.exe)|*.exe|�����ļ�(*.*)|*.*||");

	// ������ļ��Ի���   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter);
	CString strFilePath;

	// ��ʾ���ļ��Ի���   
	if (IDOK == fileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
		strFilePath = fileDlg.GetPathName();
	}

	return strFilePath;
}

//�����ȡ�ļ���·��
CString BrowseDirectory(CString m_sPath)
{
	TCHAR targetPath[MAX_PATH];

	// ��ȡ�ض��ļ��е�LPITEMIDLIST�����Խ�֮���ΪHANDLE
	// ��ν���ض��ļ���,�������CSIDL_XXX������֮��
	LPITEMIDLIST rootLoation;
	SHGetSpecialFolderLocation(NULL, CSIDL_DESKTOP, &rootLoation);
	if (rootLoation == NULL) {
		// unkown error
		return targetPath;
	}
	// ���öԻ���
	BROWSEINFO bi;
	ZeroMemory(&bi, sizeof(bi));
	bi.pidlRoot = rootLoation; // �ļ��жԻ���֮��Ŀ¼����ָ���Ļ���Ϊ�ҵĵ���
	bi.lpszTitle = _T("ѡ��Ŀ¼"); // ���Բ�ָ��
	// bi.ulFlags = BIF_EDITBOX | BIF_RETURNONLYFSDIRS;

	// �򿪶Ի���, �е���DoModal
	LPITEMIDLIST targetLocation = SHBrowseForFolder(&bi);
	if (targetLocation != NULL) {

		SHGetPathFromIDList(targetLocation, targetPath);
		return targetPath;
	}

	return m_sPath;
}