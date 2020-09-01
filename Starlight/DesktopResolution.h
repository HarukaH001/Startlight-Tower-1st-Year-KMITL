#pragma once
class DesktopResolution
{
public:
	int horizontal = 0;
	int vertical = 0;
	DesktopResolution();
	void GetDesktopResolution(int& horizontal, int& vertical);
};

