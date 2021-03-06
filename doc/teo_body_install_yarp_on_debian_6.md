## Install YARP (Debian 6.0)

We use YARP for communications. Installing YARP on Debian should be quite straightforward. Note that you will be prompted for your password upon using '''sudo''' a couple of times:

```bash
sudo apt-get install build-essential libace-dev subversion git
sudo apt-get install libgsl0-dev  # Needed for creating YARP lib_math we use for kinematics
cd  # go home
mkdir -p repos; cd repos  # make $HOME/repos if it doesn't exist; then, enter it
git clone https://github.com/robotology/yarp
cd yarp; mkdir build; cd build
cmake .. -DCREATE_LIB_MATH=ON -DYARP_USE_QT5=OFF  # YARP_USE_QT5 can induce errors as of 02/2016.
make -j3;  sudo make install; sudo ldconfig; cd  # go home
```

For additional options use ccmake instead of cmake.
