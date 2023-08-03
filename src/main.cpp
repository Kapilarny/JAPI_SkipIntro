#include "main.h"

#include <stdio.h>

ModMeta __stdcall GetModInfo() {
    static ModMeta meta = {
        "Skip Intro",
        "SkipIntro",
        "1.0.0"
    };

    return meta;
}

void __stdcall ModInit() {
    char buffer[] = "xxx";
    JAPI_PatchASBRMem((void*) 0xE4DC38, &buffer, 3);

    char* newBytes = (char*) malloc(8);
    JAPI_CopyASBRMem(newBytes, (void*)0xE5AB90, 8);

    JAPI_PatchASBRMem((void*) 0xE5AB98, newBytes, 8);
    JAPI_PatchASBRMem((void*) 0xE5ABC8, newBytes, 8);

    JAPI_LogInfo("Applied patches!");
}