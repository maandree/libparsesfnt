/* See LICENSE file for copyright and license details. */
#include "common.h"


int
libparsesfnt_parse_trak(
			const char *data, size_t size,
			struct libparsesfnt_trak *infop,
			const struct libparsesfnt_tabdir_entry *tag)
{
	return PARSE(LIBPARSESFNT_TRAK__, tag->offset, 0, 0, 0, 1, tag);
}


int
libparsesfnt_parse_trak_horiz(
			const char *data, size_t size,
			struct libparsesfnt_trak_data *infop,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_trak *trak)
{
	return PARSE(LIBPARSESFNT_TRAK_DATA__, tag->offset, trak->horiz_offset, 0, 0, 1, NULL);
}


int
libparsesfnt_parse_trak_vert(
			const char *data, size_t size,
			struct libparsesfnt_trak_data *infop,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_trak *trak)
{
	return PARSE(LIBPARSESFNT_TRAK_DATA__, tag->offset, trak->vert_offset, 0, 0, 1, NULL);
}


int
libparsesfnt_parse_trak_horiz_track_entries(
			const char *data, size_t size,
			struct libparsesfnt_trak_track_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_trak *trak,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_TRAK_TRACK_ENTRY__, tag->offset, trak->horiz_offset, 8, first, count, NULL);
}


int
libparsesfnt_parse_trak_vert_track_entries(
			const char *data, size_t size,
			struct libparsesfnt_trak_track_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_trak *trak,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_TRAK_TRACK_ENTRY__, tag->offset, trak->vert_offset, 8, first, count, NULL);
}


int
libparsesfnt_parse_trak_size_entries(
			const char *data, size_t size,
			struct libparsesfnt_trak_size_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_trak_data *trak_data,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_TRAK_SIZE_ENTRY__, tag->offset, trak_data->size_table_offset, 0, first, count, NULL);
}


int
libparsesfnt_parse_trak_track_size_entries(
			const char *data, size_t size,
			struct libparsesfnt_trak_size_entry *infop,
			const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_trak_track_entry *track,
			size_t first, size_t count)
{
	return PARSE(LIBPARSESFNT_TRAK_SIZE_ENTRY__, tag->offset, track->offset, 0, first, count, NULL);
}
