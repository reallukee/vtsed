cd %~dp0

if exist ..\.vs (
    rmdir /q /s ..\.vs
)

if exist ..\.vscode (
    rmdir /q /s ..\.vs
)
