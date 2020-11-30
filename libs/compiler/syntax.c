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

#include "syntax.h"


int syntax_init(syntax *const sx)
{
	if (sx == NULL)
	{
		return -1;
	}

	compiler_table_init(&sx->reprtab);
	sx->reprtab.len = 1;

	sx->pc = 4;
	sx->procd = 1;
	sx->funcnum = 2;
	sx->id = 2;
	sx->md = 1;

	sx->maxdisplg = 3;

	return 0;
}

int syntax_deinit(syntax *const sx)
{
	if (sx == NULL || sx->reprtab.table == NULL)
	{
		return -1;
	}

	free(sx->reprtab.table);
	sx->reprtab.table = NULL;
	return 0;
}