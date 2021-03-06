/**
 *  SISTEMAS OPERATIVOS - ITBA - 2011  
 *	ALUMNOS:                         
 *		MARSEILLAN 
 *		PEREYRA
 *		VIDELA
 * -----------------------------------
 *
 * @file includes.h
 *
 * @brief Provides functions and definitions shared across all the programs.
 *
 * @author Agustin Marseillan
 * @author Maximo Videla
 * @author Cristian Pereyra
 *
 */
#include <stdio.h>
#include <ftw.h>
#include <unistd.h>

#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#define	SOCKET_DEBUG 0
#define	SMEM_DEBUG 0
#define	MSGQ_DEBUG 0
#define	PIPE_DEBUG 0

#define READ 0x01
#define	WRITE	0x02

#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>

/**
 * Used to print coloured console
 */
typedef enum {
	NEGRO        ,
	ROJO         ,
	VERDE        ,
	MARRON       ,
	AZUL         ,
	VIOLETA      ,
	CELESTE      ,
	GRIS_CLARO   ,
	GRIS         ,
	ROSA         ,
	VERDE_CLARO  ,
	AMARILLO     ,
	AZUL_CLARO   ,
	VIOLETA_CLARO,
	CELESTE_CLARO,
	BLANCO
	
} color;

/**
 * Used to print coloured console
 */
typedef enum {
	CLEAR        ,
	NONE         ,
	
	NEGRITA      ,
	SUBRAYADO    ,
	BLINK        ,
	INVERTIDO    ,
	
	NO_NEGRITA   ,
	NO_SUBRAYADO ,
	NO_BLINK     ,
	NO_INVERTIDO
	
} attr;

/**
 * Default comparer
 */
typedef int (*comparer)(void *, void *);

/**
 * Useful for debugging
 */
typedef void (*printer)(void *);

/**
 * Generic function for cloning stuff.
 */
typedef void * (*cloner)(void *);

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )


/**
 * Compares two pointers
 *
 * @param int1 first pointer
 * @param int2 second pointer 
 *
 * @return Comparison
 */
int pointer_comparer(void * int1, void * int2);

/**
 * Compares two integers
 *
 * @param int1 first integer
 * @param int2 second integer
 *
 * @return Comparison
 */
int int_comparer(void * int1, void * int2);

/**
 * Compares two doubles
 *
 * @param double1 first double
 * @param double2 second double
 *
 * @return Comparison
 */
int double_comparer(void * double1, void * double2);

/**
 * Compares two strings
 *
 * @param s1 first char *
 * @param s2 second char *
 *
 * @return Comparison
 */
int cstring_comparer(void * s1, void * s2);

/**
 * Prints an integer.
 *
 * @param int1 integer to print.
 */
void int_printer(void * int1);

/**
 * Prints a double.
 *
 * @param double1 double to print.
 */
void double_printer(void * double1);

/**
 * Prints a string.
 *
 * @param s1 string to print.
 */
void cstring_printer(void * s1);

/**
 * Clones an integer.
 *
 * @param int1 integer to clone.
 *
 * @return Cloned integer
 */
void * int_cloner(void * int1);

/**
 * Clones a double
 *
 * @param double1 double to clone.
 *
 * @return Cloned double.
 */
void * double_cloner(void * double1);

/**
 * Clones a cstring (char *)
 *
 * @param s1 cstring to clone.
 *
 * @return Cloned cstring.
 */
void * cstring_cloner(void * s1);


void * pointer_cloner(void * ptr);

#endif
