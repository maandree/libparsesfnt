/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_bloc(
			const char *data, size_t size,
			struct libparsesfnt_bloc *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	return PARSE(LIBPARSESFNT_BLOC__, tag->offset, 0, 0, 0, 1, tag);
}


int
libparsesfnt_parse_bloc_v2_0_size_entries(
			const char *data, size_t size,
			struct libparsesfnt_bloc_v2_0_size_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_BLOC_V2_0_SIZE_ENTRY__, tag->offset, 8, 0, first, count, tag);
}


int
libparsesfnt_parse_bloc_v2_0_index_entries(
			const char *data, size_t size,
			struct libparsesfnt_bloc_v2_0_index_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			  const struct libparsesfnt_bloc_v2_0_size_entry *size_entry,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_BLOC_V2_0_INDEX_ENTRY__, tag->offset, size_entry->index_subtable_array_offset,
	             0, first, count, tag);
}


int
libparsesfnt_parse_bloc_v2_0_index_subentry(
			const char *data, size_t size,
			struct libparsesfnt_bloc_v2_0_index_subentry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			  const struct libparsesfnt_bloc_v2_0_size_entry *size_entry,
			  const struct libparsesfnt_bloc_v2_0_index_entry *index_entry)
{
	return PARSE(LIBPARSESFNT_BLOC_V2_0_INDEX_SUBENTRY__, tag->offset, size_entry->index_subtable_array_offset,
	             index_entry->additional_offset_to_index_subtable, 0, 1, tag);
}


int
libparsesfnt_parse_bloc_v2_0_format_1_offset_entries(
			const char *data, size_t size,
			uint32_t *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			  const struct libparsesfnt_bloc_v2_0_size_entry *size_entry,
			  const struct libparsesfnt_bloc_v2_0_index_entry *index_entry,
			size_t first, size_t count)
{
	return PARSE("4", (size_t)tag->offset + (size_t)size_entry->index_subtable_array_offset,
	             index_entry->additional_offset_to_index_subtable, 8, first, count, tag);
}


int
libparsesfnt_parse_bloc_v2_0_format_2_header(
			const char *data, size_t size,
			struct libparsesfnt_bloc_v2_0_index_subentry_format_2_header *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			  const struct libparsesfnt_bloc_v2_0_size_entry *size_entry,
			  const struct libparsesfnt_bloc_v2_0_index_entry *index_entry)
{
	int ret;
	ret = PARSE(LIBPARSESFNT_BLOC_V2_0_INDEX_SUBENTRY_FORMAT_2_HEADER__,
	            (size_t)tag->offset + (size_t)size_entry->index_subtable_array_offset,
	            index_entry->additional_offset_to_index_subtable, 8, 0, 1, tag);
	if (!ret) {
		if (!infop->image_size) {
			errno = EBFONT;
			return -1;
		}
	}
	return ret;
}


int
libparsesfnt_parse_bloc_v2_0_format_3_offset_entries(
			const char *data, size_t size,
			uint16_t *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			  const struct libparsesfnt_bloc_v2_0_size_entry *size_entry,
			  const struct libparsesfnt_bloc_v2_0_index_entry *index_entry,
			size_t first, size_t count)
{
	return PARSE("2", (size_t)tag->offset + (size_t)size_entry->index_subtable_array_offset,
	             index_entry->additional_offset_to_index_subtable, 8, first, count, tag);
}


int
libparsesfnt_get_bloc_v2_0_format_1_offset(
			size_t *offsetp,
			const uint32_t offset,
			const struct libparsesfnt_bloc_v2_0_index_subentry *subentry)
{
#if SIZE_MAX == UINT32_MAX /* we know that SIZE_MAX >= UINT32_MAX */
	if (offset > UINT32_MAX - subentry->image_data_offset) {
		errno = EFBIG;
		return -1;
	}
#endif
	*offsetp = (size_t)offset + (size_t)subentry->image_data_offset;
	return 0;
}


int
libparsesfnt_get_bloc_v2_0_format_2_offset(
			size_t *offsetp,
			size_t glyph_index,
			const struct libparsesfnt_bloc_v2_0_index_entry *entry,
			  const struct libparsesfnt_bloc_v2_0_index_subentry *subentry,
			  struct libparsesfnt_bloc_v2_0_index_subentry_format_2_header *header)
{
	if (glyph_index < (size_t)entry->first_glyph_index) {
		errno = EINVAL;
		return -1;
	}
	*offsetp = glyph_index - (size_t)entry->first_glyph_index;
	if (*offsetp > (SIZE_MAX - (size_t)subentry->image_data_offset) / (size_t)header->image_size) {
		errno = EFBIG;
		return -1;
	}
	*offsetp = *offsetp * header->image_size + subentry->image_data_offset;
	return 0;
}


int
libparsesfnt_get_bloc_v2_0_format_3_offset(
			size_t *offsetp,
			const uint16_t offset,
			const struct libparsesfnt_bloc_v2_0_index_subentry *subentry)
{
#if SIZE_MAX == UINT32_MAX /* we know that SIZE_MAX >= UINT32_MAX */
	if ((uint32_t)offset > UINT32_MAX - subentry->image_data_offset) {
		errno = EFBIG;
		return -1;
	}
#endif
	*offsetp = (size_t)offset + (size_t)subentry->image_data_offset;
	return 0;
}
