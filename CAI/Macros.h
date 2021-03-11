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

#define GET_SET_Property(T, name)				MGET_MSET_Property(T, name, { return name; }, { name = value; })
#define GET_MSET_Property(T, name, setMethod)	MGET_MSET_Property(T, name, { return name; }, setMethod)
#define MGET_SET_Property(T, name, getMethod)	MGET_MSET_Property(T, name, getMethod, { name = value; })

#define MGET_MSET_Property(T, name, getMethod, setMethod)	\
	private: T name;										\
	public: void Set##name(T value)setMethod				\
	public: T Get##name()getMethod							\

#define GET_PSET_Property(T, name)				MGET_PMSET_Property(T, name, { return name; }, { name = value; })
#define GET_PMSET_Property(T, name, setMethod)	MGET_PMSET_Property(T, name, { return name; }, setMethod)
#define MGET_PSET_Property(T, name, getMethod)	MGET_PMSET_Property(T, name, getMethod, { name = value; })

#define MGET_PMSET_Property(T, name, getMethod, setMethod)	\
	private: T name;										\
	private: void Set##name(T value)setMethod				\
	public: T Get##name()getMethod							\


#endif

