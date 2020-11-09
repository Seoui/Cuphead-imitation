#pragma once

class LineCollider
{
public:
	static float Cross(Vector2 vec1, Vector2 vec2);
	static float CCW(Vector2 vec1, Vector2 vec2);
	static float CCW(Vector2 init, Vector2 position1, Vector2 position2);

	static bool LineIntersect(Vector2 A, Vector2 B, Vector2 C, Vector2 D);
};