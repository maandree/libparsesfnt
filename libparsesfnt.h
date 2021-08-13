/* See LICENSE file for copyright and license details. */
#ifndef LIBPARSESFNT_H
#define LIBPARSESFNT_H

#include <stddef.h>
#include <stdint.h>


#define LIBPARSESFNT_8C__ "1111""1111"
#define LIBPARSESFNT_16C__ LIBPARSESFNT_8C__""LIBPARSESFNT_8C__
#define LIBPARSESFNT_32C__ LIBPARSESFNT_16C__""LIBPARSESFNT_16C__
#define LIBPARSESFNT_64C__ LIBPARSESFNT_32C__""LIBPARSESFNT_32C__
#define LIBPARSESFNT_128C__ LIBPARSESFNT_64C__""LIBPARSESFNT_64C__
#define LIBPARSESFNT_255C__ LIBPARSESFNT_128C__""LIBPARSESFNT_64C__""LIBPARSESFNT_32C__""\
                            LIBPARSESFNT_32C__""LIBPARSESFNT_16C__""LIBPARSESFNT_16C__""\
                            LIBPARSESFNT_8C__"1111""11""1"


#define LIBPARSESFNT_UNIX_EPOCH          ((time_t)-2082844800L) /* 1904-01-01 00:00:00 */
#define LIBPARSESFNT_TO_UNIX_EPOCH(TIME) ((time_t)(TIME) + LIBPARSESFNT_UNIX_EPOCH)



/* === font directory === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6.html */

struct libparsesfnt_fontdir {
	char scaler_type[4];
	uint16_t num_tables;
	uint16_t search_range;   /* use to determine how to bsearch(3) the table directory */
	uint16_t entry_selector; /* use to determine whether to bsearch(3) the table directory */
	uint16_t range_shift;    /* use to determine how to bsearch(3) the table directory */
};
#define LIBPARSESFNT_FONTDIR__ "11112222"

int libparsesfnt_parse_fontdir(
	const char *data, size_t size,
	struct libparsesfnt_fontdir *infop);



/* === table directory === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6.html */

struct libparsesfnt_tabdir_entry {
	char tab[4];
	uint32_t checksum;
	uint32_t offset;
	uint32_t length;
};
#define LIBPARSESFNT_TABDIR_ENTRY__ "1111444"

int libparsesfnt_parse_tabdir(
	const char *data, size_t size,
	struct libparsesfnt_tabdir_entry *infop,
	size_t first, size_t count);



/* === 'head' (font header) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6head.html */

struct libparsesfnt_head {
	uint32_t version;
	uint32_t font_revision;
	uint32_t checksum_adjustment;
	uint32_t magic_number;
#define LIBPARSESFNT_HEAD_MAGIC_NUMBER_EXPECTED UINT32_C(0x5f0f3cf5)
	uint16_t flags;
	uint16_t units_per_em;
#define LIBPARSESFNT_HEAD_UNITS_PER_EM_MIN 64
#define LIBPARSESFNT_HEAD_UNITS_PER_EM_MAX 16384
	uint32_t __padding1;
	uint64_t created;
	uint64_t modified;
	int16_t x_min;
	int16_t y_min;
	int16_t x_max;
	int16_t y_max;
	uint16_t style_flags;
	uint16_t lowest_ppem; /* smallest readable size in pixels (per em) */
	int16_t font_direction_hint;
	int16_t loca_table_format; /* 0 = "short" offsets, 1 = "long" offsets */
	int16_t glyph_data_format;
	uint16_t __padding2[3];
};
#define LIBPARSESFNT_HEAD__ "444422pppp88-2222+22-222pppppp"

int libparsesfnt_parse_head(
	const char *data, size_t size,
	struct libparsesfnt_head *infop,
	const struct libparsesfnt_tabdir_entry *tag);



/* === 'bhed' (bitmap font header) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6bhed.html */

struct libparsesfnt_bhed {
	uint32_t version;
	uint32_t font_revision;
	uint32_t checksum_adjustment;
	uint32_t magic_number;
#define LIBPARSESFNT_BHED_MAGIC_NUMBER_EXPECTED HEAD_MAGIC_NUMBER_EXPECTED
	uint16_t flags;
	uint16_t units_per_em;
#define LIBPARSESFNT_BHED_UNITS_PER_EM_MIN LIBPARSESFNT_HEAD_UNITS_PER_EM_MIN
#define LIBPARSESFNT_BHED_UNITS_PER_EM_MAX LIBPARSESFNT_HEAD_UNITS_PER_EM_MAX
	uint32_t __padding1;
	uint64_t created;
	uint64_t modified;
	int16_t x_min;
	int16_t y_min;
	int16_t x_max;
	int16_t y_max;
	uint16_t style_flags;
	uint16_t lowest_ppem; /* smallest readable size in pixels (per em) */
	int16_t font_direction_hint;
	int16_t bloc_table_format; /* 0 = "short" offsets, 1 = "long" offsets */
	int16_t glyph_data_format;
	uint16_t __padding2[3];
};
#define LIBPARSESFNT_BHED__ "444422pppp88-2222+22-222pppppp"

int libparsesfnt_parse_bhed(
	const char *data, size_t size,
	struct libparsesfnt_bhed *infop,
	const struct libparsesfnt_tabdir_entry *tag);



/* === 'hhea' (horizontal header) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6hhea.html */

struct libparsesfnt_hhea {
	uint32_t version;
	int16_t max_ascent;
	int16_t max_descent;
	int16_t line_gap;
	uint16_t max_advance;
	int16_t min_left_side_bearing;
	int16_t max_left_side_bearing;
	int16_t x_max_extent;
	int16_t caret_slope_rise;
	int16_t caret_slope_run;
	int16_t caret_offset;
	uint8_t ___reserved1[8];
	int16_t metric_data_format;
	uint16_t num_advances_in_hmtx_table;
};
#define LIBPARSESFNT_HHEA__ "4-222+2-222222........2+2"

int libparsesfnt_parse_hhea(
	const char *data, size_t size,
	struct libparsesfnt_hhea *infop,
	const struct libparsesfnt_tabdir_entry *tag);



/* === 'hmtx' (horizontal metrics) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6hmtx.html */

struct libparsesfnt_hmtx_entry {
	uint16_t advance;
	int16_t left_side_bearing;
};
#define LIBPARSESFNT_HMTX_ENTRY__ "2-2"

struct libparsesfnt_hmtx_lsb_subtable_entry {
	int16_t left_side_bearing2;
};
#define LIBPARSESFNT_HMTX_LSB_SUBTABLE_ENTRY__ "-2"

int libparsesfnt_parse_hmtx(
	const char *data, size_t size,
	struct libparsesfnt_hmtx_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t first, size_t count);

int libparsesfnt_get_hmtx_lsb_subtable_length(
	size_t *lengthp,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_hhea *hhea);

int libparsesfnt_parse_hmtx_lsb_subtable(
	const char *data, size_t size,
	struct libparsesfnt_hmtx_lsb_subtable_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_hhea *hhea,
	size_t first, size_t count);



/* === 'vhea' (vertical header) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6vhea.html */

struct libparsesfnt_vhea {
	int32_t version;
	int16_t max_ascent;
	int16_t max_descent;
	int16_t line_gap;
	uint16_t max_advance;
	int16_t min_top_side_bearing;
	int16_t min_bottom_side_bearing;
	int16_t y_max_extent;
	int16_t caret_slope_rise;
	int16_t caret_slope_run;
	int16_t caret_offset;
	uint8_t ___reserved1[8];
	int16_t metric_data_format;
	uint16_t num_advances_in_vmtx_table;
};
#define LIBPARSESFNT_VHEA__ "4-222+2-222222........2+2"

int libparsesfnt_parse_vhea(
	const char *data, size_t size,
	struct libparsesfnt_vhea *infop,
	const struct libparsesfnt_tabdir_entry *tag);



/* === 'vmtx' (vertical metrics) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6vmtx.html */

struct libparsesfnt_vmtx_entry {
	uint16_t advance;
	int16_t top_side_bearing;
};
#define LIBPARSESFNT_VMTX_ENTRY__ "2-2"

struct libparsesfnt_vmtx_tsb_subtable_entry {
	int16_t top_side_bearing2;
};
#define LIBPARSESFNT_VMTX_TSB_SUBTABLE_ENTRY__ "-2"

int libparsesfnt_parse_vmtx(
	const char *data, size_t size,
	struct libparsesfnt_vmtx_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t first, size_t count);

int libparsesfnt_get_vmtx_tsb_subtable_length(
	size_t *lengthp,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_vhea *vhea);

int libparsesfnt_parse_vmtx_tsb_subtable(
	const char *data, size_t size,
	struct libparsesfnt_vmtx_tsb_subtable_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_vhea *vhea,
	size_t first, size_t count);



/* === 'maxp' (maximum profile) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6maxp.html */

struct libparsesfnt_maxp_0_5 {
	uint16_t num_glyphs;
};
#define LIBPARSESFNT_MAXP_0_5__ "2"

struct libparsesfnt_maxp_1_0 {
	uint16_t num_glyphs;
	uint16_t max_points_noncompound;
	uint16_t max_contours_noncompound;
	uint16_t max_points_compound;
	uint16_t max_contours_compound;
	uint16_t max_zones; /* should be 2 */
	uint16_t max_twilight_points;
	uint16_t max_storage_areas;
	uint16_t max_fdefs;
	uint16_t max_odefs;
	uint16_t max_stack_depth;
	uint16_t max_size_of_instructions;
	uint16_t max_top_level_glyphs;
	uint16_t max_recursion;
};
#define LIBPARSESFNT_MAXP_1_0__ "22222222222222"

struct libparsesfnt_maxp {
	uint32_t version;
	union {
		struct libparsesfnt_maxp_0_5 v0_5;
		struct libparsesfnt_maxp_1_0 v1_0; /* extends .v0_5 */
	} v;
};
#define LIBPARSESFNT_MAXP__ "4"

int libparsesfnt_parse_maxp(
	const char *data, size_t size,
	struct libparsesfnt_maxp *infop,
	const struct libparsesfnt_tabdir_entry *tag);



/* === 'loca' (glyph locations) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6loca.html */

/* There is one extra entry at the end, so that (entry[i + 1].offset - entry[i].offset)
 * calculates the size of entry i. */

struct libparsesfnt_loca_short_entry {
	uint16_t offset;
};
#define LIBPARSESFNT_LOCA_SHORT_ENTRY__ "2"

struct libparsesfnt_loca_long_entry {
	uint32_t offset;
};
#define LIBPARSESFNT_LOCA_LONG_ENTRY__ "4"

int libparsesfnt_parse_loca_short(
	const char *data, size_t size,
	struct libparsesfnt_loca_short_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t first, size_t count);

int libparsesfnt_parse_loca_long(
	const char *data, size_t size,
	struct libparsesfnt_loca_long_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t first, size_t count);



/* === 'name' (name) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6name.html */
/* TODO platform ID, platform-specific ID, language ID */

struct libparsesfnt_name {
	uint16_t format;
	uint16_t count;
	uint16_t string_offset;
};
#define LIBPARSESFNT_NAME__ "222"

struct libparsesfnt_name_entry {
	uint16_t platform_id;
	uint16_t platform_specific_id;
	uint16_t language_id;
	uint16_t name_id;
	uint16_t name_length;
	uint16_t name_offset;
};
#define LIBPARSESFNT_NAME_ENTRY__ "222222"

enum libparsesfnt_name_id {
	LIBPARSESFNT_NAME_ID_COPYRIGHT_NOTICE = 0,
	LIBPARSESFNT_NAME_ID_FONT_FAMILY = 1,
	LIBPARSESFNT_NAME_ID_FONT_SUBFAMILY = 2,
	LIBPARSESFNT_NAME_ID_UNIQUE_SUBFAMILY_IDENTIFICATION = 3,
	LIBPARSESFNT_NAME_ID_FULL_NAME_OF_THE_FONT = 4,
	LIBPARSESFNT_NAME_ID_VERSION_OF_THE_NAME_TABLE = 5,
	LIBPARSESFNT_NAME_ID_POSTSCRIPT_NAME_OF_THE_FONT = 6,
	LIBPARSESFNT_NAME_ID_TRADEMARK_NOTICE = 7,
	LIBPARSESFNT_NAME_ID_MANUFACTURER = 8,
	LIBPARSESFNT_NAME_ID_DESIGNER = 9,
	LIBPARSESFNT_NAME_ID_DESCRIPTION = 10,
	LIBPARSESFNT_NAME_ID_VENDOR_URL = 11,
	LIBPARSESFNT_NAME_ID_DESIGNER_URL = 12,
	LIBPARSESFNT_NAME_ID_LICENSE_DESCRIPTION = 13,
	LIBPARSESFNT_NAME_ID_LICENSE_INFORMATION_URL = 14,
	/* 15 is reserved */
	LIBPARSESFNT_NAME_ID_PREFERRED_FAMILY = 16,
	LIBPARSESFNT_NAME_ID_PREFERRED_SUBFAMILY = 17,
	LIBPARSESFNT_NAME_ID_COMPATIBLE_FULL = 18,
	LIBPARSESFNT_NAME_ID_SAMPLE_TEXT = 19
	/* 20–22 are defined by OpenType */
	/* 23–255 are reserved for future expansions*/
	/* 256–32767 are for font-specific names */
};

int libparsesfnt_parse_name(
	const char *data, size_t size,
	struct libparsesfnt_name *infop,
	const struct libparsesfnt_tabdir_entry *tag);

int libparsesfnt_parse_name_entries(
	const char *data, size_t size,
	struct libparsesfnt_name_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t first, size_t count);



/* === 'fmtx' (font metrics) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6fmtx.html */

struct libparsesfnt_fmtx {
	uint32_t version;
	uint32_t glyph_index;
	uint8_t horizontal_before;
	uint8_t horizontal_after;
	uint8_t horizontal_caret_head;
	uint8_t horizontal_caret_base;
	uint8_t vertical_before;
	uint8_t vertical_after;
	uint8_t vertical_caret_head;
	uint8_t vertical_caret_base;
};
#define LIBPARSESFNT_FMTX__ "4411111111"

int libparsesfnt_parse_fmtx(
	const char *data, size_t size,
	struct libparsesfnt_fmtx *infop,
	const struct libparsesfnt_tabdir_entry *tag);



/* === 'ltag' (language tag) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6ltag.html */

struct libparsesfnt_ltag {
	uint32_t version;
	uint32_t flags; /* unused, should be 0 */
	uint32_t num_tags;
};
#define LIBPARSESFNT_LTAG__ "444"

struct libparsesfnt_ltag_entry {
	uint16_t offset; /* relative to the beginning of the 'ltag' table */
	uint16_t length;
};
#define LIBPARSESFNT_LTAG_ENTRY__ "22"

int libparsesfnt_parse_ltag(
	const char *data, size_t size,
	struct libparsesfnt_ltag *infop,
	const struct libparsesfnt_tabdir_entry *tag);

int libparsesfnt_parse_ltag_entries(
	const char *data, size_t size,
	struct libparsesfnt_ltag_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t first, size_t count);

int libparsesfnt_get_ltag_offset(
	size_t size,
	size_t *offsetp,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_ltag_entry *entry);



/* === 'xref' (cross-reference) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6xref.html */

struct libparsesfnt_xref {
	uint32_t version;
	uint32_t flags; /* unused, should be 0 */
	uint32_t num_entries;
	uint32_t string_offset; /* position of the string table: relative to the beginning of this table */
};
#define LIBPARSESFNT_XREF__ "4444"

struct libparsesfnt_xref_entry {
	char table_tab[4];
	int16_t chain_index;
	int16_t subtable_index;
	int16_t table_type;
	uint16_t string_offset; /* relative to the beginning of the string table */
	uint16_t string_length;
};
#define LIBPARSESFNT_XREF_ENTRY__ "1111-2222+22"

enum libparsesfnt_xref_table_type {
	LIBPARSESFNT_XREF_CLASS_NAME_TABLE = 0,
	LIBPARSESFNT_XREF_STATE_NAME_TABLE = 1,
	LIBPARSESFNT_XREF_ENTRY_TRANSITION_NAME_TABLE = 2,
	LIBPARSESFNT_XREF_ACTION_NAME_TABLE = 3,
	LIBPARSESFNT_XREF_COLUMN_CLASS_NAME_TABLE = 4,
	LIBPARSESFNT_XREF_ROW_CLASS_NAME_TABLE = 5
};

int libparsesfnt_parse_xref(
	const char *data, size_t size,
	struct libparsesfnt_xref *infop,
	const struct libparsesfnt_tabdir_entry *tag);

int libparsesfnt_parse_xref_entries(
	const char *data, size_t size,
	struct libparsesfnt_xref_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t first, size_t count);

int libparsesfnt_get_xref_offset(
	size_t size,
	size_t *offsetp,
	const struct libparsesfnt_tabdir_entry *tag,
	  const struct libparsesfnt_xref *xref,
	  const struct libparsesfnt_xref_entry *entry);



/* === 'trak' (tracking) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6trak.html */

struct libparsesfnt_trak {
	uint32_t version;
	uint16_t format;
	uint16_t horiz_offset; /* relative to the beginning of this table, 0 if missing */
	uint16_t vert_offset; /* relative to the beginning of this table, 0 if missing */
	uint8_t __reserved1[2];
};
#define LIBPARSESFNT_TRAK__ "4222.."

struct libparsesfnt_trak_data {
	uint16_t n_tracks;
	uint16_t n_sizes;
	uint32_t size_table_offset; /* position of the size subtable: relative to the beginning of the 'trak' tabletable */
};
#define LIBPARSESFNT_TRAK_DATA__ "224"

struct libparsesfnt_trak_track_entry {
	int32_t track;
	uint16_t name_index; /* should be > 255 */
	uint16_t offset; /* position of this track's per-size tracking values: relative to the beginning of the 'trak' table */
};
#define LIBPARSESFNT_TRAK_TRACK_ENTRY__ "-4+22"

struct libparsesfnt_trak_size_entry {
	int32_t size;
};
#define LIBPARSESFNT_TRAK_SIZE_ENTRY__ "-4"

int libparsesfnt_parse_trak(
	const char *data, size_t size,
	struct libparsesfnt_trak *infop,
	const struct libparsesfnt_tabdir_entry *tag);

int libparsesfnt_parse_trak_horiz(
	const char *data, size_t size,
	struct libparsesfnt_trak_data *infop,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_trak *trak);

int libparsesfnt_parse_trak_vert(
	const char *data, size_t size,
	struct libparsesfnt_trak_data *infop,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_trak *trak);

int libparsesfnt_parse_trak_horiz_track_entries(
	const char *data, size_t size,
	struct libparsesfnt_trak_track_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_trak *trak,
	size_t first, size_t count);

int libparsesfnt_parse_trak_vert_track_entries(
	const char *data, size_t size,
	struct libparsesfnt_trak_track_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_trak *trak,
	size_t first, size_t count);

int libparsesfnt_parse_trak_size_entries(
	const char *data, size_t size,
	struct libparsesfnt_trak_size_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_trak_data *trak_data,
	size_t first, size_t count);

int libparsesfnt_parse_trak_track_size_entries(
	const char *data, size_t size,
	struct libparsesfnt_trak_size_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_trak_track_entry *track,
	size_t first, size_t count);



/* === 'cvt ' (control value) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6cvt.html */

struct libparsesfnt_cvt_entry {
	int16_t control_value;
};

/* TODO it is documented that entry count is table length divided by 4,
 *      however the element type (FWord) is 2 bytes wide */



/* === 'gcid' (glyph to CID mapping) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6gcid.html */

struct libparsesfnt_gcid {
	uint16_t version;
	uint16_t format;
	uint32_t size;
	uint16_t registry;
	char registry_name[64];
	uint16_t order;
	char order_name[64];
	uint16_t supplement_version;
	uint16_t count;
};
#define LIBPARSESFNT_GCID__ "2242"LIBPARSESFNT_64C__"2"LIBPARSESFNT_64C__"22"

struct libparsesfnt_gcid_entry {
	uint16_t cid;
#define LIBPARSESFNT_GCID_NO_CID UINT16_C(0xFFFF)
};
#define LIBPARSESFNT_GCID_ENTRY__ "2"

int libparsesfnt_parse_gcid(
	const char *data, size_t size,
	struct libparsesfnt_gcid *infop,
	const struct libparsesfnt_tabdir_entry *tag);

int libparsesfnt_parse_gcid_entries(
	const char *data, size_t size,
	struct libparsesfnt_gcid_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t first, size_t count);



/* === 'fpgm' (font program) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6fpgm.html */

int libparsesfnt_parse_fpgm(
	const char *data, size_t size,
	uint8_t *programp,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t first, size_t count);



/* === 'prep' (control value program) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6prep.html */

#define libparsesfnt_parse_prep libparsesfnt_parse_fpgm



/* === 'fdsc' (font descriptors) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6fdsc.html */

struct libparsesfnt_fdsc {
	uint32_t version;
	uint32_t descriptor_count;
};
#define LIBPARSESFNT_FDSC__ "44"

struct libparsesfnt_fdsc_entry {
	char tag[4];
	int32_t value;
};
#define LIBPARSESFNT_FDSC_ENTRY__ "1111-4"

enum libparsesfnt_fdsc_nalf {
	LIBPARSESFNT_FDSC_NALF_ALPHABETIC = 0,
	LIBPARSESFNT_FDSC_NALF_DINGBATS = 1,
	LIBPARSESFNT_FDSC_NALF_PI_CHARACTERS = 2,
	LIBPARSESFNT_FDSC_NALF_FLEURONS = 3,
	LIBPARSESFNT_FDSC_NALF_DECORATIVE_BORDERS = 4,
	LIBPARSESFNT_FDSC_NALF_INTERNATIONAL_SYMBOLS = 5,
	LIBPARSESFNT_FDSC_NALF_MATH_SYMBOLS = 6
};

int libparsesfnt_parse_fdsc(
	const char *data, size_t size,
	struct libparsesfnt_fdsc *infop,
	const struct libparsesfnt_tabdir_entry *tag);

int libparsesfnt_parse_fdsc_entries(
	const char *data, size_t size,
	struct libparsesfnt_fdsc_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t first, size_t count);



/* === 'gasp' (grid-fitting and scan-conversion procedure) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6gasp.html */

struct libparsesfnt_gasp {
	uint16_t version;
	uint16_t num_ranges;
};
#define LIBPARSESFNT_GASP__ "22"

struct libparsesfnt_gasp_entry {
	uint16_t range_max_ppem;
	uint16_t range_gasp_behaviour;
};
#define LIBPARSESFNT_GASP_ENTRY__ "22"

enum libparsesfnt_gasp_behaviour {
	LIBPARSESFNT_GASP_BEHAVIOUR_GRID_FIT = 0x0001,
	LIBPARSESFNT_GASP_BEHAVIOUR_DO_GREY = 0x0002
};

int libparsesfnt_parse_gasp(
	const char *data, size_t size,
	struct libparsesfnt_gasp *infop,
	const struct libparsesfnt_tabdir_entry *tag);

int libparsesfnt_parse_gasp_entries(
	const char *data, size_t size,
	struct libparsesfnt_gasp_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t first, size_t count);



/* === 'avar' (axis variation) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6avar.html */

struct libparsesfnt_avar {
	uint32_t name;
	uint32_t axis_count;
};
#define LIBPARSESFNT_AVAR__ "44"

struct libparsesfnt_avar_entry {
	uint16_t pair_count;
	char __padding1[sizeof(size_t) - sizeof(uint16_t)]; /* using sizeof for simplicity (may have same alignment) */
	size_t libparsesfnt_subentry_location;
};
#define LIBPARSESFNT_AVAR_ENTRY__ "2"

struct libparsesfnt_avar_subentry {
	int16_t from_coord;
	int16_t to_coord;
};
#define LIBPARSESFNT_AVAR_SUBENTRY__ "22"

int libparsesfnt_parse_avar(
	const char *data, size_t size,
	struct libparsesfnt_avar *infop,
	const struct libparsesfnt_tabdir_entry *tag);

int libparsesfnt_parse_avar_entries(
	const char *data, size_t size,
	struct libparsesfnt_avar_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t *offsetp /* start at 0 */, size_t count);

int libparsesfnt_parse_avar_subentries(
	const char *data, size_t size,
	struct libparsesfnt_avar_subentry *infop,
	const struct libparsesfnt_avar_entry *entry,
	size_t first, size_t count);



/* === 'meta' (metadata) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6meta.html */

struct libparsesfnt_meta {
	uint32_t version;
	uint32_t flags;
	uint32_t data_offset; /* relative to the beginning of this table */
	uint32_t num_data_maps;
};
#define LIBPARSESFNT_META__ "4444"

struct libparsesfnt_meta_entry {
	char tag[4];
	uint32_t data_offset; /* relative to the beginning of the 'meta' table */
	uint32_t data_length;
};
#define LIBPARSESFNT_META_ENTRY__ "111144"

int libparsesfnt_parse_meta(
	const char *data, size_t size,
	struct libparsesfnt_meta *infop,
	const struct libparsesfnt_tabdir_entry *tag);

int libparsesfnt_parse_meta_entries(
	const char *data, size_t size,
	struct libparsesfnt_meta_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_meta *meta,
	size_t first, size_t count);


#endif
