#pragma once

#if defined(CBBASE_LIBRARY)
#  define CBBASESHARED_EXPORT __declspec(dllexport)
#else
#  define CBBASESHARED_EXPORT __declspec(dllimport)
#endif