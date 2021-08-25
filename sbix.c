/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_sbix(
			const char *data, size_t size,
			struct libparsesfnt_sbix *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	return PARSE(LIBPARSESFNT_SBIX__, tag->offset, 0, 0, 0, 1, tag);
}


int
libparsesfnt_parse_sbix_v1_strike_offset_entries(
			const char *data, size_t size,
			uint32_t *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count)
{
	return PARSE("4", tag->offset, 8, 0, first, count, tag);
}


int
libparsesfnt_parse_sbix_v1_strike_entry(
			const char *data, size_t size,
			struct libparsesfnt_sbix_v1_strike_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag, size_t strike_offset)
{
	return PARSE(LIBPARSESFNT_SBIX_V1_STRIKE_ENTRY__, tag->offset, strike_offset, 0, 0, 1, tag);
}


int
libparsesfnt_parse_sbix_v1_glyph_data_offset_entries(
			const char *data, size_t size,
			uint32_t *infop,
			const struct libparsesfnt_tabdir_entry *tag, size_t strike_offset,
			size_t first, size_t count)
{
	return PARSE("4", tag->offset, strike_offset, 4, first, count, tag);
}


int
libparsesfnt_parse_sbix_v1_glyph_data_entry(
			const char *data, size_t size,
			struct libparsesfnt_sbix_v1_glyph_data_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			  size_t strike_offset, size_t glyph_data_offset, size_t next_glyphs_data_offset)
{
	int ret;
	size_t image_data_length;
	if (next_glyphs_data_offset < glyph_data_offset)
		goto ebfont;
	image_data_length = next_glyphs_data_offset - glyph_data_offset;
	if (!image_data_length) {
		errno = EINVAL;
		return -1;
	} else if (image_data_length < 8) {
		goto ebfont;
	}
	ret = PARSE(LIBPARSESFNT_SBIX_V1_GLYPH_DATA_ENTRY__, tag->offset, strike_offset, glyph_data_offset, 0, 1, tag);
	if (!ret) {
		infop->libparsesfnt_image_data_offset = (size_t)tag->offset + (size_t)strike_offset + (size_t)glyph_data_offset + 8;
		infop->libparsesfnt_image_data_length = image_data_length - 8;
		if (infop->libparsesfnt_image_data_length > size - infop->libparsesfnt_image_data_offset)
			goto ebfont;
	}
	return ret;

ebfont:
	errno = EBFONT;
	return -1;
}


int
libparsesfnt_parse_sbix_v1_image_data_dupe(
			const char *data, size_t size,
			struct libparsesfnt_sbix_v1_image_data_dupe *infop,
			const struct libparsesfnt_sbix_v1_glyph_data_entry *glyph_data)
{
	return PARSE(LIBPARSESFNT_SBIX_V1_IMAGE_DATA_DUPE__, glyph_data->libparsesfnt_image_data_offset, 0, 0, 0, 1, NULL);
}


int
libparsesfnt_parse_sbix_v1_image_data_mask(
			const char *data, size_t size,
			struct libparsesfnt_sbix_v1_image_data_mask *infop,
			const struct libparsesfnt_sbix_v1_glyph_data_entry *glyph_data)
{
	int ret;
	if (glyph_data->libparsesfnt_image_data_length < 8 ||
	    glyph_data->libparsesfnt_image_data_offset > SIZE_MAX - 8)
			goto ebfont;
	ret = PARSE(LIBPARSESFNT_SBIX_V1_IMAGE_DATA_MASK__, glyph_data->libparsesfnt_image_data_offset, 0, 0, 0, 1, NULL);
	if (!ret) {
		infop->libparsesfnt_image_data_offset = glyph_data->libparsesfnt_image_data_offset + 8;
		infop->libparsesfnt_image_data_length = glyph_data->libparsesfnt_image_data_length - 8;
		if (infop->libparsesfnt_image_data_length > size - infop->libparsesfnt_image_data_offset)
			goto ebfont;
	}
	return ret;

ebfont:
	errno = EBFONT;
	return -1;
}


int
libparsesfnt_parse_sbix_v1_mask(
			const char *data, size_t size,
			struct libparsesfnt_sbix_v1_mask *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			  const struct libparsesfnt_sbix_v1_image_data_mask *image_data)
{
	int ret;
	ret = PARSE(LIBPARSESFNT_SBIX_V1_MASK__, tag->offset, image_data->mask_offset, 0, 0, 1, NULL);
	if (!ret) {
		infop->libparsesfnt_mask_offset = (size_t)tag->offset + (size_t)image_data->mask_offset + 16;
		if ((size_t)infop->mask_length > size - infop->libparsesfnt_mask_offset) {
			errno = EBFONT;
			return -1;
		}
	}
	return ret;
}
