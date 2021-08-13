/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_maxp(
			const char *data, size_t size,
			struct libparsesfnt_maxp *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	uint8_t major_high, major_low;
	const char *fmt;

	major_high = *(const uint8_t *)&data[tag->offset + 0];
	major_low  = *(const uint8_t *)&data[tag->offset + 1];

	if (major_high == 0 && major_low == 0) {
		if (*(const uint8_t *)&data[tag->offset + 2] < 0x50U)
			goto bfont;
		fmt = LIBPARSESFNT_MAXP__""LIBPARSESFNT_MAXP_0_5__;

	} else if (major_high && major_low == 1) {
		fmt = LIBPARSESFNT_MAXP__""LIBPARSESFNT_MAXP_1_0__;

	} else {
		goto bfont;
	}

	return PARSE(fmt, tag->offset, 0, 0, 0, 1, tag);

bfont:
	errno = EBFONT;
	return -1;
}
