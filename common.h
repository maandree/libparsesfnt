/* See LICENSE file for copyright and license details. */
#include "libparsesfnt.h"

#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>


#define ELEMSOF(A) (sizeof(A) / sizeof(*(A)))


int libparsesfnt_parse___(const char *data, size_t size, void *infop, size_t esize,
                          const char *fmt, size_t offset, size_t offset2, size_t offset3,
                          size_t first, size_t count, const struct libparsesfnt_tabdir_entry *tag);

#define PARSE(...) libparsesfnt_parse___(data, size, infop, sizeof(*infop), __VA_ARGS__)
