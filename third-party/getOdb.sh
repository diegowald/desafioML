#wget https://www.codesynthesis.com/download/odb/2.4/odb_2.4.0-1_amd64.deb
wget https://www.codesynthesis.com/download/odb/2.4/odb-2.4.0.tar.gz
wget https://www.codesynthesis.com/download/odb/2.4/libodb-2.4.0.tar.gz
#wget https://www.codesynthesis.com/download/odb/2.4/libodb-mysql-2.4.0.tar.gz
wget https://www.codesynthesis.com/download/odb/2.4/libodb-sqlite-2.4.0.tar.gz
wget https://www.codesynthesis.com/download/odb/2.4/libodb-pgsql-2.4.0.tar.gz
wget https://www.codesynthesis.com/download/odb/2.4/libodb-boost-2.4.0.tar.gz
#wget https://www.codesynthesis.com/download/odb/2.4/libodb-qt-2.4.0.tar.gz
#wget https://www.codesynthesis.com/download/odb/2.4/odb-examples-2.4.0.tar.gz
#wget https://www.codesynthesis.com/download/odb/2.4/odb-tests-2.4.0.tar.gz

# Para compilar los lib
#  ./configure CPPFLAGS=-I/usr/local/include LDFLAGS=-L/usr/local/lib

tar xvzf odb-2.4.0.tar.gz
tar xvzf libodb-2.4.0.tar.gz
tar xvzf libodb-sqlite-2.4.0.tar.gz
tar xvzf libodb-pgsql-2.4.0.tar.gz
#tar xvzf libodb-mysql-2.4.0.tar.gz
tar xvzf libodb-boost-2.4.0.tar.gz
tar xvzf libodb-qt-2.4.0.tar.gz


cd odb-2.4.0
./configure
make
cd ..

cd libodb-2.4.0
./configure
make
cd ..

cd libodb-sqlite-2.4.0
./configure
make
cd ..

cd libodb-pgsql-2.4.0
./configure
make
cd ..

#cd libodb-mysql-2.4.0
#./configure
#make
#cd ..

cd libodb-boost-2.4.0
./configure
make
cd ..

cd libodb-qt-2.4.0
./configure
make
cd ..
