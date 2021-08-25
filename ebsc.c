/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_ebsc(
			const char *data, size_t size,
			struct libparsesfnt_ebsc *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	return PARSE(LIBPARSESFNT_EBSC__, tag->offset, 0, 0, 0, 1, tag);
}


int
libparsesfnt_parse_ebsc_v2_0_entries(
			const char *data, size_t size,
			struct libparsesfnt_ebsc_v2_0_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_EBSC_V2_0_ENTRY__, tag->offset, 8, 0, first, count, tag);
}
