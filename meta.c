/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_meta(
			const char *data, size_t size,
			struct libparsesfnt_meta *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	int ret;
	ret = PARSE(LIBPARSESFNT_META__, tag->offset, 0, 0, 0, 1, tag);
	if (!ret) {
		if (infop->data_offset > size - tag->offset ||
		    infop->num_data_maps > (size - tag->offset - infop->data_offset) / 12) {
			errno = EBFONT;
			return -1;
		}
	}
	return ret;
}


int
libparsesfnt_parse_meta_entries(
			const char *data, size_t size,
			struct libparsesfnt_meta_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_meta *meta,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_META_ENTRY__, tag->offset, meta->data_offset, 0, first, count, NULL);
}
