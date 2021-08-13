/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_avar(
			const char *data, size_t size,
			struct libparsesfnt_avar *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	return PARSE(LIBPARSESFNT_AVAR__, tag->offset, 0, 0, 0, 1, tag);
}


static uint16_t
avar_parse16(const char *data)
{
	uint16_t b1 = (uint16_t)((const uint8_t *)data)[0];
	uint16_t b2 = (uint16_t)((const uint8_t *)data)[1];
	b1 = (uint16_t)(b1 << 8);
	b2 = (uint16_t)(b2 << 0);
	return (uint16_t)(b1 | b2);
}

int
libparsesfnt_parse_avar_entries(
			const char *data, size_t size,
			struct libparsesfnt_avar_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t *offsetp, size_t count)
{
	size_t offset = offsetp ? *offsetp : 0;
	if (offset < 8) {
		if (tag->length < 8) {
			errno = EBFONT;
			return -1;
		}
		offset = 8;
	}
	if ((size_t)tag->length < offset || size < (size_t)tag->length - offset) {
		errno = EBFONT;
		return -1;
	}
	while (count--) {
		if (tag->length - offset < 2) {
			errno = EBFONT;
			return -1;
		}
		infop->pair_count = avar_parse16(&data[offset]);
		offset += 2;
		infop->libparsesfnt_subentry_location = offset;
		memset(infop->__padding1, 0, sizeof(infop->__padding1));
		if ((size_t)infop->pair_count > ((size_t)tag->length - offset) / 4) {
			errno = EBFONT;
			return -1;
		}
		infop++;
	}
	if (offsetp)
		*offsetp = offset;
	return 0;
}


int
libparsesfnt_parse_avar_subentries(
			const char *data, size_t size,
			struct libparsesfnt_avar_subentry *infop,
			const struct libparsesfnt_avar_entry *entry,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_AVAR_SUBENTRY__, entry->libparsesfnt_subentry_location, 0, 0, first, count, NULL);
}
