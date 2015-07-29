/*
 *   stunnel       Universal SSL tunnel
 *   Copyright (C) 1998-2011 Michal Trojnara <Michal.Trojnara@mirt.net>
 *
 *   This program is free software; you can redistribute it and/or modify it
 *   under the terms of the GNU General Public License as published by the
 *   Free Software Foundation; either version 2 of the License, or (at your
 *   option) any later version.
 * 
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *   See the GNU General Public License for more details.
 * 
 *   You should have received a copy of the GNU General Public License along
 *   with this program; if not, see <http://www.gnu.org/licenses>.
 * 
 *   Linking stunnel statically or dynamically with other modules is making
 *   a combined work based on stunnel. Thus, the terms and conditions of
 *   the GNU General Public License cover the whole combination.
 * 
 *   In addition, as a special exception, the copyright holder of stunnel
 *   gives you permission to combine stunnel with free software programs or
 *   libraries that are released under the GNU LGPL and with code included
 *   in the standard release of OpenSSL under the OpenSSL License (or
 *   modified versions of such code, with unchanged license). You may copy
 *   and distribute such a system following the terms of the GNU GPL for
 *   stunnel and the licenses of the other code concerned.
 * 
 *   Note that people who make modified versions of stunnel are not obligated
 *   to grant this special exception for their modified versions; it is their
 *   choice whether to do so. The GNU General Public License gives permission
 *   to release a modified version without this exception; this exception
 *   also makes it possible to release a modified version which carries
 *   forward this exception.
 */

#ifndef VERSION_MAJOR

/* START CUSTOMIZE */
#define VERSION_MAJOR 4
#define VERSION_MINOR 43
/* END CUSTOMIZE */

/* all the following macros are ABSOLUTELY NECESSARY to have proper string
   construction with VARIOUS C preprocessors (EVC, VC, BCC, GCC) */
#define STRINGIZE0(x) #x
#define STRINGIZE(x) STRINGIZE0(x)
#define STRZCONCAT30(a,b,c) a##b##c
#define STRZCONCAT3(a,b,c) STRZCONCAT30(a,b,c)
 
/* for resource.rc, stunnel.c, gui.c */
#define STUNNEL_VERSION0 STRZCONCAT3(VERSION_MAJOR, . , VERSION_MINOR)
#define STUNNEL_VERSION STRINGIZE(STUNNEL_VERSION0)

/* HOST may be undefined on Win32 platform */
#ifndef HOST
#ifdef __MINGW32__
#define HOST "x86-pc-mingw32-gnu"
#else /* __MINGW32__ */
#ifdef _MSC_VER
#define _QUOTEME(x) #x
#define QUOTEME(x) _QUOTEME(x)
#define HOST "x86-pc-msvc-" ## QUOTEME(_MSC_VER)
#else /* _MSC_VER */
#define HOST "x86-pc-unknown"
#endif /* _MSC_VER */
#endif /* __MINGW32__ */
#endif /* !HOST */

/* for resources.rc */
#define STUNNEL_VERSION_FIELDS VERSION_MAJOR,VERSION_MINOR,0,0
#define STUNNEL_PRODUCTNAME "stunnel " STUNNEL_VERSION " for " HOST

/* some useful tricks for preprocessing debugging */
#if 0
#pragma message ( "VERSION.H: STUNNEL_VERSION is " STUNNEL_VERSION )
#pragma message ( "VERSION.H: HOST is " HOST )
#pragma message ( "VERSION.H: STUNNEL_PRODUCTNAME is " STUNNEL_PRODUCTNAME )
#endif

#endif

/* end of version.h */