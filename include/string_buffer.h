/*
  Copyright (C) 2006, 2009, 2010  Novell, Inc.
  Copyright (C) 2015  Red Hat, Inc.
  Written by Andreas Gruenbacher <agruenba@redhat.com>

  The richacl library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public License as
  published by the Free Software Foundation; either version 2.1 of the
  License, or (at your option) any later version.

  The richacl library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, see
  <http://www.gnu.org/licenses/>.
*/

#ifndef __STRING_BUFFER_H
#define __STRING_BUFFER_H

#include <sys/types.h>

/* A resizeable string buffer */
struct string_buffer {
	char *buffer;
	size_t offset;
	size_t size;
};

extern struct string_buffer *alloc_string_buffer(size_t size);
extern void reset_string_buffer(struct string_buffer *);
extern void free_string_buffer(struct string_buffer *);
extern char *buffer_sprintf(struct string_buffer *, const char *, ...)
	__attribute__((format (printf, 2, 3)));

static inline int string_buffer_okay(const struct string_buffer *buffer)
{
	return !!buffer->buffer;
}

#endif  /* __STRING_BUFFER_H */
