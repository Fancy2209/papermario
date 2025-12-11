if [ ! -d "build" ]; then
    cmake -S . -B build
fi
cd build
if [ ! -e "ver" ]; then
    ln -s ../ver ver
fi
if [ ! -e "include" ]; then
    ln -s ../include include
fi
make -j$(nproc)
