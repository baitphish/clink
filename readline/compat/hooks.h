// Copyright (c) 2012 Martin Ridgers
// License: http://opensource.org/licenses/MIT

#pragma once

#if !defined(S_IFLNK)
# if defined(__cplusplus) || defined(_MSC_VER)
static_assert((_S_IFMT & ~0xF000) == 0, "_S_IFMT has bits outside 0xF000");
static_assert(_S_IFMT == S_IFMT, "_S_IFMT is not equal to S_IFMT");
# else
_Static_assert((_S_IFMT & ~0xF000) == 0, "_S_IFMT has bits outside 0xF000");
_Static_assert(_S_IFMT == S_IFMT, "_S_IFMT is not equal to S_IFMT");
# endif
# define _S_IFLNK       0x0800
# define S_IFLNK        _S_IFLNK
# undef S_ISLNK
# define S_ISLNK(m)	    (((m)&S_IFLNK) == S_IFLNK)
#endif

#undef S_IRUSR
#undef S_IWUSR
#undef S_IXUSR
#define S_IRUSR         (S_IREAD)       /* read, owner */
#define S_IWUSR         (S_IWRITE)      /* write, owner */
#define S_IXUSR         (S_IEXEC)       /* execute, owner */

#undef S_IRGRP
#undef S_IWGRP
#undef S_IXGRP
#define S_IRGRP         (0)             /* read, group */
#define S_IWGRP         (0)             /* write, group */
#define S_IXGRP         (0)             /* execute, group */

#undef S_IROTH
#undef S_IWOTH
#undef S_IXOTH
#define S_IROTH         (0)             /* read, other */
#define S_IWOTH         (0)             /* write, other */
#define S_IXOTH         (0)             /* execute, other */

struct hooked_stat
{
    __int64 st_size;
    int st_mode;
    short st_uid;
    short st_gid;
    short st_nlink;                     /* Always 1 in MSVC */
};

void end_prompt(int crlf);

// These are implemented in matches_lookaside.cpp.
extern int lookup_match_type(const char* match);
extern unsigned char lookup_match_flags(const char* match);
extern const char* lookup_match_display(const char* match);
extern const char* lookup_match_description(const char* match);
