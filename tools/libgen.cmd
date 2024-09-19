@echo off

rem Generate library files from DLL

setlocal enabledelayedexpansion


rem Check for Visual Studio enviroment

where /q lib.exe && where /q dumpbin.exe

if %errorlevel% neq 0 (
	echo Visual Studio enviroment not initialized
	goto error
)


rem Check arguments

if "%~1" equ "" (
	goto usage
) else if not exist "%1" (
	echo Input path does not exist
	goto error
)

if "%~2" equ "" (
	goto usage
) else (
	set "machine=%~2"
)


rem Set up paths

set "lib=%~dpn1.lib"
set "dump=%~dpn1.dump"
set "def=%~dpn1.def"
set "exp=%~dpn1.exp"
set "und=%~dpn1.und"

if exist "%lib%"	del %lib%
if exist "%dump%"	del %dump%
if exist "%def%"	del %def%
if exist "%exp%"	del %exp%
if exist "%und%"	del %und%


rem Dump binary exports

dumpbin /exports %1 > %dump%

if %errorlevel% neq 0 (
	echo Tool dumpbin failed
	goto error
)


rem Create module definition

echo EXPORTS > %def%

set "i=0"

for /f "delims=" %%l in (%dump%) do (

	set "str=%%l"
	set /a "i+=1"

	if !i! equ 10 (
		set /a "end=str"
		set /a "end+=13"
	)

	if !i! gtr 12 if !i! lss !end! (
		echo !str:~26! >> %def%
	)

)


rem Generate lib

lib /nologo /machine:%machine% "/def:%def%" "/out:%lib%" >nul

if %errorlevel% neq 0 (
	echo Tool lib failed
	goto error
)


endlocal

exit /b 0


:usage

echo Invalid arguments
echo Usage: libgen.cmd ^<Input^> <Machine>


:error

endlocal

exit /b 1
