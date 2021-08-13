/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_vhea(
			const char *data, size_t size,
			struct libparsesfnt_vhea *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	return PARSE(LIBPARSESFNT_VHEA__, tag->offset, 0, 0, 0, 1, tag);
}
