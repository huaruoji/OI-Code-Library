@echo off
:loop
make.exe < data.in
good.exe > data.in < test1.out
force.exe > data.in <test2.out
fc test1.out test2.out
if not errorlevel 1 goto loop
pause
:end