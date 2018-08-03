#!/bin/sh
###############################################################################
#  Copyright (c) 2014-2015 libbitcoin developers (see COPYING).
#  Copyright (c) 2018 bitcoin.org.vc Bitcoin Venture Currency/Jason Coombs (see COAUTHORS)
#         GENERATED SOURCE CODE, DO NOT EDIT EXCEPT EXPERIMENTALLY
#
###############################################################################

# Define tests and options.
#==============================================================================
BOOST_UNIT_TEST_OPTIONS=\
"--run_test=* "\
"--show_progress=no "\
"--detect_memory_leak=0 "\
"--report_level=no "\
"--build_info=yes"


# Run tests.
#==============================================================================
./test/bitcoinvc-test ${BOOST_UNIT_TEST_OPTIONS} > test.log
