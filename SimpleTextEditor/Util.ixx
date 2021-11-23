#include <type_traits>
#include <string>

export module Util;

/* Concepts */
export template<typename Type>
concept FormatableString = std::is_same<Type, const char*>::value || std::is_same<Type, std::string>::value;
