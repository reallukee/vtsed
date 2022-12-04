cd %~dp0

set src=..\vtsed

set bin64debug=..\bin\x64\Debug
set bin64release=..\bin\x64\Release
set bin86debug=..\bin\x86\Debug
set bin86release=..\bin\x86\Release

set include=..\templates\default\include
set lib=..\templates\default\lib
set dll=..\templates\default\dll

copy %src%\common.hpp %include%
copy %src%\console.hpp %include%
copy %src%\cmf.hpp %include%
copy %src%\dcontrols.hpp %include%
copy %src%\scontrols.hpp %include%
copy %src%\vts.hpp %include%
copy %src%\vts2.hpp %include%
copy %src%\vtsed.hpp %include%

copy %bin64debug%\vtsed-d-x64.lib %lib%
copy %bin64release%\vtsed-x64.lib %lib%
copy %bin86debug%\vtsed-d-x86.lib %lib%
copy %bin86release%\vtsed-x86.lib %lib%

copy %bin64debug%\vtsed-d-x64.dll %dll%
copy %bin64release%\vtsed-x64.dll %dll%
copy %bin86debug%\vtsed-d-x86.dll %dll%
copy %bin86release%\vtsed-x86.dll %dll%
