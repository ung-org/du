/*
 * UNG's Not GNU
 *
 * Copyright (c) 2011-2017, Jakob Kaivo <jkk@ung.org>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */

#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

static int du(const char *path, int blocksize)
{
	if (path == NULL) {
		path = ".";
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int blocksize = 512;

	int c;
	while ((c = getopt(argc, argv, "askxHL")) != -1) {
		switch (c) {
		case 'a':	/** report all files **/
			break;

		case 'H':	/** dereference symlinks on command line **/
			break;

		case 'k':	/** report in 1024-byte units **/
			blocksize = 1024;
			break;

		case 'L':	/** follow symlinks while recursing **/
			break;

		case 's':	/** summarize total usage **/
			break;

		case 'x':	/** do not cross file systems **/
			break;

		default:
			return 1;
		}
	}

	int r = 0;
	do {
		r |= du(argv[optind++], blocksize);
	} while (optind < argc);

	return r;
}
