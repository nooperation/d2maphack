#ifndef HACK_MAP_H
#define HACK_MAP_H

#include "memhelper.h"

#define ARRAYSIZE(x) (sizeof(x)/sizeof(x[0]))

enum DllNo {DLLNO_D2CLIENT, DLLNO_D2COMMON, DLLNO_D2GFX, DLLNO_D2WIN, DLLNO_D2LANG, DLLNO_D2CMP, DLLNO_D2MULTI, DLLNO_BNCLIENT, DLLNO_D2NET, DLLNO_STORM};

enum DllBase {
	DLLBASE_D2CLIENT = 0x6FAA0000,
	DLLBASE_D2COMMON = 0x6FD40000,
	DLLBASE_D2GFX = 0x6FA70000,
	DLLBASE_D2WIN = 0x6F8A0000,
	DLLBASE_D2LANG = 0x6FC10000,
	DLLBASE_D2CMP = 0x6FDF0000,
	DLLBASE_D2MULTI = 0x6F9A0000,
	DLLBASE_BNCLIENT = 0x6FF00000,
	DLLBASE_D2NET = 0x6FC00000,
	DLLBASE_STORM = 0x6FFB0000
};

#define DLLOFFSET(a1,b1) ((DLLNO_##a1)|(( ((b1)<0)?(b1):(b1)-DLLBASE_##a1 )<<8))

//NOTE :- reference vars buggy

#define D2FUNCPTR(d1,v1,t1,t2,o1) typedef t1 d1##_##v1##_t t2; d1##_##v1##_t *d1##_##v1 = (d1##_##v1##_t *)DLLOFFSET(d1,o1);
#define D2VARPTR(d1,v1,t1,o1)     typedef t1 d1##_##v1##_t;    d1##_##v1##_t *p_##d1##_##v1 = (d1##_##v1##_t *)DLLOFFSET(d1,o1);
#define D2ASMPTR(d1,v1,o1)        DWORD d1##_##v1 = DLLOFFSET(d1,o1);

#define D2PATCH_HELPER(x) {x.func, x.addr, x.param, x.len, x.mask, x.oldcode}

struct Patch_t{
	void (*func)(DWORD, DWORD, DWORD);
	DWORD addr;
	DWORD param;
	BYTE len;
	DWORD mask;
	BYTE *oldcode;
};

struct PatchItem_t {
	Patch_t *patch;
	int num;
	BOOL fInitOnDemand;
};

struct ConfigVar {
	char *szName1, *szName2;
	union {
		void *pVar;
		char **pszVar;
	};
	BYTE nSize, nSize2; //0 for string
	short anArrayMax[4];

};

extern HMODULE hInstDLL;

struct ToggleVar {
	BYTE flag;
	BYTE key;
	char* desc;
	void (*func)();
	BYTE _2[2];
};

struct TreeNode {
	char *key, *str;
	TreeNode *left, *right;
};


BOOL RelocD2Ptrs(DWORD* pPtrsStart, DWORD* pPtrsEnd);
DWORD RelocD2Patchs(Patch_t* pPatchStart, Patch_t* pPatchEnd);
BOOL SaveD2Patchs(Patch_t* pPatchStart, Patch_t* pPatchEnd);
BOOL InstallD2Patchs(Patch_t* pPatchStart, Patch_t* pPatchEnd);
void RemoveD2Patchs(Patch_t* pPatchStart, Patch_t* pPatchEnd);
void DeleteD2Patchs(Patch_t* pPatchStart, Patch_t* pPatchEnd);
DWORD GetDllOffset(int num);

// config stuff
void LoadConfig(ConfigVar* config, int num);
void DeleteConfig(ConfigVar* config, int num);

// misc helpers
char isquote(char c);
char *AllocStrN(char *str, int len);
void AllocStrN(char **pstr, char *str, int len);
int strtol2(int &num, char *&str, int base);
char *isnumber(char *str, int base);
void SwapInt(int &num1, int &num2);
void *memcpy2(void *dest, const void *src, size_t count);
int strnicmp2(const char *str1, const char *str2, size_t count);
char skipspace(char *&p);
wchar_t * __cdecl wsprintfW2(wchar_t *dest, char *fmt, ...);
void wcscpy2(wchar_t *dest, char *src);
wchar_t * wcsrcat(wchar_t *dest, wchar_t *src);
void trimspaces(char *str);
void trimspaces(wchar_t *str);


// file helpers
HANDLE OpenFileRead(char *filename);
HANDLE OpenFileWrite(char *filename);
DWORD WriteFile(HANDLE hFile, void *buf, DWORD len);
DWORD ReadFile(HANDLE hFile, void *buf, DWORD len);
char *ReadFileLine(char *str, int len, HANDLE hFile);
BYTE *AllocReadFile(char *filename);
char *GetMyFileNameStrrchr(char *dest, char ch);
HANDLE OpenFileReadHelper(char *postfix);

#endif // HACK_MAP_H
