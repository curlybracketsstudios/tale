#pragma once

#if defined(CBENTITYCOMPONENTSYSTEM_LIBRARY)
#  define CBENTITYCOMPONENTSYSTEMSHARED_EXPORT __declspec(dllexport)
#else
#  define CBENTITYCOMPONENTSYSTEMSHARED_EXPORT __declspec(dllimport)
#endif