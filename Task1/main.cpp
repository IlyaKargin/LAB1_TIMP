#include <iostream>
#include "modAlphaCipher.h"
#include <locale>
#include <cwctype>
using namespace std;
void check(const wstring& Text, const wstring& key)
{
    wstring cipherText;
    wstring decryptedText;
    modAlphaCipher cipher(key);
    cipherText = cipher.encrypt(Text);
    decryptedText = cipher.decrypt(cipherText);
    wcout<<"key="<<key<<endl;
    wcout<<Text<<endl;
    wcout<<cipherText<<endl;
    wcout<<decryptedText<<endl;
    if (Text == decryptedText)
        cout<<"Ok\n";
    else
        cout<<"Err\n";
}
int main(int argc, char **argv)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    check(L"КАРГИН",L"ПРОСТОЙ");
    check(L"ИЛЬЯ",L"ПРИМЕР");
    check(L"СЕРГЕЕВИЧ",L"АБЦД");
    return 0;
}