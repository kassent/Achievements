#include "Relocation/RVA.h"
#include "SafeWrite.h"
#include <shlobj.h>

IDebugLog	gLog;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD reason, LPVOID reserved)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		gLog.OpenRelative(CSIDL_MYDOCUMENTS, "\\Larian Studios\\Divinity Original Sin 2\\NativeModLogs\\Achievements.log");
		uintptr_t patchIndex = 0;
		try
		{
			uintptr_t patchA = RVAScan<uintptr_t>("75 3E 48 8B 8B ? ? ? ?").GetUIntPtr();//0x9090
			SafeWrite16(patchA, 0x9090);
			_MESSAGE("(%016I64X) patched sucessfully...", patchA - RelocationManager::s_baseAddr);
		}
		catch (const no_result_exception & exceptioin)
		{
			_MESSAGE("[%d]%s", ++patchIndex, exceptioin.what());
		}

		try
		{
			uintptr_t patchB = RVAScan<uintptr_t>("75 3F 48 8B 8B ? ? ? ?").GetUIntPtr();
			SafeWrite16(patchB, 0x9090);
			_MESSAGE("(%016I64X) patched sucessfully...", patchB - RelocationManager::s_baseAddr);
		}
		catch (const no_result_exception & exceptioin)
		{
			_MESSAGE("[%d]%s", ++patchIndex, exceptioin.what());
		}

		try
		{
			uintptr_t patchC = RVAScan<uintptr_t>("74 08 32 C0 48 83 C4 20 5B C3 48 8B 53 08").GetUIntPtr(); //74->EB
			SafeWrite8(patchC, 0xEB);
			_MESSAGE("(%016I64X) patched sucessfully...", patchC - RelocationManager::s_baseAddr);
		}
		catch (const no_result_exception & exceptioin)
		{
			_MESSAGE("[%d]%s", ++patchIndex, exceptioin.what());
		}
		//patchD
		//v3.0.150.188
		try
		{
			uintptr_t patchD = RVAScan<uintptr_t>("74 07 E8 ? ? ? ? EB 14 E8 ? ? ? ? EB 0D 48 8D 54 24 ? 48 8B ? E8 ? ? ? ? 48 8B 4C 24 ?").GetUIntPtr();
			SafeWrite8(patchD, 0xEB);
			_MESSAGE("(%016I64X) patched sucessfully...", patchD - RelocationManager::s_baseAddr);
		}
		catch (const no_result_exception & exceptioin)
		{
			_MESSAGE("[%d]%s", ++patchIndex, exceptioin.what());
		}

		try
		{
			uintptr_t patchE = RVAScan<uintptr_t>("74 12 40 32 FF").GetUIntPtr();
			SafeWrite8(patchE, 0xEB);
			_MESSAGE("(%016I64X) patched sucessfully...", patchE - RelocationManager::s_baseAddr);
		}
		catch (const no_result_exception & exceptioin)
		{
			_MESSAGE("[%d]%s", ++patchIndex, exceptioin.what());
		}

		try
		{
			uintptr_t patchF = RVAScan<uintptr_t>("74 0F 40 32 FF").GetUIntPtr();
			SafeWrite8(patchF, 0xEB);
			_MESSAGE("(%016I64X) patched sucessfully...", patchF - RelocationManager::s_baseAddr);
		}
		catch (const no_result_exception & exceptioin)
		{
			_MESSAGE("[%d]%s", ++patchIndex, exceptioin.what());
		}

		try
		{
			uintptr_t patchG = RVAScan<uintptr_t>("48 89 5C 24 ? 8B 59 1C").GetUIntPtr();
			UInt8 codes[] = {0x32, 0xC0, 0xC3, 0x90, 0x90};
			SafeWriteBuf(patchG, codes, sizeof(codes));
			_MESSAGE("(%016I64X) patched sucessfully...", patchG - RelocationManager::s_baseAddr);
		}
		catch (const no_result_exception & exceptioin)
		{
			_MESSAGE("[%d]%s", ++patchIndex, exceptioin.what());
		}

		//74 22 48 8B 83 ? ? ? ? 8B 8B ? ? ? ?
		try
		{
			uintptr_t patchH = RVAScan<uintptr_t>("74 22 48 8B 83 ? ? ? ? 8B 8B ? ? ? ?").GetUIntPtr();
			SafeWrite8(patchH, 0xEB);
			_MESSAGE("(%016I64X) patched sucessfully...", patchH - RelocationManager::s_baseAddr);
		}
		catch (const no_result_exception & exceptioin)
		{
			_MESSAGE("[%d]%s", ++patchIndex, exceptioin.what());
		}
	}
	else if (reason == DLL_PROCESS_DETACH)
	{

	}
	return TRUE;
}