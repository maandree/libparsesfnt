/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_gasp(
			const char *data, size_t size,
			struct libparsesfnt_gasp *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	if ((tag->length - 4) % 4) {
		errno = EBFONT;
		return -1;
	}
	return PARSE(LIBPARSESFNT_GASP__, tag->offset, 0, 0, 0, 1, tag);
}


int
libparsesfnt_parse_gasp_entries(
			const char *data, size_t size,
			struct libparsesfnt_gasp_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_GASP_ENTRY__, tag->offset, 4, 0, first, count, tag);
}
