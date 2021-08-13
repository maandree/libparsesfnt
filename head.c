/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_head(
			const char *data, size_t size,
			struct libparsesfnt_head *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	return PARSE(LIBPARSESFNT_HEAD__, tag->offset, 0, 0, 0, 1, tag);
}
