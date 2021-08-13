/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_xref(
			const char *data, size_t size,
			struct libparsesfnt_xref *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	return PARSE(LIBPARSESFNT_XREF__, tag->offset, 0, 0, 0, 1, tag);
}


int
libparsesfnt_parse_xref_entries(
			const char *data, size_t size,
			struct libparsesfnt_xref_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_XREF_ENTRY__, tag->offset, 16, 0, first, count, tag);
}


int
libparsesfnt_get_xref_offset(
			size_t size,
			size_t *offsetp,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_xref *xref,
			const struct libparsesfnt_xref_entry *entry)
{
	size_t offset = (size_t)tag->offset;
	if ((size_t)xref->string_offset > size - offset)
		goto ebfont;
	offset += (size_t)xref->string_offset;
	if ((size_t)entry->string_offset > size - offset)
		goto ebfont;
	offset += (size_t)entry->string_offset;
	if ((size_t)entry->string_length > size - offset)
		goto ebfont;
	*offsetp = offset;
	return 0;

ebfont:
	errno = EBFONT;
	return -1;
}
