@echo Hello bat

del /q /s build
mkdir build
cd build

cmake --version

cmake -G "NMake Makefiles" ..
