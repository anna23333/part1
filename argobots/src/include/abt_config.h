/* src/include/abt_config.h.  Generated from abt_config.h.in by configure.  */
/* src/include/abt_config.h.in.  Generated from configure.ac by autoheader.  */


/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 * See COPYRIGHT in top-level directory.
 */

#ifndef ABT_CONFIG_H_INCLUDED
#define ABT_CONFIG_H_INCLUDED


/* Define to 1 if we preserve fpu registers */
#define ABTD_FCONTEXT_PRESERVE_FPU 1

/* Default filename for publishing the performance data */
#define ABT_CONFIG_DEFAULT_PUB_FILENAME "stdout"

/* Define to disable error check */
/* #undef ABT_CONFIG_DISABLE_ERROR_CHECK */

/* Define to disable supporting external threads */
/* #undef ABT_CONFIG_DISABLE_EXT_THREAD */

/* Define to disable ULT migration */
/* #undef ABT_CONFIG_DISABLE_MIGRATION */

/* Define to disable pool consumer check */
/* #undef ABT_CONFIG_DISABLE_POOL_CONSUMER_CHECK */

/* Define to disable pool producer check */
/* #undef ABT_CONFIG_DISABLE_POOL_PRODUCER_CHECK */

/* Define to disable stackable scheduler */
/* #undef ABT_CONFIG_DISABLE_STACKABLE_SCHED */

/* Define to disable tasklet cancellation */
/* #undef ABT_CONFIG_DISABLE_TASK_CANCEL */

/* Define to disable ULT cancellation */
/* #undef ABT_CONFIG_DISABLE_THREAD_CANCEL */

/* Define to handle power management events */
/* #undef ABT_CONFIG_HANDLE_POWER_EVENT */

/* Define if __atomic_exchange_n is supported */
#define ABT_CONFIG_HAVE_ATOMIC_EXCHANGE 1

/* Define to publish execution information */
/* #undef ABT_CONFIG_PUBLISH_INFO */

/* Define to allocate objects aligned to the cache line size */
#define ABT_CONFIG_USE_ALIGNED_ALLOC 1

/* Define to enable debug logging */
/* #undef ABT_CONFIG_USE_DEBUG_LOG */

/* Define to enable printing debug log messages */
/* #undef ABT_CONFIG_USE_DEBUG_LOG_PRINT */

/* Define to use fcontext */
#define ABT_CONFIG_USE_FCONTEXT 1

/* Define to use memory pools for ULT and tasklet creation */
#define ABT_CONFIG_USE_MEM_POOL 1

/* Define to make the scheduler sleep when its pools are empty */
/* #undef ABT_CONFIG_USE_SCHED_SLEEP */

/* Define to use a simple mutex implementation */
/* #undef ABT_CONFIG_USE_SIMPLE_MUTEX */

/* Whether C compiler supports symbol visibility or not */
#define ABT_C_HAVE_VISIBILITY 1

/* Define to 1 if you have the <beacon.h> header file. */
/* #undef HAVE_BEACON_H */

/* Define to 1 if you have the <clh.h> header file. */
/* #undef HAVE_CLH_H */

/* Define to 1 if you have the `clock_getres' function. */
#define HAVE_CLOCK_GETRES 1

/* Define to 1 if you have the `clock_gettime' function. */
#define HAVE_CLOCK_GETTIME 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the `gettimeofday' function. */
#define HAVE_GETTIMEOFDAY 1

/* Define to 1 if you have the <inttypes.h> header file. */
/* #undef HAVE_INTTYPES_H */

/* Define to 1 if you have the <lh_lock.h> header file. */
/* #undef HAVE_LH_LOCK_H */

/* Define to 1 if you have the `hugetlbfs' library (-lhugetlbfs). */
/* #undef HAVE_LIBHUGETLBFS */

/* Define to 1 if you have the `intercoolr' library (-lintercoolr). */
/* #undef HAVE_LIBINTERCOOLR */

/* Define to 1 if you have the `m' library (-lm). */
#define HAVE_LIBM 1

/* Define to 1 if you have the `pthread' library (-lpthread). */
#define HAVE_LIBPTHREAD 1

/* Define to 1 if you have the `mach_absolute_time' function. */
/* #undef HAVE_MACH_ABSOLUTE_TIME */

/* Define if MAP_ANON is defined */
/* #undef HAVE_MAP_ANON */

/* Define if MAP_ANONYMOUS is defined */
#define HAVE_MAP_ANONYMOUS 1

/* Define if MAP_HUGETLB is supported */
#define HAVE_MAP_HUGETLB 1

/* Define to 1 if you have the <memory.h> header file. */
/* #undef HAVE_MEMORY_H */

/* Define to 1 if you have the `pthread_barrier_init' function. */
#define HAVE_PTHREAD_BARRIER_INIT 1

/* Define to 1 if you have the <pthread.h> header file. */
#define HAVE_PTHREAD_H 1

/* Define if pthread_setaffinity_np is available */
/* #undef HAVE_PTHREAD_SETAFFINITY_NP */

/* Define to 1 if you have the <raplreader.h> header file. */
/* #undef HAVE_RAPLREADER_H */

/* Define to 1 if you have the <stdint.h> header file. */
/* #undef HAVE_STDINT_H */

/* Define to 1 if you have the <stdlib.h> header file. */
/* #undef HAVE_STDLIB_H */

/* Define to 1 if you have the <strings.h> header file. */
/* #undef HAVE_STRINGS_H */

/* Define to 1 if you have the <string.h> header file. */
/* #undef HAVE_STRING_H */

/* Define to 1 if you have the <sys/stat.h> header file. */
/* #undef HAVE_SYS_STAT_H */

/* Define to 1 if you have the <sys/types.h> header file. */
/* #undef HAVE_SYS_TYPES_H */

/* Define to 1 if you have the <unistd.h> header file. */
/* #undef HAVE_UNISTD_H */

/* Define valgrind support */
/* #undef HAVE_VALGRIND_SUPPORT */

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Name of package */
#define PACKAGE "argobots"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "argobots"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "argobots 1.0a1"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "argobots"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.0a1"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Version number of package */
#define VERSION "1.0a1"


#endif /* ABT_CONFIG_H_INCLUDED */

