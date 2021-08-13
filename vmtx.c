/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_vmtx(
			const char *data, size_t size,
			struct libparsesfnt_vmtx_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_VMTX_ENTRY__, tag->offset, 0, 0, first, count, tag);
}


int
libparsesfnt_get_vmtx_tsb_subtable_length(
			size_t *lengthp,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_vhea *vhea)
{
	size_t off;
	/* vhea->num_advances_in_vmtx_table is uint16_t, so overflow is impossible */
	off = (size_t)vhea->num_advances_in_vmtx_table * 4;
	if (off > tag->length || (tag->length - off) % 2) {
		errno = EBFONT;
		return -1;
	}
	*lengthp = (tag->length - off) / 2;
	return 0;
}


int
libparsesfnt_parse_vmtx_tsb_subtable(
			const char *data, size_t size,
			struct libparsesfnt_vmtx_tsb_subtable_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_vhea *vhea,
			size_t first, size_t count)
{
	size_t off;
	/* vhea->num_advances_in_vmtx_table is uint16_t, so overflow is impossible */
	off = (size_t)vhea->num_advances_in_vmtx_table * 4;
	return PARSE(LIBPARSESFNT_VMTX_TSB_SUBTABLE_ENTRY__, tag->offset, off, 0, first, count, NULL);
}
