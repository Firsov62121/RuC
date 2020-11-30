/*
 *	Copyright 2020 Andrey Terekhov, Victor Y. Fadeev
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *
 *		http://www.apache.org/licenses/LICENSE-2.0
 *
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 */

#pragma once

#include "context.h"
#include "defs.h"


#define REPRTAB		(sx->reprtab.table)
#define REPRTAB_POS (sx->reprtab.pos)
#define REPRTAB_LEN (sx->reprtab.len)


#ifdef __cplusplus
extern "C" {
#endif

/** Global vars definition */
typedef struct syntax
{
	// mem, pc & iniprocs - usage here only for codes printing

	int mem[MAXMEMSIZE];		/** Memory */
	int pc;						/** Program counter */

	int iniprocs[INIPROSIZE];	/** Init processes */
	int procd;					/** Process management daemon */

	int functions[FUNCSIZE];	/** Functions table */
	int funcnum;				/** Number of functions */

	int identab[MAXIDENTAB];	/** Identifiers table */
	int id;						/** Number of identifiers */

	int modetab[MAXMODETAB];	/** Modes table */
	int md;						/** Number of modes */
	
	int tree[MAXTREESIZE];		/** Tree */
	int tc;						/** Tree counter */

	int maxdisplg;				/** Max displacement */
	int wasmain;				/** Main function flag */

	int anstdispl;				/** Stack displacement */

	compiler_table reprtab;		/** Representations table */
} syntax;


/**
 *	Initialize syntax structure (by allocating memory)
 *
 *	@param	sx		Syntax structure
 *
 *	@return	@c 0 on success, @c -1 on failure
 */
int syntax_init(syntax *const sx);

/**
 *	Deinitialize syntax structure (by free memory)
 *
 *	@param	sx		Syntax structure
 *
 *	@return	@c 0 on success, @c -1 on failure
 */
int syntax_deinit(syntax *const sx);

#ifdef __cplusplus
} /* extern "C" */
#endif