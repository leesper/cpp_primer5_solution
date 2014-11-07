#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <vector>
#include <iostream>

class Screen;
class Window_mgr
{
public:
	Window_mgr();
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex i);
private:
	std::vector<Screen> screens;
};

class Screen
{
friend void Window_mgr::clear(ScreenIndex);
public:
	using pos_t = std::string::size_type;
	Screen() = default;
	Screen(pos_t ht, pos_t wd, char c): height(ht), width(wd),
										contents(ht * wd, c) {}
	Screen(pos_t ht, pos_t wd): Screen(ht, wd, ' ') {}
	char get() const { return contents[cursor]; }
	inline char get(pos_t ht, pos_t wd) const;
	Screen &move(pos_t r, pos_t c);
	Screen &set(char c);
	Screen &set(pos_t row, pos_t col, char c);
	Screen &display(std::ostream &os)
		{ do_display(os); return *this; }
	const Screen &display(std::ostream &os) const
		{ do_display(os); return *this; }
private:
	void do_display(std::ostream &os) const { os << contents; }
	pos_t cursor = 0;
	pos_t height = 0, width = 0;
	std::string contents;
};

Window_mgr::Window_mgr(): screens({Screen(24, 80, ' ')})
{}

void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}

inline
Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline
Screen &Screen::set(pos_t row, pos_t col, char c)
{
	contents[row * width +col] = c;
	return *this;
}

inline
Screen &Screen::move(pos_t r, pos_t c)
{
	pos_t row = r * width;
	cursor = row + c;
	return *this;
}

char Screen::get(pos_t r, pos_t c) const
{
	pos_t row = r * width;
	return contents[row + c];
}

#endif//WINDOW_H
