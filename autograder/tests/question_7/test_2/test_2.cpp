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
        const auto left = utec::tf::Tensor<int>::zeros(utec::tf::Shape{2, 3});
        const auto right = utec::tf::Tensor<int>::ones(utec::tf::Shape{3, 2});
        (void)(left + right);
        cout << "no-exception\n";
    }
    catch (const invalid_argument&) {
        cout << "invalid_argument\n";
    }
}

TEST_CASE("Question #7.2") {
    execute_test("question_7_test_2.in", test_2);
}