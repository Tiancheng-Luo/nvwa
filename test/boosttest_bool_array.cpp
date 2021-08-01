#include "nvwa/bool_array.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <type_traits>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test_framework;

BOOST_AUTO_TEST_CASE(bool_array_test)
{
    nvwa::bool_array ba;
    BOOST_CHECK(ba.create(100));
    ba.initialize(false);
    BOOST_CHECK_EQUAL(ba[0], false);
    BOOST_CHECK_EQUAL(ba[1], false);
    BOOST_CHECK_EQUAL(ba[2], false);
    BOOST_CHECK_EQUAL(ba[99], false);
    ba[5] = true;
    ba.set(6);
    BOOST_CHECK_EQUAL(ba.at(5), true);
    BOOST_CHECK_EQUAL(ba[6], true);
    BOOST_CHECK_EQUAL(ba.count(), 2);
    ba.flip();
    BOOST_CHECK_EQUAL(ba.at(0), true);
    BOOST_CHECK_EQUAL(ba[1], true);
    BOOST_CHECK_EQUAL(ba[2], true);
    BOOST_CHECK_EQUAL(ba[5], false);
    BOOST_CHECK_EQUAL(ba.at(6), false);
    BOOST_CHECK_EQUAL(ba.at(99), true);
    BOOST_CHECK_EQUAL(ba.count(), 98);
    BOOST_REQUIRE_THROW(ba.at(100), std::out_of_range);

    nvwa::bool_array ba2(ba);
    BOOST_CHECK_EQUAL(ba2.at(0), true);
    BOOST_CHECK_EQUAL(ba2[1], true);
    BOOST_CHECK_EQUAL(ba2[2], true);
    BOOST_CHECK_EQUAL(ba2[5], false);
    BOOST_CHECK_EQUAL(ba2.at(6), false);
    BOOST_CHECK_EQUAL(ba2.at(99), true);
    BOOST_CHECK_EQUAL(ba2.count(), 98);

    std::ostringstream oss;
    oss << ba;
    BOOST_CHECK_EQUAL(oss.str(),
                      "11111001111111111111111111111111111111111111111111"
                      "11111111111111111111111111111111111111111111111111");

    BOOST_TEST_MESSAGE("is_nothrow_constructible is "
                << std::is_nothrow_constructible<nvwa::bool_array>::value);
    BOOST_TEST_MESSAGE("is_nothrow_default_constructible is "
                << std::is_nothrow_default_constructible<nvwa::bool_array>::value);
    BOOST_TEST_MESSAGE("is_nothrow_move_constructible is "
                << std::is_nothrow_move_constructible<nvwa::bool_array>::value);
    BOOST_TEST_MESSAGE("is_nothrow_copy_constructible is "
                << std::is_nothrow_copy_constructible<nvwa::bool_array>::value);
    BOOST_TEST_MESSAGE("is_nothrow_move_assignable is "
                << std::is_nothrow_move_assignable<nvwa::bool_array>::value);
    BOOST_TEST_MESSAGE("is_nothrow_copy_assignable is "
                << std::is_nothrow_copy_assignable<nvwa::bool_array>::value);
    BOOST_TEST_MESSAGE("is_nothrow_destructible is "
                << std::is_nothrow_destructible<nvwa::bool_array>::value);
}
