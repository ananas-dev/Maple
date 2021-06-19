#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Maple/Log.h"

#ifdef MP_PLATFORM_WINDOWS
    #define NOMINMAX
    #include <Windows.h>
#elif MP_PLATFORM_UNIX
    #include <unistd.h>
#endif

