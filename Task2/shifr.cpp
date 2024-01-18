#include "shifr.h"
#include <locale>
#include <codecvt>
Marshrut::Marshrut(const int &skey)
{
    this->key = skey;
}
string Marshrut::encrypt(const string &open_text)
{
    setlocale(LC_ALL, "Russian");
    locale loc("ru_RU.UTF-8");
    wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
    wstring op = codec.from_bytes(open_text);
    int LENGTH = op.size();
    if (key>LENGTH/2) {
        throw std::invalid_argument("Ключ превышает половину длины сообщения");
    }
    wchar_t ch[LENGTH+1];
    int KEY = key-1;
    int k = 0;
    int i = 0;
    while(KEY>=0) {
        k = KEY;
        while(k<LENGTH) {
            if(k + key > LENGTH) {
                break;
            }
            k = k + key;
        }
        while(k>=0) {
            if(k!= LENGTH) {
                ch[i] = op[k];
                i++;
            }
            k = k - key;
        }
        KEY--;
    }
    ch[LENGTH] = '\0';
    op = wstring(ch);
    string str = codec.to_bytes(op);
    return str;
}
string Marshrut::decrypt(const string &open_text)
{
    setlocale(LC_ALL, "Russian");
    locale loc("ru_RU.UTF-8");
    wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
    wstring op = codec.from_bytes(open_text);
    int LENGTH = op.size();
    if (key>LENGTH/2) {
        throw std::invalid_argument("Ключ превышает половину длины сообщения");
    }
    wchar_t ch [LENGTH+1];
    int KEY = LENGTH-1;
    int k = 0, y = 0;
    int cl = 1;
    k = KEY;
    int Div = (KEY)/key+(((KEY)%key)>0);
    while (KEY>=0 && cl < LENGTH){
        k = KEY;
        while (k>=0){
            ch[y] = op[k];
            y++;
            k = k - Div;
            cl++;
        }
        KEY--;
    }
    ch[LENGTH] = '\0';
    op = wstring(ch);
    string str = codec.to_bytes(op);
    return str;
}