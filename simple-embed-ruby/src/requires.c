#include <stdio.h>

#include "requires.h"

VALUE __real_rb_require(const char*);
VALUE __real_rb_require_safe(VALUE, int);

/* Wraps exported rb_require from Ruby's static library */
VALUE
__wrap_rb_require(const char* fname)
{
	printf("rb_require: %s\n", fname);

	return __real_rb_require(fname);
}

/* Wraps exported rb_require_safe from Ruby's static library */
VALUE
__wrap_rb_require_safe(VALUE fname, int safe)
{
	printf("rb_require_safe: %s\n", RSTRING_PTR(fname));

	return __real_rb_require_safe(fname, safe);
}

/* Provides a replacement of Kernel::require */
VALUE
alternate_require(VALUE obj, VALUE fname)
{
	printf("alternate_require: %s\n", RSTRING_PTR(fname));

	return rb_require_safe(fname, rb_safe_level());
}
