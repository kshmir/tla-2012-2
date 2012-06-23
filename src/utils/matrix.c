/*
 *  matrix.c
 *  TLA-2011
 *
 *  Created by Luciana Reznik on 23/07/2012
 *  Copyright 2012 My Own. All rights reserved.
 *
 */

#include "matrix.h"

#include "../includes.h"
#include "./list.h"

#include <stdlib.h>
#include <stdio.h>

struct  matrix{
	list data;
	int Xsize;
	int Ysize;
};


// Inits the matrix
matrix matrix_init(int x, int y) {
	matrix ret = (matrix) malloc(sizeof(struct matrix));
	ret->Xsize = x;
	ret->Ysize = y;
	ret->data = list_init();

	for(int i=0;i<x;i++){

		list_add(ret->data,list_init());
	}


	return ret;
}

// Adds the pointer to the matrix in the position x, y.
int matrix_add(matrix m, void * obj,int x, int y) {

	if (m == NULL) {
		return -1;
	}

	if(x>m->Xsize || y>m->Ysize){
	return -1;
	}

	list l=list_get(m->data,x);
	list_insert(l,y,obj);

	return 1;
}

// Gets the pointer from a given x, y indexes
void *  matrix_get(matrix m, int x, int y) {

	if (m == NULL) {
		return NULL;
	}

	return list_get(list_get(m->data,x),y);

}


// Removes an item form selected x, y coord.
int matrix_remove(matrix m, int Xindex, int Yindex) {

	if (Xindex < 0 || Yindex < 0 || m == NULL || Xindex >= m->Xsize || Yindex >= m->Ysize) {
		return -1;
	}

	list l=list_get(m->data,Xindex);
	list_remove(l,Yindex);

	return 1;
}


// Free's up the matrix
void matrix_free(matrix m) {


	for(int i=0;i<m->Xsize;i++){

			list to_free=list_get(m->data,i);
			list_free(to_free);
	}

	list_free(m->data);

}


int matrix_Xsize(matrix m) {
	int size = m->Xsize;
	return size;
}


int matrix_Ysize(matrix m) {
	int size = m->Ysize;
	return size;
}

