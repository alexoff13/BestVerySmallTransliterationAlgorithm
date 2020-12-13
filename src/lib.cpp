#include <iostream>
#include <map>
#include "lib.h"
std::map <wchar_t, char*> book = {
    {L'а', "a"}, {L'б', "b"}, {L'в', "v"}, {L'г', "g"}, {L'д', "d"}, {L'е', "e"},
    {L'ж', "zh"},{L'ё', "yo"},{L'з', "z"}, {L'и', "i"}, {L'й', "j"}, {L'к', "k"},
    {L'л', "l"}, {L'м', "m"}, {L'н', "n"}, {L'о', "o"}, {L'п', "p"}, {L'р', "r"},
    {L'с', "s"}, {L'т', "t"}, {L'у', "u"}, {L'ф', "f"}, {L'х', "h"}, {L'ц', "ts"},
    {L'ч', "ch"},{L'ш', "sh"},{L'щ', "sc"},{L'ъ', "'"}, {L'ы', "i"}, {L'ь', "'"},
    {L'э', "e"}, {L'ю', "yu"},{L'я', "ya"},{L'А', "A"}, {L'Б', "B"}, {L'В', "V"},
    {L'Г', "G"}, {L'Д', "D"}, {L'Е', "E"}, {L'Ё', "Yo"},{L'Ж', "Zh"},{L'З', "Z"},
    {L'И', "I"}, {L'Й', "J"}, {L'К', "K"}, {L'Л', "L"}, {L'М', "M"}, {L'Н', "N"},
    {L'О', "O"}, {L'П', "P"}, {L'Р', "R"}, {L'С', "S"}, {L'Т', "T"}, {L'У', "U"},
    {L'Ф', "F"}, {L'Х', "H"}, {L'Ц', "Ts"},{L'Ч', "Ch"},{L'Ш', "Sh"},{L'Щ', "Sc"},
    {L'Ъ', "'"}, {L'Ы', "I"}, {L'Ь', "'"}, {L'Э', "E"}, {L'Ю', "Yu"},{L'Я', "Ya"},
};

void getTranslittedText(wchar_t text[MAX_LENGTH+1],std::wostream& out) {
    std::map <wchar_t, char*> ::iterator it;
    for (int textIndex=0; textIndex< MAX_LENGTH+1;++textIndex) {
        it = book.find(text[textIndex]);
        it != book.end() ? out<<it->second : out<<text[textIndex];
    }
}