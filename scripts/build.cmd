cd %~dp0

set msbuild="C:\Program Files\Microsoft Visual Studio\2022\Community\Msbuild\Current\Bin\MSBuild.exe"

%msbuild% ..\vtsed\vtsed.vcxproj -nologo -v:q -p:warninglevel=0 -p:configuration=Release -p:platform=x64
%msbuild% ..\vtsed\vtsed.vcxproj -nologo -v:q -p:warninglevel=0 -p:configuration=Release -p:platform=x86
%msbuild% ..\vtsed\vtsed.vcxproj -nologo -v:q -p:warninglevel=0 -p:configuration=Debug -p:platform=x64
%msbuild% ..\vtsed\vtsed.vcxproj -nologo -v:q -p:warninglevel=0 -p:configuration=Debug -p:platform=x86
