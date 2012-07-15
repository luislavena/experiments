#include "ruby.h"
#include "requires.h"

#ifdef HAVE_LOCALE_H
#include <locale.h>
#endif

int
main(int argc, char **argv)
{
#ifdef HAVE_LOCALE_H
	setlocale(LC_CTYPE, "");
#endif

	ruby_sysinit(&argc, &argv);
	{
		RUBY_INIT_STACK;
		ruby_init();

		/* redefines global require to the alternate one provided by us */
		rb_define_global_function("require", alternate_require, 1);

		return ruby_run_node(ruby_options(argc, argv));
	}
}
