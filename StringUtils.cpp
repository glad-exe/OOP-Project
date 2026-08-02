
#include "StringUtils.h"

char* copyString(const char* original){
    if(!original) original = "";
    int len = 0;
    while(original[len] != '\0') len++;

    char* temp = new char[len + 1];
    for(int i = 0; i < len; i++) temp[i] = original[i];

    temp[len] = '\0';
    return temp;
}
