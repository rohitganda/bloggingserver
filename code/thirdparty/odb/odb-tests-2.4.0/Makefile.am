# file      : Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

SUBDIRS = libcommon common evolution

if ODB_TESTS_BOOST
SUBDIRS += boost
endif

if ODB_TESTS_QT
SUBDIRS += qt
endif

if DATABASE_MYSQL
SUBDIRS += mysql
endif

if DATABASE_SQLITE
SUBDIRS += sqlite
endif

if DATABASE_PGSQL
SUBDIRS += pgsql
endif

if DATABASE_ORACLE
SUBDIRS += oracle
endif

if DATABASE_MSSQL
SUBDIRS += mssql
endif

EXTRA_DIST = GPLv2 LICENSE README INSTALL version test.bat tester.bat mysql-driver.bat mysql.options sqlite-driver.bat sqlite.options pgsql-driver.bat pgsql.options oracle.options oracle-driver.bat mssql.options mssql-driver.bat bootstrap tester.in build.bat
ACLOCAL_AMFLAGS = -I m4
