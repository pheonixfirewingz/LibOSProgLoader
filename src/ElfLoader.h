#pragma once

#include <libos/Defines.h>

typedef enum LoseExecPremissions
{
	LOSE_ALL
} LoseExecPremissions;

typedef struct loseExecInfo
{
    uint8_t exeBits = 0;
    const char* path; 
    size_t path_size = 0;

} loseExecInfo;

EXPORT_DLL losResult loseExec(_in_ const loseExecInfo exec_info);