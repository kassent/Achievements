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
			uintptr_t patchA = RVA<uintptr_t>("49 8B F8 8B F2 48 8B 8B B0 00 00 00 48 81 C1 48 02 00 00 E8 ? ? ? ? 84 C0 75 3E 48 8B 8B 90 00 00 00 48 8B 01 FF 90 88 00 00 00 48 85 C0 74 29", 0x1A).GetUIntPtr();//0x9090
			SafeWrite16(patchA, 0x9090);
			_MESSAGE("(%016I64X) patched sucessfully...", patchA - RelocationManager::s_baseAddr);
		}
		catch (const no_result_exception & exceptioin)
		{
			_MESSAGE("[%d]%s", ++patchIndex, exceptioin.what());
		}

		try
		{
			uintptr_t patchB = RVA<uintptr_t>("48 8B FA 48 8B 8B B0 00 00 00 48 81 C1 48 02 00 00 E8 ? ? ? ? 84 C0 75 3F 48 8B 8B 90 00 00 00 48 8B 01 FF 90 88 00 00 00 48 85 C0 74 2A 4C 8B 08", 0x18).GetUIntPtr();
			SafeWrite16(patchB, 0x9090);
			_MESSAGE("(%016I64X) patched sucessfully...", patchB - RelocationManager::s_baseAddr);
		}
		catch (const no_result_exception & exceptioin)
		{
			_MESSAGE("[%d]%s", ++patchIndex, exceptioin.what());
		}

		try
		{
			uintptr_t patchC = RVA<uintptr_t>("40 53 48 83 EC 20 48 8B 05 ? ? ? ? 48 8B DA 48 8B 88 B0 00 00 00 48 81 C1 48 02 00 00 E8 ? ? ? ? 84 C0 74 08 32 C0 48 83 C4 20 5B C3 48 8B 53 08 48 83 C4 20 5B E9 ? ? ? ?", 0x25).GetUIntPtr(); //74->EB
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
			uintptr_t patchD = RVA<uintptr_t>("48 8B CF 84 DB 74 07 E8 ? ? ? ? EB 14 E8 ? ? ? ? EB 0D 48 8D 54 24 50 48 8B CF E8 ? ? ? ? 48 8B 4C 24 58", 0x5).GetUIntPtr();
			SafeWrite8(patchD, 0xEB);
			_MESSAGE("(%016I64X) patched sucessfully...", patchD - RelocationManager::s_baseAddr);
		}
		catch (...)
		{
			try
			{
				uintptr_t patchD = RVA<uintptr_t>("48 8B CB 40 84 F6 74 07 E8 ? ? ? ? EB 14 E8 ? ? ? ? EB 0D 48 8D 54 24 40 48 8B CB E8 ? ? ? ? 48 8B 4C 24 48", 0x6).GetUIntPtr();
				SafeWrite8(patchD, 0xEB);
				_MESSAGE("(%016I64X) patched sucessfully...", patchD - RelocationManager::s_baseAddr);
			}
			catch (const no_result_exception & exceptioin)
			{
				_MESSAGE("[%d]%s", ++patchIndex, exceptioin.what());
			}
		}

		try
		{
			uintptr_t patchE = RVA<uintptr_t>("84 DB 74 12 40 32 FF BA 06 00 00 00 49 8B CF E8 ? ? ? ? EB 19 E8 ? ? ? ? 0F B6 F8 EB 0F 40 32 FF 48 8D 55 10 49 8B CF", 0x2).GetUIntPtr();
			SafeWrite8(patchE, 0xEB);
			_MESSAGE("(%016I64X) patched sucessfully...", patchE - RelocationManager::s_baseAddr);
		}
		catch (const no_result_exception & exceptioin)
		{
			_MESSAGE("[%d]%s", ++patchIndex, exceptioin.what());
		}

		try
		{
			uintptr_t patchF = RVA<uintptr_t>("48 8B 88 08 01 00 00 48 81 C1 48 02 00 00 E8 ? ? ? ? 49 8B CF 84 C0 74 0F 40 32 FF BA 07 00 00 00 E8 ? ? ? ? EB 1F 48 8B 05 ? ? ? ? 80 B8 D1 0B 00 00 03 75 0A", 0x18).GetUIntPtr();
			SafeWrite8(patchF, 0xEB);
			_MESSAGE("(%016I64X) patched sucessfully...", patchF - RelocationManager::s_baseAddr);
		}
		catch (const no_result_exception & exceptioin)
		{
			_MESSAGE("[%d]%s", ++patchIndex, exceptioin.what());
		}
		//STEAM:
		//49 8B F8 8B F2 48 8B 8B B0 00 00 00 48 81 C1 48 02 00 00 E8 ? ? ? ? 84 C0 75 3E 48 8B 8B 90 00 00 00 48 8B 01 FF 90 88 00 00 00 48 85 C0 74 29
		//48 8B FA 48 8B 8B B0 00 00 00 48 81 C1 48 02 00 00 E8 ? ? ? ? 84 C0 75 3F 48 8B 8B 90 00 00 00 48 8B 01 FF 90 88 00 00 00 48 85 C0 74 2A 4C 8B 08
		//40 53 48 83 EC 20 48 8B 05 ? ? ? ? 48 8B DA 48 8B 88 B0 00 00 00 48 81 C1 48 02 00 00 E8 ? ? ? ? 84 C0 74 08 32 C0 48 83 C4 20 5B C3 48 8B 53 08 48 83 C4 20 5B E9 ? ? ? ?
	}
	else if (reason == DLL_PROCESS_DETACH)
	{

	}
	return TRUE;
}