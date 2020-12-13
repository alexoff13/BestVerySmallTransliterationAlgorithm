#include <iostream>
#include "src/lib.h"

int main() {
    setlocale(LC_CTYPE, "");
    std::wcout << L"Enter text: ";
    wchar_t text[MAX_LENGTH + 1]{};
    std::wcin.getline(text,MAX_LENGTH+1);
    getTranslittedText(text,std::wcout);
}