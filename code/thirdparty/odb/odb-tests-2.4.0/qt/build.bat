@echo off
rem file      : qt/build.bat
rem copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
rem license   : GNU GPL v2; see accompanying LICENSE file

rem
rem Build Qt tests using the VC++ batch mode compilation.
rem
rem build.bat database qt-version vc-version conf plat [/Build|/Clean|/Rebuild]
rem
rem conf: {Debug,Release}|all
rem plat: {Win32,x64}|all
rem

setlocal

if "_%1_" == "__" (
  echo no database specified
  goto usage
)

if "_%2_" == "__" (
  echo no Qt version specified
  goto usage
)

if "_%3_" == "__" (
  echo no VC++ version specified
  goto usage
)

if "_%~4_" == "__" (
  echo no configuration specified
  goto usage
)

if "_%~5_" == "__" (
  echo no platform specified
  goto usage
)

set "failed="

if "_%2_" == "_4_" set "qtver=4"
if "_%2_" == "_5_" set "qtver=5"

if "_%qtver%_" == "__" (
  echo unknown Qt version %2
  goto usage
)

if "_%3_" == "_8_" set "vcver=8"
if "_%3_" == "_9_" set "vcver=9"
if "_%3_" == "_10_" set "vcver=10"
if "_%3_" == "_11_" set "vcver=11"
if "_%3_" == "_12_" set "vcver=12"

if "_%vcver%_" == "__" (
  echo unknown VC++ version %3
  goto usage
)

set "confs=%~4"
set "plats=%~5"

if "_%confs%_" == "_all_" set "confs=Debug Release"
if "_%plats%_" == "_all_" set "plats=Win32 x64"

set "action=%6"
if "_%action%_" == "__" set "action=/Build"

set "devenv=%DEVENV%"
if "_%devenv%_" == "__" set "devenv=devenv.com"

goto start

rem
rem %1 - solution name
rem %2 - configuration to build
rem %3 - platform to build
rem
:run_build
  echo.
  echo building qt/%1 %3 %2
  "%devenv%" %1 %action% "%2|%3" 2>&1
  if errorlevel 1 set "failed=%failed% qt/%1\%3\%2"
goto :eof

:start

for %%d in (%1) do (
  for %%c in (%confs%) do (
      for %%p in (%plats%) do (
        call :run_build %%d/qt-%%d-qt%qtver%-vc%vcver%.sln %%c %%p
    )
  )
)

for %%c in (%confs%) do (
  for %%p in (%plats%) do (
    call :run_build common/qt-common-qt%qtver%-%1-vc%vcver%.sln %%c %%p
  )
)

if not "_%failed%_" == "__" goto error

echo.
echo ALL BUILDS SUCCEEDED
echo.
goto end

:usage
echo.
echo usage: build.bat database qt-version vc-version conf plat [action]
echo   valid configurations are: {Debug,Release}|all
echo   valid platforms are: {Win32,x64}|all
echo   valid actions are: /Build (default), /Clean, and /Rebuild
echo.

:error
if not "_%failed%_" == "__" (
  echo.
  for %%t in (%failed%) do echo FAILED: %%t
  echo.
)
endlocal
exit /b 1

:end
endlocal
