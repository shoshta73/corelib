#ifndef __CORELIB_INTERNAL_BUILD_TYPE_H__
#define __CORELIB_INTERNAL_BUILD_TYPE_H__ 1

#if defined(__DEBUG__)
#define CORELIB_BUILD_TYPE "Debug"
#define CORELIB_DEBUG 1
#elif defined(__RELEASE__)
#define CORELIB_BUILD_TYPE "Release"
#define CORELIB_RELEASE 1
#elif defined(__REL_WITH_DEB_INFO__)
#define CORELIB_BUILD_TYPE "RelWithDebInfo"
#define CORELIB_REL_WITH_DEB_INFO 1
#elif defined(__MIN_SIZE_REL__)
#define CORELIB_BUILD_TYPE "MinSizeRel"
#define CORELIB_MIN_SIZE_REL 1
#else
#error "Unknown build type"
#endif

#ifndef CORELIB_BUILD_TYPE
#error "CORELIB_BUILD_TYPE is not defined"
#endif

#ifndef CORELIB_DEBUG
#define CORELIB_DEBUG 0
#endif

#ifndef CORELIB_RELEASE
#define CORELIB_RELEASE 0
#endif

#ifndef CORELIB_REL_WITH_DEB_INFO
#define CORELIB_REL_WITH_DEB_INFO 0
#endif

#ifndef CORELIB_MIN_SIZE_REL
#define CORELIB_MIN_SIZE_REL 0
#endif

#ifndef __DEBUG__
#define __DEBUG__ 0
#endif

#ifndef __RELEASE__
#define __RELEASE__ 0
#endif

#ifndef __REL_WITH_DEB_INFO__
#define __REL_WITH_DEB_INFO__ 0
#endif

#ifndef __MIN_SIZE_REL__
#define __MIN_SIZE_REL__ 0
#endif

#endif // __CORELIB_INTERNAL_BUILD_TYPE_H__
