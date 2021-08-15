/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_hdmx(
			const char *data, size_t size,
			struct libparsesfnt_hdmx *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	int ret;
	ret = PARSE(LIBPARSESFNT_HDMX__, tag->offset, 0, 0, 0, 1, tag);
	if (!ret) {
		if (!infop->record_size ||
		    (size_t)infop->num_records > (size_t)tag->length / (size_t)infop->record_size) {
			errno = EBFONT;
			return -1;
		}
	}
	return ret;
}


int
libparsesfnt_parse_hdmx_entries(
			const char *data, size_t size,
			struct libparsesfnt_hdmx_v0_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_hdmx *hdmx,
			size_t first, size_t count)
{
	size_t off;

	off = tag->offset;
	if (off > size || 8 > size - off || hdmx->record_size < 2)
		goto ebfont;
	off += 8;
	if (first > (size - off) / hdmx->record_size)
		goto ebfont;
	off += hdmx->record_size * first;
	if (count > (size - off) / hdmx->record_size)
		goto ebfont;

	data = &data[off];
	for (; count--; infop++) {
		infop->pixel_size = ((const uint8_t *)data)[0];
		infop->maximum_width = ((const uint8_t *)data)[1];
		data = &data[2];
	}

	return 0;

ebfont:
	errno = EBFONT;
	return -1;
}


int
libparsesfnt_parse_hdmx_v0_subentry(
	const char *data, size_t size,
	uint8_t *widthp,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_hdmx *hdmx, size_t record,
	size_t first, size_t count)
{
	size_t off;

	off = tag->offset;
	if (off > size || 10 > size - off)
		goto ebfont;
	off += 10;
	if (record > (size - off) / hdmx->record_size)
		goto ebfont;
	off += hdmx->record_size * record;
	if (first > size - off)
		goto ebfont;
	off += first;
	if (count > size - off)
		goto ebfont;

	if (2 > hdmx->record_size || first + count > hdmx->record_size - 2)
		goto ebfont;

	memcpy(widthp, &data[off], count);
	return 0;

ebfont:
	errno = EBFONT;
	return -1;
}
