#include <iostream>
#include <string>

#include "LFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo) {

        LFSR l("00111", 2);
        BOOST_REQUIRE(l.step() == 1);
        BOOST_REQUIRE(l.step() == 1);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 1);
        BOOST_REQUIRE(l.step() == 1);
        BOOST_REQUIRE(l.step() == 0);

        LFSR l2("00111", 2);
        BOOST_REQUIRE(l2.generate(8) == 198);
}

// This test runs a basic example that runs for a short string
BOOST_AUTO_TEST_CASE(threeBitTapAtOne) {

	LFSR l("101", 1);
	BOOST_REQUIRE(l.step() == 1);

	LFSR l2("101", 1);
	BOOST_REQUIRE(l2.generate(5) == 25);
}

// This test runs through the examples given in the PDF and ensures
// that the program runs as it should with a simple, common example
BOOST_AUTO_TEST_CASE(pdfExamples) {

	LFSR l("01101000010", 8);
	BOOST_REQUIRE(l.step() == 1);
	BOOST_REQUIRE(l.step() == 1);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 1);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 1);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);

        LFSR l2("01101000010", 8);
	BOOST_REQUIRE(l2.generate(5) == 25);
	BOOST_REQUIRE(l2.generate(5) == 4);
	BOOST_REQUIRE(l2.generate(5) == 30);
	BOOST_REQUIRE(l2.generate(5) == 27);
	BOOST_REQUIRE(l2.generate(5) == 18);
	BOOST_REQUIRE(l2.generate(5) == 26);
	BOOST_REQUIRE(l2.generate(5) == 28);
	BOOST_REQUIRE(l2.generate(5) == 24);
	BOOST_REQUIRE(l2.generate(5) == 23);
	BOOST_REQUIRE(l2.generate(5) == 29);
}