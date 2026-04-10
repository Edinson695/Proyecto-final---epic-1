//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "tensor_backend.h"
#include <iostream>
using namespace std;

static void test_1() {
    const auto tensor = utec::tf::Tensor<int>::from_data(utec::tf::Shape{2, 3}, {1, 2, 3, 4, 5, 6});
    const auto reshaped = tensor.reshape(utec::tf::Shape{3, 2});

    cout << reshaped.shape()[0] << ' ' << reshaped.shape()[1] << '\n';
    cout << reshaped(0, 0) << ' ' << reshaped(1, 1) << ' ' << reshaped(2, 1) << '\n';
}

TEST_CASE("Question #6.1") {
    execute_test("question_6_test_1.in", test_1);
}