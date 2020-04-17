// Copyright 2020 Zinkov Artem

#include <gtest/gtest.h>
#include <string>
#include "include/vigenere_cipher.h"

TEST(Vigenere_Cipher_Test, Encryption_With_Zero_Length_Key) {
    std::string text("skjdfkop");
    std::string key;

    ASSERT_ANY_THROW(Encrypt_Vigenere_Cipher(text, key));
}

TEST(Vigenere_Cipher_Test, Encryption_With_Zero_Length_Text) {
    std::string text;
    std::string key("abc");

    std::string res = Encrypt_Vigenere_Cipher(text, key);

    ASSERT_EQ(res, "");
}

TEST(Vigenere_Cipher_Test, Encryption_Uppercase_Text) {
    std::string text("AAAA");
    std::string key("bb");

    std::string res = Encrypt_Vigenere_Cipher(text, key);

    ASSERT_EQ(res, "BBBB");
}

TEST(Vigenere_Cipher_Test, Encryption_Uppercase_Key) {
    std::string text("kdokfs");
    std::string key("LSLFA");

    std::string res = Encrypt_Vigenere_Cipher(text, key);

    ASSERT_EQ(res, "vvzpfd");
}

TEST(Vigenere_Cipher_Test, Encryption_Uppercase_Key_And_Text) {
    std::string text("OSKOFOSKFPASD");
    std::string key("LSLFA");

    std::string res = Encrypt_Vigenere_Cipher(text, key);

    ASSERT_EQ(res, "ZKVTFZKVKPLKO");
}

TEST(Vigenere_Cipher_Test, Encryption_With_Different_Registers) {
    std::string text("skLSFspldfpsLFLDPLF");
    std::string key("sefsaLLFFsaggsd");

    std::string res = Encrypt_Vigenere_Cipher(text, key);

    ASSERT_EQ(res, "koQKFdaqixpyRXOVTQX");
}

TEST(Vigenere_Cipher_Test, Encryption_Text_Shorter_Key) {
    std::string text("f");
    std::string key("abc");

    std::string res = Encrypt_Vigenere_Cipher(text, key);

    ASSERT_EQ(res, "f");
}

TEST(Vigenere_Cipher_Test, Encryption_Key_Shorter_Text) {
    std::string text("sdkfasdaslfsl");
    std::string key("abc");

    std::string res = Encrypt_Vigenere_Cipher(text, key);

    ASSERT_EQ(res, "semfbudbulgul");
}

TEST(Vigenere_Cipher_Test, Encryption_Key_A) {
    std::string text("fsdfsgsdgassd");
    std::string key("aaaa");

    std::string res = Encrypt_Vigenere_Cipher(text, key);

    ASSERT_EQ(res, text);
}

TEST(Vigenere_Cipher_Test, Encryption_Key_Lenght_1) {
    std::string text("fsdfsgsdgassd");
    std::string key("g");

    std::string res = Encrypt_Vigenere_Cipher(text, key);

    ASSERT_EQ(res, "lyjlymyjmgyyj");
}

TEST(Vigenere_Cipher_Test, Decryption_With_Zero_Length_Key) {
    std::string text("oskokfkssokdf");
    std::string key;

    ASSERT_ANY_THROW(Decrypt_Vigenere_Cipher(text, key));
}

TEST(Vigenere_Cipher_Test, Decryption_With_Zero_Length_Text) {
    std::string text;
    std::string key("abc");

    std::string res = Decrypt_Vigenere_Cipher(text, key);

    ASSERT_EQ(res, "");
}

TEST(Vigenere_Cipher_Test, Decryption_Uppercase_Text) {
    std::string text("SKFOD");
    std::string key("fffsg");

    std::string res = Decrypt_Vigenere_Cipher(text, key);

    ASSERT_EQ(res, "NFAWX");
}

TEST(Vigenere_Cipher_Test, Decryption_Uppercase_Key) {
    std::string text("dfffdss");
    std::string key("PSLDFA");

    std::string res = Decrypt_Vigenere_Cipher(text, key);

    ASSERT_EQ(res, "onucysd");
}

TEST(Vigenere_Cipher_Test, Decryption_Uppercase_Key_And_Text) {
    std::string text("JSSOFKSFSJDIFJJAJISAFIJSIFJAIJSfiAJISJFA");
    std::string key("SIJFSJDFSF");

    std::string res = Decrypt_Vigenere_Cipher(text, key);

    ASSERT_EQ(res, "RKJJNBPAAELAWERRGDAVNAANQWGVQEAxzVRZPENV");
}

TEST(Vigenere_Cipher_Test, Decryption_With_Different_Registers) {
    std::string text("JSfsfsdfskdfkSDJFISJDFJjdif");
    std::string key("idfIDS");

    std::string res = Decrypt_Vigenere_Cipher(text, key);

    ASSERT_EQ(res, "BPakcavcncancPYBCQKGYXGrvfa");
}

TEST(Vigenere_Cipher_Test, Decryption_Text_Shorter_Key) {
    std::string text("f");
    std::string key("abc");

    std::string res = Decrypt_Vigenere_Cipher(text, key);

    ASSERT_EQ(res, "f");
}

TEST(Vigenere_Cipher_Test, Decryption_Key_Shorter_Text) {
    std::string text("sdkfasdaslfsl");
    std::string key("dogony");

    std::string res = Decrypt_Vigenere_Cipher(text, key);

    ASSERT_EQ(res, "ppernuammxsui");
}

TEST(Vigenere_Cipher_Test, Decryption_Key_A) {
    std::string text("ksoekfksesd");
    std::string key("aaaa");

    std::string res = Decrypt_Vigenere_Cipher(text, key);

    ASSERT_EQ(res, text);
}

TEST(Vigenere_Cipher_Test, Decryption_Key_Lenght_1) {
    std::string text("sleoasldalfapFLS");
    std::string key("h");

    std::string res = Decrypt_Vigenere_Cipher(text, key);

    ASSERT_EQ(res, "lexhtlewteytiYEL");
}

TEST(Vigenere_Cipher_Test, Encryption_and_Decryption_Text) {
    std::string text("skefsejsiejfsefksfsekdjfsdfopakfs");
    std::string key("bbgekaksokdaw");

    std::string res = Encrypt_Vigenere_Cipher(text, key);
    res = Decrypt_Vigenere_Cipher(res, key);

    ASSERT_EQ(res, text);
}
