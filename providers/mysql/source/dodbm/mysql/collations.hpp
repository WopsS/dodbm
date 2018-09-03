#pragma once

#include <dodbm/mysql/charsets.hpp>

namespace dodbm
{
    namespace mysql
    {
        namespace collations
        {
            inline namespace armscii8
            {
                struct armscii8_bin : charsets::armscii8
                {
                    static constexpr auto name = "armscii8_bin";
                };

                struct armscii8_general_ci : charsets::armscii8
                {
                    static constexpr auto name = "armscii8_general_ci";
                };

                struct armscii8_general_nopad_ci : charsets::armscii8
                {
                    static constexpr auto name = "armscii8_general_nopad_ci";
                };

                struct armscii8_nopad_bin : charsets::armscii8
                {
                    static constexpr auto name = "armscii8_nopad_bin";
                };
            }

            inline namespace ascii
            {
                struct ascii_bin : charsets::ascii
                {
                    static constexpr auto name = "ascii_bin";
                };

                struct ascii_general_ci : charsets::ascii
                {
                    static constexpr auto name = "ascii_general_ci";
                };

                struct ascii_general_nopad_ci : charsets::ascii
                {
                    static constexpr auto name = "ascii_general_nopad_ci";
                };

                struct ascii_nopad_bin : charsets::ascii
                {
                    static constexpr auto name = "ascii_nopad_bin";
                };
            }

            inline namespace big5
            {
                struct big5_bin : charsets::big5
                {
                    static constexpr auto name = "big5_bin";
                };

                struct big5_chinese_ci : charsets::big5
                {
                    static constexpr auto name = "big5_chinese_ci";
                };

                struct big5_chinese_nopad_ci : charsets::big5
                {
                    static constexpr auto name = "big5_chinese_nopad_ci";
                };

                struct big5_nopad_bin : charsets::big5
                {
                    static constexpr auto name = "big5_nopad_bin";
                };
            }

            inline namespace binary
            {
                struct binary : charsets::binary
                {
                    static constexpr auto name = "binary";
                };
            }

            inline namespace cp1250
            {
                struct cp1250_bin : charsets::cp1250
                {
                    static constexpr auto name = "cp1250_bin";
                };

                struct cp1250_croatian_ci : charsets::cp1250
                {
                    static constexpr auto name = "cp1250_croatian_ci";
                };

                struct cp1250_czech_cs : charsets::cp1250
                {
                    static constexpr auto name = "cp1250_czech_cs";
                };

                struct cp1250_general_ci : charsets::cp1250
                {
                    static constexpr auto name = "cp1250_general_ci";
                };

                struct cp1250_general_nopad_ci : charsets::cp1250
                {
                    static constexpr auto name = "cp1250_general_nopad_ci";
                };

                struct cp1250_nopad_bin : charsets::cp1250
                {
                    static constexpr auto name = "cp1250_nopad_bin";
                };

                struct cp1250_polish_ci : charsets::cp1250
                {
                    static constexpr auto name = "cp1250_polish_ci";
                };
            }

            inline namespace cp1251
            {
                struct cp1251_bin : charsets::cp1251
                {
                    static constexpr auto name = "cp1251_bin";
                };

                struct cp1251_bulgarian_ci : charsets::cp1251
                {
                    static constexpr auto name = "cp1251_bulgarian_ci";
                };

                struct cp1251_general_ci : charsets::cp1251
                {
                    static constexpr auto name = "cp1251_general_ci";
                };

                struct cp1251_general_cs : charsets::cp1251
                {
                    static constexpr auto name = "cp1251_general_cs";
                };

                struct cp1251_general_nopad_ci : charsets::cp1251
                {
                    static constexpr auto name = "cp1251_general_nopad_ci";
                };

                struct cp1251_nopad_bin : charsets::cp1251
                {
                    static constexpr auto name = "cp1251_nopad_bin";
                };

                struct cp1251_ukrainian_ci : charsets::cp1251
                {
                    static constexpr auto name = "cp1251_ukrainian_ci";
                };
            }

            inline namespace cp1256
            {
                struct cp1256_bin : charsets::cp1256
                {
                    static constexpr auto name = "cp1256_bin";
                };

                struct cp1256_general_ci : charsets::cp1256
                {
                    static constexpr auto name = "cp1256_general_ci";
                };

                struct cp1256_general_nopad_ci : charsets::cp1256
                {
                    static constexpr auto name = "cp1256_general_nopad_ci";
                };

                struct cp1256_nopad_bin : charsets::cp1256
                {
                    static constexpr auto name = "cp1256_nopad_bin";
                };
            }

            inline namespace cp1257
            {
                struct cp1257_bin : charsets::cp1257
                {
                    static constexpr auto name = "cp1257_bin";
                };

                struct cp1257_general_ci : charsets::cp1257
                {
                    static constexpr auto name = "cp1257_general_ci";
                };

                struct cp1257_general_nopad_ci : charsets::cp1257
                {
                    static constexpr auto name = "cp1257_general_nopad_ci";
                };

                struct cp1257_lithuanian_ci : charsets::cp1257
                {
                    static constexpr auto name = "cp1257_lithuanian_ci";
                };

                struct cp1257_nopad_bin : charsets::cp1257
                {
                    static constexpr auto name = "cp1257_nopad_bin";
                };
            }

            inline namespace cp850
            {
                struct cp850_bin : charsets::cp850
                {
                    static constexpr auto name = "cp850_bin";
                };

                struct cp850_general_ci : charsets::cp850
                {
                    static constexpr auto name = "cp850_general_ci";
                };

                struct cp850_general_nopad_ci : charsets::cp850
                {
                    static constexpr auto name = "cp850_general_nopad_ci";
                };

                struct cp850_nopad_bin : charsets::cp850
                {
                    static constexpr auto name = "cp850_nopad_bin";
                };
            }

            inline namespace cp852
            {
                struct cp852_bin : charsets::cp852
                {
                    static constexpr auto name = "cp852_bin";
                };

                struct cp852_general_ci : charsets::cp852
                {
                    static constexpr auto name = "cp852_general_ci";
                };

                struct cp852_general_nopad_ci : charsets::cp852
                {
                    static constexpr auto name = "cp852_general_nopad_ci";
                };

                struct cp852_nopad_bin : charsets::cp852
                {
                    static constexpr auto name = "cp852_nopad_bin";
                };
            }

            inline namespace cp866
            {
                struct cp866_bin : charsets::cp866
                {
                    static constexpr auto name = "cp866_bin";
                };

                struct cp866_general_ci : charsets::cp866
                {
                    static constexpr auto name = "cp866_general_ci";
                };

                struct cp866_general_nopad_ci : charsets::cp866
                {
                    static constexpr auto name = "cp866_general_nopad_ci";
                };

                struct cp866_nopad_bin : charsets::cp866
                {
                    static constexpr auto name = "cp866_nopad_bin";
                };
            }

            inline namespace cp932
            {
                struct cp932_bin : charsets::cp932
                {
                    static constexpr auto name = "cp932_bin";
                };

                struct cp932_japanese_ci : charsets::cp932
                {
                    static constexpr auto name = "cp932_japanese_ci";
                };

                struct cp932_japanese_nopad_ci : charsets::cp932
                {
                    static constexpr auto name = "cp932_japanese_nopad_ci";
                };

                struct cp932_nopad_bin : charsets::cp932
                {
                    static constexpr auto name = "cp932_nopad_bin";
                };
            }

            inline namespace dec8
            {
                struct dec8_bin : charsets::dec8
                {
                    static constexpr auto name = "dec8_bin";
                };

                struct dec8_nopad_bin : charsets::dec8
                {
                    static constexpr auto name = "dec8_nopad_bin";
                };

                struct dec8_swedish_ci : charsets::dec8
                {
                    static constexpr auto name = "dec8_swedish_ci";
                };

                struct dec8_swedish_nopad_ci : charsets::dec8
                {
                    static constexpr auto name = "dec8_swedish_nopad_ci";
                };
            }

            inline namespace eucjpms
            {
                struct eucjpms_bin : charsets::eucjpms
                {
                    static constexpr auto name = "eucjpms_bin";
                };

                struct eucjpms_japanese_ci : charsets::eucjpms
                {
                    static constexpr auto name = "eucjpms_japanese_ci";
                };

                struct eucjpms_japanese_nopad_ci : charsets::eucjpms
                {
                    static constexpr auto name = "eucjpms_japanese_nopad_ci";
                };

                struct eucjpms_nopad_bin : charsets::eucjpms
                {
                    static constexpr auto name = "eucjpms_nopad_bin";
                };
            }

            inline namespace euckr
            {
                struct euckr_bin : charsets::euckr
                {
                    static constexpr auto name = "euckr_bin";
                };

                struct euckr_korean_ci : charsets::euckr
                {
                    static constexpr auto name = "euckr_korean_ci";
                };

                struct euckr_korean_nopad_ci : charsets::euckr
                {
                    static constexpr auto name = "euckr_korean_nopad_ci";
                };

                struct euckr_nopad_bin : charsets::euckr
                {
                    static constexpr auto name = "euckr_nopad_bin";
                };
            }

            inline namespace gb2312
            {
                struct gb2312_bin : charsets::gb2312
                {
                    static constexpr auto name = "gb2312_bin";
                };

                struct gb2312_chinese_ci : charsets::gb2312
                {
                    static constexpr auto name = "gb2312_chinese_ci";
                };

                struct gb2312_chinese_nopad_ci : charsets::gb2312
                {
                    static constexpr auto name = "gb2312_chinese_nopad_ci";
                };

                struct gb2312_nopad_bin : charsets::gb2312
                {
                    static constexpr auto name = "gb2312_nopad_bin";
                };
            }

            inline namespace gbk
            {
                struct gbk_bin : charsets::gbk
                {
                    static constexpr auto name = "gbk_bin";
                };

                struct gbk_chinese_ci : charsets::gbk
                {
                    static constexpr auto name = "gbk_chinese_ci";
                };

                struct gbk_chinese_nopad_ci : charsets::gbk
                {
                    static constexpr auto name = "gbk_chinese_nopad_ci";
                };

                struct gbk_nopad_bin : charsets::gbk
                {
                    static constexpr auto name = "gbk_nopad_bin";
                };
            }

            inline namespace geostd8
            {
                struct geostd8_bin : charsets::geostd8
                {
                    static constexpr auto name = "geostd8_bin";
                };

                struct geostd8_general_ci : charsets::geostd8
                {
                    static constexpr auto name = "geostd8_general_ci";
                };

                struct geostd8_general_nopad_ci : charsets::geostd8
                {
                    static constexpr auto name = "geostd8_general_nopad_ci";
                };

                struct geostd8_nopad_bin : charsets::geostd8
                {
                    static constexpr auto name = "geostd8_nopad_bin";
                };
            }

            inline namespace greek
            {
                struct greek_bin : charsets::greek
                {
                    static constexpr auto name = "greek_bin";
                };

                struct greek_general_ci : charsets::greek
                {
                    static constexpr auto name = "greek_general_ci";
                };

                struct greek_general_nopad_ci : charsets::greek
                {
                    static constexpr auto name = "greek_general_nopad_ci";
                };

                struct greek_nopad_bin : charsets::greek
                {
                    static constexpr auto name = "greek_nopad_bin";
                };
            }

            inline namespace hebrew
            {
                struct hebrew_bin : charsets::hebrew
                {
                    static constexpr auto name = "hebrew_bin";
                };

                struct hebrew_general_ci : charsets::hebrew
                {
                    static constexpr auto name = "hebrew_general_ci";
                };

                struct hebrew_general_nopad_ci : charsets::hebrew
                {
                    static constexpr auto name = "hebrew_general_nopad_ci";
                };

                struct hebrew_nopad_bin : charsets::hebrew
                {
                    static constexpr auto name = "hebrew_nopad_bin";
                };
            }

            inline namespace hp8
            {
                struct hp8_bin : charsets::hp8
                {
                    static constexpr auto name = "hp8_bin";
                };

                struct hp8_english_ci : charsets::hp8
                {
                    static constexpr auto name = "hp8_english_ci";
                };

                struct hp8_english_nopad_ci : charsets::hp8
                {
                    static constexpr auto name = "hp8_english_nopad_ci";
                };

                struct hp8_nopad_bin : charsets::hp8
                {
                    static constexpr auto name = "hp8_nopad_bin";
                };
            }

            inline namespace keybcs2
            {
                struct keybcs2_bin : charsets::keybcs2
                {
                    static constexpr auto name = "keybcs2_bin";
                };

                struct keybcs2_general_ci : charsets::keybcs2
                {
                    static constexpr auto name = "keybcs2_general_ci";
                };

                struct keybcs2_general_nopad_ci : charsets::keybcs2
                {
                    static constexpr auto name = "keybcs2_general_nopad_ci";
                };

                struct keybcs2_nopad_bin : charsets::keybcs2
                {
                    static constexpr auto name = "keybcs2_nopad_bin";
                };
            }

            inline namespace koi8r
            {
                struct koi8r_bin : charsets::koi8r
                {
                    static constexpr auto name = "koi8r_bin";
                };

                struct koi8r_general_ci : charsets::koi8r
                {
                    static constexpr auto name = "koi8r_general_ci";
                };

                struct koi8r_general_nopad_ci : charsets::koi8r
                {
                    static constexpr auto name = "koi8r_general_nopad_ci";
                };

                struct koi8r_nopad_bin : charsets::koi8r
                {
                    static constexpr auto name = "koi8r_nopad_bin";
                };
            }

            inline namespace koi8u
            {
                struct koi8u_bin : charsets::koi8u
                {
                    static constexpr auto name = "koi8u_bin";
                };

                struct koi8u_general_ci : charsets::koi8u
                {
                    static constexpr auto name = "koi8u_general_ci";
                };

                struct koi8u_general_nopad_ci : charsets::koi8u
                {
                    static constexpr auto name = "koi8u_general_nopad_ci";
                };

                struct koi8u_nopad_bin : charsets::koi8u
                {
                    static constexpr auto name = "koi8u_nopad_bin";
                };
            }

            inline namespace latin1
            {
                struct latin1_bin : charsets::latin1
                {
                    static constexpr auto name = "latin1_bin";
                };

                struct latin1_danish_ci : charsets::latin1
                {
                    static constexpr auto name = "latin1_danish_ci";
                };

                struct latin1_general_ci : charsets::latin1
                {
                    static constexpr auto name = "latin1_general_ci";
                };

                struct latin1_general_cs : charsets::latin1
                {
                    static constexpr auto name = "latin1_general_cs";
                };

                struct latin1_german1_ci : charsets::latin1
                {
                    static constexpr auto name = "latin1_german1_ci";
                };

                struct latin1_german2_ci : charsets::latin1
                {
                    static constexpr auto name = "latin1_german2_ci";
                };

                struct latin1_nopad_bin : charsets::latin1
                {
                    static constexpr auto name = "latin1_nopad_bin";
                };

                struct latin1_spanish_ci : charsets::latin1
                {
                    static constexpr auto name = "latin1_spanish_ci";
                };

                struct latin1_swedish_ci : charsets::latin1
                {
                    static constexpr auto name = "latin1_swedish_ci";
                };

                struct latin1_swedish_nopad_ci : charsets::latin1
                {
                    static constexpr auto name = "latin1_swedish_nopad_ci";
                };
            }

            inline namespace latin2
            {
                struct latin2_bin : charsets::latin2
                {
                    static constexpr auto name = "latin2_bin";
                };

                struct latin2_croatian_ci : charsets::latin2
                {
                    static constexpr auto name = "latin2_croatian_ci";
                };

                struct latin2_czech_cs : charsets::latin2
                {
                    static constexpr auto name = "latin2_czech_cs";
                };

                struct latin2_general_ci : charsets::latin2
                {
                    static constexpr auto name = "latin2_general_ci";
                };

                struct latin2_general_nopad_ci : charsets::latin2
                {
                    static constexpr auto name = "latin2_general_nopad_ci";
                };

                struct latin2_hungarian_ci : charsets::latin2
                {
                    static constexpr auto name = "latin2_hungarian_ci";
                };

                struct latin2_nopad_bin : charsets::latin2
                {
                    static constexpr auto name = "latin2_nopad_bin";
                };
            }

            inline namespace latin5
            {
                struct latin5_bin : charsets::latin5
                {
                    static constexpr auto name = "latin5_bin";
                };

                struct latin5_nopad_bin : charsets::latin5
                {
                    static constexpr auto name = "latin5_nopad_bin";
                };

                struct latin5_turkish_ci : charsets::latin5
                {
                    static constexpr auto name = "latin5_turkish_ci";
                };

                struct latin5_turkish_nopad_ci : charsets::latin5
                {
                    static constexpr auto name = "latin5_turkish_nopad_ci";
                };
            }

            inline namespace latin7
            {
                struct latin7_bin : charsets::latin7
                {
                    static constexpr auto name = "latin7_bin";
                };

                struct latin7_estonian_cs : charsets::latin7
                {
                    static constexpr auto name = "latin7_estonian_cs";
                };

                struct latin7_general_ci : charsets::latin7
                {
                    static constexpr auto name = "latin7_general_ci";
                };

                struct latin7_general_cs : charsets::latin7
                {
                    static constexpr auto name = "latin7_general_cs";
                };

                struct latin7_general_nopad_ci : charsets::latin7
                {
                    static constexpr auto name = "latin7_general_nopad_ci";
                };

                struct latin7_nopad_bin : charsets::latin7
                {
                    static constexpr auto name = "latin7_nopad_bin";
                };
            }

            inline namespace macce
            {
                struct macce_bin : charsets::macce
                {
                    static constexpr auto name = "macce_bin";
                };

                struct macce_general_ci : charsets::macce
                {
                    static constexpr auto name = "macce_general_ci";
                };

                struct macce_general_nopad_ci : charsets::macce
                {
                    static constexpr auto name = "macce_general_nopad_ci";
                };

                struct macce_nopad_bin : charsets::macce
                {
                    static constexpr auto name = "macce_nopad_bin";
                };
            }

            inline namespace macroman
            {
                struct macroman_bin : charsets::macroman
                {
                    static constexpr auto name = "macroman_bin";
                };

                struct macroman_general_ci : charsets::macroman
                {
                    static constexpr auto name = "macroman_general_ci";
                };

                struct macroman_general_nopad_ci : charsets::macroman
                {
                    static constexpr auto name = "macroman_general_nopad_ci";
                };

                struct macroman_nopad_bin : charsets::macroman
                {
                    static constexpr auto name = "macroman_nopad_bin";
                };
            }

            inline namespace sjis
            {
                struct sjis_bin : charsets::sjis
                {
                    static constexpr auto name = "sjis_bin";
                };

                struct sjis_japanese_ci : charsets::sjis
                {
                    static constexpr auto name = "sjis_japanese_ci";
                };

                struct sjis_japanese_nopad_ci : charsets::sjis
                {
                    static constexpr auto name = "sjis_japanese_nopad_ci";
                };

                struct sjis_nopad_bin : charsets::sjis
                {
                    static constexpr auto name = "sjis_nopad_bin";
                };
            }

            inline namespace swe7
            {
                struct swe7_bin : charsets::swe7
                {
                    static constexpr auto name = "swe7_bin";
                };

                struct swe7_nopad_bin : charsets::swe7
                {
                    static constexpr auto name = "swe7_nopad_bin";
                };

                struct swe7_swedish_ci : charsets::swe7
                {
                    static constexpr auto name = "swe7_swedish_ci";
                };

                struct swe7_swedish_nopad_ci : charsets::swe7
                {
                    static constexpr auto name = "swe7_swedish_nopad_ci";
                };
            }

            inline namespace tis620
            {
                struct tis620_bin : charsets::tis620
                {
                    static constexpr auto name = "tis620_bin";
                };

                struct tis620_nopad_bin : charsets::tis620
                {
                    static constexpr auto name = "tis620_nopad_bin";
                };

                struct tis620_thai_ci : charsets::tis620
                {
                    static constexpr auto name = "tis620_thai_ci";
                };

                struct tis620_thai_nopad_ci : charsets::tis620
                {
                    static constexpr auto name = "tis620_thai_nopad_ci";
                };
            }

            inline namespace ucs2
            {
                struct ucs2_bin : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_bin";
                };

                struct ucs2_croatian_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_croatian_ci";
                };

                struct ucs2_croatian_mysql561_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_croatian_mysql561_ci";
                };

                struct ucs2_czech_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_czech_ci";
                };

                struct ucs2_danish_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_danish_ci";
                };

                struct ucs2_esperanto_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_esperanto_ci";
                };

                struct ucs2_estonian_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_estonian_ci";
                };

                struct ucs2_general_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_general_ci";
                };

                struct ucs2_general_mysql500_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_general_mysql500_ci";
                };

                struct ucs2_general_nopad_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_general_nopad_ci";
                };

                struct ucs2_german2_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_german2_ci";
                };

                struct ucs2_hungarian_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_hungarian_ci";
                };

                struct ucs2_icelandic_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_icelandic_ci";
                };

                struct ucs2_latvian_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_latvian_ci";
                };

                struct ucs2_lithuanian_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_lithuanian_ci";
                };

                struct ucs2_myanmar_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_myanmar_ci";
                };

                struct ucs2_nopad_bin : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_nopad_bin";
                };

                struct ucs2_persian_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_persian_ci";
                };

                struct ucs2_polish_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_polish_ci";
                };

                struct ucs2_roman_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_roman_ci";
                };

                struct ucs2_romanian_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_romanian_ci";
                };

                struct ucs2_sinhala_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_sinhala_ci";
                };

                struct ucs2_slovak_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_slovak_ci";
                };

                struct ucs2_slovenian_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_slovenian_ci";
                };

                struct ucs2_spanish_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_spanish_ci";
                };

                struct ucs2_spanish2_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_spanish2_ci";
                };

                struct ucs2_swedish_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_swedish_ci";
                };

                struct ucs2_thai_520_w2 : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_thai_520_w2";
                };

                struct ucs2_turkish_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_turkish_ci";
                };

                struct ucs2_unicode_520_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_unicode_520_ci";
                };

                struct ucs2_unicode_520_nopad_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_unicode_520_nopad_ci";
                };

                struct ucs2_unicode_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_unicode_ci";
                };

                struct ucs2_unicode_nopad_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_unicode_nopad_ci";
                };

                struct ucs2_vietnamese_ci : charsets::ucs2
                {
                    static constexpr auto name = "ucs2_vietnamese_ci";
                };
            }

            inline namespace ujis
            {
                struct ujis_bin : charsets::ujis
                {
                    static constexpr auto name = "ujis_bin";
                };

                struct ujis_japanese_ci : charsets::ujis
                {
                    static constexpr auto name = "ujis_japanese_ci";
                };

                struct ujis_japanese_nopad_ci : charsets::ujis
                {
                    static constexpr auto name = "ujis_japanese_nopad_ci";
                };

                struct ujis_nopad_bin : charsets::ujis
                {
                    static constexpr auto name = "ujis_nopad_bin";
                };
            }

            inline namespace utf16
            {
                struct utf16_bin : charsets::utf16
                {
                    static constexpr auto name = "utf16_bin";
                };

                struct utf16_croatian_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_croatian_ci";
                };

                struct utf16_croatian_mysql561_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_croatian_mysql561_ci";
                };

                struct utf16_czech_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_czech_ci";
                };

                struct utf16_danish_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_danish_ci";
                };

                struct utf16_esperanto_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_esperanto_ci";
                };

                struct utf16_estonian_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_estonian_ci";
                };

                struct utf16_general_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_general_ci";
                };

                struct utf16_general_nopad_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_general_nopad_ci";
                };

                struct utf16_german2_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_german2_ci";
                };

                struct utf16_hungarian_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_hungarian_ci";
                };

                struct utf16_icelandic_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_icelandic_ci";
                };

                struct utf16_latvian_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_latvian_ci";
                };

                struct utf16_lithuanian_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_lithuanian_ci";
                };

                struct utf16_myanmar_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_myanmar_ci";
                };

                struct utf16_nopad_bin : charsets::utf16
                {
                    static constexpr auto name = "utf16_nopad_bin";
                };

                struct utf16_persian_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_persian_ci";
                };

                struct utf16_polish_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_polish_ci";
                };

                struct utf16_roman_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_roman_ci";
                };

                struct utf16_romanian_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_romanian_ci";
                };

                struct utf16_sinhala_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_sinhala_ci";
                };

                struct utf16_slovak_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_slovak_ci";
                };

                struct utf16_slovenian_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_slovenian_ci";
                };

                struct utf16_spanish_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_spanish_ci";
                };

                struct utf16_spanish2_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_spanish2_ci";
                };

                struct utf16_swedish_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_swedish_ci";
                };

                struct utf16_thai_520_w2 : charsets::utf16
                {
                    static constexpr auto name = "utf16_thai_520_w2";
                };

                struct utf16_turkish_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_turkish_ci";
                };

                struct utf16_unicode_520_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_unicode_520_ci";
                };

                struct utf16_unicode_520_nopad_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_unicode_520_nopad_ci";
                };

                struct utf16_unicode_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_unicode_ci";
                };

                struct utf16_unicode_nopad_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_unicode_nopad_ci";
                };

                struct utf16_vietnamese_ci : charsets::utf16
                {
                    static constexpr auto name = "utf16_vietnamese_ci";
                };
            }

            inline namespace utf16le
            {
                struct utf16le_bin : charsets::utf16le
                {
                    static constexpr auto name = "utf16le_bin";
                };

                struct utf16le_general_ci : charsets::utf16le
                {
                    static constexpr auto name = "utf16le_general_ci";
                };

                struct utf16le_general_nopad_ci : charsets::utf16le
                {
                    static constexpr auto name = "utf16le_general_nopad_ci";
                };

                struct utf16le_nopad_bin : charsets::utf16le
                {
                    static constexpr auto name = "utf16le_nopad_bin";
                };
            }

            inline namespace utf32
            {
                struct utf32_bin : charsets::utf32
                {
                    static constexpr auto name = "utf32_bin";
                };

                struct utf32_croatian_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_croatian_ci";
                };

                struct utf32_croatian_mysql561_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_croatian_mysql561_ci";
                };

                struct utf32_czech_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_czech_ci";
                };

                struct utf32_danish_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_danish_ci";
                };

                struct utf32_esperanto_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_esperanto_ci";
                };

                struct utf32_estonian_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_estonian_ci";
                };

                struct utf32_general_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_general_ci";
                };

                struct utf32_general_nopad_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_general_nopad_ci";
                };

                struct utf32_german2_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_german2_ci";
                };

                struct utf32_hungarian_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_hungarian_ci";
                };

                struct utf32_icelandic_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_icelandic_ci";
                };

                struct utf32_latvian_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_latvian_ci";
                };

                struct utf32_lithuanian_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_lithuanian_ci";
                };

                struct utf32_myanmar_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_myanmar_ci";
                };

                struct utf32_nopad_bin : charsets::utf32
                {
                    static constexpr auto name = "utf32_nopad_bin";
                };

                struct utf32_persian_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_persian_ci";
                };

                struct utf32_polish_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_polish_ci";
                };

                struct utf32_roman_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_roman_ci";
                };

                struct utf32_romanian_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_romanian_ci";
                };

                struct utf32_sinhala_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_sinhala_ci";
                };

                struct utf32_slovak_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_slovak_ci";
                };

                struct utf32_slovenian_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_slovenian_ci";
                };

                struct utf32_spanish_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_spanish_ci";
                };

                struct utf32_spanish2_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_spanish2_ci";
                };

                struct utf32_swedish_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_swedish_ci";
                };

                struct utf32_thai_520_w2 : charsets::utf32
                {
                    static constexpr auto name = "utf32_thai_520_w2";
                };

                struct utf32_turkish_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_turkish_ci";
                };

                struct utf32_unicode_520_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_unicode_520_ci";
                };

                struct utf32_unicode_520_nopad_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_unicode_520_nopad_ci";
                };

                struct utf32_unicode_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_unicode_ci";
                };

                struct utf32_unicode_nopad_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_unicode_nopad_ci";
                };

                struct utf32_vietnamese_ci : charsets::utf32
                {
                    static constexpr auto name = "utf32_vietnamese_ci";
                };
            }

            inline namespace utf8
            {
                struct utf8_bin : charsets::utf8
                {
                    static constexpr auto name = "utf8_bin";
                };

                struct utf8_croatian_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_croatian_ci";
                };

                struct utf8_croatian_mysql561_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_croatian_mysql561_ci";
                };

                struct utf8_czech_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_czech_ci";
                };

                struct utf8_danish_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_danish_ci";
                };

                struct utf8_esperanto_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_esperanto_ci";
                };

                struct utf8_estonian_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_estonian_ci";
                };

                struct utf8_general_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_general_ci";
                };

                struct utf8_general_mysql500_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_general_mysql500_ci";
                };

                struct utf8_general_nopad_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_general_nopad_ci";
                };

                struct utf8_german2_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_german2_ci";
                };

                struct utf8_hungarian_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_hungarian_ci";
                };

                struct utf8_icelandic_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_icelandic_ci";
                };

                struct utf8_latvian_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_latvian_ci";
                };

                struct utf8_lithuanian_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_lithuanian_ci";
                };

                struct utf8_myanmar_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_myanmar_ci";
                };

                struct utf8_nopad_bin : charsets::utf8
                {
                    static constexpr auto name = "utf8_nopad_bin";
                };

                struct utf8_persian_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_persian_ci";
                };

                struct utf8_polish_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_polish_ci";
                };

                struct utf8_roman_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_roman_ci";
                };

                struct utf8_romanian_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_romanian_ci";
                };

                struct utf8_sinhala_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_sinhala_ci";
                };

                struct utf8_slovak_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_slovak_ci";
                };

                struct utf8_slovenian_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_slovenian_ci";
                };

                struct utf8_spanish_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_spanish_ci";
                };

                struct utf8_spanish2_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_spanish2_ci";
                };

                struct utf8_swedish_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_swedish_ci";
                };

                struct utf8_thai_520_w2 : charsets::utf8
                {
                    static constexpr auto name = "utf8_thai_520_w2";
                };

                struct utf8_turkish_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_turkish_ci";
                };

                struct utf8_unicode_520_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_unicode_520_ci";
                };

                struct utf8_unicode_520_nopad_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_unicode_520_nopad_ci";
                };

                struct utf8_unicode_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_unicode_ci";
                };

                struct utf8_unicode_nopad_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_unicode_nopad_ci";
                };

                struct utf8_vietnamese_ci : charsets::utf8
                {
                    static constexpr auto name = "utf8_vietnamese_ci";
                };
            }

            inline namespace utf8mb4
            {
                struct utf8mb4_bin : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_bin";
                };

                struct utf8mb4_croatian_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_croatian_ci";
                };

                struct utf8mb4_croatian_mysql561_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_croatian_mysql561_ci";
                };

                struct utf8mb4_czech_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_czech_ci";
                };

                struct utf8mb4_danish_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_danish_ci";
                };

                struct utf8mb4_esperanto_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_esperanto_ci";
                };

                struct utf8mb4_estonian_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_estonian_ci";
                };

                struct utf8mb4_general_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_general_ci";
                };

                struct utf8mb4_general_nopad_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_general_nopad_ci";
                };

                struct utf8mb4_german2_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_german2_ci";
                };

                struct utf8mb4_hungarian_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_hungarian_ci";
                };

                struct utf8mb4_icelandic_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_icelandic_ci";
                };

                struct utf8mb4_latvian_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_latvian_ci";
                };

                struct utf8mb4_lithuanian_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_lithuanian_ci";
                };

                struct utf8mb4_myanmar_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_myanmar_ci";
                };

                struct utf8mb4_nopad_bin : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_nopad_bin";
                };

                struct utf8mb4_persian_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_persian_ci";
                };

                struct utf8mb4_polish_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_polish_ci";
                };

                struct utf8mb4_roman_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_roman_ci";
                };

                struct utf8mb4_romanian_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_romanian_ci";
                };

                struct utf8mb4_sinhala_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_sinhala_ci";
                };

                struct utf8mb4_slovak_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_slovak_ci";
                };

                struct utf8mb4_slovenian_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_slovenian_ci";
                };

                struct utf8mb4_spanish_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_spanish_ci";
                };

                struct utf8mb4_spanish2_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_spanish2_ci";
                };

                struct utf8mb4_swedish_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_swedish_ci";
                };

                struct utf8mb4_thai_520_w2 : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_thai_520_w2";
                };

                struct utf8mb4_turkish_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_turkish_ci";
                };

                struct utf8mb4_unicode_520_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_unicode_520_ci";
                };

                struct utf8mb4_unicode_520_nopad_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_unicode_520_nopad_ci";
                };

                struct utf8mb4_unicode_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_unicode_ci";
                };

                struct utf8mb4_unicode_nopad_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_unicode_nopad_ci";
                };

                struct utf8mb4_vietnamese_ci : charsets::utf8mb4
                {
                    static constexpr auto name = "utf8mb4_vietnamese_ci";
                };
            }
        }
    }
}