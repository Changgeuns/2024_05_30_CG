#pragma once
class PaintScene : public Scene
{
public:
	PaintScene();
	~PaintScene();



	void Update() override;
	void Render(HDC hdc) override;


private:
	vector<HBRUSH> _brushes;
	vector<HPEN> _pens;


	shared_ptr<RectCollider> _rect;
	shared_ptr<CircleCollider> _circle;
	//shared_ptr<Line> _line;
};

