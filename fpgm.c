/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_fpgm(
			const char *data, size_t size,
			uint8_t *programp,
			const struct libparsesfnt_tabdir_entry *tag,
			size_t first, size_t count)
{
	if (count > SIZE_MAX - first) {
		errno = EFBIG;
		return -1;
	}
	if (tag->offset < size || first + count > size - tag->offset) {
		errno = EBFONT;
		return -1;
	}
	memcpy(programp, &data[tag->offset + first], count - first);
	return 0;
}
