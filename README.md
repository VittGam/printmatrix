# printmatrix by VittGam

A C / C++ function to print matrices as tables.

## Usage

Just include the header at the beginning of your C / C++ code:

    #include "printmatrix.h"

The parameters are:

    - void *matrix     -> pointer to the matrix
    - int sizeofelm    -> size of a single element
    - char *formatstr  -> a printf format string that defines how to print a single cell
    - int rows         -> the number of rows of the resulting table
    - int cols         -> the number of columns of the resulting table
    - int bordercolor  -> (optional) the color used to print the borders of the table
    - int elementcolor -> (optional) the color used to print the elements of the table

The bordercolor and elementcolor arguments are optional and can be omitted.

The bordercolor and elementcolor arguments are ignored if colorprintf.h is not included.

Return value is negative for errors, the length of the printed columns otherwise.

The table can be colored if colorprintf.h is included _before_ printmatrix.h:

    color = -1 -> not colored
             0 -> red
             1 -> green
             2 -> yellow
             3 -> blue
             4 -> magenta
             5 -> cyan

You can get the colorprintf.h header from [the colorprintf repo](https://github.com/VittGam/colorprintf).

Please look at the example file to learn how to use printmatrix in various cases.

## License

Copyright (C) 2013 VittGam.net. All Rights Reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

