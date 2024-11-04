#include <algorithm>
#include <string>

#include "Point.hpp"
#include "Slider.hpp"

Slider::Slider(float x, float y, float w, float h) :
	ImageButton("stage-select/slider.png", "stage-select/slider-blue.png", x, y),
	Bar("stage-select/bar.png", x, y, w, h),
	End1("stage-select/end.png", x, y + h / 2, 0, 0, 0.5, 0.5),
	End2("stage-select/end.png", x + w, y + h / 2, 0, 0, 0.5, 0.5) {
	Position.x += w;
	Position.y += h / 2;
	Anchor = Engine::Point(0.5, 0.5);
}
void Slider::Draw() const {
    Bar.Draw();
    End1.Draw();
    End2.Draw();
    ImageButton::Draw();
}
void Slider::SetOnValueChangedCallback(std::function<void(float value)> onValueChangedCallback) {
    OnValueChangedCallback = onValueChangedCallback;
}
void Slider::SetValue(float value) {
	// 
	//  1 (4/7): Call 'OnValueChangedCallback' when value changed. Can imitate ImageButton's 'OnClickCallback'.
	// Also, move the slider along the bar, to the corresponding position.
	if (this->value!=value){
		if (OnValueChangedCallback) {
			OnValueChangedCallback(value);
		}
		Position.x+=(value-this->value)*190;
		this->value = value;
	}
}
void Slider::OnMouseDown(int button, int mx, int my) {
	// TODO 1 (5/7): Set 'Down' to true if mouse is in the slider.
	if ((button & 1) && mouseIn && Enabled) {
		Down = true;
	}

}
void Slider::OnMouseUp(int button, int mx, int my) {
	// TODO 1 (6/7): Set 'Down' to false.
		Down = false;
}
void Slider::OnMouseMove(int mx, int my) {
	// TODO 1 (7/7): Clamp the coordinates and calculate the value. Call 'SetValue' when you're done.
	ImageButton::OnMouseMove(mx, my);//change color
	if (Down ==true) {
		if (mx < End1.Position.x) SetValue(Min);
		else if (mx > End2.Position.x) SetValue(Max);
		else SetValue((mx-End1.Position.x)/190);
	}
}
