#ifndef
#define

#define NDEBUG
#include <assert.h>

#if DEBUG == 1
#include <assert.h>
#endif

#ifdef JUST_CHECKING
	assert()...
#endif
