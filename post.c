/* See LICENSE file for copyright and license details. */
#include "common.h"


static uint16_t
post_parse16(const char *data)
{
	uint16_t b1 = (uint16_t)((const uint8_t *)data)[0];
	uint16_t b2 = (uint16_t)((const uint8_t *)data)[1];
	b1 = (uint16_t)(b1 << 8);
	b2 = (uint16_t)(b2 << 0);
	return (uint16_t)(b1 | b2);
}

static void
post_sign16(union {uint16_t u; int16_t s;} *info)
{
	info->s = ((info->u >> 15) ? -(int16_t)(~info->u + 1) : (int16_t)info->u);
}


int
libparsesfnt_parse_post(
			const char *data, size_t size,
			struct libparsesfnt_post *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	int ret;
	ret = PARSE(LIBPARSESFNT_POST__, tag->offset, 0, 0, 0, 1, tag);
	if (!ret) {
		if (infop->format >> 16 == 2) {
			if (2 > tag->length - tag->offset)
				goto ebfont;
			infop->subtable.v2.number_of_glyphs = post_parse16(&data[tag->offset + 2]);
		}
	}
	return ret;

ebfont:
	errno = EBFONT;
	return -1;
}


static int
post_indices(
			const char *data, size_t size,
			uint16_t *indexp,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count,
			size_t offset)
{
	if (offset > tag->length || first > (tag->length - offset) / 2)
		goto ebfont;
	offset += first * 2;
	if (count > (tag->length - offset) / 2)
		goto ebfont;
	if (tag->offset > size || offset > size - tag->offset)
		goto ebfont;
	offset += tag->offset;

	for (; count--; indexp++, offset += 2)
		*indexp = post_parse16(&data[offset]);

	return 0;

ebfont:
	errno = EBFONT;
	return -1;
}


int
libparsesfnt_parse_post_format_2_0_indices(
			const char *data, size_t size,
			uint16_t *indexp,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count)
{
	return post_indices(data, size, indexp, tag, first, count, 34);
}


int
libparsesfnt_parse_post_format_2_0_name(
	const char *data, size_t size,
	char namep[256],
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_post *post,
	size_t *offsetp /* start at 0 */)
{
	size_t len;

	if (!*offsetp) {
		if ((size_t)post->subtable.v2.number_of_glyphs > ((size_t)tag->length - 34) / 2)
			goto ebfont;
		*offsetp = 34 + (size_t)post->subtable.v2.number_of_glyphs / 2;
		if ((size_t)tag->length > size - (size_t)tag->offset)
			goto ebfont;
	}

	if (*offsetp >= (size_t)tag->length)
		goto ebfont;
	len = (size_t)*(const uint8_t *)&data[*offsetp];
	*offsetp += 1;

	if (len > (size_t)tag->length - *offsetp)
		goto ebfont;
	memcpy(namep, &data[*offsetp], len);
	namep[len] = 0;
	*offsetp += len;

	return 0;

ebfont:
	errno = EBFONT;
	return -1;
}


int
libparsesfnt_parse_post_format_2_5_offsets(
			const char *data, size_t size,
			int16_t *offsetp,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count)
{
	if (post_indices(data, size, (uint16_t *)offsetp, tag, first, count, 34))
		return -1;
	for (; count--; offsetp++)
		post_sign16((void *)offsetp);
	return 0;
}


int
libparsesfnt_parse_post_format_4_0_indices(
			const char *data, size_t size,
			uint16_t *indexp,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count)
{
	return post_indices(data, size, indexp, tag, first, count, 32);
}
