/****************************************************************************
 * printmatrix v2.0 example                                                 *
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
 * Note that printmatrix works without colorprintf.h too; but if you want a *
 * colored output, you can get it from [1]. See the colorprintf.h file for  *
 * a list of the available colors.                                          *
 *                                                                          *
 * [1]: https://github.com/VittGam/colorprintf                              *
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* #include "colorprintf.h" */
#include "printmatrix.h"

int main() {
	int i, j;

	printf("Matrix of integers (array of arrays of ints)\n");
	int intmatrix[3][5];
	for (i = 0; i < 3; i++) for (j = 0; j < 5; j++) intmatrix[i][j] = (i * 5) + j + 1;
	printmatrix(intmatrix, sizeof(**intmatrix), "%d", 3, 5, 5, 1);
	/* Note the double star in the sizeof (**), that's because we need the size of one pointer, not the size of an array of pointers. */

	printf("\n");

	printf("Dynamically allocated matrix of integers (array of ints)\n");
	int *dynintmatrix = calloc(3 * 5, sizeof(int));
	for (i = 0; i < 3 * 5; i++) dynintmatrix[i] = i + 1;
	printmatrix(dynintmatrix, sizeof(*dynintmatrix), "%d", 3, 5, 5, 1);
	free(dynintmatrix);

	printf("\n");

	printf("Array of integers (array of ints)\n");
	int intarray[3 * 5];
	for (i = 0; i < 3 * 5; i++) intarray[i] = i + 1;
	printmatrix(intarray, sizeof(*intarray), "%d", 3, 5, 5, 1);

	printf("\n");

	printf("String (array of chars)\n");
	char string[3 * 5] = "abcdefghijklmno";
	printmatrix(string, sizeof(*string), "%c", 3, 5, 5, 1);
	/* Note how %c is used, that's because every char is taken separately. */

	printf("\n");

	printf("Array of strings (array of pointers to arrays of chars)\n");
	char *stringarray[3 * 5]={"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii", "jj", "kk", "ll", "mm", "nn", "oo"};
	printmatrix(stringarray, sizeof(*stringarray), "%s", 3, 5, 5, 1);

	printf("\n");

	printf("Matrix of strings (array of arrays of pointers to arrays of chars)\n");
	char *stringmatrix[3][5] = {
		{"aa", "bb", "cc", "dd", "ee"},
		{"ff", "gg", "hh", "ii", "jj"},
		{"kk", "ll", "mm", "nn", "oo"},
	};
	printmatrix(stringmatrix, sizeof(**stringmatrix), "%s", 3, 5, 5, 1);
	/* Note the double star in the sizeof (**), that's because we need the size of one pointer, not the size of an array of pointers. */

	printf("\n");

#ifdef _WIN32
	system("pause");
#endif
	return 0;
}

