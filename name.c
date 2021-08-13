/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_name(
			const char *data, size_t size,
			struct libparsesfnt_name *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	if ((tag->length - 6) % 12)
		goto ebfont;
	if (PARSE(LIBPARSESFNT_NAME__, tag->offset, 0, 0, 0, 1, tag))
		return -1;
	if ((tag->length - 6) / 12 != infop->count)
		goto ebfont;
	return 0;

ebfont:
	errno = EBFONT;
	return -1;
}


int
libparsesfnt_parse_name_entries(
			const char *data, size_t size,
			struct libparsesfnt_name_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_NAME_ENTRY__, tag->offset, 6, 0, first, count, tag);
}
