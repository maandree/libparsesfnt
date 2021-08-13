/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_fdsc(
			const char *data, size_t size,
			struct libparsesfnt_fdsc *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	if ((tag->length - 8) % 8) {
		errno = EBFONT;
		return -1;
	}
	return PARSE(LIBPARSESFNT_FDSC__, tag->offset, 0, 0, 0, 1, tag);
}


int
libparsesfnt_parse_fdsc_entries(
			const char *data, size_t size,
			struct libparsesfnt_fdsc_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_FDSC_ENTRY__, tag->offset, 8, 0, first, count, tag);
}
