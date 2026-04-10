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
        (void)utec::tf::Tensor<int>::zeros(utec::tf::Shape{2, -1});
        cout << "no-exception\n";
    }
    catch (const invalid_argument&) {
        cout << "invalid_argument\n";
    }
}

TEST_CASE("Question #2.2") {
    execute_test("question_2_test_2.in", test_2);
}