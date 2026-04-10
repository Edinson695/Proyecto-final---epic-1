//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "tensor_backend.h"
#include <iostream>
using namespace std;

static void test_1() {
    auto tensor = utec::tf::Tensor<int>::from_data(utec::tf::Shape{2, 3}, {1, 2, 3, 4, 5, 6});
    tensor(0, 1) = 20;

    cout << tensor(0, 0) << ' ' << tensor(0, 1) << ' ' << tensor(1, 2) << '\n';
}

TEST_CASE("Question #5.1") {
    execute_test("question_5_test_1.in", test_1);
}