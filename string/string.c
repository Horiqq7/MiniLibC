// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char *p = destination;
	while (*source != '\0') {
		*p = *source;
		p++;
		source++;
	}
	*p = *source;
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *p = destination;
	size_t length = 0;
	while ((length < len) && (*source != '\0')) {
		*p = *source;
		p++;
		source++;
		length++;
	}
	*p = *source;
	return destination;
}

char *strcat(char *destination, const char *source)
{
	char *original_destination = destination;
	while (*destination != '\0') {
		destination++;
	}
	while (*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return original_destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *original_destination = destination;
	while (*destination != '\0') {
		destination++;
	}
	size_t length = 0;
	while ((length < len) && (*source != '\0')) {
		*destination = *source;
		destination++;
		source++;
		length++;
	}
	*destination = '\0';
	return original_destination;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 != *str2) {
			if (*str1 < *str2)
				return -1;
			else
				return 1;
		}
		str1++;
		str2++;
	}
    if (*str1 == '\0' && *str2 != '\0') {
        return -1;
    } else if (*str1 != '\0' && *str2 == '\0') {
        return 1;
    }
    return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	size_t length = 0;
	while (*str1 != '\0' && *str2 != '\0' && length < len) {
		if (*str1 != *str2) {
			if (*str1 < *str2)
				return -1;
			else
				return 1;
		}
		str1++;
		str2++;
		length++;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;
	while (*str != '\0') {
		str++;
		i++;
	}
	return i;
}

char *strchr(const char *str, int c)
{
	char *p = str;
	while (*p != '\0') {
		if (*p == c)
			return p;
		p++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	char *p = str;
	char *last = NULL;
	while (*p != '\0') {
		if (*p == c)
			last = p;
		p++;
	}
	if (last != NULL)
		return last;
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	while (*haystack != '\0') {
		char *h = haystack;
		char *s = haystack;
		char *n = needle;
		while ((*h != '\0') && (*n != '\0') && (*h == *n)) {
			h++;
			n++;
		}
		if (*n == '\0')
			return s;
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	char *last = NULL;
	while (*haystack != '\0') {
		char *h = haystack;
		char *s = haystack;
		char *n = needle;
		while ((*h != '\0') && (*n != '\0') && (*h == *n)) {
			h++;
			n++;
		}
		if (*n == '\0')
			last = s;
		haystack++;
	}
	if (last != NULL)
		return last;
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *dest = destination;
    char *src = source;
    for (size_t i = 0; i < num; i++) {
        dest[i] = src[i];
    }
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
    char *dest = destination;
    const char *src = source;
    if (dest == src || num == 0) {
        return destination;
    }
    if (dest < src) {
        for (size_t i = 0; i < num; i++) {
            dest[i] = src[i];
        }
    } else {
        for (size_t i = 0; i < num; i++) {
    		dest[num - 1 - i] = src[num - 1 - i];
		}
    }
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	char *p1 = ptr1;
    char *p2 = ptr2;
    for (size_t i = 0; i < num; i++) {
        if (p1[i] < p2[i]) {
            return -1;
        } else if (p1[i] > p2[i]) {
            return 1;
        }
    }
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char *p = source;
    for (size_t i = 0; i < num; i++) {
        p[i] = value;
    }
    return source;
}
