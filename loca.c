/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_loca_short(
			const char *data, size_t size,
			struct libparsesfnt_loca_short_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_LOCA_SHORT_ENTRY__, tag->offset, 0, 0, first, count, tag);
}


int
libparsesfnt_parse_loca_long(
			const char *data, size_t size,
			struct libparsesfnt_loca_long_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_LOCA_LONG_ENTRY__, tag->offset, 0, 0, first, count, tag);
}
