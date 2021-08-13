/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_ltag(
			const char *data, size_t size,
			struct libparsesfnt_ltag *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	return PARSE(LIBPARSESFNT_LTAG__, tag->offset, 0, 0, 0, 1, tag);
}


int
libparsesfnt_parse_ltag_entries(
			const char *data, size_t size,
			struct libparsesfnt_ltag_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_LTAG_ENTRY__, tag->offset, 12, 0, first, count, tag);
}


int
libparsesfnt_get_ltag_offset(
			size_t size,
			size_t *offsetp,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_ltag_entry *entry)
{
	size_t offset;
	if ((size_t)entry->offset > size - (size_t)tag->offset) {
		errno = EBFONT;
		return -1;
	}
	offset = (size_t)tag->offset + (size_t)entry->offset;
	if ((size_t)entry->length > size - offset) {
		errno = EBFONT;
		return -1;
	}
	*offsetp = offset;
	return 0;
}
