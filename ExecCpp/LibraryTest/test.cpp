#include "pch.h"

#include <iostream>
#include <gtest/gmock.h>
#include <gtest/gtest.h>

#include "Library/PrimeFactorization/SieveOfEratosthenes.h"
#include "test.h"

TEST(PrimeFactorizationTest, SieveOfEratorthenesTest) {
    SieveOfEratosthenes<int> erato(100);
    auto res = std::move(erato.decompose());
    auto b = res.cbegin();
    EXPECT_EQ(b->first, 2);
    b++;
    EXPECT_EQ(b->first, 5);
}