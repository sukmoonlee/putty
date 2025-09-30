/*
 * Work around lack of wmemchr in older MSVC libraries.
 */

#include <wchar.h>

#include "defs.h"

#if !defined(_MSC_VER) || _MSC_VER < 1400  // Visual Studio 2005
wchar_t *wmemchr(const wchar_t *s, wchar_t c, size_t n)
{
    for (; n != 0; s++, n--)
        if (*s == c)
            return (wchar_t *)s;
    return NULL;
}
#endif
