#ifndef STRINGUTILS_H
#define STRINGUTILS_H

char* copyString(const char* original);         //moved from being copied in every file, to this.
bool sameText(const char* a, const char* b);    // made for inventory, migrated here
#endif