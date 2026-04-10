//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "tensor_backend.h"
#include <iostream>
using namespace std;

static void test_1() {
    const auto tensor = utec::tf::Tensor<int>::ones(utec::tf::Shape{2, 2});

    cout << tensor(0, 0) << ' ' << tensor(0, 1) << ' ' << tensor(1, 0) << ' ' << tensor(1, 1) << '\n';
}

TEST_CASE("Question #3.1") {
    execute_test("question_3_test_1.in", test_1);
}