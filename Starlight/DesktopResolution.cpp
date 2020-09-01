#include "DesktopResolution.h"
#include "wtypes.h"


DesktopResolution::DesktopResolution()
{
}

void DesktopResolution::GetDesktopResolution(int& horizontal, int& vertical)
{
	horizontal = 0;
	vertical = 0;
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	horizontal = desktop.right;
	vertical = desktop.bottom;
}