//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "tensor_backend.h"
#include <iostream>
using namespace std;

static void test_2() {
    const auto tensor = utec::tf::Tensor<int>::zeros(utec::tf::Shape{4, 5});

    cout << boolalpha << (tensor.shape() == utec::tf::Shape{4, 5}) << '\n';
    cout << tensor.shape()[0] << ' ' << tensor.shape()[1] << '\n';
}

TEST_CASE("Question #4.2") {
    execute_test("question_4_test_2.in", test_2);
}