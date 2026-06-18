#pragma once

#ifdef _WIN32
    #ifdef RENDERLAMP_EXPORTS
        #define RENDERLAMP_API __declspec(dllexport)
    #else
        #define RENDERLAMP_API __declspec(dllimport)
    #endif
#else
    #define RENDERLAMP_API
#endif

#define RANDERLAMP_API RENDERLAMP_API

