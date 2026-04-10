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
        const auto tensor = utec::tf::Tensor<int>::ones(utec::tf::Shape{2, 3});
        (void)tensor.reshape(utec::tf::Shape{4, 2});
        cout << "no-exception\n";
    }
    catch (const invalid_argument&) {
        cout << "invalid_argument\n";
    }
}

TEST_CASE("Question #6.2") {
    execute_test("question_6_test_2.in", test_2);
}