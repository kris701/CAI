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

#define ISVALIDPIN(p) (p == DIGITAL_A || p == DIGITAL_B || p == DIGITAL_C || p == MOTOR_A_1 || p == MOTOR_A_2 || p == MOTOR_B_1 || p == MOTOR_B_2 || p == ANALOG_A || p == ANALOG_B)
#define GETVARNAME(p) #p

#define CHECKVALUE(condition, attemptedValue, className)	\
if (condition)												\
{															\
	Serial.begin(115200);									\
	Serial.print(F("Warning, invalid value for '"));		\
	Serial.print(GETVARNAME(attemptedValue));				\
	Serial.print(F("' set to '"));							\
	Serial.print(value);									\
	Serial.print(F("' (in "));								\
	Serial.print(GETVARNAME(className));					\
	Serial.println(F(")"));									\
	Serial.flush();											\
}															\

#endif

