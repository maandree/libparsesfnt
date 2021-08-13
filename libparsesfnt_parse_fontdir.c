/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_fontdir(
			const char *data, size_t size,
			struct libparsesfnt_fontdir *infop)
{
	return PARSE(LIBPARSESFNT_FONTDIR__, 0, 0, 0, 0, 1, NULL);
}
