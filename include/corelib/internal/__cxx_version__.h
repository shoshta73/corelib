#ifndef __CORELIB_INTERNAL_CXX_VERSION_H__
#define __CORELIB_INTERNAL_CXX_VERSION_H__

#ifndef __cplusplus

#define CORELIB_HAS_CXX 0
#define CORELIB_CXX 0

#else

#define CORELIB_HAS_CXX 1

#if __cplusplus >= 202302L

#define CORELIB_HAS_CXX23 1

#ifndef CORELIB_CXX
#define CORELIB_CXX 23
#endif

#else

#define CORELIB_HAS_CXX23 0

#endif

#if __cplusplus >= 202002L

#define CORELIB_HAS_CXX20 1

#ifndef CORELIB_CXX
#define CORELIB_CXX 20
#endif

#else

#define CORELIB_HAS_CXX20 0
#endif

#if __cplusplus >= 201703L

#define CORELIB_HAS_CXX17 1

#ifndef CORELIB_CXX
#define CORELIB_CXX 17
#endif

#else

#define CORELIB_HAS_CXX17 0

#endif

#if __cplusplus >= 201402L

#define CORELIB_HAS_CXX14 1

#ifndef CORELIB_CXX
#define CORELIB_CXX 14
#endif

#else

#define CORELIB_HAS_CXX14 0

#endif

#if __cplusplus >= 201103L

#define CORELIB_HAS_CXX11 1

#ifndef CORELIB_CXX
#define CORELIB_CXX 11
#endif

#else

#define CORELIB_HAS_CXX11 0

#endif

#if __cplusplus >= 199711L

#define CORELIB_HAS_CXX98 1

#ifndef CORELIB_CXX
#define CORELIB_CXX 98
#endif

#else

#define CORELIB_HAS_CXX98 0

#endif

#endif

#endif // __CORELIB_INTERNAL_CXX_VERSION_H__
