/*
 * stdafx.h
 *
 *  Created on: Jul 18, 2018
 *      Author: bhart
 */

#ifndef __STDAFX_H__
#define __STDAFX_H__

#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>

#include <include/conversion_core.h>
#include <include/console_core.h>
#include <include/debug_core.h>
#include <include/geometry_core.h>
#include <include/file_core.h>

void save_results_to_file(const char* format_string, double results);

#include "resource.h"

#endif /* __STDAFX_H__ */
