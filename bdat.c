/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_bdat(
			const char *data, size_t size,
			struct libparsesfnt_bdat *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	return PARSE(LIBPARSESFNT_BDAT__, tag->offset, 0, 0, 0, 1, tag);
}


int
libparsesfnt_parse_bdat_v2_0_big_glyph_metrics_entry(
			const char *data, size_t size,
			struct libparsesfnt_bdat_v2_0_big_glyph_metrics *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t offset)
{
	return PARSE(LIBPARSESFNT_BDAT_V2_0_BIG_GLYPH_METRICS__, tag->offset, offset, 0, 0, 1, tag);
}


int
libparsesfnt_parse_bdat_v2_0_small_glyph_metrics_entry(
			const char *data, size_t size,
			struct libparsesfnt_bdat_v2_0_small_glyph_metrics *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t offset)
{
	return PARSE(LIBPARSESFNT_BDAT_V2_0_SMALL_GLYPH_METRICS__, tag->offset, offset, 0, 0, 1, tag);
}


int
libparsesfnt_parse_bdat_v2_0_format_4_glyph_data_entry(
			const char *data, size_t size,
			struct libparsesfnt_bdat_v2_0_format_4_glyph_data *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t offset)
{
	return PARSE(LIBPARSESFNT_BDAT_V2_0_FORMAT_4_GLYPH_DATA__, tag->offset, offset, 0, 0, 1, tag);
}


static int
get_bdat_image_data_offset(
			size_t size,
			size_t *offsetp,
			const struct libparsesfnt_tabdir_entry *tag, size_t header_size,
			size_t offset, size_t image_size_or_zero)
{
	if (image_size_or_zero > SIZE_MAX ||
	    header_size > SIZE_MAX - image_size_or_zero ||
	    offset > SIZE_MAX - image_size_or_zero - header_size ||
	    offset + image_size_or_zero + header_size > (size_t)tag->length ||
	    (size_t)tag->offset + offset + image_size_or_zero + header_size > size) {
		errno = EBFONT;
		return -1;
	}
	*offsetp = (size_t)tag->offset + offset + header_size;
	return 0;
}


int
libparsesfnt_get_bdat_v2_0_format_1_image_data_offset(
			size_t size,
			size_t *offsetp,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t offset, size_t image_size_or_zero)
{
	return get_bdat_image_data_offset(size, offsetp, tag, 5, offset, image_size_or_zero);
}


int
libparsesfnt_get_bdat_v2_0_format_4_image_data_offset(
			size_t size,
			size_t *offsetp,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t offset, size_t image_size_or_zero)
{
	return get_bdat_image_data_offset(size, offsetp, tag, 12, offset, image_size_or_zero);
}


int
libparsesfnt_get_bdat_v2_0_format_5_image_data_offset(
			size_t size,
			size_t *offsetp,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t offset, size_t image_size_or_zero)
{
	return get_bdat_image_data_offset(size, offsetp, tag, 0, offset, image_size_or_zero);
}


int
libparsesfnt_get_bdat_v2_0_format_6_image_data_offset(
			size_t size,
			size_t *offsetp,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t offset, size_t image_size_or_zero)
{
	return get_bdat_image_data_offset(size, offsetp, tag, 8, offset, image_size_or_zero);
}
