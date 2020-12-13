#include "src/lib.h"
#include "gtest/gtest.h"

using namespace std;

TEST(getTranslittedText, noChangesExpected) {
    const int N = 1600;
    wchar_t text[N + 1] = L"abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890 .!??*%;№@^:()-+=";
    wchar_t expected[N + 1] =L"abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890 .!??*%;№@^:()-+=" ;
    std::wostringstream  strm;
    getTranslittedText(text,strm);
    ASSERT_STREQ(expected, strm.str().c_str());
}


TEST(getTranslittedText, lowerLettersTransliterationExpected) {
    const int N = 100;
    wchar_t text[N + 1] = L"а б в г д е ё ж з и й к л м н о п р с т у ф х ц ч ш щ ы э ю я";
    wchar_t expected[N + 1] = L"a b v g d e yo zh z i j k l m n o p r s t u f h ts ch sh sc i e yu ya";
    std::wostringstream  strm;
    getTranslittedText(text,strm);
    ASSERT_STREQ(expected, strm.str().c_str());
}


TEST(getTranslittedText, higherLettersTransliterationExpected) {
    const int N = 100;
    wchar_t text[N + 1] = L"А Б В Г Д Е Ё Ж З И Й К Л М Н О П Р С Т У Ф Х Ц Ч Ш Щ Ы Э Ю Я";
    wchar_t expected[N + 1] = L"A B V G D E Yo Zh Z I J K L M N O P R S T U F H Ts Ch Sh Sc I E Yu Ya";
    std::wostringstream  strm;
    getTranslittedText(text,strm);
    ASSERT_STREQ(expected, strm.str().c_str());
}


TEST(getTranslittedText, noTransliterationExpected) {
    const int N = 10;
    wchar_t text[N + 1] = L"ьъЬЪ";
    wchar_t expected[N + 1] = L"''''";
    std::wostringstream  strm;
    getTranslittedText(text,strm);
    ASSERT_STREQ(expected, strm.str().c_str());
}


TEST(getTranslittedText, clippedTransliterationExpected) {
    const int N = 7;
    wchar_t text[] = L"Привет!";
    wchar_t expected[N + 1] = L"Privet!";
    std::wostringstream  strm;
    getTranslittedText(text,strm);
    ASSERT_STREQ(expected, strm.str().c_str());
}


TEST(getTranslittedText, correctTransliterationExpected) {
    const int N = 100;
    wchar_t text[] = L"Съешь ещё этих мягких французских булок да выпей чаю!";
    wchar_t expected[N + 1] = L"S'esh' escyo etih myagkih frantsuzskih bulok da vipej chayu!";
    std::wostringstream  strm;
    getTranslittedText(text,strm);
    ASSERT_STREQ(expected, strm.str().c_str());
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}