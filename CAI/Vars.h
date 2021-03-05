#pragma once

#include <Arduino.h>
#include "MenuStructure.h"

#ifndef VAR_DECLS
# define _DECL extern
# define _INIT(x)
#else
# define _DECL
# define _INIT(x)  = x
#endif

#define BASE_MENU_LENGTH 2

