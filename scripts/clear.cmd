cd %~dp0

if exist ..\.vs rmdir /q /s ..\.vs
if exist ..\.vscode rmdir /q /s ..\.vs

if exist ..\vtsed\x64 rmdir /q /s ..\vtsed\x64
if exist ..\vtsed\x86 rmdir /q /s ..\vtsed\x86
if exist ..\vtsed.test\x64 rmdir /q /s ..\vtsed.test\x64
if exist ..\vtsed.test\x86 rmdir /q /s ..\vtsed.test\x86
if exist ..\examples\checklistbox\x64 rmdir /q /s ..\examples\checklistbox\x64
if exist ..\examples\checklistbox\x86 rmdir /q /s ..\examples\checklistbox\x86
if exist ..\examples\gridcol\x86 rmdir /q /s ..\examples\gridcol\x86
if exist ..\examples\gridcol\x64 rmdir /q /s ..\examples\gridrcol\x64
if exist ..\examples\gridrow\x86 rmdir /q /s ..\examples\gridrow\x86
if exist ..\examples\gridrow\x64 rmdir /q /s ..\examples\gridrow\x64
if exist ..\examples\listbox\x86 rmdir /q /s ..\examples\listbox\x86
if exist ..\examples\listbox\x64 rmdir /q /s ..\examples\listbox\x64
if exist ..\examples\table\x86 rmdir /q /s ..\examples\table\x86
if exist ..\examples\table\x64 rmdir /q /s ..\examples\table\x64
if exist ..\templates\default\x64 rmdir /q /s ..\templates\default\x64
if exist ..\templates\default\x86 rmdir /q /s ..\templates\default\x86
if exist ..\x64 rmdir /q /s ..\x64
if exist ..\x86 rmdir /q /s ..\x86
