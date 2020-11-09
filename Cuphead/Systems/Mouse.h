#pragma once

class CMouse
{
private:
	enum class Button { None, Down, Up, Press, DoubleClick };

public:
	CMouse(HWND handle);
	~CMouse() = default;

	void WndProc(UINT msg, WPARAM wParam, LPARAM lParam);
	void Update();
	Vector2 Position() { return position; }

	bool Down(UINT button) { return buttonMap[button] == Button::Down; }
	bool Up(UINT button) { return buttonMap[button] == Button::Up; }
	bool DoubleClick(UINT button) { return buttonMap[button] == Button::DoubleClick; }
	bool Press(UINT button) { return buttonMap[button] == Button::Press; }

	float Wheel() { return wheelMoveValue; }

private:

	HWND handle;

	Vector2 position;

	BYTE buttonStatus[8];
	BYTE buttonPrevStatus[8];
	Button buttonMap[8];

	float wheelValue;
	float wheelPrevValue;
	float wheelMoveValue;

	DWORD doubleClickTime;
	DWORD startDoubleClickTime[8];
	int buttonCount[8];
};