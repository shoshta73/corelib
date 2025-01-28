#ifndef __CORELIB_INTERNAL_BUILD_TYPE_H__
#define __CORELIB_INTERNAL_BUILD_TYPE_H__ 1

#if defined(DEBUG)
#define CORELIB_BUILD_TYPE "Debug"
#define CORELIB_DEBUG 1
#elif defined(RELEASE)
#define CORELIB_BUILD_TYPE "Release"
#define CORELIB_RELEASE 1
#elif defined(REL_WITH_DEB_INFO)
#define CORELIB_BUILD_TYPE "RelWithDebInfo"
#define CORELIB_REL_WITH_DEB_INFO 1
#elif defined(MIN_SIZE_REL)
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

#ifndef DEBUG
#define DEBUG 0
#endif

#ifndef RELEASE
#define RELEASE 0
#endif

#ifndef REL_WITH_DEB_INFO
#define REL_WITH_DEB_INFO 0
#endif

#ifndef MIN_SIZE_REL
#define MIN_SIZE_REL 0
#endif

#endif // __CORELIB_INTERNAL_BUILD_TYPE_H__
