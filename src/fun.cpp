// Copyright 2022 UNN-IASR
#include <math.h>
#include <iostream>
#include <cctype>
#include "fun.h"

unsigned int faStr1(const char* str) {
int inw = 0;
int iterator = 0;
int count = 0;
while (*(str + iterator)) {
if (*(str + iterator) != ' '
&& !isdigit(*(str + iterator)) && !finWord(inw)) {
count = count + 1;
inw = 1;}
else if (*(str + iterator) == ' '
&& finWord(inw)) inw = 0;
else if (isdigit(*(str + iterator))
&& inw == 0) inw = 2;
else
if (isdigit(*(str + iterator)) && inw == 1) {
inw = 2;
count = count - 1;}
iterator = iterator + 1;
}
return count;
}
unsigned int faStr2(const char* str) {
int count = 0;
int inw = 0;
int iterator = 0;
while (*(str + iterator)) {
if (isupper(*(str + iterator)) && inw == 0) {
count++;
inw = 1;}
else if (!mylower(*(str + iterator))
&& !finWord(inw)) inw = 2;
else if (*(str + iterator) == ' '
&& finWord(inw)) inw = 0;
else
if (!mylower(*(str + iterator)) && inw == 1) {
inw = 2;
count = count - 1;}
iterator = iterator + 1;
}
return count;
}
unsigned int faStr3(const char* str) {
int count = 0;
int sum = 0;
bool inw = false;
int iterator = 0;
while (*(str + iterator)) {
if (*(str + iterator) != ' ' && inw == false) {
count = count + 1;
inw = true;
} else if (*(str + iterator) == ' ' && inw == true) {
inw = false;}
if (inw == true)
sum = sum + 1;
iterator = iterator + 1;
}
count = round(static_cast<double>(sum) / static_cast<double>(count));
return count;
}
int inword(int inw) {
if (inw == 0)
return 0;
else
return 1;
}
int mylower(char str) {
if (static_cast<int>(str) < 96 || static_cast<int>(str) > 123)
return 0;
else
return 1;
}
