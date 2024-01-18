#pragma once
#include <string>
using namespace std;
class Marshrut
{
public:
    Marshrut(const int &skey);
    string encrypt(const string &open_text);
    string decrypt(const string &cipher_text);
    Marshrut()=delete;
private:
    int key;
};