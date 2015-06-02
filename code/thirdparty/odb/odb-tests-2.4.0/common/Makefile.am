# file      : common/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

SUBDIRS = access auto blob bulk callback circular/single circular/multiple composite composite-id const-object const-member container/basics container/change-tracking ctor default definition enum erase-query index inheritance/polymorphism inheritance/reuse inheritance/transient inverse lazy-ptr lifecycle no-id object optimistic pragma prepared query/basics query/array query/one readonly relationship/basics relationship/on-delete relationship/query schema/namespace schema/embedded/basics schema/embedded/order section/basics section/polymorphism session/cache statement/processing template transaction/basics transaction/callback types view/basics virtual wrapper

if ODB_TESTS_THREADS
SUBDIRS += threads
endif

if HAVE_CXX11
SUBDIRS += session/custom view/olv
endif

EXTRA_DIST = test.bat common-mysql-vc8.sln common-sqlite-vc8.sln common-pgsql-vc8.sln common-oracle-vc8.sln common-mssql-vc8.sln common-mysql-vc9.sln common-sqlite-vc9.sln common-pgsql-vc9.sln common-oracle-vc9.sln common-mssql-vc9.sln common-mysql-vc10.sln common-sqlite-vc10.sln common-pgsql-vc10.sln common-oracle-vc10.sln common-mssql-vc10.sln common-mysql-vc11.sln common-sqlite-vc11.sln common-pgsql-vc11.sln common-oracle-vc11.sln common-mssql-vc11.sln common-mysql-vc12.sln common-sqlite-vc12.sln common-pgsql-vc12.sln common-oracle-vc12.sln common-mssql-vc12.sln
