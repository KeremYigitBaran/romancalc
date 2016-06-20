#include <check.h>
#include "romanmath.h"
#include <stdlib.h>


START_TEST(convertRoman)
{
	ck_assert_int_eq( romanToInt("I"), 1);
	ck_assert_int_eq( romanToInt("II"), 2);
	ck_assert_int_eq( romanToInt("III"), 3);
	ck_assert_int_eq( romanToInt("IV"), 4);
	ck_assert_int_eq( romanToInt("V"), 5);
	ck_assert_int_eq( romanToInt("VI"), 6);
	ck_assert_int_eq( romanToInt("VII"), 7);
	ck_assert_int_eq( romanToInt("VIII"), 8);
	ck_assert_int_eq( romanToInt("IX"), 9);
	ck_assert_int_eq( romanToInt("X"), 10);
	ck_assert_int_eq( romanToInt("L"), 50);
	ck_assert_int_eq( romanToInt("C"), 100);
	ck_assert_int_eq( romanToInt("D"), 500);
	ck_assert_int_eq( romanToInt("M"), 1000);
	ck_assert_int_eq( romanToInt("MMDXVI"), 2516);

}
END_TEST

START_TEST(convertRomanInvalids)
{
	ck_assert_int_eq( romanToInt("IIII"), INVALID_ROMAN_NUMERAL);
	ck_assert_int_eq( romanToInt("VVV"), INVALID_ROMAN_NUMERAL);
	ck_assert_int_eq( romanToInt("VV"), INVALID_ROMAN_NUMERAL);
	ck_assert_int_eq( romanToInt("XXXX"), INVALID_ROMAN_NUMERAL);
	ck_assert_int_eq( romanToInt("LL"), INVALID_ROMAN_NUMERAL);
	ck_assert_int_eq( romanToInt("CCCC"), INVALID_ROMAN_NUMERAL);
	ck_assert_int_eq( romanToInt("DD"), INVALID_ROMAN_NUMERAL);
	ck_assert_int_eq( romanToInt("MMMMM"), INVALID_ROMAN_NUMERAL);
	ck_assert_int_eq( romanToInt(""), INVALID_ROMAN_NUMERAL);
	ck_assert_int_eq( romanToInt("W"), INVALID_ROMAN_NUMERAL);
	ck_assert_int_eq( romanToInt("WII"), INVALID_ROMAN_NUMERAL);
	ck_assert_int_eq( romanToInt("VX"), INVALID_ROMAN_NUMERAL);
	ck_assert_int_eq( romanToInt("VL"), INVALID_ROMAN_NUMERAL);
	ck_assert_int_eq( romanToInt("VD"), INVALID_ROMAN_NUMERAL);
	ck_assert_int_eq( romanToInt("VM"), INVALID_ROMAN_NUMERAL);
	ck_assert_int_eq( romanToInt(""), INVALID_ROMAN_NUMERAL);
}
END_TEST

START_TEST(sumRomanNumeralsInt)
{
	ck_assert_int_eq( romanSumInt("I", "I"), 2);
	ck_assert_int_eq( romanSumInt("XIV", "LX"), 74);
}
END_TEST

START_TEST(sumRomanNumerals)
{
	char* ptr = 0;
	ck_assert_str_eq( (ptr = romanSum("I", "I")), "II");
	free(ptr);
	ck_assert_str_eq( (ptr = romanSum("XIV", "LX")), "LXXIV");
	free(ptr);
}
END_TEST

START_TEST(subtractRomanNumerals)
{
	char* ptr = 0;
	ptr = romanSubtract("II", "I");
	ck_assert_str_eq(ptr, "I");
	free(ptr);
	ck_assert_str_eq( (ptr = romanSubtract("II", "I")), "I");
	free(ptr);
	ck_assert_str_eq( (ptr = romanSubtract("LXXIV", "LX")), "XIV");
	free(ptr);

	//ck_assert_ptr_eq( romanSubtract("I", "I"), 0);
}
END_TEST

START_TEST(convertIntToRoman)
{
	char* ptr = 0;
	ck_assert_str_eq( (ptr = intToRoman(1)), "I");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(2)), "II");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(3)), "III");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(4)), "IV");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(5)), "V");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(6)), "VI");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(7)), "VII");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(8)), "VIII");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(9)), "IX");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(10)), "X");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(11)), "XI");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(21)), "XXI");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(31)), "XXXI");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(41)), "XLI");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(49)), "XLIX");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(50)), "L");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(90)), "XC");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(100)), "C");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(400)), "CD");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(500)), "D");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(900)), "CM");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(1000)), "M");
	free(ptr);
	ck_assert_str_eq( (ptr = intToRoman(2516)), "MMDXVI");
	free(ptr);
}
END_TEST

START_TEST(checkInvalidValues)
{
	//ck_assert_ptr_eq( intToRoman(6000), 0);
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, convertRoman);
    tcase_add_test(tc1_1, convertRomanInvalids);
    tcase_add_test(tc1_1, sumRomanNumeralsInt);
    tcase_add_test(tc1_1, sumRomanNumerals);
    tcase_add_test(tc1_1, subtractRomanNumerals);
    tcase_add_test(tc1_1, convertIntToRoman);
    tcase_add_test(tc1_1, checkInvalidValues);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
