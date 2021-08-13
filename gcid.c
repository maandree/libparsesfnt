/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_gcid(
			const char *data, size_t size,
			struct libparsesfnt_gcid *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	if ((tag->length - 144) % 2)
		goto ebfont;
	if (PARSE(LIBPARSESFNT_GCID__, tag->offset, 0, 0, 0, 1, tag))
		return -1;
	if (((size_t)(tag->length - 144) / 2 != (size_t)infop->count &&
	     (size_t)(tag->length - 144) / 2 != (size_t)infop->count + 1) ||
	    tag->length != infop->size)
		goto ebfont;
	return 0;

ebfont:
	errno = EBFONT;
	return -1;
}


int
libparsesfnt_parse_gcid_entries(
			const char *data, size_t size,
			struct libparsesfnt_gcid_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_GCID_ENTRY__, tag->offset, 144, 0, first, count, tag);
}
