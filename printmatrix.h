/****************************************************************************
 * printmatrix v2.1                                                         *
 * Copyright (C) 2012 VittGam.net. All Rights Reserved.                     *
 * https://github.com/VittGam/printmatrix                                   *
 ****************************************************************************
 * Permission is hereby granted, free of charge, to any person obtaining a  *
 * copy of this software and associated documentation files (the            *
 * "Software"), to deal in the Software without restriction, including      *
 * without limitation the rights to use, copy, modify, merge, publish,      *
 * distribute, sublicense, and/or sell copies of the Software, and to       *
 * permit persons to whom the Software is furnished to do so, subject to    *
 * the following conditions:                                                *
 *                                                                          *
 * The above copyright notice and this permission notice shall be included  *
 * in all copies or substantial portions of the Software.                   *
 *                                                                          *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY     *
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,     *
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE        *
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                   *
 ****************************************************************************
 * If you want a colored output, you can get the colorprintf.h header from  *
 * https://github.com/VittGam/colorprintf .                                 *
 ****************************************************************************/

#ifndef PRINTMATRIX_H_
#define PRINTMATRIX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*
 * Prints a matrix as a table.
 *
 * The parameters are:
 * - void *matrix     -> pointer to the matrix
 * - int sizeofelm    -> size of a single element
 * - char *formatstr  -> a printf format string that defines how to print a single cell
 * - int rows         -> the number of rows of the resulting table
 * - int cols         -> the number of columns of the resulting table
 * - int bordercolor  -> (optional) the color used to print the borders of the table
 * - int elementcolor -> (optional) the color used to print the elements of the table
 *
 * The bordercolor and elementcolor arguments are optional and can be omitted.
 *
 * The bordercolor and elementcolor arguments are ignored if colorprintf.h is not included.
 *
 * Return value is negative for errors, the length of the printed columns otherwise.
 *
 * The table can be colored if colorprintf.h is included _before_ printmatrix.h:
 * color = -1 -> not colored
 *          0 -> red
 *          1 -> green
 *          2 -> yellow
 *          3 -> blue
 *          4 -> magenta
 *          5 -> cyan
 */
#ifndef COLORPRINTF_H_
int printmatrix(void *matrix, int sizeofelm, const char *formatstr, int rows, int cols, ...) {
#define colorprintf(color, ...) printf(__VA_ARGS__)
#else
int printmatrix(int argc, void *matrix, int sizeofelm, const char *formatstr, int rows, int cols, ...) {
#define PRINTMATRIX_H_NUMARGS_VS_WORKAROUND(x) x
#define PRINTMATRIX_H_NUMARGS(...) PRINTMATRIX_H_NUMARGS_VS_WORKAROUND(PRINTMATRIX_H_NUMARGS_IMPL(__VA_ARGS__,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0))
#define PRINTMATRIX_H_NUMARGS_IMPL(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,N,...) N
#define printmatrix(...) printmatrix(PRINTMATRIX_H_NUMARGS(__VA_ARGS__), __VA_ARGS__)
#endif
	int i, j, k, l, len = 1;
#ifdef COLORPRINTF_H_
	int bordercolor = -1, elementcolor = -1;
#endif
	if (rows <= 0 || cols <= 0) {
		return 0;
	}
	if (matrix == NULL || formatstr == NULL || sizeofelm <= 0) {
		return -99;
	}
#ifdef COLORPRINTF_H_
	if (argc >= 7) {
		va_list ap;
		va_start(ap, cols);
		bordercolor = va_arg(ap, int);
		elementcolor = va_arg(ap, int);
		va_end(ap);
	}
#endif
#define CURRENT_MATRIX_ELEMENT *((char **)matrix + (sizeofelm * ((i * cols) + j)))
	for (i = 0; i < rows; i++) for (j = 0; j < cols; j++) {
		int tmp = snprintf(NULL, 0, formatstr, CURRENT_MATRIX_ELEMENT);
		if (tmp < 0) {
			return -99;
		}
		if (tmp > len) len = tmp;
	}
	colorprintf(bordercolor, "+");
	for (k = 0; k < cols; k++) {
		for (l = 0; l < len + 2; l++) colorprintf(bordercolor, "-");
		colorprintf(bordercolor, "+");
	}
	printf("\n");
	char *tmpbuf = (char *) calloc(len + 1, sizeof(char));
	if (tmpbuf == NULL) {
		return -99;
	}
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			colorprintf(bordercolor, "|");
			printf(" ");
			snprintf(tmpbuf, len + 1, formatstr, CURRENT_MATRIX_ELEMENT);
			colorprintf(elementcolor, "%*s", len, tmpbuf);
			printf(" ");
		}
		colorprintf(bordercolor, "|\n+");
		for (k = 0; k < cols; k++) {
			for (l = 0; l < len + 2; l++) colorprintf(bordercolor, "-");
			colorprintf(bordercolor, "+");
		}
		printf("\n");
	}
	free(tmpbuf);
	return (1 + ((len + 3) * cols));
#undef CURRENT_MATRIX_ELEMENT
#ifndef COLORPRINTF_H_
#undef colorprintf
#endif
}

#ifdef __cplusplus
}
#endif

#endif
