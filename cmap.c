/* See LICENSE file for copyright and license details. */
#include "common.h"


static int
get_uint16s(const char *data, size_t size, uint16_t *output, size_t offset, size_t first, size_t count)
{
	uint16_t b1, b2;
	if (count > SIZE_MAX - first) {
		errno = EFBIG;
		return -1;
	}
	if (offset > size || first + count > (size - offset) / 2) {
		errno = EBFONT;
		return -1;
	}
	offset += first * 2;
	data = &data[offset];
	for (; count--; output++, data = &data[2]) {
		b1 = (uint16_t)((uint16_t)((const uint8_t *)data)[0] << 8);
		b2 = (uint16_t)((uint16_t)((const uint8_t *)data)[1] << 0);
		*output = (uint16_t)(b1 | b2);
	}
	return 0;
}


int
libparsesfnt_parse_cmap(
			const char *data, size_t size,
			struct libparsesfnt_cmap *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	return PARSE(LIBPARSESFNT_CMAP__, tag->offset, 0, 0, 0, 1, tag);
}


int
libparsesfnt_parse_cmap_entries(
			const char *data, size_t size,
			struct libparsesfnt_cmap_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count)
{
	int ret;
	ret = PARSE(LIBPARSESFNT_CMAP_ENTRY__, tag->offset, 4, 0, first, count, tag);
	if (!ret) {
		for (; count--; infop++) {
			if (infop->offset > tag->length - 2) {
				errno = EBFONT;
				return -1;
			}
		}
	}
	return ret;
}


int
libparsesfnt_parse_cmap_entry_subtable(
			const char *data, size_t size,
			union libparsesfnt_cmap_entry_subtable *infop,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_cmap_entry *entry)
{
	int ret = 0;
	size_t i;
	uint16_t u16;

	if (PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE__, tag->offset, entry->offset, 0, 0, 1, tag))
		return -1;

	if (infop->format == 0) {
		ret = PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_0__, tag->offset, entry->offset, 0, 0, 1, tag);
		if (!ret) {
			if (infop->f0.length != 3 * 2 + 256 ||
			    infop->f0.length > tag->length - entry->offset)
				goto ebfont;
		}

	} else if (infop->format == 2) {
		ret = PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_2__, tag->offset, entry->offset, 0, 0, 1, tag);
		if (!ret) {
			u16 = 0;
			for (i = 0; i < ELEMSOF(infop->f2.subheader_keys); i++)
				if (infop->f2.subheader_keys[i] > u16)
					u16 = infop->f2.subheader_keys[i];
			infop->f2.libparsesfnt_subheader_keys_max = u16;
			if (u16 > (UINT16_MAX - 8) / 8 - 1 ||
			    infop->f2.length < 8 * 8 * (u16 + 1) ||
			    infop->f2.length > tag->length - entry->offset)
				goto ebfont;
		}

	} else if (infop->format == 4) {
		ret = PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_4__, tag->offset, entry->offset, 0, 0, 1, tag);
		if (!ret) {
			if (infop->f4.seg_count_x2 > (UINT16_MAX - 16) / 4 ||
			    infop->f4.length < 16 + 4 * infop->f4.seg_count_x2 ||
			    infop->f4.length > tag->length - entry->offset)
				goto ebfont;
		}

	} else if (infop->format == 6) {
		ret = PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_6__, tag->offset, entry->offset, 0, 0, 1, tag);
		if (!ret) {
			if (infop->f6.entry_count > UINT16_MAX / 2 - 5 ||
			    infop->f6.length != (5 + infop->f6.entry_count) * 2 ||
			    infop->f6.length > tag->length - entry->offset)
				goto ebfont;
		}

	} else if (infop->format == 8) {
		ret = PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_8__, tag->offset, entry->offset, 0, 0, 1, tag);
		if (!ret) {
			if (infop->f8.n_groups > (UINT32_MAX - 16 - 8192) / 12 ||
			    infop->f8.length != 16 + 8192 + infop->f8.n_groups * 12 ||
			    infop->f8.length > tag->length - entry->offset)
				goto ebfont;
		}

	} else if (infop->format == 10) {
		ret = PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_10__, tag->offset, entry->offset, 0, 0, 1, tag);
		if (!ret) {
			if (infop->f10.num_chars > (UINT32_MAX - 20) / 2 ||
			    infop->f10.length != 20 + infop->f10.num_chars * 2 ||
			    infop->f10.length > tag->length - entry->offset)
				goto ebfont;
		}

	} else if (infop->format == 12) {
		ret = PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_12__, tag->offset, entry->offset, 0, 0, 1, tag);
		if (!ret) {
			if (infop->f12.n_groups > (UINT32_MAX - 16) / 12 ||
			    infop->f12.length != 16 + infop->f12.n_groups * 12 ||
			    infop->f12.length > tag->length - entry->offset)
				goto ebfont;
		}

	} else if (infop->format == 13) {
		ret = PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_13__, tag->offset, entry->offset, 0, 0, 1, tag);
		if (!ret) {
			if (infop->f13.n_groups > (UINT32_MAX - 16) / 12 ||
			    infop->f13.length != 16 + infop->f13.n_groups * 12 ||
			    infop->f13.length > tag->length - entry->offset)
				goto ebfont;
		}

	} else if (infop->format == 14) {
		ret = PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_14__, tag->offset, entry->offset, 0, 0, 1, tag);
		if (!ret) {
			if (infop->f14.num_var_selector_records > (UINT32_MAX - 12) / 12 ||
			    infop->f14.length < 12 + infop->f14.num_var_selector_records * 12 ||
			    infop->f14.length > tag->length - entry->offset)
				goto ebfont;
		}

	} else {
		goto ebfont;
	}
	return ret;

ebfont:
	errno = EBFONT;
	return -1;
}


int
libparsesfnt_parse_cmap_entry_subtable_2_subheader_entries(
			const char *data, size_t size,
			struct libparsesfnt_cmap_entry_subtable_2_subheader *infop,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_cmap_entry *entry,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_2_SUBHEADER__, tag->offset, entry->offset, 259 * 2, first, count, tag);
}


int
libparsesfnt_parse_cmap_entry_subtable_2_glyph_index_entries(
			const char *data, size_t size,
			uint16_t *glyph_indexp,
			const struct libparsesfnt_tabdir_entry *tag,
			  const struct libparsesfnt_cmap_entry *entry,
			  const struct libparsesfnt_cmap_entry_subtable_2 *subtable,
			size_t first, size_t count)
{
	size_t offset;
	offset = 259 * 2 + ((size_t)subtable->libparsesfnt_subheader_keys_max + 1) * 8;
	if (first + count > (subtable->length - offset) / 2) {
		errno = EBFONT;
		return -1;
	}
	offset += tag->offset + entry->offset;
	return get_uint16s(data, size, glyph_indexp, offset, first, count);
}


int
libparsesfnt_parse_cmap_entry_subtable_4_end_code_entries(
			const char *data, size_t size,
			uint16_t *end_codep,
			const struct libparsesfnt_tabdir_entry *tag,
			  const struct libparsesfnt_cmap_entry *entry,
			size_t first, size_t count)
{
	return get_uint16s(data, size, end_codep, tag->offset + entry->offset + 14, first, count);
}


int
libparsesfnt_parse_cmap_entry_subtable_4_start_code_entries(
			const char *data, size_t size,
			uint16_t *start_codep,
			const struct libparsesfnt_tabdir_entry *tag,
			  const struct libparsesfnt_cmap_entry *entry,
			  const struct libparsesfnt_cmap_entry_subtable_4 *subtable,
			size_t first, size_t count)
{
	return get_uint16s(data, size, start_codep, tag->offset + entry->offset + 16 + 1 * subtable->seg_count_x2, first, count);
}


int
libparsesfnt_parse_cmap_entry_subtable_4_id_delta_entries(
			const char *data, size_t size,
			uint16_t *id_deltap,
			const struct libparsesfnt_tabdir_entry *tag,
			  const struct libparsesfnt_cmap_entry *entry,
			  const struct libparsesfnt_cmap_entry_subtable_4 *subtable,
			size_t first, size_t count)
{
	return get_uint16s(data, size, id_deltap, tag->offset + entry->offset + 16 + 2 * subtable->seg_count_x2, first, count);
}


int
libparsesfnt_parse_cmap_entry_subtable_4_id_range_offset_entries(
			const char *data, size_t size,
			uint16_t *id_range_offsetp,
			const struct libparsesfnt_tabdir_entry *tag,
			  const struct libparsesfnt_cmap_entry *entry,
			  const struct libparsesfnt_cmap_entry_subtable_4 *subtable,
			size_t first, size_t count)
{
	return get_uint16s(data, size, id_range_offsetp, tag->offset + entry->offset + 16 + 3 * subtable->seg_count_x2, first, count);
}


int
libparsesfnt_parse_cmap_entry_subtable_4_glyph_index_entries(
			const char *data, size_t size,
			uint16_t *glyph_indexp,
			const struct libparsesfnt_tabdir_entry *tag,
			  const struct libparsesfnt_cmap_entry *entry,
			  const struct libparsesfnt_cmap_entry_subtable_4 *subtable,
			size_t first, size_t count)
{
	if (count > SIZE_MAX - first) {
		errno = EFBIG;
		return -1;
	}
	if (first + count > (tag->length - entry->offset - 16 - 4 * subtable->seg_count_x2) / 2) {
		errno = EBFONT;
		return -1;
	}
	return get_uint16s(data, size, glyph_indexp, tag->offset + entry->offset + 16 + 4 * subtable->seg_count_x2, first, count);
}


int
libparsesfnt_parse_cmap_entry_subtable_6_entries(
			const char *data, size_t size,
			uint16_t *glyphp,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_cmap_entry *entry,
			size_t first, size_t count)
{
	return get_uint16s(data, size, glyphp, tag->offset + entry->offset + 10, first, count);
}


int
libparsesfnt_parse_cmap_entry_subtable_8_entries(
			const char *data, size_t size,
			struct libparsesfnt_cmap_entry_subtable_8_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_cmap_entry *entry,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_8_ENTRY__, tag->offset, entry->offset, 16 + 8192, first, count, tag);
}

int
libparsesfnt_parse_cmap_entry_subtable_10_entries(
			const char *data, size_t size,
			uint16_t *glyphp,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_cmap_entry *entry,
			size_t first, size_t count)
{
	return get_uint16s(data, size, glyphp, tag->offset + entry->offset + 10, first, count);
}


int
libparsesfnt_parse_cmap_entry_subtable_12_entries(
			const char *data, size_t size,
			struct libparsesfnt_cmap_entry_subtable_12_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_cmap_entry *entry,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_12_ENTRY__, tag->offset, entry->offset, 16, first, count, tag);
}


int
libparsesfnt_parse_cmap_entry_subtable_13_entries(
			const char *data, size_t size,
			struct libparsesfnt_cmap_entry_subtable_13_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_cmap_entry *entry,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_13_ENTRY__, tag->offset, entry->offset, 16, first, count, tag);
}


int
libparsesfnt_parse_cmap_entry_subtable_14_entries(
			const char *data, size_t size,
			struct libparsesfnt_cmap_entry_subtable_14_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			  const struct libparsesfnt_cmap_entry *entry,
			  const struct libparsesfnt_cmap_entry_subtable_14 *subtable,
			size_t first, size_t count)
{
	int ret;
	uint8_t high;
	union { uint16_t u16; uint8_t u8s[2]; } low;
	ret = PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_14_ENTRY__, tag->offset, entry->offset, 10, first, count, tag);
	if (!ret) {
		for (; count--; infop++) {
			high = ((uint8_t *)infop)[1];
			low.u8s[0] = ((uint8_t *)infop)[2];
			low.u8s[1] = ((uint8_t *)infop)[3];
			infop->var_selector = ((uint32_t)high << 16) | (uint32_t)low.u16;
			if (infop->default_uvs_offset) {
				if (infop->default_uvs_offset > subtable->length ||
				    4 > subtable->length - infop->default_uvs_offset) {
					goto ebfont;
				}
			}
			if (infop->non_default_uvs_offset) {
				if (infop->non_default_uvs_offset > subtable->length ||
				    4 > subtable->length - infop->non_default_uvs_offset) {
					goto ebfont;
				}
			}
		}
	}
	return 0;

ebfont:
	errno = EBFONT;
	return -1;
}


int
libparsesfnt_parse_cmap_entry_subtable_14_default_uvs(
			const char *data, size_t size,
			struct libparsesfnt_cmap_entry_subtable_14_default_uvs *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			  const struct libparsesfnt_cmap_entry *entry,
			  const struct libparsesfnt_cmap_entry_subtable_14 *subtable,
			  const struct libparsesfnt_cmap_entry_subtable_14_entry *subentry)
{
	int ret;
	ret = PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_14_DEFAULT_UVS__,
	            tag->offset, entry->offset, subentry->default_uvs_offset, 0, 1, tag);
	if (!ret) {
		if (infop->num_unicode_value_ranges > subtable->length / 4) {
			errno = EBFONT;
			return -1;
		}
	}
	return ret;
}


int
libparsesfnt_parse_cmap_entry_subtable_14_default_uvs_entries(
			const char *data, size_t size,
			struct libparsesfnt_cmap_entry_subtable_14_default_uvs_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			  const struct libparsesfnt_cmap_entry *entry,
			  const struct libparsesfnt_cmap_entry_subtable_14_entry *subentry,
			size_t first, size_t count)
{
	int ret;
	uint8_t high;
	union { uint16_t u16; uint8_t u8s[2]; } low;
	ret = PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_14_DEFAULT_UVS_ENTRY__,
	            (size_t)tag->offset + (size_t)entry->offset, subentry->default_uvs_offset, 4,
	            first, count, tag);
	if (!ret) {
		for (; count--; infop++) {
			high = ((uint8_t *)infop)[1];
			low.u8s[0] = ((uint8_t *)infop)[2];
			low.u8s[1] = ((uint8_t *)infop)[3];
			infop->start_unicode_value = ((uint32_t)high << 16) | (uint32_t)low.u16;
		}
	}
	return ret;
}


int
libparsesfnt_parse_cmap_entry_subtable_14_non_default_uvs(
			const char *data, size_t size,
			struct libparsesfnt_cmap_entry_subtable_14_non_default_uvs *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			  const struct libparsesfnt_cmap_entry *entry,
			  const struct libparsesfnt_cmap_entry_subtable_14 *subtable,
			  const struct libparsesfnt_cmap_entry_subtable_14_entry *subentry)
{
	int ret;
	ret = PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_14_NON_DEFAULT_UVS__,
	            tag->offset, entry->offset, subentry->non_default_uvs_offset, 0, 1, tag);
	if (!ret) {
		if (infop->num_uvs_mappings > subtable->length / 4) {
			errno = EBFONT;
			return -1;
		}
	}
	return ret;
}


int
libparsesfnt_parse_cmap_entry_subtable_14_non_default_uvs_entries(
			const char *data, size_t size,
			struct libparsesfnt_cmap_entry_subtable_14_non_default_uvs_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			  const struct libparsesfnt_cmap_entry *entry,
			  const struct libparsesfnt_cmap_entry_subtable_14_entry *subentry,
			size_t first, size_t count)
{
	int ret;
	uint8_t high;
	union { uint16_t u16; uint8_t u8s[2]; } low;
	ret = PARSE(LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_14_NON_DEFAULT_UVS_ENTRY__,
	            (size_t)tag->offset + (size_t)entry->offset, subentry->non_default_uvs_offset, 4,
	            first, count, tag);
	if (!ret) {
		for (; count--; infop++) {
			high = ((uint8_t *)infop)[1];
			low.u8s[0] = ((uint8_t *)infop)[2];
			low.u8s[1] = ((uint8_t *)infop)[3];
			infop->start_unicode_value = ((uint32_t)high << 16) | (uint32_t)low.u16;
		}
	}
	return ret;
}
