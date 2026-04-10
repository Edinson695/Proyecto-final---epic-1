//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "tensor_backend.h"
#include <iostream>
using namespace std;

static void test_1() {
    const auto tensor = utec::tf::Tensor<int>::ones(utec::tf::Shape{2, 3, 4});

    cout << tensor.rank() << '\n';
    cout << tensor.numel() << '\n';
}

TEST_CASE("Question #4.1") {
    execute_test("question_4_test_1.in", test_1);
}