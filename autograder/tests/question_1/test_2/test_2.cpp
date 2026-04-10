//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "shape.h"
#include <iostream>
#include <stdexcept>
using namespace std;

static void test_2() {
    const utec::tf::Shape shape(vector<int>{5, 1});
    cout << shape.rank() << ' ' << shape.numel() << '\n';

    try {
        (void)utec::tf::Shape{2, 0};
        cout << "no-exception\n";
    }
    catch (const invalid_argument&) {
        cout << "invalid_argument\n";
    }
}

TEST_CASE("Question #1.2") {
    execute_test("question_1_test_2.in", test_2);
}