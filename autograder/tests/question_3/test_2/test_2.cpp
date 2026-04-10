//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "tensor_backend.h"
#include <iostream>
using namespace std;

static void test_2() {
    auto tensor = utec::tf::Tensor<long long>::ones(utec::tf::Shape{2, 1, 2});
    tensor(1, 0, 1) = 9;

    cout << tensor(0, 0, 0) << ' ' << tensor(0, 0, 1) << ' ' << tensor(1, 0, 0) << ' ' << tensor(1, 0, 1) << '\n';
}

TEST_CASE("Question #3.2") {
    execute_test("question_3_test_2.in", test_2);
}