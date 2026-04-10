//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "tensor_backend.h"
#include <iostream>
#include <stdexcept>
using namespace std;

static void test_2() {
    try {
        (void)utec::tf::Tensor<int>::from_data(utec::tf::Shape{2, 3}, {1, 2, 3});
        cout << "no-exception\n";
    }
    catch (const invalid_argument&) {
        cout << "invalid_argument\n";
    }

    try {
        auto tensor = utec::tf::Tensor<int>::from_data(utec::tf::Shape{2, 2}, {1, 2, 3, 4});
        (void)tensor(2, 0);
        cout << "no-exception\n";
    }
    catch (const out_of_range&) {
        cout << "out_of_range\n";
    }
}

TEST_CASE("Question #5.2") {
    execute_test("question_5_test_2.in", test_2);
}