/* See LICENSE file for copyright and license details. */
#include "common.h"


static uint16_t
parse16(const char *data)
{
	uint16_t b1 = (uint16_t)((const uint8_t *)data)[0];
	uint16_t b2 = (uint16_t)((const uint8_t *)data)[1];
	b1 = (uint16_t)(b1 << 8);
	b2 = (uint16_t)(b2 << 0);
	return (uint16_t)(b1 | b2);
}

static uint32_t
parse32(const char *data)
{
	uint32_t b1 = (uint32_t)((const uint8_t *)data)[0];
	uint32_t b2 = (uint32_t)((const uint8_t *)data)[1];
	uint32_t b3 = (uint32_t)((const uint8_t *)data)[2];
	uint32_t b4 = (uint32_t)((const uint8_t *)data)[3];
	b1 = (uint32_t)(b1 << 24);
	b2 = (uint32_t)(b2 << 16);
	b3 = (uint32_t)(b3 << 8);
	b4 = (uint32_t)(b4 << 0);
	return (uint32_t)(b1 | b2 | b3 | b4);
}

static uint64_t
parse64(const char *data)
{
	uint64_t b1 = (uint64_t)((const uint8_t *)data)[0];
	uint64_t b2 = (uint64_t)((const uint8_t *)data)[1];
	uint64_t b3 = (uint64_t)((const uint8_t *)data)[2];
	uint64_t b4 = (uint64_t)((const uint8_t *)data)[3];
	uint64_t b5 = (uint64_t)((const uint8_t *)data)[4];
	uint64_t b6 = (uint64_t)((const uint8_t *)data)[5];
	uint64_t b7 = (uint64_t)((const uint8_t *)data)[6];
	uint64_t b8 = (uint64_t)((const uint8_t *)data)[7];
	b1 = (uint32_t)(b1 << 56);
	b2 = (uint32_t)(b2 << 48);
	b3 = (uint32_t)(b3 << 40);
	b4 = (uint32_t)(b4 << 32);
	b5 = (uint32_t)(b5 << 24);
	b6 = (uint32_t)(b6 << 16);
	b7 = (uint32_t)(b7 << 8);
	b8 = (uint32_t)(b8 << 0);
	return (uint32_t)(b1 | b2 | b3 | b4 | b5 | b6 | b7 | b8);
}


static void
sign8(union {uint8_t u; int8_t s;} *info)
{
	info->s = ((info->u >> 7) ? -(int8_t)(~info->u + 1) : (int8_t)info->u);
}

static void
sign16(union {uint16_t u; int16_t s;} *info)
{
	info->s = ((info->u >> 15) ? -(int16_t)(~info->u + 1) : (int16_t)info->u);
}

static void
sign32(union {uint32_t u; int32_t s;} *info)
{
	info->s = ((info->u >> 31) ? -(int32_t)(~info->u + 1) : (int32_t)info->u);
}

static void
sign64(union {uint64_t u; int64_t s;} *info)
{
	info->s = ((info->u >> 63) ? -(int64_t)(~info->u + 1) : (int64_t)info->u);
}


int
libparsesfnt_parse___(const char *data, size_t size, void *infop, size_t esize,
                      const char *fmt, size_t offset, size_t offset2, size_t offset3,
                      size_t first, size_t count, const struct libparsesfnt_tabdir_entry *tag)
{
	const char *s;
	size_t tag_offset = 0;
	size_t need = 0;
	size_t padding = 0;
	int is_signed = 0;
	char *info = infop;

	if (offset > size || offset2 > size - offset)
		goto ebfont;
	offset += offset2;
	if (offset3 > size - offset)
		goto ebfont;
	offset += offset3;

	if (tag)
		tag_offset = offset - tag->offset;

	for (s = fmt; *s; s++) {
		if (*s == 'p')
			padding += 1;
		else if (*s == '1' || *s == '.')
			need += 1;
		else if (*s == '2')
			need += 2;
		else if (*s == '4')
			need += 4;
		else if (*s == '8')
			need += 8;
	}

	if (count > SIZE_MAX - first ||
	    first > (SIZE_MAX - offset) / need)
		goto efbig;
	offset += first * need;

	if (offset > size || need > size - offset)
		goto ebfont;

	if (count > (SIZE_MAX - offset) / need)
		goto efbig;
	if (offset + count * need > size ||
	    (tag && (tag->length < count * need ||
	             tag->length > size ||
	             tag->offset > size - tag->length ||
	             tag_offset > tag->length ||
	             first + count > (tag->length - tag_offset) / need)))
		goto ebfont;

	data = &data[offset];

	padding = esize - need - padding;
	for (; count--; info = &info[padding]) {
		for (s = fmt; *s; s++) {
			if (*s == 'p') {
				*info++ = 0;
			} else if (*s == '.') {
				*info++ = *data++;
			} else if (*s == '1') {
				*(uint8_t *)info = *(const uint8_t *)data;
				if (is_signed)
					sign8((void *)info);
				data = &data[1];
				info = &info[1];
#ifdef __GNUC__
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wcast-align" /* in practice alignment will be correct */
#endif
			} else if (*s == '2') {
				*(uint16_t *)info = parse16(data);
				if (is_signed)
					sign16((void *)info);
				data = &data[2];
				info = &info[2];
			} else if (*s == '4') {
				*(uint32_t *)info = parse32(data);
				if (is_signed)
					sign32((void *)info);
				data = &data[4];
				info = &info[4];
			} else if (*s == '8') {
				*(uint64_t *)info = parse64(data);
				if (is_signed)
					sign64((void *)info);
				data = &data[8];
				info = &info[8];
#ifdef __GNUC__
# pragma GCC diagnostic pop
#endif
			} else if (*s == '-') {
				is_signed = 1;
			} else if (*s == '+') {
				is_signed = 0;
			} else {
				abort();
			}
		}
	}

	return 0;

efbig:
	errno = EFBIG;
	return -1;

ebfont:
	errno = EBFONT;
	return -1;
}
