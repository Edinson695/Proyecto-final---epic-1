//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "tensor_backend.h"
#include <iostream>
using namespace std;

static void test_1() {
    const auto left = utec::tf::Tensor<int>::from_data(utec::tf::Shape{2, 2}, {0, 1, 2, 3});
    const auto right = utec::tf::Tensor<int>::ones(utec::tf::Shape{2, 2});
    const auto sum = left + right;

    cout << sum(0, 0) << ' ' << sum(0, 1) << ' ' << sum(1, 0) << ' ' << sum(1, 1) << '\n';
    cout << left(1, 1) << '\n';
}

TEST_CASE("Question #7.1") {
    execute_test("question_7_test_1.in", test_1);
}