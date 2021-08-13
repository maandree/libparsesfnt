/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_tabdir(
			const char *data, size_t size,
			struct libparsesfnt_tabdir_entry *infop,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_TABDIR_ENTRY__, 12, 0, 0, first, count, NULL);
}
