// Copyright 2022 UNN-IASR
#include "fun.h"
#include <ctype.h>
#include <stdbool.h>

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
            if (isdigit(str[i])) {
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
    int wordLen = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            if (!inWord) {
                inWord = true;
                wordLen = 1;
                isValid = (str[i] >= 'A' && str[i] <= 'Z');
            } else {
                wordLen++;
                if (!(str[i] >= 'a' && str[i] <= 'z')) {
                    isValid = false;
                }
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
    float totalLen = 0;
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
    return (unsigned int)(totalLen / wordCount + 0.5f);
}
