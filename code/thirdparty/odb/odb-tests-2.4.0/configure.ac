# file      : configure.ac
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

AC_PREREQ(2.60)
AC_INIT([odb-tests], [2.4.0], [odb-users@codesynthesis.com])
AC_CONFIG_AUX_DIR([config])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([common/template/driver.cxx])

AM_INIT_AUTOMAKE([-Wall -Werror foreign nostdinc subdir-objects dist-bzip2 dist-zip tar-ustar])
m4_ifdef([AM_PROG_AR], [AM_PROG_AR]) # Required by automake 1.12.

LT_INIT([win32-dll])

AC_CANONICAL_HOST

# Check for diff.
#
DIFF_TOOL

# Check for C++ compiler and use it to compile the tests.
#
AC_PROG_CXX
AC_LANG(C++)

# Create the libtool executable so that we can use it in further tests.
#
LT_OUTPUT

# Check for threads.
#
THREADS

AM_CONDITIONAL([ODB_TESTS_THREADS], [test x$threads != xnone])

# Check for C++11.
#
CXX11([HAVE_CXX11], [Compiling in the C++11 mode.])

# Check for the ODB compiler.
#
ODB_COMPILER([], [AC_MSG_ERROR([odb compiler is not found; consider setting ODB variable or using --with-odb=DIR])])

# Check for the ODB libs.
#
LIBODB([], [AC_MSG_ERROR([libodb is not found; consider using --with-libodb=DIR])])

# Check for TR1 <memory> availability (has to be after libodb).
#
TR1_MEMORY

# Check for boost.
#
odb_tests_boost=yes
LIBBOOST([], [odb_tests_boost=no])
LIBBOOST_SYSTEM
LIBBOOST_SMART_PTR([], [odb_tests_boost=no])
LIBBOOST_UNORDERED([], [odb_tests_boost=no])
LIBBOOST_DATE_TIME([], [odb_tests_boost=no])

# Check for libodb-boost.
#
LIBODB_BOOST([], [odb_tests_boost=no])

AM_CONDITIONAL([ODB_TESTS_BOOST], [test x$odb_tests_boost != xno])

# Check for Qt.
#
odb_tests_qt=yes
LIBQTCORE([], [odb_tests_qt=no])

# Check for libodb-qt.
#
LIBODB_QT([], [odb_tests_qt=no])

AM_CONDITIONAL([ODB_TESTS_QT], [test x$odb_tests_qt != xno])

# Check which database we are using.
#
DATABASE

case $database in
  mysql)
    LIBODB_MYSQL([], [AC_MSG_ERROR([libodb-mysql is not found; consider using --with-libodb-mysql=DIR])])
    MYSQL
    ;;
  sqlite)
    LIBODB_SQLITE([], [AC_MSG_ERROR([libodb-sqlite is not found; consider using --with-libodb-sqlite=DIR])])
    SQLITE
    ;;
  pgsql)
    LIBODB_PGSQL([], [AC_MSG_ERROR([libodb-pgsql is not found; consider using --with-libodb-pgsql=DIR])])
    PGSQL
    ;;
  oracle)
    LIBODB_ORACLE([], [AC_MSG_ERROR([libodb-oracle is not found; consider using --with-libodb-oracle=DIR])])
    ORACLE
    ;;
  mssql)
    LIBODB_MSSQL([], [AC_MSG_ERROR([libodb-mssql is not found; consider using --with-libodb-mssql=DIR])])
    MSSQL
    ;;
esac

# Define LIBCOMMON_STATIC_LIB if we are build static library on certain
# platforms.
#
STATIC_LIB([LIBCOMMON_STATIC_LIB], [Static library interface.])

# Output.
#
AC_CONFIG_HEADERS([config.h libcommon/common/config.h])
AC_CONFIG_FILES([boost/common/Makefile boost/common/multi-index/Makefile boost/common/optional/Makefile boost/common/smart-ptr/Makefile boost/common/template/Makefile boost/common/unordered/Makefile boost/common/uuid/Makefile boost/Makefile boost/mssql/date-time/Makefile boost/mssql/Makefile boost/mssql/template/Makefile boost/mysql/date-time/Makefile boost/mysql/Makefile boost/mysql/template/Makefile boost/oracle/date-time/Makefile boost/oracle/Makefile boost/oracle/template/Makefile boost/pgsql/date-time/Makefile boost/pgsql/Makefile boost/pgsql/template/Makefile boost/sqlite/date-time/Makefile boost/sqlite/Makefile boost/sqlite/template/Makefile common/access/Makefile common/auto/Makefile common/blob/Makefile common/bulk/Makefile common/callback/Makefile common/circular/multiple/Makefile common/circular/single/Makefile common/composite-id/Makefile common/composite/Makefile common/const-member/Makefile common/const-object/Makefile common/container/basics/Makefile common/container/change-tracking/Makefile common/ctor/Makefile common/default/Makefile common/definition/Makefile common/enum/Makefile common/erase-query/Makefile common/index/Makefile common/inheritance/polymorphism/Makefile common/inheritance/reuse/Makefile common/inheritance/transient/Makefile common/inverse/Makefile common/lazy-ptr/Makefile common/lifecycle/Makefile common/Makefile common/no-id/Makefile common/object/Makefile common/optimistic/Makefile common/pragma/Makefile common/prepared/Makefile common/query/array/Makefile common/query/basics/Makefile common/query/one/Makefile common/readonly/Makefile common/relationship/basics/Makefile common/relationship/on-delete/Makefile common/relationship/query/Makefile common/schema/embedded/basics/Makefile common/schema/embedded/order/Makefile common/schema/namespace/Makefile common/section/basics/Makefile common/section/polymorphism/Makefile common/session/cache/Makefile common/session/custom/Makefile common/statement/processing/Makefile common/template/Makefile common/threads/Makefile common/transaction/basics/Makefile common/transaction/callback/Makefile common/types/Makefile common/view/basics/Makefile common/view/olv/Makefile common/virtual/Makefile common/wrapper/Makefile evolution/add-column/Makefile evolution/add-foreign-key/Makefile evolution/add-index/Makefile evolution/add-table/Makefile evolution/alter-column/Makefile evolution/combined/Makefile evolution/data/Makefile evolution/drop-column/Makefile evolution/drop-foreign-key/Makefile evolution/drop-index/Makefile evolution/drop-table/Makefile evolution/embedded/Makefile evolution/Makefile evolution/soft-add/Makefile evolution/soft-delete/Makefile evolution/template/Makefile evolution/tester evolution/version/Makefile libcommon/common/Makefile libcommon/Makefile Makefile mssql/custom/Makefile mssql/database/Makefile mssql/Makefile mssql/native/Makefile mssql/query/Makefile mssql/stored-proc/Makefile mssql/template/Makefile mssql/types/Makefile mysql/custom/Makefile mysql/database/Makefile mysql/index/Makefile mysql/Makefile mysql/native/Makefile mysql/template/Makefile mysql/truncation/Makefile mysql/types/Makefile oracle/custom/Makefile oracle/database/Makefile oracle/Makefile oracle/native/Makefile oracle/template/Makefile oracle/types/Makefile pgsql/custom/Makefile pgsql/database/Makefile pgsql/index/Makefile pgsql/Makefile pgsql/native/Makefile pgsql/template/Makefile pgsql/truncation/Makefile pgsql/types/Makefile qt/common/basic/Makefile qt/common/containers/basics/Makefile qt/common/containers/change-tracking/Makefile qt/common/Makefile qt/common/smart-ptr/Makefile qt/common/template/Makefile qt/Makefile qt/mssql/basic/Makefile qt/mssql/date-time/Makefile qt/mssql/Makefile qt/mssql/template/Makefile qt/mysql/basic/Makefile qt/mysql/date-time/Makefile qt/mysql/Makefile qt/mysql/template/Makefile qt/oracle/basic/Makefile qt/oracle/date-time/Makefile qt/oracle/Makefile qt/oracle/template/Makefile qt/pgsql/basic/Makefile qt/pgsql/date-time/Makefile qt/pgsql/Makefile qt/pgsql/template/Makefile qt/sqlite/basic/Makefile qt/sqlite/date-time/Makefile qt/sqlite/Makefile qt/sqlite/template/Makefile sqlite/custom/Makefile sqlite/database/Makefile sqlite/Makefile sqlite/native/Makefile sqlite/template/Makefile sqlite/transaction/Makefile sqlite/truncation/Makefile sqlite/types/Makefile tester])
AC_CONFIG_COMMANDS([tester-mode], [chmod +x tester evolution/tester])
AC_OUTPUT
