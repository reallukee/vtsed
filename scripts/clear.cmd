cd %~dp0

if exist ..\.vs rmdir /q /s ..\.vs
if exist ..\.vscode rmdir /q /s ..\.vs

if exist ..\vtsed\x64 rmdir /q /s ..\vtsed\x64
if exist ..\vtsed\x86 rmdir /q /s ..\vtsed\x86
if exist ..\vtsed.test\x64 rmdir /q /s ..\vtsed.test\x64
if exist ..\vtsed.test\x86 rmdir /q /s ..\vtsed.test\x86
