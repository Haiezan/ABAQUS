#ifndef _READALINE_H
#define _READALINE_H
#define LINELEN 1500
class TReadALine{//�ı���ȡ��
protected:
	long line;
	char *string,FileName[MAX_PATH];
public:
	BOOL endfile;
	TReadALine(void){line=0;endfile=FALSE;string=new char[LINELEN];};
	void SetLineNumber(int l){line=l;};
	BOOL ReadIntegers(FILE *stream,int start,int &num_of_int,int *intarray);
	BOOL ReadDoubles(FILE *stream,int start,int &num_of_dble,float *dblearray);
	char *ReadAString(FILE *stream);
	BOOL ReadInteger(FILE *stream,int start,int num_of_int,int *intarray);
	BOOL ReadDouble(FILE *stream,int start,int num_of_dble,float *dblearray);
	void SetFileName(const char *name);
	BOOL GetNumFromStr(const char *str1,const char *str2,char start,int num,float *ff);
	BOOL GetNumFromStrs(const char *str1,const char *str2,char start,char &num,float *ff);
	BOOL FindString(FILE *stream, const char* str);//�ҵ�����ָ�������У�ͬʱ�ļ�ָ��Ҳ������
	//BOOL FindString2(FILE *stream, const char* str, CString& strString);//�ҵ�����ָ�������У�ͬʱ�ļ�ָ��Ҳ������

	BOOL GetStrFromStr(const char *str1,char *s);
	BOOL GetStrsFromStr(const char *str1, char s[][20]);
	BOOL GetStrFromStr2(const char *str1, const int start, const int length, char *s);

	~TReadALine(void){ delete[] string; };
};
#endif 
