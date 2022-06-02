#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <string>

namespace Color
{
    enum StringsColor
    {
        BLACK = 30,
        RED = 31,
        GREEN = 32,
        YELLOW = 33,
        BLUE = 34,
        MAGENTA = 35,
        CYAN = 36,
        WHITE = 37,
        DEFAULT = 39
    };

    std::string
    getColor(StringsColor color);
    std::string
    getColorBold(StringsColor color);

}; // namespace Color

std::string
Color::getColor(Color::StringsColor color)
{
    return "\033[" + std::to_string(color) + "m";
}
std::string
Color::getColorBold(Color::StringsColor color)
{
    return "\033[" + std::to_string(1) + ";" + std::to_string(color) + "m";
}

#endif // COLOR_H