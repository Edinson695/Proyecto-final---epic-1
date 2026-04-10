//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "shape.h"
#include <iostream>
using namespace std;

static void test_1() {
    const utec::tf::Shape shape{2, 3, 4};
    const utec::tf::Shape expected{2, 3, 4};

    cout << shape.rank() << '\n';
    cout << shape.numel() << '\n';
    cout << shape[0] << ' ' << shape[1] << ' ' << shape[2] << '\n';
    cout << boolalpha << (shape == expected) << '\n';
}

TEST_CASE("Question #1.1") {
    execute_test("question_1_test_1.in", test_1);
}