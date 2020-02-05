#ifndef EDIT_DIST_LTE1
#define EDIT_DIST_LTE1

#ifndef size_t
#  include <stdlib.h>
#endif

/* In C, this is just wchar_t and unsigned char, in Python, lev_wchar can
 * be anything.  If you really want to cheat, define wchar_t to any integer
 * type you like before including Levenshtein.h and recompile it. */
#ifndef lev_wchar
#  ifndef wchar_t
#    include <wchar.h>
#  endif
#  define lev_wchar wchar_t
#endif
typedef unsigned char lev_byte;

static
size_t
lev_u_edit_distance(size_t len1,
                    const lev_wchar *string1,
                    size_t len2,
                    const lev_wchar *string2);



#endif /* not EDIT_DIST_LTE1 */