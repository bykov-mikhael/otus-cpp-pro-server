#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

 
void button_callback(Fl_Widget* o, void*)
{
	Fl_Button* button = (Fl_Button*) o;
	button->label("Уиииии!");
	button->redraw();
}
 
int main()
{
	/**
	 * Инициализировать окно шириной 300px,
	 * высотой 200px и названием "Тест".
	 */
	Fl_Window window(300, 200, "Тест.");

	/**
	 * В блоке между методами begin() и end() объявляем кнопку,
	 * левый верхний край которой расположен в (10; 150),
	 * шириною 100px и высотою 30px.
	 */
	window.begin();
		Fl_Button button(10, 150, 100, 30, "Нажми");
	window.end();

	/* Привязать callback-функцию к кнопке. */
	button.callback(button_callback);

	/* Показать окно. */
	window.show();
	return Fl::run();
}