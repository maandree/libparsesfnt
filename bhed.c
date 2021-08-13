/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_bhed(
			const char *data, size_t size,
			struct libparsesfnt_bhed *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	return PARSE(LIBPARSESFNT_BHED__, tag->offset, 0, 0, 0, 1, tag);
}
