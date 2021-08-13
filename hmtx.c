/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_hmtx(
			const char *data, size_t size,
			struct libparsesfnt_hmtx_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_HMTX_ENTRY__, tag->offset, 0, 0, first, count, tag);
}


int
libparsesfnt_get_hmtx_lsb_subtable_length(
			size_t *lengthp,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_hhea *hhea)
{
	size_t off;
	/* hhea->num_advances_in_hmtx_table is uint16_t, so overflow is impossible */
	off = (size_t)hhea->num_advances_in_hmtx_table * 4;
	if (off > tag->length || (tag->length - off) % 2) {
		errno = EBFONT;
		return -1;
	}
	*lengthp = (tag->length - off) / 2;
	return 0;
}


int
libparsesfnt_parse_hmtx_lsb_subtable(
			const char *data, size_t size,
			struct libparsesfnt_hmtx_lsb_subtable_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_hhea *hhea,
			size_t first, size_t count)
{
	size_t off;
	/* hhea->num_advances_in_hmtx_table is uint16_t, so overflow is impossible */
	off = (size_t)hhea->num_advances_in_hmtx_table * 4;
	return PARSE(LIBPARSESFNT_HMTX_LSB_SUBTABLE_ENTRY__, tag->offset, off, 0, first, count, NULL);
}
