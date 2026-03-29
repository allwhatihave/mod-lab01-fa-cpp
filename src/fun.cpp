// Copyright 2026 UNN-IASR
#include <cctype>
#include <cmath>
#include "fun.h"

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            if (!inWord) {
                inWord = true;
                hasDigit = false;
            }
            if (isdigit(static_cast<unsigned char>(str[i]))) {
                hasDigit = true;
            }
        } else {
            if (inWord) {
                if (!hasDigit) count++;
                inWord = false;
            }
        }
    }
    if (inWord && !hasDigit) count++;
    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool isValid = true;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            if (!inWord) {
                inWord = true;
                isValid = (str[i] >= 'A' && str[i] <= 'Z');
            } else if (isValid) {
                if (!(str[i] >= 'a' && str[i] <= 'z')) isValid = false;
            }
        } else {
            if (inWord) {
                if (isValid) count++;
                inWord = false;
            }
        }
    }
    if (inWord && isValid) count++;
    return count;
}

unsigned int faStr3(const char *str) {
    double totalLen = 0;
    unsigned int wordCount = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            if (!inWord) {
                inWord = true;
                wordCount++;
            }
            totalLen++;
        } else {
            inWord = false;
        }
    }

    if (wordCount == 0) return 0;
    return static_cast<unsigned int>(round(totalLen / wordCount));
}
