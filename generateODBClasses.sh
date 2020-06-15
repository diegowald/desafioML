rm *-odb.cxx
rm *-odb.ixx
rm *-odb.hxx
rm *.sql

#./third-party/odb-2.4.0/odb/odb -d pgsql --std c++11 --generate-schema --generate-query  *.h
odb -d pgsql  -p boost/date-time --std c++11 --generate-schema --generate-query  --at-once DTO.h



