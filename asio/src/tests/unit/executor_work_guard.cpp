//
// executor_work_guard.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

// Disable autolinking for unit tests.
#if !defined(BOOST_ALL_NO_LIB)
#define BOOST_ALL_NO_LIB 1
#endif // !defined(BOOST_ALL_NO_LIB)

// Test that header file is self-contained.
#include "asio/executor_work_guard.hpp"

#include "unit_test.hpp"

#include "asio/io_context.hpp"
#if defined(ASIO_HAS_MOVE)
#include <utility>
#endif

void executor_work_guard_ctad_test() {
#if defined(ASIO_HAS_DEDUCTION_GUIDES)
  asio::io_context ioc;
  asio::io_context::executor_type executor = ioc.get_executor();
  // executor_work_guard can be CTAD constructed by copy
  asio::executor_work_guard copy_guard(executor);
  // executor_work_guard can be CTAD constructed by move
#if defined(ASIO_HAS_MOVE)
  asio::executor_work_guard move_guard(std::move(executor));
#endif // defined(ASIO_HAS_DEDUCTION_GUIDES)
#endif // defined(ASIO_HAS_MOVE)
}

ASIO_TEST_SUITE
(
  "executor_work_guard",
  ASIO_TEST_CASE(executor_work_guard_ctad_test)
)
