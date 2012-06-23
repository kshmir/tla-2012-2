/*
 *  matrix.h
 *  TLA-2012
 *
 *  Created by Luciana Reznik on 23/07/12.
 *  Copyright 2012 My Own. All rights reserved.
 *
 */

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "../includes.h"

// Inits the matrix
matrix matrix_init(int x, int y);
// Adds the pointer to the matrix in the position x, y.
int matrix_add(matrix m, void * obj,int x, int y);
// Gets the pointer from a given x, y indexes
void *  matrix_get(matrix m, int x, int y);
// Removes an item form selected x, y coord
int matrix_remove(matrix m, int Xindex, int Yindex);
// Free's up the matrix
void matrix_free(matrix m);

int matrix_Xsize(matrix m);
int matrix_Ysize(matrix m);

#endif
