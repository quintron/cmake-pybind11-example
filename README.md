# cmake-pybind11-example
Clone project and update submodules
```batch
git clone git@github.com:quintron/cmake-pybind11-example.git
cd cmake-pybind11-example
git submodule init
git submodule update
```
Build Project and run tests with cmake
```batch
mkdir build & cd build
cmake -A x64 ..
cmake --build . --config Release
ctest --build . -C Release
```
Test python module
```batch
cd Release & python
```
within python console
```python
import myproject
myproject.add(2,8)
```