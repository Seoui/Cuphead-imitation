#pragma once

class EndClip
{
public:
	friend class Cagney;

public:
	EndClip();
	~EndClip() = default;

	void Update(Matrix& V, Matrix& P);
	void Render();
	void Play();

private:
	unique_ptr<Clip> end_clip;
};