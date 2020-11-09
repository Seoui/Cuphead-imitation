#pragma once

static const int KEYMAX = 256;

class Keyboard
{
public:
	Keyboard();
	~Keyboard() = default;

	bool Down(const int key);
	bool Up(const int key);
	bool Press(const int Key);
	bool Toggle(const int key);

private:
	bitset<KEYMAX> up;
	bitset<KEYMAX> down;
};