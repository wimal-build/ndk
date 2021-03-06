/*
 * Copyright (C) 2011 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <windows.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

/* A brain-dead 'echo' toolbox program for Windows, because the cmd.exe
 * 'echo' command is too weird to be usable with the NDK.
 */

int main(void)
{
    bool flagNoNewline = false;
    int argc;
    wchar_t** argv = CommandLineToArgvW(GetCommandLineW(), &argc);

    // Discard the name of the executable.
    if (argc > 0) {
        argc--;
        argv++;
    }

    // IMPORTANT: echo should only accept -n as a first option, everything
    // else must be treated as part of the input string.
    if (argc > 0 && !wcscmp(argv[0], L"-n")) {
        flagNoNewline = true;
        argc--;
        argv++;
    }

    for (int i = 0; i < argc; ++i) {
        wprintf(L"%ls%ls", ((i > 0) ? L" " : L""), argv[i]);
    }
    if (!flagNoNewline) {
        wprintf(L"\n");
    }

    return 0;
}
