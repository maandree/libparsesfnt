/* See LICENSE file for copyright and license details. */
#ifndef LIBPARSESFNT_H
#define LIBPARSESFNT_H

#include <stddef.h>
#include <stdint.h>


#define LIBPARSESFNT_UNIX_EPOCH          ((time_t)-2082844800L) /* 1904-01-01 00:00:00 */
#define LIBPARSESFNT_TO_UNIX_EPOCH(TIME) ((time_t)(TIME) + LIBPARSESFNT_UNIX_EPOCH)



enum libparsesfnt_platform_id {
	LIBPARSESFNT_PLATFORM_ID_UNICODE = 0,
	LIBPARSESFNT_PLATFORM_ID_MACHINTOSH = 1,
	LIBPARSESFNT_PLATFORM_ID_WINDOWS = 3
};

enum libparsesfnt_unicode_encoding_id {
	LIBPARSESFNT_UNICODE_ENCODING_ID_VERSION_1_0 = 0,
	LIBPARSESFNT_UNICODE_ENCODING_ID_VERSION_1_1 = 1,
	LIBPARSESFNT_UNICODE_ENCODING_ID_ISO_10646_1993 = 2,
	LIBPARSESFNT_UNICODE_ENCODING_ID_VERSION_2_0_BMP_ONLY = 3,
	LIBPARSESFNT_UNICODE_ENCODING_ID_VERSION_2_0 = 4,
	/* the following are using in 'cmap' but not 'name' */
	LIBPARSESFNT_UNICODE_ENCODING_ID_UNICODE_VARIATION_SEQUENCES = 5,
	LIBPARSESFNT_UNICODE_ENCODING_ID_LAST_RESORT = 6
};

enum libparsesfnt_macintosh_encoding_id {
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_ROMAN = 0,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_JAPANESE = 1,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_TRADITIONAL_CHINESE = 2,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_KOREAN = 3,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_ARABIC = 4,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_HEBREW = 5,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_GREEK = 6,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_RUSSIAN = 7,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_RSYMBOL = 8,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_DEVANAGARI = 9,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_GURMUKHI = 10,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_GUJARATI = 11,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_ORIYA = 12,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_BENGALI = 13,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_TAMIL = 14,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_TELUGU = 15,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_KANNADA = 16,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_MALAYALAM = 17,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_SINHALESE = 18,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_BURMESE = 19,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_KHMER = 20,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_THAI = 21,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_LAOTIAN = 22,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_GEORGIAN = 23,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_ARMENIAN = 24,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_SIMPLIFIED_CHINESE = 25,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_TIBETAN = 26,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_MONGOLIAN = 27,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_GEEZ = 28,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_SLAVIC = 29,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_VIETNAMESE = 30,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_SINDHI = 31,
	LIBPARSESFNT_MACINTOSH_ENCODING_ID_UNINTERPRETED = 32
};

enum libparsesfnt_macintosh_language_id {
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_ENGLISH = 0,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_FRENCH = 1,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_GERMAN = 2,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_ITALIAN = 3,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_DUTCH = 4,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_SWEDISH = 5,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_SPANISH = 6,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_DANISH = 7,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_PORTUGUESE = 8,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_NORWEGIAN = 9,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_HEBREW = 10,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_JAPANESE = 11,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_ARABIC = 12,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_FINNISH = 13,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_GREEK = 14,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_ICELANDIC = 15,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_MALTESE = 16,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_TURKISH = 17,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_CROATIAN = 18,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_TRADITIONAL_CHINESE = 19,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_URDU = 20,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_HINDI = 21,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_THAI = 22,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_KOREAN = 23,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_LITHUANIAN = 24,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_POLISH = 25,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_HUNGARIAN = 26,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_ESTONIAN = 27,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_LATVIAN = 28,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_SAMI = 29,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_FAROESE = 30,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_FARSI = 31, /* Persian */
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_RUSSIAN = 32,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_SIMPLIFIED_CHINESE = 33,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_FLEMISH = 34,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_IRISH_GAELIC = 35,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_ALBANIAN = 36,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_ROMANIAN = 37,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_CZECH = 38,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_SLOVAK = 39,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_SLOVENIAN = 40,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_YIDDISH = 41,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_SERBIAN = 42,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_MACEDONIAN = 43,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_BULGARIAN = 44,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_UKRAINIAN = 45,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_BYELORUSSIAN = 46,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_UZBEK = 47,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_KAZAKH = 48,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_CYRILLIC_AZERBAIJANI = 49,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_ARABIC_AZERBAIJANI = 50,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_ARMENIAN = 51,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_GEORGIAN = 52,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_MOLDAVIAN = 53,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_KIRGHIZ = 54,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_TAJIKI = 55,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_TURKMEN = 56,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_MONGOLIAN = 57,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_CYRILLIC_MONGOLIAN = 58,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_PASHTO = 59,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_KURDISH = 60,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_KASHMIRI = 61,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_SINDHI = 62,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_TIBETAN = 63,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_NEPALI = 64,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_SANSKRIT = 65,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_MARATHI = 66,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_BENGALI = 67,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_ASSAMESE = 68,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_GUJARATI = 69,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_PUNJABI = 70,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_ORIYA = 71,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_MALAYALAM = 72,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_KANNADA = 73,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_TAMIL = 74,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_TELUGU = 75,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_SINHALESE = 76,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_BURMESE = 77,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_KHMER = 78,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_LAO = 79,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_VIETNAMESE = 80,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_INDONESIAN = 81,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_TAGALOG = 82,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_ROMAN_MALAY = 83,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_ARABIC_MALAY = 84,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_AMHARIC = 85,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_TIGRINYA = 86,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_GALLA = 87,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_SOMALI = 88,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_SWAHILI = 89,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_KINYARWANDA = 90, /* Ruanda */
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_RUNDI = 91,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_NYANJA = 92, /* Chewa */
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_MALAGASY = 93,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_ESPERANTO = 94,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_WELSH = 128,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_BASQUE = 129,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_CATALAN = 130,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_LATIN = 131,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_QUECHUA = 132,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_GUARANI = 133,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_AYMARA = 134,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_TATAR = 135,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_UIGHUR = 136,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_DZONGKHA = 137,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_ROMAN_JAVANESE = 138,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_ROMAN_SUNDANESE = 139,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_GALICIAN = 140,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_AFRIKAANS = 141,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_BRETON = 142,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_INUKTITUT = 143,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_SCOTTISH_GAELIC = 144,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_MANX_GAELIC = 145,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_IRISH_GAELIC_WITH_DOT_ABOVE = 146,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_TONGAN = 147,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_POLYTONIC_GREEK = 148,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_GREENLANDIC = 149,
	LIBPARSESFNT_MACINTOSH_LANGUAGE_ID_ROMAN_AZERBAIJANI = 150
};

enum libparsesfnt_windows_encoding_id {
	LIBPARSESFNT_WINDOWS_ENCODING_ID_SYMBOL = 0,
	LIBPARSESFNT_WINDOWS_ENCODING_ID_UNICODE_BMP = 1,
	LIBPARSESFNT_WINDOWS_ENCODING_ID_SHIFT_JIS = 2,
	LIBPARSESFNT_WINDOWS_ENCODING_ID_PRC = 3,
	LIBPARSESFNT_WINDOWS_ENCODING_ID_BIG5 = 4,
	LIBPARSESFNT_WINDOWS_ENCODING_ID_WANSUNG = 5,
	LIBPARSESFNT_WINDOWS_ENCODING_ID_JOHAB = 6,
	/* According to Microsoft's documentation Wansung is 5 and Johab is 6,
	 * but according to Apple's documentation Johab is 5 and Wansung is missing */
	LIBPARSESFNT_WINDOWS_ENCODING_ID_FULL_UNICODE = 10
};

enum libparsesfnt_windows_language_id {
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_AFRIKAANS_SOUTH_AFRICA = 0x0436,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ALBANIAN_ALBANIA = 0x041C,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ALSATIAN_FRANCE = 0x0484,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_AMHARIC_ETHIOPIA = 0x045E,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ARABIC_ALGERIA = 0x1401,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ARABIC_BAHRAIN = 0x3C01,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ARABIC_EGYPT = 0x0C01,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ARABIC_IRAQ = 0x0801,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ARABIC_JORDAN = 0x2C01,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ARABIC_KUWAIT = 0x3401,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ARABIC_LEBANON = 0x3001,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ARABIC_LIBYA = 0x1001,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ARABIC_MOROCCO = 0x1801,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ARABIC_OMAN = 0x2001,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ARABIC_QATAR = 0x4001,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ARABIC_SAUDI_ARABIA = 0x0401,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ARABIC_SYRIA = 0x2801,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ARABIC_TUNISIA = 0x1C01,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ARABIC_UAE = 0x3801,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ARABIC_YEMEN = 0x2401,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ARMENIAN_ARMENIA = 0x042B,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ASSAMESE_INDIA = 0x044D,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_CYRILLIC_AZERI_AZERBAIJAN = 0x082C,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_LATIN_AZERI_AZERBAIJAN = 0x042C,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_BASHKIR_RUSSIA = 0x046D,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_BASQUE_BASQUE = 0x042D,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_BELARUSIAN_BELARUS = 0x0423,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_BENGALI_BANGLADESH = 0x0845,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_BENGALI_INDIA = 0x0445,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_CYRILLIC_BOSNIAN_BOSNIA_AND_HERZEGOVINA = 0x201A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_LATIN_BOSNIAN_BOSNIA_AND_HERZEGOVINA = 0x141A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_BRETON_FRANCE = 0x047E,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_BULGARIAN_BULGARIA = 0x0402,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_CATALAN_CATALAN = 0x0403,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_CHINESE_HONG_KONG = 0x0C04,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_CHINESE_MACAO = 0x1404,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_CHINESE_CHINA = 0x0804,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_CHINESE_SINGAPORE = 0x1004,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_CHINESE_TAIWAN = 0x0404,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_CORSICAN_FRANCE = 0x0483,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_CROATIAN_CROATIA = 0x041A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_LATIN_CROATIAN_BOSNIA_AND_HERZEGOVINA = 0x101A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_CZECH_CZECH_REPUBLIC = 0x0405,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_DANISH_DENMARK = 0x0406,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_DARI_AFGHANISTAN = 0x048C,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_DIVEHI_MALDIVES = 0x0465,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_DUTCH_BELGIUM = 0x0813,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_DUTCH_NETHERLANDS = 0x0413,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ENGLISH_AUSTRALIA = 0x0C09,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ENGLISH_BELIZE = 0x2809,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ENGLISH_CANADA = 0x1009,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ENGLISH_CARIBBEAN = 0x2409,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ENGLISH_INDIA = 0x4009,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ENGLISH_IRELAND = 0x1809,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ENGLISH_JAMAICA = 0x2009,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ENGLISH_MALAYSIA = 0x4409,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ENGLISH_NEW_ZEALAND = 0x1409,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ENGLISH_PHILIPPINES = 0x3409,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ENGLISH_SINGAPORE = 0x4809,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ENGLISH_SOUTH_AFRICA = 0x1C09,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ENGLISH_TRINIDAD_AND_TOBAGO = 0x2C09,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ENGLISH_UNITED_KINGDOM = 0x0809,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ENGLISH_UNITED_STATES = 0x0409,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ENGLISH_ZIMBABWE = 0x3009,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ESTONIAN_ESTONIA = 0x0425,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_FAROESE_FAROE_ISLANDS = 0x0438,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_FILIPINO_PHILIPPINES = 0x0464,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_FINNISH_FINLAND = 0x040B,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_FRENCH_BELGIUM = 0x080C,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_FRENCH_CANADA = 0x0C0C,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_FRENCH_FRANCE = 0x040C,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_FRENCH_LUXEMBOURG = 0x140C,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_FRENCH_MONACO = 0x180C,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_FRENCH_SWITZERLAND = 0x100C,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_FRISIAN_NETHERLANDS = 0x0462,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_GALICIAN_GALICIAN = 0x0456,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_GEORGIAN_GEORGIA = 0x0437,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_GERMAN_AUSTRIA = 0x0C07,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_GERMAN_GERMANY = 0x0407,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_GERMAN_LIECHTENSTEIN = 0x1407,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_GERMAN_LUXEMBOURG = 0x1007,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_GERMAN_SWITZERLAND = 0x0807,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_GREEK_GREECE = 0x0408,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_GREENLANDIC_GREENLAND = 0x046F,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_GUJARATI_INDIA = 0x0447,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_LATIN_HAUSA_NIGERIA = 0x0468,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_HEBREW_ISRAEL = 0x040D,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_HINDI_INDIA = 0x0439,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_HUNGARIAN_HUNGARY = 0x040E,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ICELANDIC_ICELAND = 0x040F,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_IGBO_NIGERIA = 0x0470,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_INDONESIAN_INDONESIA = 0x0421,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_INUKTITUT_CANADA = 0x045D,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_LATIN_INUKTITUT_CANADA = 0x085D,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_IRISH_IRELAND = 0x083C,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ISIXHOSA_SOUTH_AFRICA = 0x0434,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ISIZULU_SOUTH_AFRICA = 0x0435,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ITALIAN_ITALY = 0x0410,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ITALIAN_SWITZERLAND = 0x0810,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_JAPANESE_JAPAN = 0x0411,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_KANNADA_INDIA = 0x044B,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_KAZAKH_KAZAKHSTAN = 0x043F,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_KHMER_CAMBODIA = 0x0453,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_KICHE_GUATEMALA = 0x0486,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_KINYARWANDA_RWANDA = 0x0487,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_KISWAHILI_KENYA = 0x0441,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_KONKANI_INDIA = 0x0457,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_KOREAN_KOREA = 0x0412,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_KYRGYZ_KYRGYZSTAN = 0x0440,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_LAO_LAO = 0x0454,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_LATVIAN_LATVIA = 0x0426,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_LITHUANIAN_LITHUANIA = 0x0427,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_LOWER_SORBIAN_GERMANY = 0x082E,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_LUXEMBOURGISH_LUXEMBOURG = 0x046E,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_MACEDONIAN_NORTH_MACEDONIA = 0x042F,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_MALAY_BRUNEI_DARUSSALAM = 0x083E,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_MALAY_MALAYSIA = 0x043E,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_MALAYALAM_INDIA = 0x044C,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_MALTESE_MALTA = 0x043A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_MAORI_NEW_ZEALAND = 0x0481,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_MAPUDUNGUN_CHILE = 0x047A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_MARATHI_INDIA = 0x044E,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_MOHAWK_MOHAWK = 0x047C,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_CYRILLIC_MONGOLIAN_MONGOLIA = 0x0450,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_TRADITIONAL_MONGOLIAN_CHINA = 0x0850,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_NEPALI_NEPAL = 0x0461,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_BOKMAAL_NORWEGIAN_NORWAY = 0x0414,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_NYNORSK_NORWEGIAN_NORWAY = 0x0814,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_OCCITAN_FRANCE = 0x0482,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ODIA_INDIA = 0x0448,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_PASHTO_AFGHANISTAN = 0x0463,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_POLISH_POLAND = 0x0415,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_PORTUGUESE_BRAZIL = 0x0416,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_PORTUGUESE_PORTUGAL = 0x0816,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_PUNJABI_INDIA = 0x0446,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_QUECHUA_BOLIVIA = 0x046B,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_QUECHUA_ECUADOR = 0x086B,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_QUECHUA_PERU = 0x0C6B,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ROMANIAN_ROMANIA = 0x0418,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_ROMANSH_SWITZERLAND = 0x0417,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_RUSSIAN_RUSSIA = 0x0419,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_INARI_SAMI_FINLAND = 0x243B,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_LULE_SAMI_NORWAY = 0x103B,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_LULE_SAMI_SWEDEN = 0x143B,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_NORTHERN_SAMI_FINLAND = 0x0C3B,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_NORTHERN_SAMI_NORWAY = 0x043B,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_NORTHERN_SAMI_SWEDEN = 0x083B,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SKOLT_SAMI_FINLAND = 0x203B,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SOUTHERN_SAMI_NORWAY = 0x183B,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SOUTHERN_SAMI_SWEDEN = 0x1C3B,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SANSKRIT_INDIA = 0x044F,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_CYRILLIC_SERBIAN_BOSNIA_AND_HERZEGOVINA = 0x1C1A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_CYRILLIC_SERBIAN_SERBIA = 0x0C1A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_LATIN_SERBIAN_BOSNIA_AND_HERZEGOVINA = 0x181A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_LATIN_SERBIAN_SERBIA = 0x081A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SESOTHO_SA_LEBOA_SOUTH_AFRICA = 0x046C,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SETSWANA_SOUTH_AFRICA = 0x0432,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SINHALA_SRI_LANKA = 0x045B,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SLOVAK_SLOVAKIA = 0x041B,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SLOVENIAN_SLOVENIA = 0x0424,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_ARGENTINA = 0x2C0A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_BOLIVIA = 0x400A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_CHILE = 0x340A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_COLOMBIA = 0x240A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_COSTA_RICA = 0x140A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_DOMINICAN_REPUBLIC = 0x1C0A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_ECUADOR = 0x300A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_EL_SALVADOR = 0x440A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_GUATEMALA = 0x100A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_HONDURAS = 0x480A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_MEXICO = 0x080A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_NICARAGUA = 0x4C0A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_PANAMA = 0x180A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_PARAGUAY = 0x3C0A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_PERU = 0x280A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_PUERTO_RICO = 0x500A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_MODERN_SORT_SPANISH_SPAIN = 0x0C0A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_TRADITIONAL_SORT_SPANISH_SPAIN = 0x040A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_UNITED_STATES = 0x540A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_URUGUAY = 0x380A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SPANISH_VENEZUELA = 0x200A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SWEDISH_FINLAND = 0x081D,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SWEDISH_SWEDEN = 0x041D,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_SYRIAC_SYRIA = 0x045A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_CYRILLIC_TAJIK_TAJIKISTAN = 0x0428,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_LATIN_TAMAZIGHT_ALGERIA = 0x085F,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_TAMIL_INDIA = 0x0449,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_TATAR_RUSSIA = 0x0444,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_TELUGU_INDIA = 0x044A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_THAI_THAILAND = 0x041E,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_TIBETAN_PRC = 0x0451,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_TURKISH_TURKEY = 0x041F,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_TURKMEN_TURKMENISTAN = 0x0442,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_UIGHUR_PRC = 0x0480,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_UKRAINIAN_UKRAINE = 0x0422,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_UPPER_SORBIAN_GERMANY = 0x042E,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_URDU_PAKISTAN = 0x0420,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_CYRILLIC_UZBEK_UZBEKISTAN = 0x0843,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_LATIN_UZBEK_UZBEKISTAN = 0x0443,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_VIETNAMESE_VIETNAM = 0x042A,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_WELSH_UNITED_KINGDOM = 0x0452,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_WOLOF_SENEGAL = 0x0488,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_YAKUT_RUSSIA = 0x0485,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_YI_PRC = 0x0478,
	LIBPARSESFNT_WINDOWS_LANGUAGE_ID_YORUBA_NIGERIA = 0x046A
};



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
#define LIBPARSESFNT_MAXP_1_0__ "{14}2"

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
	uint16_t offset; /* divided by 2 */
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

struct libparsesfnt_name {
	uint16_t format;
	uint16_t count;
	uint16_t string_offset;
};
#define LIBPARSESFNT_NAME__ "222"

struct libparsesfnt_name_entry {
	uint16_t platform_id;
	uint16_t encoding_id;
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
#define LIBPARSESFNT_FMTX__ "44{8}1"

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
#define LIBPARSESFNT_GCID__ "2242{64}12{64}122"

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



/* === 'hdmx' (horizontal device metrics) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6hdmx.html */

struct libparsesfnt_hdmx {
	uint16_t version;
	uint16_t num_records;
	uint32_t record_size; /* includes alignment */
};
#define LIBPARSESFNT_HDMX__ "224"

struct libparsesfnt_hdmx_v0_entry {
	uint8_t pixel_size;
	uint8_t maximum_width;
};
#define LIBPARSESFNT_HDMX_V0_ENTRY__ "11"

int libparsesfnt_parse_hdmx(
	const char *data, size_t size,
	struct libparsesfnt_hdmx *infop,
	const struct libparsesfnt_tabdir_entry *tag);

int libparsesfnt_parse_hdmx_v0_entries(
	const char *data, size_t size,
	struct libparsesfnt_hdmx_v0_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_hdmx *hdmx,
	size_t first, size_t count);

int libparsesfnt_parse_hdmx_v0_subentries(
	const char *data, size_t size,
	uint8_t *widthp,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_hdmx *hdmx, size_t record,
	size_t first, size_t count);



/* === 'post' (glyph name and PostScript compatibility) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6post.html */

struct libparsesfnt_post_format2_subtable {
	uint16_t number_of_glyphs;
	uint16_t __padding1;
};
#define LIBPARSESFNT_POST_FORMAT2__ "2pp"

struct libparsesfnt_post {
	uint32_t format;
	int32_t italic_angle;
	int16_t underline_position;
	int16_t underline_thickness;
	uint32_t is_fixed_pitch;
	uint32_t min_mem_type_42;
	uint32_t max_mem_type_42;
	uint32_t min_mem_type_1;
	uint32_t max_mem_type_1;
	union {
		struct libparsesfnt_post_format2_subtable v2; /* 2.x */
	} subtable;
};
#define LIBPARSESFNT_POST__ "4-422+44444"

int libparsesfnt_parse_post(
	const char *data, size_t size,
	struct libparsesfnt_post *infop,
	const struct libparsesfnt_tabdir_entry *tag);

int libparsesfnt_parse_post_format_2_0_indices(
	const char *data, size_t size,
	uint16_t *indexp,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t first, size_t count);

int libparsesfnt_parse_post_format_2_0_name(
	const char *data, size_t size,
	char namep[256],
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_post *post,
	size_t *offsetp /* start at 0 */);

int libparsesfnt_parse_post_format_2_5_offsets(
	const char *data, size_t size,
	int16_t *offsetp,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t first, size_t count);

int libparsesfnt_parse_post_format_4_0_indices(
	const char *data, size_t size,
	uint16_t *indexp,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t first, size_t count);



/* === 'cmap' (character code mapping) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6cmap.html */

struct libparsesfnt_cmap {
	uint16_t version;
	uint16_t num_subtables;
};
#define LIBPARSESFNT_CMAP__ "22"

struct libparsesfnt_cmap_entry {
	uint16_t platform_id;
	uint16_t encoding_id;
	uint32_t offset;
};
#define LIBPARSESFNT_CMAP_ENTRY__ "224"

struct libparsesfnt_cmap_entry_subtable_0 {
	uint16_t format;
	uint16_t length;
	uint16_t language_id;
	uint8_t glyph_index_array[256];
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_0__ "222{256}1"

struct libparsesfnt_cmap_entry_subtable_2 {
	uint16_t format;
	uint16_t length;
	uint16_t language_id;
	uint16_t subheader_keys[256];
	uint16_t libparsesfnt_subheader_keys_max;
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_2__ "222{256}2"

struct libparsesfnt_cmap_entry_subtable_2_subheader {
	uint16_t first_code;
	uint16_t entry_count;
	int16_t id_delta;
	uint16_t id_range_offset;
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_2_SUBHEADER__ "22-2+2"

struct libparsesfnt_cmap_entry_subtable_4 {
	uint16_t format;
	uint16_t length;
	uint16_t language_id;
	uint16_t seg_count_x2;
	uint16_t search_range;
	uint16_t entry_selector;
	uint16_t range_shift;
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_4__ "2222222"

struct libparsesfnt_cmap_entry_subtable_6 {
	uint16_t format;
	uint16_t length;
	uint16_t language_id;
	uint16_t first_code;
	uint16_t entry_count;
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_6__ "22222"

struct libparsesfnt_cmap_entry_subtable_8 {
	uint16_t format;
	uint16_t __reserved1;
	uint32_t length;
	uint32_t language_id;
	uint8_t is32[8192];
	uint32_t n_groups;
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_8__ "2244{8192}14"

struct libparsesfnt_cmap_entry_subtable_8_entry {
	uint32_t start_char_code;
	uint32_t end_char_code;
	uint32_t start_glyph_code;
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_8_ENTRY__ "444"

struct libparsesfnt_cmap_entry_subtable_10 {
	uint16_t format;
	uint16_t __reserved1;
	uint32_t length;
	uint32_t language_id;
	uint32_t start_char_code;
	uint32_t num_chars;
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_10__ "224444"

struct libparsesfnt_cmap_entry_subtable_12 {
	uint16_t format;
	uint16_t __reserved1;
	uint32_t length;
	uint32_t language_id;
	uint32_t n_groups;
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_12__ "22444"

struct libparsesfnt_cmap_entry_subtable_12_entry {
	uint32_t start_char_code;
	uint32_t end_char_code;
	uint32_t start_glyph_code;
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_12_ENTRY__ "444"

struct libparsesfnt_cmap_entry_subtable_13 {
	uint16_t format;
	uint16_t __reserved1;
	uint32_t length;
	uint32_t language_id;
	uint32_t n_groups;
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_13__ "22444"

struct libparsesfnt_cmap_entry_subtable_13_entry {
	uint32_t start_char_code;
	uint32_t end_char_code;
	uint32_t glyph_code;
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_13_ENTRY__ "444"

struct libparsesfnt_cmap_entry_subtable_14 {
	uint16_t format;
	uint16_t __padding1;
	uint32_t length;
	uint32_t num_var_selector_records;
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_14__ "2pp44"

struct libparsesfnt_cmap_entry_subtable_14_entry {
	uint32_t var_selector;
	uint32_t default_uvs_offset;     /* relative to the beginning of the `libparsesfnt_cmap_entry_subtable_14` */
	uint32_t non_default_uvs_offset; /* relative to the beginning of the `libparsesfnt_cmap_entry_subtable_14` */
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_14_ENTRY__ "p1244"

struct libparsesfnt_cmap_entry_subtable_14_default_uvs {
	uint32_t num_unicode_value_ranges;
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_14_DEFAULT_UVS__ "4"

struct libparsesfnt_cmap_entry_subtable_14_default_uvs_entry {
	uint32_t start_unicode_value;
	uint8_t additional_count;
	uint8_t __padding1[3];
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_14_DEFAULT_UVS_ENTRY__ "p121ppp"

struct libparsesfnt_cmap_entry_subtable_14_non_default_uvs {
	uint32_t num_uvs_mappings;
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_14_NON_DEFAULT_UVS__ "4"

struct libparsesfnt_cmap_entry_subtable_14_non_default_uvs_entry {
	uint32_t start_unicode_value;
	uint16_t glyph_id;
	uint16_t __padding1;
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE_14_NON_DEFAULT_UVS_ENTRY__ "p122pp"

union libparsesfnt_cmap_entry_subtable {
	uint16_t format;
	struct libparsesfnt_cmap_entry_subtable_0 f0;
	struct libparsesfnt_cmap_entry_subtable_2 f2;
	struct libparsesfnt_cmap_entry_subtable_4 f4;
	struct libparsesfnt_cmap_entry_subtable_6 f6;
	struct libparsesfnt_cmap_entry_subtable_8 f8;
	struct libparsesfnt_cmap_entry_subtable_10 f10;
	struct libparsesfnt_cmap_entry_subtable_12 f12;
	struct libparsesfnt_cmap_entry_subtable_13 f13;
	struct libparsesfnt_cmap_entry_subtable_14 f14;
};
#define LIBPARSESFNT_CMAP_ENTRY_SUBTABLE__ "2"

int libparsesfnt_parse_cmap(
	const char *data, size_t size,
	struct libparsesfnt_cmap *infop,
	const struct libparsesfnt_tabdir_entry *tag);

int libparsesfnt_parse_cmap_entries(
	const char *data, size_t size,
	struct libparsesfnt_cmap_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t first, size_t count);

int libparsesfnt_parse_cmap_entry_subtable(
	const char *data, size_t size,
	union libparsesfnt_cmap_entry_subtable *infop,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_cmap_entry *entry);

int libparsesfnt_parse_cmap_entry_subtable_2_subheader_entries(
	const char *data, size_t size,
	struct libparsesfnt_cmap_entry_subtable_2_subheader *infop,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_cmap_entry *entry,
	size_t first, size_t count);

int libparsesfnt_parse_cmap_entry_subtable_2_glyph_index_entries(
	const char *data, size_t size,
	uint16_t *glyph_indexp,
	const struct libparsesfnt_tabdir_entry *tag,
	  const struct libparsesfnt_cmap_entry *entry,
	  const struct libparsesfnt_cmap_entry_subtable_2 *subtable,
	size_t first, size_t count);

int libparsesfnt_parse_cmap_entry_subtable_4_end_code_entries(
	const char *data, size_t size,
	uint16_t *end_codep,
	const struct libparsesfnt_tabdir_entry *tag,
	  const struct libparsesfnt_cmap_entry *entry,
	size_t first, size_t count);

int libparsesfnt_parse_cmap_entry_subtable_4_start_code_entries(
	const char *data, size_t size,
	uint16_t *start_codep,
	const struct libparsesfnt_tabdir_entry *tag,
	  const struct libparsesfnt_cmap_entry *entry,
	  const struct libparsesfnt_cmap_entry_subtable_4 *subtable,
	size_t first, size_t count);

int libparsesfnt_parse_cmap_entry_subtable_4_id_delta_entries(
	const char *data, size_t size,
	uint16_t *id_deltap,
	const struct libparsesfnt_tabdir_entry *tag,
	  const struct libparsesfnt_cmap_entry *entry,
	  const struct libparsesfnt_cmap_entry_subtable_4 *subtable,
	size_t first, size_t count);

int libparsesfnt_parse_cmap_entry_subtable_4_id_range_offset_entries(
	const char *data, size_t size,
	uint16_t *id_range_offsetp,
	const struct libparsesfnt_tabdir_entry *tag,
	  const struct libparsesfnt_cmap_entry *entry,
	  const struct libparsesfnt_cmap_entry_subtable_4 *subtable,
	size_t first, size_t count);

int libparsesfnt_parse_cmap_entry_subtable_4_glyph_index_entries(
	const char *data, size_t size,
	uint16_t *glyph_indexp,
	const struct libparsesfnt_tabdir_entry *tag,
	  const struct libparsesfnt_cmap_entry *entry,
	  const struct libparsesfnt_cmap_entry_subtable_4 *subtable,
	size_t first, size_t count);

int libparsesfnt_parse_cmap_entry_subtable_6_entries(
	const char *data, size_t size,
	uint16_t *glyphp,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_cmap_entry *entry,
	size_t first, size_t count);

int libparsesfnt_parse_cmap_entry_subtable_8_entries(
	const char *data, size_t size,
	struct libparsesfnt_cmap_entry_subtable_8_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_cmap_entry *entry,
	size_t first, size_t count);

int libparsesfnt_parse_cmap_entry_subtable_10_entries(
	const char *data, size_t size,
	uint16_t *glyphp,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_cmap_entry *entry,
	size_t first, size_t count);

int libparsesfnt_parse_cmap_entry_subtable_12_entries(
	const char *data, size_t size,
	struct libparsesfnt_cmap_entry_subtable_12_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_cmap_entry *entry,
	size_t first, size_t count);

int libparsesfnt_parse_cmap_entry_subtable_13_entries(
	const char *data, size_t size,
	struct libparsesfnt_cmap_entry_subtable_13_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag, const struct libparsesfnt_cmap_entry *entry,
	size_t first, size_t count);

int libparsesfnt_parse_cmap_entry_subtable_14_entries(
	const char *data, size_t size,
	struct libparsesfnt_cmap_entry_subtable_14_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	  const struct libparsesfnt_cmap_entry *entry,
	  const struct libparsesfnt_cmap_entry_subtable_14 *subtable,
	size_t first, size_t count);

int libparsesfnt_parse_cmap_entry_subtable_14_default_uvs(
	const char *data, size_t size,
	struct libparsesfnt_cmap_entry_subtable_14_default_uvs *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	  const struct libparsesfnt_cmap_entry *entry,
	  const struct libparsesfnt_cmap_entry_subtable_14 *subtable,
	  const struct libparsesfnt_cmap_entry_subtable_14_entry *subentry);

int libparsesfnt_parse_cmap_entry_subtable_14_default_uvs_entries(
	const char *data, size_t size,
	struct libparsesfnt_cmap_entry_subtable_14_default_uvs_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	  const struct libparsesfnt_cmap_entry *entry,
	  const struct libparsesfnt_cmap_entry_subtable_14_entry *subentry,
	size_t first, size_t count);

int libparsesfnt_parse_cmap_entry_subtable_14_non_default_uvs(
	const char *data, size_t size,
	struct libparsesfnt_cmap_entry_subtable_14_non_default_uvs *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	  const struct libparsesfnt_cmap_entry *entry,
	  const struct libparsesfnt_cmap_entry_subtable_14 *subtable,
	  const struct libparsesfnt_cmap_entry_subtable_14_entry *subentry);

int libparsesfnt_parse_cmap_entry_subtable_14_non_default_uvs_entries(
	const char *data, size_t size,
	struct libparsesfnt_cmap_entry_subtable_14_non_default_uvs_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	  const struct libparsesfnt_cmap_entry *entry,
	  const struct libparsesfnt_cmap_entry_subtable_14_entry *subentry,
	size_t first, size_t count);



/* === 'bdat' (bitmap data) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6bdat.html */

struct libparsesfnt_bdat {
	uint32_t version;
};
#define LIBPARSESFNT_BDAT__ "4"

struct libparsesfnt_bdat_v2_0_big_glyph_metrics { /* used as header for image formats 6 and 7 */
	uint8_t height;
	uint8_t width;
	int8_t hori_bearing_x;
	int8_t hori_bearing_y;
	uint8_t hori_advance;
	int8_t vert_bearing_x;
	int8_t vert_bearing_y;
	uint8_t vert_advance;
};
#define LIBPARSESFNT_BDAT_V2_0_BIG_GLYPH_METRICS__ "11-11+1-11+1"

struct libparsesfnt_bdat_v2_0_small_glyph_metrics { /* used as header for image formats 1 and 2 */
	uint8_t height;
	uint8_t width;
	int8_t bearing_x;
	int8_t bearing_y;
	uint8_t advance;
};
#define LIBPARSESFNT_BDAT_V2_0_SMALL_GLYPH_METRICS__ "11-11+1"

struct libparsesfnt_bdat_v2_0_format_4_glyph_data { /* TODO how should these be intepreted? */
	uint32_t white_tree_offset;
	uint32_t black_tree_offset;
	uint32_t glyph_data_offset;
};
#define LIBPARSESFNT_BDAT_V2_0_FORMAT_4_GLYPH_DATA__ "444"

int libparsesfnt_parse_bdat(
	const char *data, size_t size,
	struct libparsesfnt_bdat *infop,
	const struct libparsesfnt_tabdir_entry *tag);

int libparsesfnt_parse_bdat_v2_0_big_glyph_metrics_entry(
	const char *data, size_t size,
	struct libparsesfnt_bdat_v2_0_big_glyph_metrics *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t offset);

int libparsesfnt_parse_bdat_v2_0_small_glyph_metrics_entry(
	const char *data, size_t size,
	struct libparsesfnt_bdat_v2_0_small_glyph_metrics *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t offset);

int libparsesfnt_parse_bdat_v2_0_format_4_glyph_data_entry(
	const char *data, size_t size,
	struct libparsesfnt_bdat_v2_0_format_4_glyph_data *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t offset);

int libparsesfnt_get_bdat_v2_0_format_1_image_data_offset(
	size_t size,
	size_t *offsetp,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t offset, size_t image_size_or_zero);

#define libparsesfnt_get_bdat_v2_0_format_2_image_data_offset\
        libparsesfnt_get_bdat_v2_0_format_1_image_data_offset

int libparsesfnt_get_bdat_v2_0_format_4_image_data_offset(
	size_t size,
	size_t *offsetp,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t offset, size_t image_size_or_zero);

int libparsesfnt_get_bdat_v2_0_format_5_image_data_offset(
	size_t size,
	size_t *offsetp,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t offset, size_t image_size_or_zero);

int libparsesfnt_get_bdat_v2_0_format_6_image_data_offset(
	size_t size,
	size_t *offsetp,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t offset, size_t image_size_or_zero);

#define libparsesfnt_get_bdat_v2_0_format_7_image_data_offset\
        libparsesfnt_get_bdat_v2_0_format_6_image_data_offset



/* === 'bloc' (bitmap location) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6bloc.html */

struct libparsesfnt_bloc {
	uint32_t version;
	uint32_t num_sizes;
};
#define LIBPARSESFNT_BLOC__ "44"

struct libparsesfnt_bloc_v2_0_line_metrics {
	int8_t ascender;
	int8_t descender;
	uint8_t width_max;
	int8_t caret_slope_numerator;
	int8_t caret_slope_denominator;
	int8_t caret_offset;
	int8_t min_origin_sb;
	int8_t min_advance_sb;
	int8_t max_before_bl;
	int8_t min_after_bl;
	uint8_t __reserved1[2]; /* padding included in the file */
};
#define LIBPARSESFNT_BLOC_V2_0_LINE_METRICS__ "-11+1-{7}1+.."

struct libparsesfnt_bloc_v2_0_size_entry {
	uint32_t index_subtable_array_offset; /* relative to the beginning of 'bloc' */
	uint32_t index_table_size;
	uint32_t number_of_index_subtables;
	uint32_t color_ref;
	struct libparsesfnt_bloc_v2_0_line_metrics hori;
	struct libparsesfnt_bloc_v2_0_line_metrics vert;
	uint16_t start_glyph_index;
	uint16_t end_glyph_index;
	uint8_t ppem_x;
	uint8_t ppem_y;
	uint8_t bit_depth;
	uint8_t flags;
};
#define LIBPARSESFNT_BLOC_V2_0_SIZE_ENTRY__ "4444"LIBPARSESFNT_BLOC_V2_0_LINE_METRICS__\
                                            LIBPARSESFNT_BLOC_V2_0_LINE_METRICS__"2211111"

enum libparsesfnt_bloc_v2_0_size_flag {
	LIBPARSESFNT_BLOC_V2_0_SIZE_FLAG_HORIZONTAL = 0x01,
	LIBPARSESFNT_BLOC_V2_0_SIZE_FLAG_VERTICAL = 0x02
};

struct libparsesfnt_bloc_v2_0_index_entry {
	uint16_t first_glyph_index;
	uint16_t last_glyph_index;
	uint32_t additional_offset_to_index_subtable;
};
#define LIBPARSESFNT_BLOC_V2_0_INDEX_ENTRY__ "224"

struct libparsesfnt_bloc_v2_0_index_subentry {
	uint16_t index_format; /* format in 'bloc' */
	uint16_t image_format; /* format in 'bdat' */
	uint32_t image_data_offset;
};
#define LIBPARSESFNT_BLOC_V2_0_INDEX_SUBENTRY__ "224"

struct libparsesfnt_bloc_v2_0_index_subentry_format_2_header {
	uint32_t image_size;
	struct libparsesfnt_bdat_v2_0_big_glyph_metrics big_metrics;
};
#define LIBPARSESFNT_BLOC_V2_0_INDEX_SUBENTRY_FORMAT_2_HEADER__ "4"LIBPARSESFNT_BDAT_V2_0_BIG_GLYPH_METRICS__

enum libparsesfnt_bloc_v2_0_index_format {
	LIBPARSESFNT_BLOC_V2_0_INDEX_FORMAT_PROPORTIONAL_WITH_4_BYTE_OFFSET_DELTAS = 1,
	LIBPARSESFNT_BLOC_V2_0_INDEX_FORMAT_MONOSPACED = 2,
	LIBPARSESFNT_BLOC_V2_0_INDEX_FORMAT_PROPORTIONAL_WITH_2_BYTE_OFFSET_DELTAS = 3,
};

enum libparsesfnt_bloc_v2_0_image_format {
	LIBPARSESFNT_BLOC_V2_0_IMAGE_FORMAT_PROPORTIONAL_SMALL_METRICS_BYTE_ALIGNED = 1,
	LIBPARSESFNT_BLOC_V2_0_IMAGE_FORMAT_PROPORTIONAL_SMALL_METRICS_BIT_ALIGNED = 2,
	LIBPARSESFNT_BLOC_V2_0_IMAGE_FORMAT_MONOSPACED_COMPRESSED = 4,
	LIBPARSESFNT_BLOC_V2_0_IMAGE_FORMAT_MONOSPACED_BIT_ALIGNED = 5,
	LIBPARSESFNT_BLOC_V2_0_IMAGE_FORMAT_PROPORTIONAL_BIG_METRICS_BYTE_ALIGNED = 6,
	LIBPARSESFNT_BLOC_V2_0_IMAGE_FORMAT_PROPORTIONAL_BIG_METRICS_BIT_ALIGNED = 7
};

int libparsesfnt_parse_bloc(
	const char *data, size_t size,
	struct libparsesfnt_bloc *infop,
	const struct libparsesfnt_tabdir_entry *tag);

int libparsesfnt_parse_bloc_v2_0_size_entries(
	const char *data, size_t size,
	struct libparsesfnt_bloc_v2_0_size_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t first, size_t count);

int libparsesfnt_parse_bloc_v2_0_index_entries(
	const char *data, size_t size,
	struct libparsesfnt_bloc_v2_0_index_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	  const struct libparsesfnt_bloc_v2_0_size_entry *size_entry,
	size_t first, size_t count);

int libparsesfnt_parse_bloc_v2_0_index_subentry(
	const char *data, size_t size,
	struct libparsesfnt_bloc_v2_0_index_subentry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	  const struct libparsesfnt_bloc_v2_0_size_entry *size_entry,
	  const struct libparsesfnt_bloc_v2_0_index_entry *index_entry);

/* image_size[glyph_index] = offsets[glyph_index + 1] - offsets[glyph_index] */
int libparsesfnt_parse_bloc_v2_0_format_1_offset_entries(
	const char *data, size_t size,
	uint32_t *offsets,
	const struct libparsesfnt_tabdir_entry *tag,
	  const struct libparsesfnt_bloc_v2_0_size_entry *size_entry,
	  const struct libparsesfnt_bloc_v2_0_index_entry *index_entry,
	size_t first, size_t count);

int libparsesfnt_parse_bloc_v2_0_format_2_header(
	const char *data, size_t size,
	struct libparsesfnt_bloc_v2_0_index_subentry_format_2_header *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	  const struct libparsesfnt_bloc_v2_0_size_entry *size_entry,
	  const struct libparsesfnt_bloc_v2_0_index_entry *index_entry);

/* image_size[glyph_index] = offsets[glyph_index + 1] - offsets[glyph_index] */
int libparsesfnt_parse_bloc_v2_0_format_3_offset_entries(
	const char *data, size_t size,
	uint16_t *offsets,
	const struct libparsesfnt_tabdir_entry *tag,
	  const struct libparsesfnt_bloc_v2_0_size_entry *size_entry,
	  const struct libparsesfnt_bloc_v2_0_index_entry *index_entry,
	size_t first, size_t count);

int libparsesfnt_get_bloc_v2_0_format_1_offset(
	size_t *offsetp,
	const uint32_t offset,
	const struct libparsesfnt_bloc_v2_0_index_subentry *subentry);

int libparsesfnt_get_bloc_v2_0_format_2_offset(
	size_t *offsetp,
	size_t glyph_index,
	const struct libparsesfnt_bloc_v2_0_index_entry *entry,
	  const struct libparsesfnt_bloc_v2_0_index_subentry *subentry,
	  struct libparsesfnt_bloc_v2_0_index_subentry_format_2_header *header);

int libparsesfnt_get_bloc_v2_0_format_3_offset(
	size_t *offsetp,
	const uint16_t offset,
	const struct libparsesfnt_bloc_v2_0_index_subentry *subentry);



/* === 'sbix' (extended bitmaps) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6sbix.html */

struct libparsesfnt_sbix {
	uint16_t version;
	uint16_t flags;
	uint32_t num_strikes;
};
#define LIBPARSESFNT_SBIX__ "224"

enum libparsesfnt_sbix_v1_flag {
	LIBPARSESFNT_SBIX_V1_FLAG_REQUIRED_BITS = 0x01, /* Must be set for the font to be valid */
	LIBPARSESFNT_SBIX_V1_FLAG_DRAW_OUTLINES = 0x02
};

struct libparsesfnt_sbix_v1_strike_entry {
	uint16_t ppem;
	uint16_t resolution;
};
#define LIBPARSESFNT_SBIX_V1_STRIKE_ENTRY__ "22"

struct libparsesfnt_sbix_v1_glyph_data_entry {
	int16_t origin_offset_x;
	int16_t origin_offset_y;
	char graphic_type[4]; /* 'jpg ', 'pdf ', 'png ', or 'tiff'; or 'dupe' or 'mask' */
	size_t libparsesfnt_image_data_offset; /* Relative to the beginning of the file */
	size_t libparsesfnt_image_data_length;
};
#define LIBPARSESFNT_SBIX_V1_GLYPH_DATA_ENTRY__ "-22+...."

struct libparsesfnt_sbix_v1_image_data_dupe {
	uint16_t glyph_index;
};
#define LIBPARSESFNT_SBIX_V1_IMAGE_DATA_DUPE__ "2"

struct libparsesfnt_sbix_v1_image_data_mask {
	uint32_t mask_offset;
	char graphic_type[4]; /* 'jpg ', 'pdf ', 'png ', or 'tiff' */
	size_t libparsesfnt_image_data_offset; /* Relative to the beginning of the file */
	size_t libparsesfnt_image_data_length;
};
#define LIBPARSESFNT_SBIX_V1_IMAGE_DATA_MASK__ "4...."

struct libparsesfnt_sbix_v1_mask {
	uint32_t mask_length;
	uint16_t __reserved1;
	uint16_t blending_mode;
	int16_t origin_offset_x;
	int16_t origin_offset_y;
	char graphic_type[4]; /* 'jpg ', 'png ', or 'tiff' */
	size_t libparsesfnt_mask_offset; /* Relative to the beginning of the file */
};
#define LIBPARSESFNT_SBIX_V1_MASK__ "4pp2-22+...."

enum libparsesfnt_sbix_v1_mask_blending_mode {
	LIBPARSESFNT_SBIX_V1_MASK_BLENDING_MODE_MULTIPLY = 0,
	LIBPARSESFNT_SBIX_V1_MASK_BLENDING_MODE_DARKEN = 1,
	LIBPARSESFNT_SBIX_V1_MASK_BLENDING_MODE_HARD_LIGHT = 2,
	LIBPARSESFNT_SBIX_V1_MASK_BLENDING_MODE_SOURCE_ATOP = 3,
	LIBPARSESFNT_SBIX_V1_MASK_BLENDING_MODE_XOR = 4
};

int libparsesfnt_parse_sbix(
	const char *data, size_t size,
	struct libparsesfnt_sbix *infop,
	const struct libparsesfnt_tabdir_entry *tag);

int libparsesfnt_parse_sbix_v1_strike_offset_entries(
	const char *data, size_t size,
	uint32_t *offsetp,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t first, size_t count);

int libparsesfnt_parse_sbix_v1_strike_entry(
	const char *data, size_t size,
	struct libparsesfnt_sbix_v1_strike_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag, size_t strike_offset);

/* There is one extra, so that
 * glyph_data_size[i] = glyph_data_offset[i + 1] - glyph_data_offset[i];
 * if the glyph data size is 0, there is no bitmap, but the outline shall be drawn
 * (this is the case for white space characters). */
int libparsesfnt_parse_sbix_v1_glyph_data_offset_entries(
	const char *data, size_t size,
	uint32_t *offsetp,
	const struct libparsesfnt_tabdir_entry *tag, size_t strike_offset,
	size_t first, size_t count);

int libparsesfnt_parse_sbix_v1_glyph_data_entry(
	const char *data, size_t size,
	struct libparsesfnt_sbix_v1_glyph_data_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	  size_t strike_offset, size_t glyph_data_offset, size_t next_glyphs_data_offset);

int libparsesfnt_parse_sbix_v1_image_data_dupe(
	const char *data, size_t size,
	struct libparsesfnt_sbix_v1_image_data_dupe *infop,
	const struct libparsesfnt_sbix_v1_glyph_data_entry *glyph_data);

int libparsesfnt_parse_sbix_v1_image_data_mask(
	const char *data, size_t size,
	struct libparsesfnt_sbix_v1_image_data_mask *infop,
	const struct libparsesfnt_sbix_v1_glyph_data_entry *glyph_data);

int libparsesfnt_parse_sbix_v1_mask(
	const char *data, size_t size,
	struct libparsesfnt_sbix_v1_mask *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	  const struct libparsesfnt_sbix_v1_image_data_mask *image_data);



/* === 'EBSC' (embedded bitmap scaling control) === */
/* https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6EBSC.html */

struct libparsesfnt_ebsc {
	uint32_t version;
	uint32_t num_sizes;
};
#define LIBPARSESFNT_EBSC__ "44"

struct libparsesfnt_ebsc_v2_0_entry {
	struct libparsesfnt_bloc_v2_0_line_metrics hori;
	struct libparsesfnt_bloc_v2_0_line_metrics vert;
	uint8_t ppem_x;
	uint8_t ppem_y;
	uint8_t substitute_ppem_x;
	uint8_t substitute_ppem_y;
};
#define LIBPARSESFNT_EBSC_V2_0_ENTRY__ LIBPARSESFNT_BLOC_V2_0_LINE_METRICS__""\
                                       LIBPARSESFNT_BLOC_V2_0_LINE_METRICS__"1111"

int libparsesfnt_parse_ebsc(
	const char *data, size_t size,
	struct libparsesfnt_ebsc *infop,
	const struct libparsesfnt_tabdir_entry *tag);

int libparsesfnt_parse_ebsc_v2_0_entries(
	const char *data, size_t size,
	struct libparsesfnt_ebsc_v2_0_entry *infop,
	const struct libparsesfnt_tabdir_entry *tag,
	size_t first, size_t count);


#endif
