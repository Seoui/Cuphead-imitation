#pragma once

class StartClip
{
public:
	StartClip();
	~StartClip() = default;

	void Update(Matrix& V, Matrix& P);
	void Render();

private:
	unique_ptr<Clip> ready;
	bool b_end = false;
};

