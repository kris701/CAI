// Macros.h

#ifndef _MACROS_h
#define _MACROS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define GET_Property(T, name)								\
	private: T name;										\
	public: T Get##name(){ return name; }					\

#define GET_SET_Property(T, name)				MGET_MSET_Property(T, name, { return name; }, { value = name; })
#define GET_MSET_Property(T, name, setMethod)	MGET_MSET_Property(T, name, { return name; }, setMethod)
#define MGET_SET_Property(T, name, getMethod)	MGET_MSET_Property(T, name, getMethod, { value = name; })

#define MGET_MSET_Property(T, name, getMethod, setMethod)	\
	private: T name;										\
	public: void Set##name(T value)setMethod				\
	public: T Get##name()getMethod							\


#endif

